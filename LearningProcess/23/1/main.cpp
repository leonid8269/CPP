#include <iostream>
#include <fstream>


int main() {
    using namespace std;
                                    //! app - курсор в конец файла. чтобы не стирать старое
    ofstream file("..\\text.txt", ios::app);   //  для краткости
    //! file.open("..\\text.txt);        //  можно записывать так без метода опен

    file << "It's never too late to learn\n";

    file.close();

    return 0;
}
