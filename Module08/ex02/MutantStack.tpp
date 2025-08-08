#include "MutantStack.hpp"

MutantStack();
MutantStack(const MutantStack &copy);
MutantStack &operator=(const MutantStack &rhs);
~MutantStack();
T &top();
bool empty() const;
int size()const;
void push(const T &elem);
void pop();
begin();
rbegin();
end();
rend();

