#include <iostream>
#include <vector>
#include "Statistics.hpp"
#include "Matrices.hpp"
#include "FileParse.hpp"

using namespace std;

int main() {

    vector<double> test1;
    test1.push_back(1.0);
    test1.push_back(2.0);
    vector<double> test2;
    test2.push_back(4.0);
    test2.push_back(5.0);
    vector<double> test4;
    test4.push_back(7.0);
    test4.push_back(8.0);
    vector< vector<double> > test3;
    test3.push_back(test1);
    test3.push_back(test2);
    test3.push_back(test4);

    vector<double> test5;
    vector<double> test6;
    vector<double> test7;
    test5.push_back(1.0);
    test6.push_back(2.0);
    test7.push_back(3.0);
    vector< vector<double> > test8{test5, test6};
    test8.push_back(test7);

    Matrices test0;

    /*test0.Print(test8);
    test0.Print(test3);

    vector< vector<double> > help1 = test0.Multiply(test0.Transpose(test3), test3);

    test0.Print(help1);*/

    FileParse help;

    vector<double> help_me = help.ReadCsv("test.csv");
    vector<double> constant;
    vector<double> constant1;

    for(int i = 0; i < help_me.size(); i++) {

        //cout << i << " " << help_me[i] << endl;
        constant.push_back((double) (i + 1));
        constant1.push_back(1.0);

    }

    Statistics s(help_me);
    RegressorStatistics rs(constant, help_me);

    s.Print();
    rs.Print();

    /*ahhh = test0.Transpose(ahhh);
    gahh = test0.Transpose(gahh);

    vector< vector<double> > ahhht = test0.Transpose(ahhh);
    vector< vector<double> > gahht = test0.Transpose(gahh);
    test0.Print(gahht);

    vector< vector<double> > xtxinv = test0.Inverse(test0.Multiply(gahh, gahht));
    //test0.Print(xtxinv);
    vector< vector<double> > xty = test0.Multiply(gahh, ahhht);
    vector< vector<double> > beta_hat = test0.Multiply(xtxinv, xty);

    double top = test0.Summation(test0.Multiply(test0.Multiply(test0.Transpose(beta_hat), beta_hat), test0.Multiply(gahht, gahh)));
    double bottom = test0.Summation(test0.Multiply(ahhht, ahhh));

    double r2 = top/bottom;

    cout << r2 << endl;*/

    /*Statistics test(help_me);
    
    std::cout << "Mean: " << test.mean << endl << "Mode: " << test.mode << endl << "Median: " << test.median << endl << "Standard Deviation: " << test.stan_deviation << endl;
    std::cout << "Kurtosis: " << test.kurtosis << endl << "Skewness: " << test.skewness << endl << "Standard Error: " << test.stan_error << endl;
    std::cout << "Variance: " << test.sample_variance << endl << "Range: " << test.range << endl << "Min: " << test.min << endl << "Max: " << test.max << endl << "Sum: " << test.summation << endl;
    std::cout << "Count: " << test.count << endl;*/
    

    return 1;

}