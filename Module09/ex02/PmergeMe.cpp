#include "PmergeMe.hpp"
#include<unistd.h>

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vec = rhs._vec;
		_deq = rhs._deq;
	}
	return *this;
};

int	ft_atoi(const char *str, int *index)
{
	int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = *index;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (-1);
	}
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	*index = i;
	return (result * sign);
}

template<typename Container>
bool	PmergeMe::fillChain(Container &chain,char **argv, int argc)
{
	int	nbr;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			nbr = ft_atoi(argv[i], &j);
			if (nbr > INT_MAX || nbr < 0)
				return false;
			chain.push_back(nbr);
		}
		i++;
	}
	return true;
}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	if(!fillChain(_vec, argv, argc))
		throw MergeException();
	if (!fillChain(_deq, argv, argc))
		throw MergeException();
}

std::vector<int> PmergeMe::getVec()
{
	return _vec;
}


std::deque<int> PmergeMe::getDeq()
{
	return _deq;
}

template<typename Container>
void 	PmergeMe::printChain(Container &a)
{
	for(size_t i=0;i < a.size();i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void jacobsthal(std::vector<int> &arr, int size)
{
	int a = 1, b = 1;
	int c = 1;

	while (c < size)
	{
		arr.push_back(c);
		a = b;
		b = c;
		c = b + 2*a;
	}
}

template<typename Container>
Container PmergeMe::fordJohnsonSort(Container &chain)
{
	Container main;
	Container pend;

	for (size_t i=0; i < chain.size(); i++)
	{
		if(i % 2 == 0 && i + 1 < chain.size())
		{
			if(chain[i] > chain[i + 1])
			{
				int temp = chain[i];
				chain[i] = chain[i+1];
				chain[i+1] = temp;
			}
		}	
		else if(i % 2 == 0)
			pend.push_back(chain[i]);
		else
		{
			main.push_back(chain[i]);
			pend.push_back(chain[i-1]);
		}
	}
	if (main.size() >= 2)
		main = fordJohnsonSort(main);
	if (pend.empty())
		return main;
	typename Container::iterator it;
	std::vector<int> idx;
	jacobsthal(idx, pend.size());
	int i = 0;
	int elem;
	while (!pend.empty())
	{
		if (!idx.empty())
		{
			elem = *idx.begin() - i;
			i++;
			idx.erase(idx.begin());
		}
		else
			elem = 0;
		it = std::lower_bound(main.begin(), main.end(), pend[elem]);
		main.insert(it, pend[elem]);
		pend.erase(pend.begin() + elem);
	}
	return main;
}

void PmergeMe::execute()
{
	std::cout << "Before: ";
	printChain(_vec);
	std::clock_t t1(std::clock());
	_vec = fordJohnsonSort(_vec);
	t1 = std::clock() - t1;
	std::clock_t t2(std::clock());
	_deq = fordJohnsonSort(_deq);
	t2 = std::clock() - t2;

	std::cout << "After: ";
	printChain(_vec);
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << ((double)t1 / CLOCKS_PER_SEC * 1000000.0) << " us" << std::endl;

	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque   : "
		<< std::fixed << std::setprecision(5) << ((double)t2 / CLOCKS_PER_SEC * 1000000.0) << " us" << std::endl;

}
