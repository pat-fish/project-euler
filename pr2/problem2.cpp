#include <iostream>

using namespace std;

int main() {
    long long first_term = 1;
    long long second_term = 2;
    long long sum = 0;

    while (second_term < 4000000) {
        if (second_term % 2 == 0) {
            sum += second_term;
        }

        // update first and second terms
        long long temp = first_term + second_term;
        first_term = second_term;
        second_term = temp;
    }

    cout << sum << endl;
    return 0;
}