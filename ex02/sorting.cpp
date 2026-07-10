#include "PmergeMe.hpp"

void	mergeInsertion(std::vector<Group>	list)
{
	return;
}

void sort1(std::vector<int>& list)
{
	std::vector<Group> groups;

	for (size_t i = 0; i < list.size(); i++)
	{
		Group g;

		g.values.push_back(list[i]);
		g.largest = list[i];
		groups.push_back(g);
	}

	mergeInsertion(groups);
}

void	sort2(std::deque<int>& list)
{
	return ;
}
