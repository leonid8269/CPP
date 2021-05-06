#include <iostream>
#include <ctime>
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

uint8_t number_of_bots = 5;
const uint16_t size_map = 40*40;



void update_location (vector<char>& map, character& player, std::vector<character>& NPC){ // применяется при каждом изменении позиции
    for (int i = 0 ; i < map.size(); ++i ){
        map[i] = '.';
        if (i == player.location) map[i] = 'P';
        for(int k = 0; k < number_of_bots; ++k)
            if (i == NPC[k].location) map[i] = '0' + k;
    }
}


void view_Map(vector<char>& map){
    for (int i = 0; i < map.size(); ++i ){
        if (i % (int)sqrt(map.size()) == 0 ) cout << endl;
        if (map[i] >= '0' && map[i] <= '4') cout << 'E';
        else cout << map[i];
    }
    cout << endl;

}


void location_initialization(character& player, std::vector<character>& NPC){ // расставлю персонажей, с проверкой на совпадения и соприкосновения
    srand(time(nullptr));
    while (true){
        player.location = rand() % size_map;
        for (int i = 0; i < number_of_bots; ++i) {
            NPC[i].location = rand() % size_map;
            if (NPC[i].location == player.location || NPC[i].location == player.location + 1 ||
                    NPC[i].location == player.location - 1 || NPC[i].location == player.location - 30 ||
                    NPC[i].location == player.location + 30) continue;
        }
        break;
    }
}

void new_game(vector<char>& map, character& player, std::vector<character>& NPC){

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
    for (int i = 0; i < number_of_bots; ++i){
        NPC[i].name = "Enemy#" +  std::to_string( i + 1);
        NPC[i].health = rand() % 151 + 50;
        NPC[i].armor  = rand() % 51;
        NPC[i].damage = rand() % 31 + 15;
    }

    location_initialization(player, NPC); // проверяет чтобы не попасть в одно и тоже место...
    update_location(map, player, NPC);  // расставляет фигурки
}

void save_game( character& player, std::vector<character>& NPC){

    std::ofstream save ("..\\save.bin", std::ios::binary);
    save << player.name << " " << player.health << " " << player.armor << " " << player.damage << " "
            << player.location << endl; // вторая строчка инфа игрока

    for(int i = 0; i < number_of_bots; ++i) save << NPC[i].name << " " << NPC[i].health << " " << NPC[i].armor << " "
                                    << NPC[i].damage << " " << NPC[i].location << endl; // 3-7 строчки инфа по врагам.
    save.close();
    cout << "You saved successfully!\n";
}

bool load_game(vector<char>& map, character& player, std::vector<character>& NPC){

    std::ifstream load ("..\\save.bin", std::ios::binary);
    if(!load.is_open()){
        cout << "Not found a save-game!! Start a New-Game? (y\\n)\n";
        char answer;
        cin >> answer;
        if(answer == 'y') return true;
        else {
            cout << "Goodbye!!";
            return false;
        }
    }else {
      load >> player.name >> player.health >> player.armor >> player.damage >> player.location;
      for (int i = 0;i < number_of_bots ;++i) load >> NPC[i].name >> NPC[i].health >> NPC[i].armor >> NPC[i].damage
                                        >> NPC[i].location;
    }

    load.close();
    update_location(map,player,NPC);

    return false;
}

void start_game(vector<char>& map, character& player, std::vector<character>& NPC){
    cout << "Hello! You want to begin a 'new' game or 'load'?\n";
    string answer {};

    while (true) {
        cin >> answer;


        if (answer == "new"){
            new_game(map,player, NPC);
            break;
        }
        else if (answer == "load"){
            if (load_game(map,player, NPC)){
                new_game(map,player, NPC);
            }
            break;
        }
        else {
            cout << "Ups, command not found! Try Again\n";
            continue;
        }
    }
}

bool game_over(character& player, std::vector<character>& NPC){
    if (player.health <= 0) return true;
    for(int i = 0 ; i < number_of_bots; ++i) if (NPC[i].health > 0 ) return false;

    return true;
}

void player_vs_bot (character& player, std::vector<character>& NPC, int queue){ // если передавать значения по адресу то нужно обращатся к полям через -> а если чреез ссылку то через точку
    cout << NPC[queue].name << " took damage: -" << player.damage << endl;
    NPC[queue].armor -= player.damage;
    if(NPC[queue].armor < 0){
        NPC[queue].health += NPC[queue].armor;
        NPC[queue].armor = 0;
    }

    if (NPC[queue].health <= 0){
        NPC.erase(NPC.begin() + queue);
        number_of_bots = NPC.size();
    }


}

void bot_vs_player (character& player, std::vector<character>& NPC, int queue){

    cout << player.name << " took damage: -" << NPC[queue].damage << std::endl;
    player.armor -= NPC[queue].damage;
    if(player.armor < 0) {
        player.health += player.armor;
        player.armor = 0;
    }
}

void players_turn (vector<char>& map,character& player, std::vector<character>& NPC){
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
        view_Map(map);
        players_turn(map,player,NPC);


    }else if (answer == "left") {
        if (player.location % 40 == 0) return;
        else {
            if (map[player.location - 1] >= '0' && map[player.location - 1] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location - 1] - '0');
                update_location(map,player,NPC);
            }else {
                player.location -= 1;
            }
        }

    }else if (answer == "right") {
        if ((player.location + 1) % 40 == 0) return;
        else {
            if (map[player.location + 1] >= '0' && map[player.location + 1] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location + 1] - '0');
                update_location(map,player,NPC);

            }else {
                player.location += 1;
            }
        }
    }else if (answer == "top"){
        if (player.location <= 40 ) return;
        else {
            if (map[player.location - 40 ] >= '0' && map[player.location - 40] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location - 40] - '0');
                update_location(map,player,NPC);
            }else {
                player.location -= 40;
            }
        }
    }else if (answer == "bottom"){
        if (player.location >= map.size() - 40 ) return;
        else {
            if (map[player.location + 40 ] >= '0' && map[player.location + 40] <= '4'){
                player_vs_bot(player, NPC, (int) map[player.location + 40] - '0');
                update_location(map,player,NPC);
            }else {
                player.location += 40;
            }
        }
    }
}

void bots_turn(vector<char>& map,character& player,  std::vector<character>& NPC, int queue){
    srand(time(nullptr));
     int answer = rand() % 4;

    switch (answer) {
        case 0: // right
            if ((NPC[queue].location + 1) % 40 == 0 || (map[NPC[queue].location + 1] >= '0'
                    && map[NPC[queue].location + 1] <= '4')) return;
            else {
                if (map[NPC[queue].location + 1] == 'P'){
                    bot_vs_player(player,NPC,queue);
                    update_location(map,player,NPC);
                }else {
                        NPC[queue].location += 1;
                }
            }

            break;
        case 1: // left
            if ((NPC[queue].location % 40 == 0 ) || (map[NPC[queue].location - 1] >= '0'
                    && map[NPC[queue].location - 1] <= '4') ) return;
            else {
                if (map[NPC[queue].location - 1] == 'P'){
                    bot_vs_player(player,NPC,queue);
                    update_location(map,player,NPC);
                }else {
                    NPC[queue].location -= 1;
                }
            }

            break;
        case 2: // top
            if (NPC[queue].location <=  40 || (map[NPC[queue].location + 1] >= '0'
                    && map[NPC[queue].location + 1] <= '4') ) return;
            else {
                if ( map[NPC[queue].location - 40 ] == 'P' ){
                    bot_vs_player(player,NPC,queue);
                    update_location(map,player,NPC);
                }else NPC[queue].location -= 40;
            }
            break;
        case 3: // bottom
            if (NPC[queue].location >=  map.size() - 40 || (map[NPC[queue].location + 40] >= '0'
                    && map[NPC[queue].location + 40] <= '4')) return;
            else {
                if (map[NPC[queue].location + 40]== 'P'){
                    bot_vs_player(player,NPC,queue);
                    update_location(map,player,NPC);
                }else NPC[queue].location += 40;
            }
            break;
        default:
            break;
    }
}


void process_game (vector<char>& map, character& player, std::vector<character>& NPC){

    while (!game_over(player, NPC)){
        view_Map(map);
        players_turn(map,player,NPC);
        update_location(map,player,NPC);

        for (int i = 0; i < number_of_bots; ++i){
            bots_turn(map,player,NPC, i);
        }
        update_location(map,player,NPC);
    }

}

int main() {
    std::vector<char>       map(size_map, 'Z');
    std::vector<character>  NPC(number_of_bots);

    character player;

    start_game(map, player, NPC);
    process_game(map,player,NPC);

    cout << "\n\n\tGame Result:\n\n";
    if (player.health <= 0) cout << "End of the game you've lost! =(\n";
    else cout << "Congratulations, you WON!!";

    return 0;
}
