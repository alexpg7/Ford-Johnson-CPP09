#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>

bool	ft_checkifdate(Date& date, int &i, std::string line)
{
	unsigned int	day;
	unsigned int	month;
	unsigned int	year;

	year = std::atoi(line.c_str() + i);
	for (int n = 0; n < 4; n++)
	{
		if (std::isdigit(line[i++]))
			continue ;
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	if (line[i++] != '-')
	{
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	month = std::atoi(line.c_str() + i);
	for (int n = 0; n < 2; n++)
	{
		if (std::isdigit(line[i++]))
			continue ;
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	if (line[i++] != '-')
	{
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	day = std::atoi(line.c_str() + i);
	for (int n = 0; n < 2; n++)
	{
		if (std::isdigit(line[i++]))
			continue ;
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	date = Date(year, month, day);
	return true;
}

bool	ft_checkifnum(int& i, std::string line)
{
	if (!std::isdigit(line[i]))
	{
		std::cerr << "Incorrect value format (must be positive int or float)" << std::endl;
		return false;
	}
	while (line[i])
	{
		if (!std::isdigit(line[i]))
		{
			if (line[i] != '.')
			{
				std::cerr << "Incorrect value format (must be positive int or float)" << std::endl;
				return false;
			}
			i++;
			break;
		}
		i++;
	}
	if (line[i] == '.')
		i++;
	while (line[i])
	{
		if (!std::isdigit(line[i]))
		{
			std::cerr << "Incorrect value format (must be positive int or float)" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}

bool	ft_checkifnum2(int& i, std::string line)
{
	if (!std::isdigit(line[i]))
	{
		if (line[i] == '-')
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	if (std::atof(line.c_str() + i) > __INT_MAX__)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	while (line[i])
	{
		if (!std::isdigit(line[i]))
		{
			if (line[i] != '.')
			{
				std::cerr << "Incorrect value format (must be positive int or float)" << std::endl;
				return false;
			}
			i++;
			break;
		}
		i++;
	}
	if (line[i] == '.')
		i++;
	while (line[i])
	{
		if (!std::isdigit(line[i]))
		{
			std::cerr << "Incorrect value format (must be positive int or float)" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}

bool	ft_parseline(std::map<Date, float>& datamap, std::string line)
{
	int	i = 0;
	Date	date;
	float	value;

	try
	{
		if (!ft_checkifdate(date, i, line))
			return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error in line " << i + 1 << ": " << e.what() << " => " << line << '\n';
	}
	if (line[i++] != ',')
		return false;
	value = std::atof(line.c_str() + i);
	if (!ft_checkifnum(i, line))
		return false;
	datamap.insert({date, value});
	return true;
}

Date ft_closestdate(Date date, const std::map<Date, float>& data)
{
	std::map<Date, float>::const_iterator it = data.lower_bound(date);

	if (it != data.end() && it->first == date)
		return it->first;

	if (it == data.begin())
		return it->first;

	if (it == data.end())
		return (--it)->first;

	--it;
	return it->first;
}

void	ft_getresult(Date date, float value, float price)
{
	std::ios oldState(nullptr);
	oldState.copyfmt(std::cout);
	std::cout << date << " => " << value << " = ";
	std::cout << std::fixed << std::setprecision(2) << value * price << std::endl;
	std::cout.copyfmt(oldState);
}

bool	ft_parseinputline(std::map<Date, float> data, std::string line)
{
	int	i = 0;
	Date	date;
	float	value;

	try
	{
		if (!ft_checkifdate(date, i, line))
			return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error in line " << i + 1 << ": " << e.what() << " => " << line << '\n';
		return true;
	}
	while (line[i] == ' ')
		i++;
	if (line[i++] != '|')
		return false;
	while (line[i] == ' ')
		i++;
	value = std::atof(line.c_str() + i);
	if (!ft_checkifnum2(i, line))
		return true;
	Date	closedate = ft_closestdate(date, data);
	ft_getresult(date, value, data.at(closedate));
	return true;
}

bool	ft_readfile(BitcoinExchange& exchanger, std::ifstream& fd)
{
	std::map<Date, float>	datamap;
	std::string	line;

	if (!getline(fd, line)) //skip first line (header)
		return false;
	while (true)
	{
		if (!getline(fd, line))
			break;
		if (!ft_parseline(datamap, line))
			return false;
	}
	exchanger.loadData(datamap);
	return true;
}

bool	ft_fillinput(BitcoinExchange& exchanger, std::ifstream& fd)
{
	std::string	line;

	if (!getline(fd, line)) //skip first line (header)
		return false;
	while (true)
	{
		if (!getline(fd, line))
			break;
		if (!ft_parseinputline(exchanger.getData(), line))
			return false;
	}
	return true;
}

int main(int narg, char **argv)
{

	BitcoinExchange	exchanger;

	if (narg < 2)
	{
		std::cerr << "You must put a file as an input." << std::endl;
		return 1;
	}
	std::ifstream	fd("data.csv");
	if (fd.good() == 0)
	{
		std::cerr << "Error opening \"" << "data.csv" << "\" file." << std::endl;
		return (1);
	}
	if (!ft_readfile(exchanger, fd))
	{
		fd.close();
		std::cerr << "The input file is not in the correct format (date, value)" << std::endl;
		return (1);
	}
	fd.close();
	std::ifstream	fd2(argv[1]);
	if (fd2.good() == 0)
	{
		std::cerr << "Error opening \"" << argv[1] << "\" file." << std::endl;
		return (1);
	}
	if (!ft_fillinput(exchanger, fd2))
	{
		fd.close();
		std::cerr << "The input file is not in the correct format (date | value)" << std::endl;
		return (1);
	}
	fd2.close();
	return 0;
}
