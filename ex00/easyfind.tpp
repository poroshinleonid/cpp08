#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <iterator>

template <typename T> typename T::iterator easyfind(T &container, int n) {
  return (std::find(container.begin(), container.end(), n));
}

#endif // EASYFIND_TPP
