#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
/**
 * compile:
 * g++ -g test_vector_string.cpp -o test_vector_string
 *
 * run:
 * ./test_vector_string > output.txt 2> error.txt
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

  //trip up try block
  std::vector<std::string> test_vector(4);
  try {
    std::cout << "test_vector.front() = " << test_vector.front() << '\n';
    std::cout << "test_vector.at(10) = " << test_vector.at(10) << '\n';
  } catch (const std::out_of_range& oor) {
      std::cerr << "[caught exception] std::out_of_range -- \n    '"
                << oor.what() << "'\n";
  } catch (const std::exception& e) {
    std::cerr << "[caught exception] std::exception -- \n   '"
              << e.what() << "'\n";
  }
  test_vector.push_back("This is a test");
                        // "This is only a test",
                        // "Remain calm", 
                        // "Help is on the way";
  test_vector[0] = "a1";
  test_vector[1] = "b2";
  test_vector[2] = "c3";
  test_vector[3] = "d4";
  test_vector.push_back("nah");
  test_vector.push_back("mean?");

  // Print size of vector and all it's values
  std::cout << "test_vector.size() = " << test_vector.size() << '\n';
  std::cout << "test_vector.front() = " << test_vector.front() << '\n';
  std::cout << "test_vector.back() = " << test_vector.back() << '\n';
  std::cout << "test_vector.empty() = " << test_vector.empty() << '\n';
  toString(test_vector);
}
