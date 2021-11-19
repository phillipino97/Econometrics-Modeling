#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "FileParse.hpp"

using namespace std;



FileParse :: FileParse() {

}

vector<double> FileParse :: ReadCsv(string filename) {

    ifstream file("test.csv");
    string line;
    double value;

    vector<double> result;

    while(getline(file, line)) {

        stringstream instream(line);

        int col_num = 0;

        while(instream >> value) {

            result.push_back(value);

            col_num++;

        }

    }

    return result;

}