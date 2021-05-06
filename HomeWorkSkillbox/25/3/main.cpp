#include <iostream>
#include <map>
#include <string>


bool comparison (std::map<char, int>& map_one, std::map<char, int>& map_two){
    std::string first, second;
    std::cout << "Enter first word\n";
    std::cin >> first;
    std::cout << "Enter second word\n";
    std::cin >> second;

    if (first.length() != second.length()) return false;

    for (int i = 0; i < second.length(); ++i){
        map_one.insert(std::make_pair(first[i], i));
        map_two.insert(std::make_pair(second[i],i));
    }

    for (auto it_one = map_one.begin(), it_two = map_two.begin(); it_one != map_one.end(); ++it_one, ++it_two){
       // if (it_one->first != it_two->first) return false;
       std::cout << it_one->first << " " << it_two-> first << std::endl;
    }

    return true;
}

int main() {
    std::map <char, int> map_one;
    std::map <char, int> map_two;
    std::cout << comparison(map_one, map_two);

    return 0;
}
