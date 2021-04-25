#include <iostream>
#include <cstring>
#include <string>
#include <fstream>




int main() {

   //! character people[10] = {{"Alexey", 50, 30},}; // можно так инициализировать массив


   character people[10];
   /*
   for (int i = 0; i < 10 ; ++i){
       people[i].name = "Character #" + std::to_string(i);
       people[i].health = (std::rand() % 100) + 100;
       people[i].armor = (std::rand() % 40) + 10;
   }*/

   /*
   for (int i = 0; i < 10; i++){
       take_damage(people[i], 30);
   }*/

   std::ifstream file ("..\\save.bin", std::ios::binary);
   for (int i = 0; i < 10; ++i)
       load_character(file, people[i]);

   for (int i = 0; i < 10; ++i) {
       std::cout << people[i].name << std::endl;
   }

   file.close();


    return 0;
}
