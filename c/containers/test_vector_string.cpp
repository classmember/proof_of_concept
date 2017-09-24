#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
/**
 * to compile:
 * g++ -g test_vector_string.cpp -o test_vector_string
 *
 */

/**
 * @function - toString
 * @param - vector
 */
void toString(const std::vector<std::string> &cont) {
  unsigned int iter = 0;
  for(std::string n : cont) {
    std::cout << "test_vector[" << iter << "] = " << n << '\n';
    iter++;
  }
}

int main() {

  // Make a vector and add values
  std::vector<std::string> test_vector = {"This is a test",
                                  "This is only a test",
                                  "Remain calm", 
                                  "Help is on the way"};
  test_vector.push_back("nah");
  test_vector.push_back("mean?");

  // Print size of vector and all it's values
  std::cout << "test_vector.size() = " << test_vector.size() << '\n';
  std::cout << "test_vector.front() = " << test_vector.front() << '\n';
  std::cout << "test_vector.back() = " << test_vector.back() << '\n';
  std::cout << "test_vector.empty() = " << test_vector.empty() << '\n';
  toString(test_vector);
}
