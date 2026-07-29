#include "PmergeMe.hpp"

template <typename Container, typename T>
Container	ft_insertion(Container& newgroups, T& odd, bool oddflag)
{
	Container	mainchain;

	int	index;
	mainchain.push_back(newgroups[0].list[1]);
	mainchain.push_back(newgroups[0].list[0]);
	for (int i = 1; i < newgroups.size(); i++)
	{
		index = -1;
		for (int j = 0; j < mainchain.size(); j++)
		{
			if (newgroups[i].list[1].large > mainchain[j].large)
				index = j;
			else
				break ;
		}
		mainchain.insert(mainchain.begin() + index + 1, newgroups[i].list[1]);
		mainchain.push_back(newgroups[i].list[0]);
	}
	if (oddflag)
	{
		index = -1;
		for (int j = 0; j < mainchain.size(); j++)
		{
			if (odd.large > mainchain[j].large)
				index = j;
			else
				break ;
		}
		mainchain.insert(mainchain.begin() + index + 1, odd);
	}
	return mainchain;
}

template <typename Container, typename T>
void mergeInsertion(Container& groups)
{
	if (groups.size() <= 1)
		return;

	Container	newgroups;

	for (size_t i = 0; i + 1 < groups.size(); i += 2)
	{
		T	g;

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
	T	odd;
	bool	oddflag;
	if (groups.size() % 2 != 0)
	{
		odd = groups[groups.size() - 1];
		oddflag = true;
	}
	else
		oddflag = false;
	mergeInsertion<Container, T>(newgroups);
	groups = ft_insertion<Container, T>(newgroups, odd, oddflag);
}

void sortvector(std::vector<int>& list)
{
	std::vector<Group> groups;

	for (size_t i = 0; i < list.size(); ++i)
	{
		Group	g;

		g.large = list[i];
		groups.push_back(g);
	}

	mergeInsertion<std::vector<Group>, Group>(groups);
	for (int i = 0; i < list.size(); i++)
		list[i] = groups[i].large;
}

void	sortdeque(std::deque<int>& list)
{
	std::deque<Group2> groups;

	for (size_t i = 0; i < list.size(); ++i)
	{
		Group2	g;

		g.large = list[i];
		groups.push_back(g);
	}

	mergeInsertion<std::deque<Group2>, Group2>(groups);
	for (int i = 0; i < list.size(); i++)
		list[i] = groups[i].large;
}
