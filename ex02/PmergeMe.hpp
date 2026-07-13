#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <climits>
#include <sys/time.h>
#include <iostream>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	list1;
		std::deque<int>		list2;
		int					_size = 0;
	public:
		long long	time1;
		long long	time2;
		long long	totaltime1 = 0;
		long long	totaltime2 = 0;
		PmergeMe();
		PmergeMe(PmergeMe &copy);
		~PmergeMe();
		PmergeMe	operator=(PmergeMe &copy);
		void	append1(int num);
		void	append2(int num);
		void	display();
		void	sort();
		int		getSize();
};

long long	get_time_us();

typedef struct	Group
{
	int					largest;
	std::vector<int>	values;
};

typedef struct	Pair
{
	Group	a;
	Group	b;
};

// sorting algo
void	sort1(std::vector<int>& list);
void	sort2(std::deque<int>& list);
