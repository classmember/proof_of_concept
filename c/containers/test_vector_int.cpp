#include <algorithm>
#include <iostream>
#include <vector>
/**
 * to compile:
 * g++ -g test_vector_int.cpp -o test_vector_int
 *
 */

/**
 * @function - toString
 * @param - vector
 */
void toString(const std::vector<int> &cont) {
  unsigned int iter = 0;
  for(int n : cont) {
    std::cout << "test_vector[" << iter << "] = " << n << '\n';
    iter++;
  }
}

int main() {

  // Make a vector and add values
  std::vector<int> test_vector = {7, 5, 16, 8};
  test_vector.push_back(25);
  test_vector.push_back(13);

  // Print size of vector and all it's values
  std::cout << "test_vector.size() = " << test_vector.size() << '\n';
  std::cout << "test_vector.front() = " << test_vector.front() << '\n';
  std::cout << "test_vector.back() = " << test_vector.back() << '\n';
  std::cout << "test_vector.empty() = " << test_vector.empty() << '\n';
  toString(test_vector);
}
