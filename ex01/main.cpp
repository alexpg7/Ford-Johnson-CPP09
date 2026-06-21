#include "RPN.hpp"

bool	ft_checkinput(std::string line)
{
	int i = 0;
	std::string	tokens = " +-/*";

	while (line[i])
	{
		if (!std::isdigit(line[i]) && tokens.find(line[i]) == std::string::npos)
			return false;
		i++;
	}
	return true;
}

int	main(int narg, char **argv)
{
	if (narg != 2)
	{
		std::cerr << "You must write an expression as input." << std::endl;
		return (1);
	}
	std::string	input(argv[1]);
	if (!ft_checkinput(input))
	{
		std::cerr << "Error: incorrect token." << std::endl;
		return (1);
	}
	RPN rpn(argv[1]);
	std::cout << rpn.top() << std::endl;
	return (0);

}
