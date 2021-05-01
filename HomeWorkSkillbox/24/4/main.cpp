/*!
 *
 *
Игра происходит на карте размером 40 на 40 клеток. По клеткам перемещаются враги и персонаж игрока.
После каждого хода игрока карта показывается вновь со всеми врагами на ней.
Игрок помечается буквой P. Враги буквой E. Пустые места — точкой.
Каждый персонаж игры представлен в виде структуры с полями: имя, жизни, броня, урон.
Вначале игры создаются 5 случайных врагов в случайных клетках карты.
Врагам задаются в формате “Enemy #N”, где N — это порядковый номер врага.
Уровень жизней врагам задаётся случайно, от 50 до 150.
Уровень брони варьируется от 0 до 50. Урон тоже выбирается случайно от 15 до 30 единиц.
Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя.
Все персонажи появляются в случайных местах карты.
Игрок осуществляет ход с помощью команд: left, right, top, bottom.
В зависимости от команды и выбирается направление перемещения персонажа: влево, вправо, вверх, вниз.
Враги перемещаются в случайном направлении.
Если персонаж (враг или игрок) перемещается в сторону, где уже находится какой-то персонаж,
то он бьёт этого персонажа с помощью своего урона. Враги при этом никогда не бьют врагов,
а просто пропускают ход и остаются на своём месте.
За пределы карты (40 на 40 клеток) ходить нельзя никому.
Если кто-то выбрал направление за гранью дозволенного, ход пропускается.
Формула для расчёта урона совпадает с той, что была в самом уроке.
Жизни уменьшаются на оставшийся после брони урон.
При этом сама броня тоже сокращается на приведённый урон.
Игра заканчивается тогда, когда либо умирают все враги, либо персонаж игрока.
В первом случае на экран выводится сообщение о поражении, во втором — победа.
Если в начале хода игрок вводит команду save или load вместо направления перемещения,
то игра либо делает сохранение своего состояния в файл,
либо загружает это состояние из файла соответственно.

Советы и рекомендации
Для определения команды персонажа можно завести специальный флаг внутри структуры данных персонажа.

Для отображения координат персонажей можете использовать структуру вектора из другой задачи,
но заменить типы координат.
 *
 * */



#include <iostream>
#include <ctime> //     srand(time(nullptr)); чтобы рандом был разный с каждым разом)
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

struct character{

    string name;
    int health{};
    int armor{};
    int damage{};


    int location{};
};

void location_initialization(character& player, character *NPC){ // расставлю персонажей, с проверкой на совпадения и соприкосновения
    srand(time(nullptr));
    while (true){
        player.location = rand() % (40*40);
        for (int i = 0;i < 5 ;++i) {
            NPC[i].location = rand() % (40 * 40);
            if (NPC[i].location == player.location || NPC[i].location == player.location + 1 ||
                    NPC[i].location == player.location - 1 || NPC[i].location == player.location - 30 ||
                    NPC[i].location == player.location + 30) continue;
        }
        break;
    }
}

void new_game(char *map, character& player, character *NPC){

    cout  << "Enter the name your character: \n";
    cin >>  player.name;

    cout << "Okay " << player.name << ". How many health points do you have left? Enter number: \n";
    cin >> player.health;

    cout << "How much is the armor intact?: \n";
    cin >> player.armor;

    cout << "How much damage can you do?: \n";
    cin >> player.damage;



    cout << "\n\nGood soldier! Good hunting!!\n\n";



    srand(time(nullptr));
    for (int i = 0; i < 5; ++i){
        NPC[i].name = "Enemy#" +  std::to_string( i + 1);
        NPC[i].health = rand() % 150 + 50;
        NPC[i].armor  = rand() % 50;
        NPC[i].damage = rand() % 30 + 15;
    }

    location_initialization(player, NPC);


    for (int i = 0; i < 40*40; ++i ) { // инициализация поля
        map[i] = '.';
        if (i == player.location) map[i] = 'P';
        for(int j = 0; j < 5; ++j){
            if (i == NPC[j].location) map[i] = '0' + j;
        }
    }


/*!
   for (int i = 0; i < (40*40); ++i ){
       if (i % 40 == 0 ) cout << endl;
       cout << map[i];
   }
   */
}

void load_game(char *map, character& player, character *NPC){

}



void start_game(char *map, character& player, character *NPC){
    cout << "Hello! You want to begin a 'new' game or 'load'?\n";
    string answer;

    while (true) {
        cin >> answer;


        if (answer == "new"){
            new_game(map,player, NPC);
            break;
        }
        else if (answer == "load"){
            load_game(map,player, NPC);
            break;
        }
        else {
            cout << "Ups, command not found! Try Again\n";
            continue;
        }
    }
}

int main() {
    char map[40*40];
    character player;
    character NPC[5];

    start_game(map, player, NPC);

    for (int i = 0; i < (40*40); ++i ){
        if (i % 40 == 0 ) cout << endl;
        cout << map[i];
    }


    return 0;
}
