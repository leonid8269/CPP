//! итерация по словарю и удаление элемента


#include <iostream>
#include <map>


int main() {
    std::map<int, std::string> oMap;
    oMap.insert(std::make_pair<int,std::string>(23,"fin"));
    oMap.insert(std::make_pair<int, std::string>(25, "fuck"));
    oMap.insert(std::make_pair<int, std::string>(15, "suck"));
    oMap.insert(std::make_pair<int, std::string>(12, "bitch"));
    oMap.insert(std::make_pair<int, std::string>(11, "ass"));
    oMap.insert(std::make_pair<int, std::string>(30, "hope"));
    oMap.insert(std::make_pair<int, std::string>(16, "hello"));
    oMap.insert(std::make_pair<int, std::string>(10, "end"));

    for (std::map<int,std::string>::iterator name_it = oMap.begin();
    name_it != oMap.end(); ++name_it)
        std::cout << name_it->first << " " << name_it-> second << std::endl;

    //! наводящие вопросы: как итератор пробегается по дереву чтобы вывести все в порядке возрастания?

    // узнаем как вычислить минимУМ В НАШЕЙ МАПЕ

    std::cout << oMap.begin()->first << " MIN \n";

    std::map<int,std::string>::iterator it = oMap.find(16);
    oMap.erase(it);

    std::cout << std::endl<<std::endl << std::endl;

    for (std::map<int,std::string>::iterator name_it = oMap.begin();
         name_it != oMap.end(); ++name_it)
        std::cout << name_it->first << " " << name_it-> second << std::endl;


    //! более простой способ удаления элемента из мапы:
    oMap.erase(30);

    std::cout << std::endl<<std::endl << std::endl;

    for (std::map<int,std::string>::iterator name_it = oMap.begin();
         name_it != oMap.end(); ++name_it)
        std::cout << name_it->first << " " << name_it-> second << std::endl;


    return 0;
}
