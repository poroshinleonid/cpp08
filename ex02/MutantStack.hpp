#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  using iterator = typename std::stack<T>::container_type::iterator;
  using const_iterator = typename std::stack<T>::container_type::const_iterator;
  using reverse_iterator =
      typename std::stack<T>::container_type::reverse_iterator;
  using const_reverse_iterator =
      typename std::stack<T>::container_type::const_reverse_iterator;

public:
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

public:
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
