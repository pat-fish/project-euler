#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    long long sum = 0;
    for (int i = 2; i < 2000000; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}