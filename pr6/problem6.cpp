#include <iostream>

using namespace std;

int main() {
    long long squared_sum = 0;
    long long sum_squares = 0;

    for (int i = 1; i <= 100; i++) {
        squared_sum += i;
        sum_squares += (i*i);
    }

    long long difference = (squared_sum * squared_sum) - sum_squares;

    cout << difference << endl;
    return 0;
}