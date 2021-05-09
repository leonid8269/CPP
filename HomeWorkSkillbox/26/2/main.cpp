#include <iostream>

#define CYCLE(arr)  for (int i = 0; i < (sizeof arr / 4) ;++i)

#define SETUP(arr)  CYCLE(arr) {std::cin >> arr[i]; \
                    if (arr[i] < 0) continue;}

#define CROWDED(arr) CYCLE(arr) if (arr[i] > 20) std::cout << "There is an overflow in car No. " << i + 1 << std::endl;
#define VOID(arr)    CYCLE(arr) if(arr == 0) std::cout << "Empty car No. " << i + 1;
#define FULLNESS(arr) int sum = 0; CYCLE(arr) sum += arr[i]; std::cout << "Total passengers on the train = "<< sum;

int main() {
    int train[10];
    std::cout << "Enter the number of passengers\n";
    SETUP(train)
    CROWDED(train)
    VOID(train)
    FULLNESS(train)



    return 0;
}
