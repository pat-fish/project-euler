#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string Text;
    long long sum;

    ifstream MyReadFile("input.txt");

    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, Text)) {
            try {
                // convert each line to int and add to sum
                Text = Text.substr(0, 12);
                long long curr = stoll(Text);
                sum += curr;
            } catch (const invalid_argument& e) {
                cerr << "Invalid Arg: " << e.what() << endl;
                return 1;
            } catch (const out_of_range& e) {
                cerr << "Out of range: " << e.what() << endl;
                return 1;
            }
        }
    } else {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // print final sum
    cout << sum;
    return 0;
}