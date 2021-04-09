#include <iostream>


int variants (int step, int maxJump = 3)
{
    if (step < 0) return 0;
    else if (step == 0)return 1;

    int variables = 0;
    for (int i = maxJump; i > 0; --i) variables += (variants(step - i, maxJump));
    return variables;
}


int main() {
    using std::cout;
    using std::cin;

    cout << "Enter the step number : \n";
    int step;
    cin >> step;

    std::cout << "Enter the maximum jump threshold: \n";
    int maxJump;
    std::cin >> maxJump;

    std::cout << "variants=  " << variants(step, maxJump);
}