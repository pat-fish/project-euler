#include <iostream>

using namespace std;

// runs in O(n) because sqrt(n) ** 2 = n
long long largest_prime2(long long n) {
    long long max_prime = -1;
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            int isPrime = 1;
            // i is factor of n, check if i == prime
            for (long long j = 2; j*j <= i; j++) {
                // break loop when factor of i found -> i != prime
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }

            if (isPrime) {
                max_prime = i;
            }

        }
    }
    return max_prime;
}

int main() {

    long long lp = largest_prime2(600851475143);
    cout << lp << endl;
    return 0;
}