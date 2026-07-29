#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iostream>

bool	ft_isnum(char *arg)
{
	bool	flag = false;

	while (*arg && std::isspace(*arg))
		arg++;
	while (*arg)
	{
		if (std::isdigit(*arg))
		{
			flag = true;
			arg++;
		}
		else if (std::isspace(*arg))
			break ;
		else
			return false;
	}
	while (*arg && std::isspace(*arg))
		arg++;
	if (*arg || !flag)
		return false;
	return true;
}

bool	ft_parsenum(PmergeMe& pmm, int n, char **argv)
{
	long	num;
	char	*end;
	long long	time;

	time = get_time_us();
	for (int i = 1; i < n; i++)
	{
		if (!ft_isnum(argv[i]))
		{
			std::cerr << "Error: argument \"" << argv[i] << "\" is not a positive integer." << std::endl;
			return false;
		}
		errno = 0;
		num = std::strtol(argv[i], &end, 10);
		if (errno == ERANGE || num > INT_MAX)
		{
			std::cerr << "Error: argument \"" << argv[i] << "\" is outside the range of int." << std::endl;
			return false;
		}
		pmm.append1(static_cast<int>(num));
	}
	pmm.totaltime1 += get_time_us() - time;
	time = get_time_us();
	for (int i = 1; i < n; i++)
	{
		if (!ft_isnum(argv[i]))
		{
			std::cerr << "Error: argument \"" << argv[i] << "\" is not a positive integer." << std::endl;
			return false;
		}
		errno = 0;
		num = std::strtol(argv[i], &end, 10);
		if (errno == ERANGE || num > INT_MAX)
		{
			std::cerr << "Error: argument \"" << argv[i] << "\" is outside the range of int." << std::endl;
			return false;
		}
		pmm.append2(static_cast<int>(num));
	}
	pmm.totaltime2 += get_time_us() - time;
	return true;
}

int	main(int narg, char **argv)
{
	PmergeMe	pmm;
	if (narg <= 1)
	{
		std::cerr << "You must at least input 1 number." << std::endl;
		return 1;
	}
	else
	{
		if (!ft_parsenum(pmm, narg, argv))
			return 1;
	}
	std::cout << "Before:\t";
	pmm.display();
	std::cout << std::endl;
	pmm.sort(false);
	std::cout << "After:\t";
	pmm.display();
	std::cout << std::endl;
	std::cout << "Time to process a range of " << pmm.getSize() <<
		" elements with std::vector :\t" << pmm.totaltime1 << " us" << std::endl;
	std::cout << "Time to process a range of " << pmm.getSize() <<
		" elements with std::deque  :\t" << pmm.totaltime2 << " us" << std::endl;
	return 0;
}
