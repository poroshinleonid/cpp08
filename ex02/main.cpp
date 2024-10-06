#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

void mstack() {
  MutantStack<int> ms;
  ms.push(5);
  ms.push(17);
  std::cout << "### MutantStack: (5, 17) top and pop" << std::endl;

  std::cout << "top(): " << ms.top() << std::endl;
  ms.pop();
  std::cout << "size after pop should be 1: " << ms.size() << std::endl;
  ms.pop();
  std::cout << "should be empty: " << ms.empty() << std::endl;
  ms.push(5);
  ms.push(3);
  ms.push(5);
  ms.push(737);
  ms.push(0);

  std::cout << "Looping through iterators - should print 5 3 5 737 0:"
            << std::endl;
  MutantStack<int>::iterator it = ms.begin();
  MutantStack<int>::iterator ite = ms.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;

  std::cout << "Reverse iterating through the stack:" << std::endl;
  MutantStack<int>::reverse_iterator rit = ms.rbegin();
  MutantStack<int>::reverse_iterator rite = ms.rend();
  ++rit;
  --rit;
  while (rit != rite) {
    std::cout << *rit << " ";
    ++rit;
  }
  std::cout << std::endl;

  std::stack<int> s(ms);
  std::cout << "Copy stack (std::stack):" << std::endl;
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;
}

void list() {
  std::list<int> ms;
  ms.push_back(5);
  ms.push_back(17);
  std::cout << "### std::list: (5, 17) pop" << std::endl;
  ms.pop_back();
  std::cout << "size after pop should be 1: " << ms.size() << std::endl;
  ms.pop_back();
  std::cout << "should be empty: " << ms.empty() << std::endl;
  ms.push_back(5);
  ms.push_back(3);
  ms.push_back(5);
  ms.push_back(737);
  ms.push_back(0);

  std::cout << "Looping through iterators - should print 5 3 5 737 0:"
            << std::endl;
  std::list<int>::iterator it = ms.begin();
  std::list<int>::iterator ite = ms.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;

  std::cout << "Reverse iterating through the std::list:" << std::endl;
  std::list<int>::reverse_iterator rit = ms.rbegin();
  std::list<int>::reverse_iterator rite = ms.rend();
  ++rit;
  --rit;
  while (rit != rite) {
    std::cout << *rit << " ";
    ++rit;
  }
  std::cout << std::endl;
}

int main() {
  mstack();
  std::cout << std::endl;
  list();
  std::cout << std::endl;
  MutantStack<int> ms;

  std::cout << "check iterators on empty stack " << std::endl;
  MutantStack<int>::iterator it = ms.begin();
  MutantStack<int>::iterator ite = ms.end();
  ++it;--it;
  ++ite;--ite;
  if (it == ite) {
    std::cout << "EQUAL" << std::endl;
  }
  return 0;
}
