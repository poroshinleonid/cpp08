#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span {
private:
  Span();
  Span &operator=(const Span &other);

public:
  Span(const Span &other);
  ~Span();

public:
  Span(unsigned int N);
  void addNumber(int n);
  int longestSpan();
  int shortestSpan();
  void printSpan();
  std::vector<int> &c();

public:
  template <typename IterType> void addNumbers(IterType begin, IterType end) {
    typename std::iterator_traits<IterType>::difference_type append_size =
        (std::distance(begin, end));
    if (append_size < 0) {
      throw std::logic_error("iterators in reversed order");
      return;
    }
    if (append_size + storage.size() > capacity) {
      throw std::overflow_error("Span capacity exceeded");
      return;
    }
    storage.insert(storage.end(), begin, end);
  }

private:
  std::vector<int> storage;
  unsigned int capacity;
};

#endif // SPAN_HPP
