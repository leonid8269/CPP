#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>
#include <map>


int main() {

  std::vector<int> vec {1,2,3,4,5};

  for (uint8_t i = 0; i < vec.size(); ++i){
      std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  vec.erase(vec.cbegin() + 2);

    for (uint8_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }

    return 0;
}
