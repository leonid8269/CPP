#include <iostream>


int variants (int step)
{
    if (step < 0)
        return 0;
    else
    if (step == 0)
        return 1;

    return (variants(step - 1) + variants(step - 2) + variants(step - 3));
}


int main() {
    using std::cout;
    using std::cin;

    cout << "Enter count of steps: ";
    int step;
    cin >> step;

    cout << "Variants: " << variants(step) <<  std::endl;
}