#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// global input string
string input = "";

int readInput() {
    string filePath = "./problem8.txt";

    ifstream inputFile(filePath);

    if(!inputFile.is_open()) {
        cerr << "Error: could not open file" << filePath << endl;
        return 1;
    }

    string line;
    while(getline(inputFile, line)) {
        input += line;
    }

    inputFile.close();
    return 0;
}

long long getGreatestProduct() {
    int n = input.length();
    long long max = 0;

    for(int i = 0; i < (n - 14); i++) {
        long long product = 1;
        for (int j = 0; j < 13; j++) {
            int curr = stoi(input.substr(i+j, 1));
            product *= curr;
        }
        
        if (product > max) {
            max = product;
        }
    }

    return max;
}

int main() {
    /*
    read txt as string
    iter through string, 13 digits at a time
    return largest product of 13 consecutive digits
    */

    readInput();
    long long max = getGreatestProduct();
    cout << max << endl;
}