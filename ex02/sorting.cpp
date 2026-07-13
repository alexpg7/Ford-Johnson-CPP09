#include "PmergeMe.hpp"

void mergeInsertion(std::vector<Pair>& pairs)
{
	if (pairs.size() <= 1)
		return;

	std::vector<Pair> pairs;

	for (int i = 0; i + 1 < pairs.size(); i += 2)
	{
		Pair	p;

		if (pairs[i].largest > pairs[i + 1].largest)
		{
			p.a = list[i];
			p.b = list[i + 1];
		}
		else
		{
			p.a = list[i + 1];
			p.b = list[i];
		}

		pairs.push_back(p);
	}
	mergeInsertion(pairs);
}

void sort1(std::vector<int>& list)
{
	std::vector<Pair> pairs;

	for (size_t i = 0; i + 1 < list.size(); i += 2)
	{
		Group g1;
		g1.values.push_back(list[i]);
		g1.largest = list[i];

		Group g2;
		g2.values.push_back(list[i + 1]);
		g2.largest = list[i + 1];

		Pair p;

		if (g1.largest > g2.largest)
		{
			p.a = g1;
			p.b = g2;
		}
		else
		{
			p.a = g2;
			p.b = g1;
		}

		pairs.push_back(p);
	}

	mergeInsertion(pairs);
}

void	sort2(std::deque<int>& list)
{
	return ;
}
