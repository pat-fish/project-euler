#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// matrix
long long matrix[80][80] = {};
// dp table that stores optimal sol
long long m[80][80] = {};

void transcribe_matrix() {
    ifstream matrix_txt("matrix.txt");
    // ifstream matrix_txt("matrix2.txt");

    string horizontal;
    int row = 0;
    int col = 0;
    long long curr;
    int comma_index;

    if (matrix_txt.is_open()) {
        while (getline(matrix_txt, horizontal)) {
            try {
                // for (; col < 5; col++) {
                for (; col < 80; col++) {

                    // if (col < 4) {
                    if (col < 79) {
                        comma_index = horizontal.find(",");
                        curr = stoll(horizontal.substr(0,comma_index));
                        matrix[row][col] = curr;
                        // update horizontal string
                        horizontal = horizontal.substr(comma_index+1);
                    } else {
                        curr = stoll(horizontal);
                        matrix[row][col] = curr;
                    }
                }
                col = 0;
                row++;

            } catch (const invalid_argument& e) {
                cerr << "Invalid Arg: " << e.what() << endl;
            } catch (const out_of_range& e) {
                cerr << "Out of range: " << e.what() << endl;
            }
        }
    } else {
        cerr << "Error opening file: "<< endl;
    }

}

void pop_dp_table() {
    
    // for (int col = 0; col <= 4; col++) {
    for (int col = 0; col <= 79; col++) {
    // for (int row = 0; row <= 4; row++) {
        for (int row = 0; row <= 79; row++) {
            if (col <= 0 && row <= 0) {
                m[row][col] = matrix[row][col];
            } else if (col <= 0) {
                m[row][col] = matrix[row][col] + m[row-1][col];
            } else if (row <= 0) {
                m[row][col] = matrix[row][col] + m[row][col-1];
            } else {
                // get min of (m[row-1][col], m[row][col-1])
                long above = m[row-1][col];
                long left = m[row][col-1];
    
                if (above < left) {
                    m[row][col] = matrix[row][col] + m[row-1][col];
                } else {
                    m[row][col] = matrix[row][col] + m[row][col-1];
                }
                
            }
        }
    }

    return;
}

int main() {
    /*
    init sum as elem at (0,0)
    convert string to 2d array
    keep dp table that stores optimal solution for given elem
    when elem to left and below == null -> return dp_table[79][79]
    */

    // init matrix;
    transcribe_matrix();

    // pop dp table
    pop_dp_table();

    // cout << m[4][4] << endl;
    cout << m[79][79] << endl;
