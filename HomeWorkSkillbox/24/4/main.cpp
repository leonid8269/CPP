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







Сделать так чтобы массив каждый раз не сохранялся а только положение бойцов, и каждый раз их идентифицировать...короче подумать надо


#include <iostream>
#include <ctime> //     srand(time(nullptr)); чтобы рандом был разный с каждым разом)
#include <string>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

struct character{

    string name;
    int health{};
    int armor{};
    int damage{};

    int location{}; // расположение в массиве чаров
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
    while (player.health < 1) cin >> player.health;

    cout << "How much is the armor intact?: \n";
    while (player.armor < 0) cin >> player.armor;

    cout << "How much damage can you do?: \n";
    while (player.damage < 1) cin >> player.damage;

    cout << "\n\nGood soldier! Good hunting!!\n\n";

    srand(time(nullptr));
    for (int i = 0; i < 5; ++i){
        NPC[i].name = "Enemy#" +  std::to_string( i + 1);
        NPC[i].health = rand() % 150 + 50;
        NPC[i].armor  = rand() % 50;
        NPC[i].damage = rand() % 30 + 15;
    }

    location_initialization(player, NPC);


    for (int i = 0; i < 40*40; ++i ) { // инициализация поля // З

        map[i] = '.';
        if (i == player.location) map[i] = 'P';
        for(int j = 0; j < 5; ++j){
            if (i == NPC[j].location) map[i] = '0' + j;
        }
    }
}
void save_game(char *map, character& player, character *NPC){
    std::ofstream save ("..\\save.bin", std::ios::binary);
    save << map << endl; //первая строчка карта
    save << player.name << " " << player.health << " " << player.armor << " " << player.damage << " "
            << player.location << endl; // вторая строчка инфа игрока

    for(int i = 0; i < 5; ++i) save << NPC[i].name << " " << NPC[i].health << " " << NPC[i].armor << " "
                                    << NPC[i].damage << " " << NPC[i].location << endl; // 3-7 строчки инфа по врагам.
    save.close();
}

void load_game(char *map, character& player, character *NPC){
    std::ifstream load ("..\\save.bin", std::ios::binary);
    if(!load.is_open()){
        cout << "Not found a save-game!! Start a New-Game? (y\\n)\n";
        char answer;
        cin >> answer;
        if(answer == 'y') new_game(map, player, NPC);
        else {
            cout << "Goodbye!!";
            exit(1);                                                                    //! точка выхода 1;
        }
    }else {
      load >> map;
      load >> player.name >> player.health >> player.armor >> player.damage >> player.location;
      for (int i = 0;i < 5 ;++i) load >> NPC[i].name >> NPC[i].health >> NPC[i].armor >> NPC[i].damage
                                        >> NPC[i].location;
    }
    load.close();
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

bool game_over(character& player, character *NPC){

    for (int i = 0; i < 5; ++i){
        if (NPC[i].health < 1) {
            NPC[i].name = "DEAD";
            NPC[i].location = -1;
        }
    }

    if (player.health <= 0) return true;
    for(int i = 0 ; i < 5; ++i) if (NPC[i].health > 1) return false;

    return true;
}


void process_game (char *map, character& player, character *NPC){

    while (game_over(player, NPC)){

    }
}

int main() {
    char map[40*40];
    character player;
    character NPC[5];

    start_game(map, player, NPC);



    for (int i = 0; i < (40*40); ++i ){
        if (i % 40 == 0 ) cout << endl;
        if (map[i] == '0' || map[i] == '1' || map[i] == '2' || map[i] == '3' || map[i] == '4') cout << 'E';
        else cout << map[i];
    }





    return 0;
}
