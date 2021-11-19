#ifndef MATRICES_H
#define MATRICES_H

#include <vector>

class Matrices {

    public:

        Matrices();
        std :: vector< std :: vector<double> > CreateMatrix(std :: vector< std :: vector<double> > inputs, int startc, int startr, int sizec, int sizer);
        std :: vector< std :: vector<double> > CreateMatrix(std :: vector<double> inputs, int rownum, int colnum);
        std :: vector< std :: vector<double> > Transpose(std :: vector< std :: vector<double> > inputs);
        std :: vector< std :: vector<double> > Inverse(std :: vector< std :: vector<double> > inputs);
        double Summation(std :: vector< std :: vector<double> > inputs);
        std :: vector< std :: vector<double> > Multiply(std :: vector< std :: vector<double> > inputs, std :: vector< std :: vector<double> > inputs2);
        std :: vector< std :: vector<double> > Add(std :: vector< std :: vector<double> > inputs, std :: vector< std :: vector<double> > inputs2);
        std :: vector< std :: vector<double> > Subtract(std :: vector< std :: vector<double> > inputs, std :: vector< std :: vector<double> > inputs2);
        void Print(std :: vector< std :: vector<double> > inputs);

    private:


};

#endif