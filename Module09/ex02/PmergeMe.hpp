#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include<iostream>
# include<vector>
# include<deque>
# include<climits>
# include<ctime>
# include<iomanip>

class PmergeMe
{
	private :
		std::vector<int> _vec;
		std::deque<int> _deq;
		PmergeMe(){};
	public :
		PmergeMe(int argc, char *argv[]);
		~PmergeMe(){};
		PmergeMe(const PmergeMe &copy){*this = copy;};
		PmergeMe &operator=(const PmergeMe &rhs);
		std::deque<int> getDeq();
		std::vector<int> getVec();
		template<typename Container>
		bool	fillChain(Container &chain, char **argv, int argc);
		template<typename Container>
		Container fordJohnsonSort(Container &chain);
		void execute();
		template<typename Container>
		void 	printChain(Container &a);
		class MergeException : public std::exception{
			public :
				const char *what() const throw()
				{
					return ("Error");
				};
		};
};

int	checkArgs(char **argv);
#endif
