#include <iostream>
#include <iomanip>
#include <ctime>
#include "fstream"
#include <sstream>

enum {
    START, //элементы массива конечное и начальное время задачи и дельта
    STOP,
    EXECUTE
};

struct s_task {
    std::string name;
    time_t time[3]{};

    bool flag_process{}; // если флаг тру значит задача выполняется
};


void start_task(s_task& task){                // начало задачи, то есть определяется время начала и название
    std::cout << "Enter the name of the task: \n";
    std::cin.ignore();
    getline(std::cin, task.name);

    task.flag_process = true;

    task.time[START] = std::time(nullptr);
    std::tm* start = std::localtime(&task.time[START]);

    std::ofstream save("..\\save.txt", std::ios::app);
    save << "Start time " << std::put_time(start, "[%H:%M]") << " name a task \"" << task.name << "\" ";
    save.close();

}

void end_task(s_task& task){

    task.time[STOP] = std::time(nullptr);

    task.flag_process = false; // закончился прогресс этой задачи

    double delta = std::difftime(task.time[STOP], task.time[START]);
    task.time[EXECUTE] = (std::time_t) delta;

    std::ofstream save("..\\save.txt", std::ios::app);
    std::tm* stop = std::localtime ( &task.time[STOP] );
    save << "Stop time "<< std::put_time(stop,"[%H:%M]") << " ";
    std::tm* exec = std::localtime ( &task.time[EXECUTE] );
    save << "Executed per second = " << std::put_time(exec,"[%M:%S]") << " min:sec."<< std::endl;
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
