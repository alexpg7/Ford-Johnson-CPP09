#include "PmergeMe.hpp"

long long	get_time_us()
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return static_cast<long long>(tv.tv_sec) * 1000000LL + tv.tv_usec;
}

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe	PmergeMe::operator=(PmergeMe &copy)
{
	if (this == &copy)
		return *this;
	list1 = copy.list1;
	list2 = copy.list2;
	return *this;
}

void	PmergeMe::append1(int num)
{
	list1.push_back(num);
}

void	PmergeMe::append2(int num)
{
	list2.push_back(num);
}

void	PmergeMe::display()
{
	int max = list1.size() > 5 ? 5 : list1.size();
	for (int i = 0; i < max; i++)
	{
		if (i == 4 && list1.size() > 5)
			std::cout << " [...]";
		else
			std::cout << " " << list1[i];
	}
}

void	PmergeMe::sort()
{
	_size = list1.size();
	time1 = get_time_us();
	sort1(list1);
	totaltime1 += get_time_us() - time1;

	time2 = get_time_us();
	sort2(list2);
	totaltime2 += get_time_us() - time2;
	return;
}

int	PmergeMe::getSize()
{
	return _size;
}
