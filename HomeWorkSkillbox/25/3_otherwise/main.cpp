#include <iostream>
#include <map>


void comparation (const std::string& first,const std::string& second){
    std::map<char, int> first_map;
    std::map<char, int> second_map;
    for (int i = 0; i < first.length(); ++i){
        auto char_seek = first_map.find(first[i]);
        if(char_seek->first == first[i]) char_seek->second ++;
        else first_map.insert(std::make_pair(first[i], 1));

        char_seek = second_map.find(second[i]);
        if(char_seek->first == second[i]) char_seek -> second++;
        else second_map.insert(std::make_pair(second[i], 1));
    }
    if (first_map == second_map) std::cout << "YES\n";
    else std::cout << "NO!\n";

}


int main() {
    std::cout << "Enter two words for comparison!\n";
    std::string first_word, second_word;
    std::cin >> first_word >> second_word;

    if (first_word.length() != first_word.length()) return 1;

    comparation(first_word, second_word);
    return 0;
}
