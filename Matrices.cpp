#include <iostream>
#include <vector>
#include <array>
#include "Matrices.hpp"

using namespace std;

Matrices :: Matrices() {



}

vector< vector<double> > Matrices :: CreateMatrix(vector< vector<double> > inputs, int startc, int startr, int sizec, int sizer) {

    vector< vector<double> > end;
    vector<double> h;
    
    int counter = 0;

    for(int i = startc; i < startc + sizec; i++) {

        end.push_back(h);
        for(int j = startr; j < startr + sizer; j++) {

            end[counter].push_back(inputs[i][j]);

        }

        counter++;

    }

    return end;

}

vector< vector<double> > Matrices :: CreateMatrix(vector<double> inputs, int rownum, int colnum) {

    vector< vector<double> > end;
    vector<double> h;
    
    int counter = 0;
    int val = 0;

    for(int i = 0; i < rownum; i++) {

        end.push_back(h);
        for(int j = 0; j < colnum; j++) {

            end[counter].push_back(inputs[val]);
            val++;

        }

        counter++;

    }

    return end;

}

vector< vector<double> > Matrices :: Transpose(vector< vector<double> > inputs) {

    vector< vector<double> > end;
    vector<double> h;

    int rownum = inputs[0].size();
    int colnum = inputs.size();

    for(int i = 0; i < rownum; i++) {

        end.push_back(h);
        for(int j = 0; j < colnum; j++) {

            end[i].push_back(inputs[j][i]);

        }

    }

    return end;

}

vector< vector<double> > Matrices :: Multiply(vector< vector<double> > inputs, vector< vector<double> > inputs2) {

    vector< vector<double> > end;
    vector<double> h;

    inputs2 = Transpose(inputs2);

    int counter = 0;

    for(int i = 0; i < inputs.size(); i++) {

        end.push_back(h);
        for(int j = 0; j < inputs2.size(); j++) {

            double temp = 0;

            for(int k = 0; k < inputs2[j].size(); k++) {

                temp += inputs[i][k]*inputs2[j][k];

            }

            end[counter].push_back(temp);

        }

        counter++;

    }

    return end;

}

vector< vector<double> > Matrices :: Add(vector< vector<double> > inputs, vector< vector<double> > inputs2) {

    vector< vector<double> > end;
    vector<double> h;

    int counter = 0;

    for(int i = 0; i < inputs.size(); i++) {

        end.push_back(h);
        for(int j = 0; j < inputs[i].size(); j++) {

            end[counter].push_back(inputs[i][j]+inputs2[i][j]);

        }

        counter++;

    }

    return end;

}

vector< vector<double> > Matrices :: Subtract(vector< vector<double> > inputs, vector< vector<double> > inputs2) {

    vector< vector<double> > end;
    vector<double> h;

    int counter = 0;

    for(int i = 0; i < inputs.size(); i++) {

        end.push_back(h);
        for(int j = 0; j < inputs[i].size(); j++) {

            end[counter].push_back(inputs[i][j]-inputs2[i][j]);

        }

        counter++;

    }

    return end;

}

vector< vector<double> > Matrices :: Inverse(vector< vector<double> > inputs) {

    vector< vector<double> > end;
    vector<double> h;

    int counter = 0;

    for(int i = 0; i < inputs.size(); i++) {

        end.push_back(h);
        for(int j = 0; j < inputs[i].size(); j++) {

            end[counter].push_back((double) 1/inputs[i][j]);

        }

        counter++;

    }

    return end;

}

double Matrices :: Summation(vector< vector<double> > inputs) {

    double end = 0.0;

    for(int i = 0; i < inputs.size(); i++) {

        for(int j = 0; j < inputs[i].size(); j++) {

            end += inputs[i][j];

        }

    }

    return end;

}

void Matrices :: Print(vector< vector<double> > inputs) {

    for(int i = 0; i < inputs.size(); i++) {

        for(int j = 0; j < inputs[i].size(); j++) {

            cout << inputs[i][j] << " ";

        }

        cout << endl;

    }        

}

/*

________________
|  4 |  5 |  6 |
----------------
|  7 |  8 |  9 |
----------------
| 10 | 11 | 12 |
----------------
*/