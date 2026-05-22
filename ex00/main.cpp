#include "BitcoinExchange.hpp"
#include <fstream>

bool	ft_readfile(BitcoinExchange& exchanger, std::ifstream& fd)
{
	std::map<Date, float>	inputmap;


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
