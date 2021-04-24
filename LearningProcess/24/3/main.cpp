#include <iostream>
#include <cstring>
#include <string>

struct character {

    std::string name = "unknow";
    int health = 100;
    int armor = 0;

};

void take_damage (character& person, int damage){  // если передавать значения по адресу то нужно обращатся к полям через -> а если чреез ссылку то через точку
    std::cout << person.name << " took damage: -" << damage << std::endl;
    person.armor -= damage;
    if(person.armor < 0){
        person. health += person.armor;
        person.armor = 0;
    }

}


int main() {

   //! character people[10] = {{"Alexey", 50, 30},}; // можно так инициализировать массив
    
   character people[10];
   for (int i = 0; i < 10 ; ++i){
       people[i].name = "Character #" + std::to_string(i);
       people[i].health = (std::rand() % 100) + 100;
       people[i].armor = (std::rand() % 40) + 10;
   }

   for (int i = 0; i < 10; i++){
       take_damage(people[i], 30);
   }

    return 0;
}
