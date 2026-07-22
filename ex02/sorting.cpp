#include "PmergeMe.hpp"

std::vector<Group>	ft_bubblesort(std::vector<Group>& newgroups)
{
	return newgroups;
}

void mergeInsertion(std::vector<Group>& groups)
{
	if (groups.size() <= 1)
		return;

	std::vector<Group> newgroups;

	for (size_t i = 0; i + 1 < groups.size(); i += 2)
	{
		Group	g;

		if (groups[i].large > groups[i + 1].large)
		{
			g.large = groups[i].large;
			g.list.push_back(groups[i]);
			g.list.push_back(groups[i + 1]);
		}
		else
		{
			g.large = groups[i + 1].large;
			g.list.push_back(groups[i + 1]);
			g.list.push_back(groups[i]);
		}

		newgroups.push_back(g);
	}
	// Handle an odd element here if groups.size() is odd.

	mergeInsertion(newgroups);
	groups = ft_bubblesort(newgroups);
}

void sort1(std::vector<int>& list)
{
	std::vector<Group> groups;

	for (size_t i = 0; i < list.size(); ++i)
	{
		Group	g;

		g.large = list[i];

		groups.push_back(g);
	}

	mergeInsertion(groups);

	// TODO: traverse the tree to perform the insertion phase.

	// TODO: delete every allocated Group.
}

void	sort2(std::deque<int>& list)
{
	return ;
}
