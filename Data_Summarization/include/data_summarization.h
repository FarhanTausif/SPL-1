#include <bits/stdc++.h>
using namespace std;

/// @brief summarize dataset based on the measures of Central Tendency
/// @param x vector of the dataset
/// @return mean
double calculateMean(vector<double> &x);

/// @brief summarize dataset based on the measures of Central Tendency
/// @param x vector of the dataset
/// @return median
double calculateMedian(vector<double> &x);

/// @brief summarize dataset based on the measures of Central Tendency
/// @param x vector of the dataset
/// @return mode
vector<double> calculateMode(vector<double> &x);

/// @brief find the minimum value
/// @param x vector of the dataset
/// @return minimum value
double getMinimum(vector<double> &x);


/// @brief find the maximum value
/// @param x vector of the dataset
/// @return maximum value
double getMaximum(vector<double> &x);

/// @brief summarize dataset based on the measures of Dispersion
/// @param x vector of the dataset
/// @return measures of Dispersion(range, variance, standard deviation)
double calculateRange(vector<double> &x);

/// @brief summarize dataset based on the measures of Dispersion
/// @param x vector of the dataset
/// @return variance
double calculateVariance(vector<double> &x);

/// @brief summarize dataset based on the measures of Dispersion
/// @param x vector of the dataset
/// @return standard deviation

double calculateStandardDeviation(vector<double> &x);

/// @brief calculate percentile 
/// @param x vector of the dataset
/// @param percentile 
/// @return percentileValue
double calculatePercentile(vector<double> &x, double percentile);

/// @brief calculate percentile 
/// @param x vector of the dataset 
/// @return quartiles
vector<double> calculateQuartiles(vector<double> &x);

/// @brief detect outliers if the dataset has any
/// @param x vector of the dataset
/// @return outliers 
vector<double> detectOutliers(vector<double>& x);

/// @brief Summarize the dataset
/// @param x 
/// @param size
void summarizeDataset(vector<double> &x,int size);

