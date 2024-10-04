#include "easyfind.hpp"
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T> void print_container(T container) {
  for (auto it = container.begin(); it != container.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void test_vector() {
  std::vector<int> vec = {10, 20, 30, 40, 50};
  std::cout << "Vector" << std::endl;
  print_container(vec);

  std::cout << "Test 1: Searching for 30 in a std::vector<int>...\n";
  std::vector<int>::iterator it = easyfind(vec, 30);
  if (it != vec.end()) {
    std::cout << "Success: Found element 30 in vector.\n";
  } else {
    std::cout << "Failure: Element 30 not found in vector.\n";
  }

  std::cout << "Test 2: Searching for 100 in a std::vector<int>...\n";
  it = easyfind(vec, 100);
  if (it != vec.end()) {
    std::cout << "Failure: Unexpectedly found element 100 in vector.\n";
  } else {
    std::cout << "Success: Element 100 not found in vector, as expected.\n";
  }
  std::cout << std::endl;
}

void test_array() {
  std::array<int, 5> arr = {5, 10, 15, 20, 25};
  std::cout << "Array" << std::endl;
  print_container(arr);

  std::cout << "Test 3: Searching for 15 in a std::array<int, 5>...\n";
  auto it = easyfind(arr, 15);
  if (it != arr.end()) {
    std::cout << "Success: Found element 15 in array.\n";
  } else {
    std::cout << "Failure: Element 15 not found in array.\n";
  }

  std::cout << "Test 4: Searching for 50 in a std::array<int, 5>...\n";
  it = easyfind(arr, 50);
  if (it != arr.end()) {
    std::cout << "Failure: Unexpectedly found element 50 in array.\n";
  } else {
    std::cout << "Success: Element 50 not found in array, as expected.\n";
  }
  std::cout << std::endl;
}

void test_list() {
  std::list<int> lst = {100, 200, 300, 400, 500};
  std::cout << "List:" << std::endl;
  print_container(lst);

  std::cout << "Test 5: Searching for 300 in a std::list<int>...\n";
  auto it = easyfind(lst, 300);
  if (it != lst.end()) {
    std::cout << "Success: Found element 300 in list.\n";
  } else {
    std::cout << "Failure: Element 300 not found in list.\n";
  }

  std::cout << "Test 6: Searching for 600 in a std::list<int>...\n";
  it = easyfind(lst, 600);
  if (it != lst.end()) {
    std::cout << "Failure: Unexpectedly found element 600 in list.\n";
  } else {
    std::cout << "Success: Element 600 not found in list, as expected.\n";
  }
  std::cout << std::endl;
}

void test_deque() {
  std::deque<int> deq = {1, 2, 3, 4, 5};
  std::cout << "deque:" << std::endl;
  print_container(deq);

  std::cout << "Test 7: Searching for 4 in a std::deque<int>...\n";
  auto it = easyfind(deq, 4);
  if (it != deq.end()) {
    std::cout << "Success: Found element 4 in deque.\n";
  } else {
    std::cout << "Failure: Element 4 not found in deque.\n";
  }

  std::cout << "Test 8: Searching for 10 in a std::deque<int>...\n";
  it = easyfind(deq, 10);
  if (it != deq.end()) {
    std::cout << "Failure: Unexpectedly found element 10 in deque.\n";
  } else {
    std::cout << "Success: Element 10 not found in deque, as expected.\n";
  }
  std::cout << std::endl;
}

int main() {
  test_vector();
  test_array();
  test_list();
  test_deque();
  return 0;
}