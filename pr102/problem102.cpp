#include <iostream>
#include <tuple>
#include <string>
#include <fstream>

using namespace std;

int coords[1000][6];

struct line {
    int x1;
    int y1;
    int x2;
    int y2;
};

int pop_coords() {
    string filePath = "./problem102.txt";

    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    string line;
    int triangle_num = 0;
    int coord_num = 0;
    while(getline(inputFile, line)) {

        while(line.size() > 0) {
            int comma_index = line.find(",");
            string curr = line;

            // edge case check for last coord of triangle
            if (comma_index != string::npos) {
                curr = line.substr(0,comma_index);
            }

            coords[triangle_num][coord_num] = stoi(curr);

            // update coord_num and triangle_num (if needed)
            // update line
            if (coord_num == 5) {
                coord_num = 0;
                triangle_num++;
                line = "";
            } else {
                coord_num++;
                line = line.substr(comma_index+1);
            }
        }
    }

    inputFile.close();
    return 0;
}

double y_intercept(line a) {
    double m = (double)(a.y2 - a.y1) / (a.x2 - a.x1);
    double y_int = (a.y2 - (m * a.x2));

    if ((a.x1 > 0 && a.x2 < 0) || (a.x2 > 0 && a.x1 < 0)) {
        return y_int;
    } else {
        // no y-int for line seg
        return 1001;
    }
}

int contains_origin(int triangle_num) {
    int pos_count = 0;
    int neg_count = 0;

    line A = {coords[triangle_num][0],coords[triangle_num][1],coords[triangle_num][2],coords[triangle_num][3]};
    line B = {coords[triangle_num][2],coords[triangle_num][3],coords[triangle_num][4],coords[triangle_num][5]};
    line C = {coords[triangle_num][0],coords[triangle_num][1],coords[triangle_num][4],coords[triangle_num][5]};

    double inters[3] = {y_intercept(A), y_intercept(B), y_intercept(C)};

    for (int i = 0; i < (sizeof(inters) / sizeof(inters[0])); i++) {
        if (inters[i] != 1001) {
            if (inters[i] < 0) {
                neg_count += 1;
            } else {
                pos_count += 1;
            }
        }
    }

    // odd number of pos intercepts -> contains origin
    if (pos_count == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    /*
    check if (0,0) ->(1000,0) goes through odd or even
    number of lines.  If odd->point in triangle.
    If even-> point not in triangle
    */
    pop_coords();

    int count = 0;

    for (int tri = 0; tri < 1000; tri++) {
        count += contains_origin(tri);
    }
    
    cout << count << endl;
    return 0;
}