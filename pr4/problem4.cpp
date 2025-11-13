#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int is_palindrome(long long n) {
    string s = to_string(n);
    int half = s.length() / 2;

    string first = s.substr(0,half);
    string second = s.substr(half);

    reverse(second.begin(), second.end());

    if (first == second) {
        return 1;
    } else {
        return 0;
    }
}

int get_palindrome(long long upper) {
    long long max = 1;
    for (long long i = 1; i<upper; i++) {
        for (long long j = 1; j<upper; j++) {
            long long sum = i*j;
            if (is_palindrome(sum) && sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

int main() {
    long long num = get_palindrome(999);

    cout << num << endl;
    return 0;
}
