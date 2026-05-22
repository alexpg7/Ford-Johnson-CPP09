#include "BitcoinExchange.hpp"
#include <fstream>

bool	ft_checkifdate(int &i, std::string line)
{
	std::cout << line[i] << std::endl;
	for (int n = 0; n < 4; n++)
	{
		if (std::isdigit(line[i++]))
			continue ;
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	std::cout << line[i] << std::endl;
	if (line[i++] != '-')
	{
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	std::cout << line[i] << std::endl;
	for (int n = 0; n < 2; n++)
	{
		if (std::isdigit(line[i++]))
			continue ;
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	std::cout << line[i] << std::endl;
	if (line[i++] != '-')
	{
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	std::cout << line[i] << std::endl;
	for (int n = 0; n < 2; n++)
	{
		if (std::isdigit(line[i++]))
			continue ;
		std::cerr << "Incorrect date format (must be YYYY-MM-DD)" << std::endl;
		return false;
	}
	std::cout << line[i] << std::endl;
	//input date into exchanger and check if date is valid
	return true;
}

bool	ft_checkifnum(int& i, std::string line)
{
	int	j = i;//to parse the number

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
	//input number into exchange
	return true;
}

bool	ft_parseline(std::string line)
{
	int	i = 0;

	if (!ft_checkifdate(i, line))
		return false;
	//input date in exchanger
	while (line[i] == ' ')
		i++;
	if (line[i++] != '|')
		return false;
	while (line[i] == ' ')
		i++;
	if (!ft_checkifnum(i, line))
		return false;
	//input value in exchanger
	return true;
}

bool	ft_readfile(BitcoinExchange& exchanger, std::ifstream& fd)
{
	std::map<Date, float>	inputmap;
	std::string	line;

	if (!getline(fd, line)) //skip first line (header)
		return false;
	while (true)
	{
		if (!getline(fd, line))
			break;
		if (!ft_parseline(line))
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
	std::ifstream	fd(argv[1]);
	if (fd.good() == 0)
	{
		std::cerr << "Error opening \"" << argv[1] << "\" file." << std::endl;
		return (1);
	}
	if (!ft_readfile(exchanger, fd))
	{
		fd.close();
		std::cerr << "The input file is not in the correct format (date | value)" << std::endl;
		return (1);
	}
	fd.close();
	return 0;
}
