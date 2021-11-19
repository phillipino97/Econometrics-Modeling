#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics {

    public:

        std :: vector<double> data;

        double mean, stan_error, median, mode, stan_deviation, sample_variance, kurtosis, skewness, range, min, max, summation, count;

        Statistics(std :: vector<double> data_in);
        Statistics();

        std :: vector<double> Sort(std :: vector<double> set);
        std :: vector<double> VectorSubtraction(std :: vector<double> set, double value);
        std :: vector<double> VectorSubtraction(std :: vector<double> set, std :: vector<double> set2);
        std :: vector<double> VectorAddition(std :: vector<double> set, double value);
        std :: vector<double> VectorExponent(std :: vector<double> set, int power);
        std :: vector<double> VectorDivision(std :: vector<double> set, double divisor);
        std :: vector<double> VectorMultiplication(std :: vector<double> set, double multiplier);
        std :: vector<double> VectorMultiplication(std :: vector<double> set, std :: vector<double> set2);
        double M4(std :: vector<double> set, double mean);
        double M2(std :: vector<double> set, double mean);
        double Mean(std :: vector<double> set);
        double StanError(double stan_deviation, int size);
        double Median(std :: vector<double> set);
        double Mode(std :: vector<double> set);
        double SampleVariance(std :: vector<double> set);
        double PopVariance(std :: vector<double> set);
        double SampleStanDeviation(std :: vector<double> set);
        double PopStanDeviation(std :: vector<double> set);
        double PopKurtosis(std :: vector<double> set);
        double SampleKurtosis(std :: vector<double> set);
        double Skewness(std :: vector<double> set);
        double Range(std :: vector<double> set);
        double Minimum(std :: vector<double> set);
        double Maximum(std :: vector<double> set);
        double SortMode(std :: vector<double> set);
        double SortRange(std :: vector<double> set);
        double SortMinimum(std :: vector<double> set);
        double SortMaximum(std :: vector<double> set);
        double Summation(std :: vector<double> set);
        void Print();

    private:



};

class RegressorStatistics {

    public:

    std :: vector<double> y;
    std :: vector<double> x;

    double k, r, r2, adjr2, a, b, ssr, sst, sse, msr, mse, f, dfe, dfr, se;

    RegressorStatistics(std :: vector<double> xin, std :: vector<double> yin);
    double R(std :: vector<double> x, std :: vector<double> y);
    double AdjR2(int n, int k, double r2);
    double Alpha(std :: vector<double> x, std :: vector<double> y, double b);
    double Beta(std :: vector<double> x, std :: vector<double> y);
    double SSE(std :: vector<double> x, std :: vector<double> y, double a, double b);
    double SST(std :: vector<double> y);
    double MSE(double sse, double df);
    double F(double msr, double mse);
    double FTest(double msr, double mse, double sse, int df1, int df2);
    double StandardError(std :: vector<double> y, double adjr2, int size);
    void Print();

    private:



};

#endif