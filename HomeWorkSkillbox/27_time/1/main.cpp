#include <iostream>
#include <iomanip>
#include <ctime>
#include "fstream"
#include <sstream>

enum {
    START, //элементы массива конечное и начальное время задачи и дельта
    STOP
};

struct s_task {
    std::string name;
    time_t time[2]{};
    uint8_t hour[2]{}, min[2]{};
    std::time_t execute{};

    bool flag_process{}; // если флаг тру значит задача выполняется
};


void time_label (s_task &task, uint8_t value){
    task.time[value] = std::time(nullptr);
    std::tm* local = std::localtime(&task.time[value]);

    task.hour[value] = local->tm_hour;
    task.min[value] = local->tm_min;

}

     //! начало задачи, то есть определяется время начала и название
void start_task(s_task& task){
    std::cout << "Enter the name of the task: \n";

    std::cin.ignore();
    getline(std::cin, task.name);


    time_label(task, START);
    task.flag_process = true;

    std::ofstream save("..\\save.txt", std::ios::app);
    save << "Start time [" << std::to_string (task.hour[START]) << ':' << std::to_string (task.min[START]) <<
            "] name a task \"" << task.name << "\" ";
    save.close();


}

void end_task(s_task& task){
    time_label(task, STOP);

    task.flag_process = false; // закончился прогресс этой задачи

    task.execute = task.time[STOP] - task.time[START];
    std::tm* exe = std::localtime(&task.execute);

    std::ofstream save("..\\save.txt", std::ios::app);
    save << "Stop time ["<< std::to_string (task.hour[STOP]) << ':' << std::to_string (task.min[STOP]) << "] " <<
    "Executed per second = " << std::put_time(exe,"[%M:%S]") << " min:sec."<< std::endl;
    save.close();
}


void status(){
    std::ifstream load ("..\\save.txt");
    if(!load.is_open()){
        std::cout << "Not found file\a \"save.bin\" !!!\n";
    }else {
        while (!load.eof()){
            std::string str;
            getline(load, str);
            std::cout << str << '\n';
        }
    }
    load.close();
}

int main() {

    s_task task;
    while (true){
        std::string answer{};
        std::cout << "Enter command:\n";
        std::cin >> answer;


        if (answer == "begin"){
            if (task.flag_process){
                end_task(task);
                start_task(task);
            }else{
                start_task(task);
            }

        }else if (answer == "end"){
            if (task.flag_process) end_task(task);
            else std::cout << "No active tasks found!\n\a";

        }else if (answer == "status"){
            status();

        }else if (answer == "exit"){
            std::cout << "Goodbye!\n";
            break;

        }else {
            std::cout << "This command not found!\n"
                         "Try again\n";
        }
    }
    return 0;
}
