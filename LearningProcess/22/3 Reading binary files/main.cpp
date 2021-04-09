#include <iostream>
#include <fstream>

int main() {
    using namespace std;
    std::ifstream bank;

    char buffer[20];
    bank.open("C:\\CPP\\LearningProcess\\22\\2 reading different types of data\\bank.txt", std::ios::binary);

    bank.read(buffer, sizeof (buffer));
    //for (int i = 0 ;i < sizeof(buffer) ; ++i) cout << buffer[i]; // покажет первые 20 байт с тхт файла

    /*!buffer[5] = 0;
     *!cout << buffer; // можно обойтись без цикла, так как это текст, и сткрока будет выводтся до \0
     */

    int value;

    /*!  bank.read((char*)&value, sizeof (int));
     *  cout <<  value;
     *
     *  ТУТ ПРЯМ НУ ПОЛНАЯ ХРЕНЬ)
     */

    bank.read(buffer, sizeof (buffer));
    buffer[19] = 0;

   // cout << buffer << endl; // это все можно переписать иначе управляя "считывающей" головкой

 //   bank.seekg(0);
   // bank.read(buffer, sizeof (buffer));
  //  cout << buffer;


    bank.read(buffer, sizeof (buffer));
    cout << bank.tellg() << " cursor"; // покажет в каком месте стоит курсор





    bank.close();

    return 0;
}
