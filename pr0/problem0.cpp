#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    long long sum = 0;
    for (long long i = 1; i <= 110500; i++) {
        long long squared = ((2*i - 1) * (2*i - 1));
        sum += squared;
    }

    cout << sum;
    cout << endl;
}