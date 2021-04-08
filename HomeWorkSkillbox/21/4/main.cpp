#include <iostream>

void evendigits( long long int num, int& ans){
    if (num < 10) {
        if (num % 2 == 0){
            ++ans;
            return;
        }else return;
    }

    if (num % 2 == 0) evendigits(num / 10,++ans);
    else evendigits(num / 10, ans);


}


int main() {
   int ans = 0;
   evendigits(8223372036854775806, ans);

   std::cout << ans;

    return 0;
}
