#include <iostream>
#include <fstream>
#include <string>


void roulette (int* arr, int& motion ){ // возвращает инт - вариант вопроса при "проскальзывании" волчка
    using namespace std;
    cout << "How much to rotate the top? \n";
    cin >> motion;
    if (motion > 12 ) motion /= 12; // даже если получится дробное число это неимеет значения, волчек же не перешел границу ячейки заничт он выбирает ту ечейку на которую указыват...

    while (true) {   // алгоритм для волчка, попадает на нуль перемещается дальше, пока не встретит число)
        if (arr[motion - 1] == 0) ++motion;
        else {
            arr[motion - 1] = 0;
            return;
        }
    }

}

std::string answer (const int motion){
    using namespace std;
    string result;
    ifstream ans;
    ans.open("..\\answer.txt");
    if(!ans.is_open()) return "Error";
    else {
        for (int i = 0; i != motion; ++i) { // переберает строчки пока не остановится на нужной, другого более умного не придумал)
            result = "";
            getline(ans, result);
        }
    }
    ans.close();
    return result;
}

std::string question (const int motion){
    using namespace std;
    string text;
    ifstream quest;
    quest.open("..\\questions.txt");
    if(!quest.is_open())  return "Error";
    else {
       for (int i = 0; i != motion; ++i) { // переберает строчки пока не остановится на нужной, другого более умного не придумал)
           text = "";
           getline(quest, text);
       }
    }
    quest.close();

    return text;
}


int main() {
    using namespace std;
    int motion = 0;

    int variants [] = {1,2,3,4,5,6,7,8,9,10,11,12,13}; // стол,
    int pointsExperts = 0;
    int pointsViewer = 0;

    bool gameOver = false;
    while (!gameOver) {

        roulette(variants, motion);
        if (question(motion) == "Error") {
            cout << "Error opening file. Exit program!\a";
            return 1;
        }
        cout << "Attention question!\n";
        cout << question(motion);

        if (answer(motion) == "Error") {
            cout << "Error opening file. Exit program!\a";
            return 2;
        }

        string ans;
        cout << "\nEnter you answer: \n";
        cin >> ans;

        if (ans == answer(motion)) {
            cout << "The answer is accepted! The ball goes to the experts!\n";
            pointsExperts++;
        } else {
            cout << "The answer is not accepted. The ball goes to the audience\a\n";
            pointsViewer++;
        }

        cout << "Score: \n\tViewers : " << pointsViewer << "\n\tExperts : " << pointsExperts << endl;


        if (pointsExperts >= 6 || pointsViewer >= 6) gameOver = true;
    }

    if (pointsExperts > pointsViewer) cout << "\n\nThe experts won!!!\n";
    else cout << "The victory is awarded to the audience\n";


    return 0;
}
