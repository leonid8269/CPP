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
#include <fstream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct character{

    string name;
    int health{};
    int armor{};
    int damage{};

    int location{}; // расположение в массиве чаров
};


void update_location (vector<char>& map, character& player, character *NPC ){ // применяется при каждом изменении позиции
    for (int i = 0 ; i < map.size(); ++i ){
        map[i] = '.';
        if (i == player.location) map[i] = 'P';
        for(int k = 0; k < 5; ++k)
            if (i == NPC[k].location) map[i] = '0' + k;
    }
}


void view_Map(vector<char>& map){
    for (int i = 0; i < map.size(); ++i ){
        if (i % (int)sqrt(map.size()) == 0 ) cout << endl;
        if (map[i] == '0' || map[i] == '1' || map[i] == '2' || map[i] == '3' || map[i] == '4') cout << 'E';
        else cout << map[i];
    }
    cout << endl;

}


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

void new_game(vector<char>& map, character& player, character *NPC){

    cout  << "Enter the name your character: \n";
    cin >>  player.name;

    cout << "Okay " << player.name << ". How many health points do you have left? Enter number: \n";
    do cin >> player.health;
    while (player.health < 1) ;

    cout << "How much is the armor intact?: \n";
    do cin >> player.armor;
    while (player.armor < 0);

    cout << "How much damage can you do?: \n";
    do cin >> player.damage;
    while (player.damage < 1);

    cout << "\n\nGood soldier! Good hunting!!\n\n";

    srand(time(nullptr));
    for (int i = 0; i < 5; ++i){
        NPC[i].name = "Enemy#" +  std::to_string( i + 1);
        NPC[i].health = rand() % 150 + 50;
        NPC[i].armor  = rand() % 50;
        NPC[i].damage = rand() % 30 + 15;
    }

    location_initialization(player, NPC); // проверяет чтобы не попасть в одно и тоже место...
    update_location(map, player, NPC);  // расставляет фигурки
}

void save_game( character& player, character *NPC){

    std::ofstream save ("..\\save.bin", std::ios::binary);
    save << player.name << " " << player.health << " " << player.armor << " " << player.damage << " "
            << player.location << endl; // вторая строчка инфа игрока

    for(int i = 0; i < 5; ++i) save << NPC[i].name << " " << NPC[i].health << " " << NPC[i].armor << " "
                                    << NPC[i].damage << " " << NPC[i].location << endl; // 3-7 строчки инфа по врагам.
    save.close();
    cout << "You saved successfully!\n";
}

void load_game(vector<char>& map, character& player, character *NPC){

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
      load >> player.name >> player.health >> player.armor >> player.damage >> player.location;
      for (int i = 0;i < 5 ;++i) load >> NPC[i].name >> NPC[i].health >> NPC[i].armor >> NPC[i].damage
                                        >> NPC[i].location;
    }

    load.close();
    update_location(map,player,NPC);
}

void start_game(vector<char>& map, character& player, character *NPC){
    cout << "Hello! You want to begin a 'new' game or 'load'?\n";
    string answer {};

    while (true) {
        cin >> answer;


        if (answer == "new"){
            new_game(map,player, NPC);
            break;
        }
        else if (answer == "load"){
            load_game(map,player, NPC);
            update_location(map, player, NPC);
            break;
        }
        else {
            cout << "Ups, command not found! Try Again\n";
            continue;
        }
    }
}

bool game_over(character& player, character *NPC){
    if (player.health <= 0) return true;
    for(int i = 0 ; i < 5; ++i) if (NPC[i].health > 0 ) return false;

    return true;
}

void death_check(character *NPC){
    for (int queue = 0;queue< 5 ; queue++){
        if (NPC[queue].health <= 0) {
            NPC[queue].location = -99999; //
            NPC[queue].name = "!!DEAD!!";
        }
    }
}

void player_vs_bot (character& player, character *NPC, int queue){ // если передавать значения по адресу то нужно обращатся к полям через -> а если чреез ссылку то через точку
    cout << NPC[queue].name << " took damage: -" << player.damage << endl;
    NPC[queue].armor -= player.damage;
    if(NPC[queue].armor < 0){
        NPC[queue].health += NPC[queue].armor;
        NPC[queue].armor = 0;
    }


}

void bot_vs_player (character& player, character *NPC, int queue){

    cout << player.name << " took damage: -" << NPC[queue].damage << std::endl;
    player.armor -= NPC[queue].damage;
    if(player.armor < 0) {
        player.health += player.armor;
        player.armor = 0;
    }
}

void players_turn (vector<char>& map,character& player, character *NPC){
    string answer;
    cout << "Enter the command:\n";
    do cin >> answer;
    while (answer != "save"  &&  answer != "load" && answer != "left" &&
           answer != "right" &&  answer != "top"  && answer != "bottom");

    if (answer == "save") {
        save_game(player, NPC);
        players_turn(map,player,NPC);
    }else if (answer == "load") {
        load_game(map, player, NPC);
        players_turn(map,player,NPC);
    }else if (answer == "left") {
        if (player.location % 40 == 0) return;
        else {
            if (map[player.location - 1] >= '0' && map[player.location - 1] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location - 1] - '0');
            }else {
                player.location -= 1;
            }
        }

    }else if (answer == "right") {
        if (player.location % 39 == 0) return;
        else {
            if (map[player.location + 1] >= '0' && map[player.location + 1] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location + 1] - '0');
            }else {
                player.location += 1;
            }
        }
    }else if (answer == "top"){
        if (player.location <= 39 ) return;
        else {
            if (map[player.location - 40 ] >= '0' && map[player.location - 40] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location - 40] - '0');
            }else {
                player.location -= 40;
            }
        }
    }else if (answer == "bottom"){
        if (player.location >= map.size() - 40 ) return;
        else {
            if (map[player.location + 40 ] >= '0' && map[player.location + 40] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location + 40] - '0');
            }else {
                player.location += 40;
            }
        }
    }


}

void bots_turn(vector<char>& map,character& player, character *NPC, int queue){
    srand(time(nullptr));
    int answer = rand() % 4;

    switch (answer) {
        case 0:
            if (NPC[queue].location % 39 == 0 || (map[NPC[queue].location + 1] >= '0'
                    && map[NPC[queue].location + 1] <= '4')) return;
            else {
                if (map[NPC[queue].location + 1] == 'P'){
                    bot_vs_player(player,NPC,queue);
                }else {
                        NPC[queue].location += 1;
                }
            }

            break;
        case 1:
            if (NPC[queue].location % 40 == 0 || (map[NPC[queue].location - 1] >= '0'
                    && map[NPC[queue].location - 1] <= '4') ) return;
            else {
                if (map[NPC[queue].location - 1] == 'P'){
                    bot_vs_player(player,NPC,queue);
                }else {
                    NPC[queue].location -= 1;
                }
            }

            break;
        case 2:
            if (NPC[queue].location <= 39 || (map[NPC[queue].location + 1] >= '0'
                    && map[NPC[queue].location + 1] <= '4') ) return;
            else {
                if ( map[NPC[queue].location - 40 ] == 'P' ){
                    bot_vs_player(player,NPC,queue);
                }else NPC[queue].location -= 40;
            }
            break;
        case 3:
            if (NPC[queue].location >= map.size() - 40 || (map[NPC[queue].location + 40] >= '0'
                    && map[NPC[queue].location + 40] <= '4')) return;
            else {
                if (map[NPC[queue].location + 40]== 'P'){
                    bot_vs_player(player,NPC,queue);
                }else NPC[queue].location += 40;
            }
            break;
        default:
            break;
    }
}


void process_game (vector<char>& map, character& player, character *NPC){

    while (!game_over(player, NPC)){
        death_check(NPC);
        view_Map(map);
        players_turn(map,player,NPC);
        update_location(map,player,NPC);
        for (int i = 0; i < 5; ++i){
            bots_turn(map,player,NPC,i);
        }
        update_location(map,player,NPC);
    }

}

//! Основные проблемы - перепрыгивают сквозь поле если масимально справа, бот после <0 здоровья умирает только через 4 хода

int main() {
    std::vector<char> map(40*40, 'Z');

    character player;
    character NPC[5];

    start_game(map, player, NPC);
    process_game(map,player,NPC);

    cout << "\n\n\tGame Result:\n\n";
    if (player.health <= 0) cout << "End of the game you've lost! =(\n";
    else cout << "Congratulations, you WON!!";

    return 0;
}
