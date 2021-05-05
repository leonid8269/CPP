#include <iostream>
#include <map>
#include <fstream>


int main() {
    std::map<std::string, std::string> tel_guide;

    for (int t = 0; t < 5; ++t){
        std::cout << "\n\nWhat do you want to do?\n"
                     "1 - Add a name with a number!\n"
                     "2 - Find out the subscriber's last name by phone number! \n"
                     "3 - Find out the phone number by last name! \n"
                     "4 - Initialize with a \"standard\" set of numbers and names\n"
                     "5 - Stop program!\n";

        int ans = 0;
        while (ans < 1 || ans > 5) std::cin >> ans;


        switch (ans) {
            case 1: {
                int16_t count = 0;
                std::cout << "How many entries do you want to make?\n";
                while (count < 1)std::cin >> count;

                for (int16_t i = 0; i < count; ++i) {
                    std::string buf_telephone, buf_name;

                    std::cout << "Enter the subscriber's phone number\n";
                    std::cin >> buf_telephone;

                    std::cout << "Enter the subscriber name\n";
                    std::cin >> buf_name;

                    tel_guide.insert(std::make_pair(buf_telephone, buf_name));
                }
            }
                break;
            case 2:
                //! узнать фамилию абонента по номеру телефона
                break;
            case 3: {
                std::string name_seek;
                std::cout << "Enter the name of the subscriber whose number you want to find out:\n";
                std::cin >> name_seek;

                int count = 0;
                for (std::map<std::string, std::string>::iterator it = tel_guide.begin();
                     it != tel_guide.end(); ++it) {
                    if (it->second == name_seek) {
                        count++;
                        std::cout << it->first << std::endl;
                    }
                }
                std::cout << "Found " << count << " results named: \"" << name_seek << "\" \n";
            }
                break;
            case 4:
            {
                std::ifstream file("..\\name_and_number.txt");
                if (!file.is_open()) {
                    std::cout << "Phone log not found!!\n";
                    exit(4);
                } else {
                    while (!file.eof()) {
                        std::string buf_name, buf_telephone;

                        file >> buf_telephone;
                        file >> buf_name;
                        tel_guide.insert(std::make_pair(buf_telephone, buf_name));
                    }
                    std::cout << "Okay!";
                }
                file.close();

            }
                break;
            default:
                exit(1);
        }

    }

    return 0;
}
