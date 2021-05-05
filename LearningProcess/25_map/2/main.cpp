
//!Дерево поиска
//! Вставка и просмотр элементов std::map


#include <iostream>
#include <map>


int main() {
    std::pair<std::string, int> oPair ("Hello", 5);
    std::map<std::string , int> ourMap;

    ourMap.insert(oPair);

    std::cout << ourMap["Hello"] << std::endl;

    //!далее чтобы работать с элементами пары есть методы ferst and second
    std::cout <<  oPair.first << " " << oPair.second << std::endl;

    //! вставка элементов в мар

    ourMap.insert(std::pair<std::string, int>("world", 6));
    ourMap.insert(std::make_pair<std::string, int>("tank", 7));

    ourMap.insert(std::pair<std::string, int>("Hello", 20));

    std::cout << ourMap["Hello"] << std::endl; //! выдаст 5 - потому что метод insert
                                                //! не заменяет уже имеющееся  значение.



   //!поиск в std::map

   std::map<std::string, int>::iterator nameIter = ourMap.find("tank");

   std::cout << nameIter -> first << " " << nameIter->second << std::endl;






    return 0;
}
