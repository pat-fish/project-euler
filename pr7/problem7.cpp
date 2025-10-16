#include <iostream>

using namespace std;

int main() {
    // init prime_count as 2 and prime as 2nd prime number (3)
    long long prime_count = 2;
    long long prime = 3;

    while (prime_count < 10001) {
        prime++;
        int isPrime = 1;
        for (long long i = 2; i <= (prime / 2); i++) {
            if (prime % i == 0) {
                isPrime = 0;
                break;
            }
        }
        
        // check if prime is actually prime
        if (isPrime) {
            prime_count++;
        }
    }

    cout << prime;
    return 0;
}