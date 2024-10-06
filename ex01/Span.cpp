#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

Span::Span() {}

Span::Span(const Span &other)
    : storage(other.storage), capacity(other.capacity) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    storage = other.storage;
    capacity = other.capacity;
  }
  return *this;
}

Span::~Span() {}

Span::Span(unsigned int N) : capacity(N) {}

void Span::addNumber(int n) {
  if (storage.size() >= capacity) {
    throw std::overflow_error("Span capacity exceeded");
  }
  storage.push_back(n);
}

int Span::longestSpan() {
  if (storage.size() < 2) {
    throw std::logic_error("Not enough numbers to find a span.");
  }
  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> extremes =
      std::minmax_element(storage.begin(), storage.end());
  return *extremes.second - *extremes.first;
}

int Span::shortestSpan() {
  if (storage.size() < 2) {
    throw std::logic_error("Not enough numbers to find a span.");
  }

  std::vector<int> sorted_storage = storage;
  std::sort(sorted_storage.begin(), sorted_storage.end());

  std::vector<int> diffs(storage);
  std::adjacent_difference(sorted_storage.begin(), sorted_storage.end(),
                           diffs.begin());
  return *(std::min_element(diffs.begin() + 1, diffs.end()));
}

void Span::printSpan() {
  for (std::vector<int>::iterator it = storage.begin(); it != storage.end(); it++) {
    std::cout << *it << " ";
  }
}

std::vector<int> &Span::c() {
  return storage;
}
