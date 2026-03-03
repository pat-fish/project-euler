#include <iostream>
#include <cmath>

using namespace std;

long long min_flips(int a, int b, int c) {
    double curr_deg = 0;
    long long flips = 0;
    double x = 360.0 / a;
    double y = 360.0 / b;
    double z = 360.0 / sqrt(c);
    int instr = 0;

    while (true) {
        if (instr == 0) {
            curr_deg += x;
        } else if (instr == 1) {
            curr_deg += y;
        } else {
            curr_deg += z;
        }

        if (curr_deg >= 360.0) {
            curr_deg -= 360;
        }

        // update instr
        instr = (instr + 1) % 3;
        flips++;

        if (curr_deg == 0.0) { // not how to check coverage of frosting
            break;
        }
    }

    return flips;
}

int main() {
    /*
    figure out when iterator lands on 0 deg twice
    brute force F(a,b,c)
    */
    long long flips = min_flips(10,14,16);
    cerr << flips << endl;
    return 0;
}