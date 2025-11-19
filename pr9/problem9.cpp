#include <iostream>
#include <cmath>

using namespace std;

int main() {
    for (int b = 1; b <= 1000; b++) {
        for (int a = 1; a < b; a++) {
            double c = sqrt((a*a)+(b*b));
            if (a+b+c == 1000) {
                long long product = (a*b*c);
                cout << product << endl;
                return 0;
            }
        }
    }
    
    return 1;
}