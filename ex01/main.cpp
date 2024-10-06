#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int genrandnum() {
    return rand() % 20000;
}

int main() {
  std::cout << "=== Span Tests ===" << std::endl;

  Span sp1(5);
  std::cout << "Testing span {5, 3, 17, 8, 11}" << std::endl;
  sp1.addNumber(5);
  sp1.addNumber(3);
  sp1.addNumber(17);
  sp1.addNumber(9);
  sp1.addNumber(11);

  std::cout << "Shortest Span (should be 2): " << sp1.shortestSpan()
            << std::endl;
  std::cout << "Longest Span (should be 14): " << sp1.longestSpan()
            << std::endl;

  std::cout << "Testing exception when adding more than capacity..."
            << std::endl;
  try {
    sp1.addNumber(42);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "run functions on an empty object..." << std::endl;
  Span sp2(2);
  try {
    std::cout << sp2.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    std::cout << sp2.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << "run functions on an object with only one item..." << std::endl;
  sp2.addNumber(1);
  try {
    std::cout << sp2.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    std::cout << sp2.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "Add items using Range of iterators..." << std::endl;
  Span sp3(10);
  std::vector<int> numbers = {1, 2, 3, 4, 500, 600};
  sp3.addNumbers(numbers.begin(), numbers.end());
  std::cout << "vector: " << std::endl;
  for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "stack: " << std::endl;
  sp3.printSpan();
  std::cout << std::endl;
  std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;

  std::cout << "Testing exception when range addition exceeds capacity..."
            << std::endl;
  try {
    sp3.addNumbers(numbers.begin(), numbers.end());
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "Testing with 20 000 numbers..." << std::endl;
  Span sp4(20000);
  std::vector<int> v2(20000);
  srand(time(0));
  std::generate(v2.begin(), v2.end(), rand);
  sp4.addNumbers(v2.begin(), v2.end());
  std::cout << "std::max_element for span: " << *std::max_element(sp4.c().begin(), sp4.c().end()) << " and for vector: " << *std::max_element(v2.begin(), v2.end()) << std::endl;
  std::cout << "std::min_element for span: " << *std::min_element(sp4.c().begin(), sp4.c().end()) << " and for vector: " << *std::min_element(v2.begin(), v2.end()) << std::endl;
  std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;

  return 0;
}

