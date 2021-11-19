#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
//TODO: Delete the algorithm include after implementing merge sort
#include <algorithm>
#include "Statistics.hpp"

using namespace std;

vector<double> data;

double mean, stan_error, median, mode, stan_deviation, sample_variance, kurtosis, skewness, range, min, max, summation, count;

Statistics :: Statistics(vector<double> data_in) : data(data_in) {

    data = Sort(data);
    count = data.size();
    mean = Mean(data);
    median = Median(data);
    mode = Mode(data);
    stan_deviation = SampleStanDeviation(data);
    sample_variance = SampleVariance(data);
    stan_error = StanError(stan_deviation, count);
    kurtosis = SampleKurtosis(data);
    skewness = Skewness(data);
    range = Range(data);
    min = Minimum(data);
    max = Maximum(data);
    summation = Summation(data);

}

Statistics :: Statistics() {



}

vector<double> Statistics :: Sort(vector<double> set) {

    //TODO: Switch this to a merge sort algorithm
    sort(set.begin(), set.end());

    return set;

}

vector<double> Statistics :: VectorSubtraction(vector<double> set, double value) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(set[i] - value);

    }

    return result;

}

vector<double> Statistics :: VectorSubtraction(vector<double> set, vector<double> set2) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(set[i]-set2[i]);

    }

    return result;

}

vector<double> Statistics :: VectorAddition(vector<double> set, double value) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(set[i] + value);

    }

    return result;

}

vector<double> Statistics :: VectorExponent(vector<double> set, int power) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(pow(set[i], power));

    }

    return result;

}

vector<double> Statistics :: VectorDivision(vector<double> set, double divisor) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(set[i]/divisor);

    }

    return result;

}

vector<double> Statistics :: VectorMultiplication(vector<double> set, double multiplier) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(set[i]*multiplier);

    }

    return result;

}

vector<double> Statistics :: VectorMultiplication(vector<double> set, vector<double> set2) {

    if(set.size() < 1) {
        vector<double> bad;
        bad.push_back(-1.0);
        return bad;
    }

    vector<double> result;

    for(int i = 0; i < set.size(); i++) {

        result.push_back(set[i]*set2[i]);

    }

    return result;

}

double Statistics :: M4(vector<double> set, double mean) {

    if(set.size() < 1) {
        return -1;
    }

    vector<double> m4;
    double result_m4 = 0.0;

    m4 = VectorSubtraction(set, mean);
    m4 = VectorExponent(m4, 4);
    result_m4 = Summation(m4);

    return result_m4/set.size();

}

double Statistics :: M2(vector<double> set, double mean) {

    if(set.size() < 1) {
        return -1;
    }

    vector<double> m2;
    double result_m2 = 0.0;

    m2 = VectorSubtraction(set, mean);
    m2 = VectorExponent(m2, 2);
    result_m2 = Summation(m2);

    return result_m2/set.size();

}

double Statistics :: Mean(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double total = 0.0;

    for(int i = 0; i < set.size(); i++) {
        total += set[i];
    }

    return total/set.size();

}

double Statistics :: StanError(double stan_deviation, int size) {

    return (stan_deviation/sqrt(size));

}

double Statistics :: Median(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double median = 0.0;

    if(set.size() % 2 == 0) {

        int half = set.size()/2;
        median = (set[half] + set[half + 1])/2;

    } else {

        int half = ceil(set.size()/2);
        median = set[half];

    }

    return median;

}

double Statistics :: Mode(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double curr_mode = -1.0;
    double placeholder_mode = -1.0;
    int curr_occur = 0;
    int placeholder_occur = 0;

    for(int i = 0; i < set.size(); i++) {

        if(i == 0) {

            curr_mode = set[i];
            curr_occur += 1;

        } else {

            if(set[i] == curr_mode) {

                curr_occur += 1;

            } else if(set[i] == placeholder_mode) {

                placeholder_occur += 1;

            } else {

                placeholder_mode = set[i];
                placeholder_occur = 1;

            }

            if(placeholder_occur > curr_occur) {

                curr_mode = placeholder_mode;
                curr_occur = placeholder_occur;
                placeholder_mode = -1.0;
                placeholder_occur = 0;

            }

        }

    }

    if(curr_occur <= 1) {
        return -1.0;
    }

    return curr_mode;

}

double Statistics :: SampleVariance(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    int count = set.size();
    double summation = Summation(set);
    double mean = Mean(set);
    vector<double> differences = VectorSubtraction(set, mean);
    vector<double> differences_square = VectorExponent(differences, 2);
    double sum_diff_square = Summation(differences_square);

    double variance = sum_diff_square/(count - 1);

    return variance;        

}

double Statistics :: PopVariance(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    int count = set.size();
    double summation = Summation(set);
    double mean = Mean(set);
    vector<double> differences = VectorSubtraction(set, mean);
    vector<double> differences_square = VectorExponent(differences, 2);
    double sum_diff_square = Summation(differences_square);

    double variance = sum_diff_square/count;

    return variance;        

}

double Statistics :: SampleStanDeviation(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double stan_deviation = sqrt(SampleVariance(set));

    return stan_deviation;

}

double Statistics :: PopStanDeviation(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double stan_deviation = sqrt(PopVariance(set));

    return stan_deviation;

}

double Statistics :: PopKurtosis(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    int count = set.size();
    double mean = Mean(set);
    double m4 = M4(set, mean);
    double m2 = M2(set, mean);

    return count*(m4/pow(m2, 2));

}

double Statistics :: SampleKurtosis(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    int count = set.size();
    double mean = Mean(set);
    double m4 = M4(set, mean);
    double m2 = pow(M2(set, mean), 2);

    double k = m4/m2;

    return (k - 3.0);

}

double Statistics :: Skewness(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double skew = 0.0;

    vector<double> second = VectorSubtraction(set, mean);
    second = VectorDivision(second, SampleStanDeviation(set));
    second = VectorExponent(second, 3);
    double second_dub = Summation(second);

    double first = (double) set.size()/(((double) set.size() - 1)*((double) set.size() - 2));

    skew = first*second_dub;

    return skew;

}

double Statistics :: Range(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    return set[set.size() - 1] - set[0];

}

double Statistics :: Minimum(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    return set[0];

}

double Statistics :: Maximum(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    return set[set.size() - 1];

}

double Statistics :: SortMode(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    set = Sort(set);

    double curr_mode = -1.0;
    double placeholder_mode = -1.0;
    int curr_occur = 0;
    int placeholder_occur = 0;

    for(int i = 0; i < set.size(); i++) {

        if(i == 0) {

            curr_mode = set[i];
            curr_occur += 1;

        } else {

            if(set[i] == curr_mode) {

                curr_occur += 1;

            } else if(set[i] == placeholder_mode) {

                placeholder_occur += 1;

            } else {

                placeholder_mode = set[i];
                placeholder_occur = 1;

            }

            if(placeholder_occur > curr_occur) {

                curr_mode = placeholder_mode;
                curr_occur = placeholder_occur;
                placeholder_mode = -1.0;
                placeholder_occur = 0;

            }

        }

    }

    return curr_mode;
}

double Statistics :: SortRange(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    vector<double> sorted = Sort(set);
    return sorted[sorted.size() - 1] - sorted[0];

}

double Statistics :: SortMinimum(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    vector<double> sorted = Sort(set);
    return sorted[0];

}

double Statistics :: SortMaximum(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    vector<double> sorted = Sort(set);
    return sorted[set.size() - 1];

}

double Statistics :: Summation(vector<double> set) {

    if(set.size() < 1) {
        return -1.0;
    }

    double total = 0.0;

    for(int i = 0; i < set.size(); i++) {
        total += set[i];
    }

    return total;

}

void Statistics :: Print() {

    cout << endl << "Statistics" << endl;
    cout << "---------------------------------------" << endl;
    cout << right;
    cout << "| Mean: " << setw(30) << mean << "|" << endl;
    cout << "| Stn. Err: " << setw(26) << stan_error << "|" << endl;
    cout << "| Median: " << setw(28) << median << "|" << endl;
    cout << "| Mode: " << setw(30) << mode << "|" << endl;
    cout << "| Stn. Dev: " << setw(26) << stan_deviation << "|" << endl;
    cout << "| Sam. Var: " << setw(26) << sample_variance << "|" << endl;
    cout << "| Kurtosis: " << setw(26) << kurtosis << "|" << endl;
    cout << "| Skewness: " << setw(26) << skewness << "|" << endl;
    cout << "| Range: " << setw(29) << range << "|" << endl;
    cout << "| Minimum: " << setw(27) << min << "|" << endl;
    cout << "| Maximum: " << setw(27) << max << "|" << endl;
    cout << "| Sum: " << setw(31) << summation << "|" << endl;
    cout << "| count: " << setw(29) << count << "|" << endl;
    cout << "---------------------------------------" << endl;

}

// mean, stan_error, median, mode, stan_deviation, sample_variance, kurtosis, skewness, range, min, max, summation, count;

vector<double> x;
vector<double> y;

double k, r, r2, adjr2, a, b, ssr, sst, sse, msr, mse, f, dfe, dfr, se;

RegressorStatistics :: RegressorStatistics(vector<double> xin, vector<double> yin) {

    k = 1;
    x = xin;
    y = yin;
    r = R(x, y);
    r2 = pow(r, 2);
    adjr2 = AdjR2(y.size(), k, r2);
    se = StandardError(y, adjr2, y.size());
    b = Beta(x, y);
    a = Alpha(x, y, b);
    sse = SSE(x, y, a, b);
    sst = SST(y);
    ssr = sst - sse;
    msr = ssr;
    mse = MSE(sse, (y.size() - k - 1));
    f = F(msr, mse);

}

double RegressorStatistics :: R(vector<double> x, vector<double> y) {

    Statistics stats;

    double top = (y.size()*(stats.Summation(stats.VectorMultiplication(x, y)))) - (stats.Summation(x)*stats.Summation(y));
    double bottom = sqrt(((y.size()*stats.Summation(stats.VectorExponent(x, 2))) - pow(stats.Summation(x), 2))*((y.size()*stats.Summation(stats.VectorExponent(y, 2))) - pow(stats.Summation(y), 2)));

    return top/bottom;

}

double RegressorStatistics :: AdjR2(int n, int k, double r2) {

    return 1 - (((1 - r2)*(n - 1))/(n - k - 1));

}

double RegressorStatistics :: StandardError(vector<double> y, double adjr2, int size) {

    Statistics y_stats(y);

    return sqrt(1 - adjr2)*(y_stats.stan_deviation);

}

double RegressorStatistics :: Alpha(vector<double> x, vector<double> y, double b) {

    Statistics y_stats(y);
    Statistics x_stats(x);
    Statistics stats;

    //return stats.Summation(stats.VectorSubtraction(y, stats.VectorMultiplication(x, b)));
    return y_stats.mean - (b*x_stats.mean);

}

double RegressorStatistics :: Beta(vector<double> x, vector<double> y) {

    Statistics y_stats(y);
    Statistics x_stats(x);
    Statistics stats;

    double top = stats.Summation(stats.VectorMultiplication(stats.VectorSubtraction(y, y_stats.mean), stats.VectorSubtraction(x, x_stats.mean)));
    double bottom = stats.Summation(stats.VectorExponent(stats.VectorSubtraction(x, x_stats.mean), 2));

    return top/bottom;

}

double RegressorStatistics :: SSE(vector<double> x, vector<double> y, double a, double b) {

    Statistics stats;

    return stats.Summation(stats.VectorExponent(stats.VectorSubtraction(y, stats.VectorAddition(stats.VectorMultiplication(x, b), a)), 2));

}

double RegressorStatistics :: SST(vector<double> y) {

    Statistics y_stats(y);
    Statistics stats;

    return stats.Summation(stats.VectorExponent(stats.VectorSubtraction(y, y_stats.mean), 2));

}

double RegressorStatistics :: MSE(double sse, double df) {

    return sse/df;

}

double RegressorStatistics :: F(double msr, double mse) {

    return msr/mse;

}

void RegressorStatistics :: Print() {
    
    cout << endl << "Regression Statistics" << endl;
    cout << "--------------------------" << endl;
    cout << right;
    cout << "| R: " << setw(20) << r << "|" << endl;
    cout << "| R2: " << setw(19) << r2 << "|" << endl;
    cout << "| Adjusted R2: " << setw(10) << adjr2 << "|" << endl;
    cout << "| Stn Err: " << setw(14) << se << "|" << endl;
    cout << "| Count: " << setw(16) << y.size() << "|" << endl;
    cout << "--------------------------" << endl;
    cout << "ANOVA" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(15) << "|" << setw(15) << "|     DF" << setw(15) << "|     SS" << setw(15) << "|     MS" << setw(15) << "|      F" << setw(15) << "|    Sig F" << "|" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "| Regression" << "|";
    cout << right;
    cout << setw(13) << k << " |" << setw(13) << ssr << " |" << setw(13) << msr << " |" << setw(13) << f << " |" << setw(13) << "Not here" << " |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(15) << "| Errors" << "|";
    cout << right;
    cout << setw(13) << y.size() - k - 1 << " |" << setw(13) << sse << " |" << setw(13) << mse << " |" << setw(13) << "" << " |" << setw(13) << "" << " |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(15) << "| Total" << "|";
    cout << right;
    cout << setw(13) << y.size() - 1 << " |" << setw(13) << sst << " |" << setw(13) << "" << " |" << setw(13) << "" << " |" << setw(13) << "" << " |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "ALPHA/BETA" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(15) << "|" << setw(15) << "| Coefficients" << setw(15) << "|   Stn. Err." << setw(15) << "|    t stat" << setw(15) << "|   P-value" << setw(15) << "|    Low 95%" << setw(15) << "|     Up 95%" << setw(15) << "|   Low 95.0%" << setw(15) << "|   Up 95.0%" << "|" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "| Intercept" << "|";
    cout << right;
    cout << setw(13) << a << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(15) << "| X Var. 1" << "|";
    cout << right;
    cout << setw(13) << b << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << setw(13) << "Not here" << " |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

}