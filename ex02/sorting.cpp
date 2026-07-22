#include "PmergeMe.hpp"

std::vector<Group>	ft_bubblesort(std::vector<Group>& newgroups)
{
	std::vector<Group>	groups;

	for (int i = 0; i < newgroups.size(); i++)
	{
		groups.push_back(newgroups[i].list[0]);
		groups.push_back(newgroups[i].list[1]);
	}
	for (int i = 0; i < groups.size() - 1; i++)
	{
		for (int j = i + 1; j < groups.size(); j++)
		{
			if (groups[i].large > groups[j].large)
			{
				Group	aux = groups[i];
				groups[i] = groups[j];
				groups[j] = aux;
			}
		}
	}
	return groups;
}

std::vector<Group>	ft_insertion(std::vector<Group>& newgroups, Group odd, bool oddflag)
{
	std::vector<Group>	mainchain;

	int	index;
	mainchain.push_back(newgroups[0].list[0]);
	mainchain.push_back(newgroups[0].list[1]);
	for (int i = 1; i < newgroups.size(); i++)
	{
		index = 0;
		for (int j = 0; j < mainchain.size(); j++)
		{
			if (newgroups[i].list[1].large > mainchain[j].large)
				index = j;
			else
				break ;
		}
		//insert [1] in index position in mainchain
		mainchain.push_back(newgroups[i].list[0]);
	}
	if (oddflag)
	{
		for (int j = 0; j < mainchain.size(); j++)
		{
			if (odd.large > mainchain[j].large)
				index = j;
			else
				break ;
		}
		//insert odd in index position in mainchain
	}
	return mainchain;
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
	Group	odd;
	bool	oddflag;
	if (groups.size() % 2 != 0)
	{
		odd = groups[groups.size() - 1];
		oddflag = true;
	}
	else
		oddflag = false;
	mergeInsertion(newgroups);
	//here, do binary insertion sort
	groups = ft_bubblesort(newgroups);
	//groups = ft_insertion(newgroups, odd, oddflag);
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
	for (int i = 0; i < list.size(); i++)
		list[i] = groups[i].large;
}

void	sort2(std::deque<int>& list)
{
	return ;
}
