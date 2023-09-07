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

/// @brief calculates the CV
/// @param x vector of the dataset
/// @return coefficient of variation 
double calculateCoefficientOfVariation(vector<double> &x);

/// @brief calculate percentile 
/// @param x vector of the dataset
/// @param percentile 
/// @return percentileValue
double calculatePercentile(vector<double> &x, double percentile);

/// @brief calculate quartile 
/// @param x vector of the dataset 
/// @return quartiles
vector<double> calculateQuartiles(vector<double> &x);

/// @brief calculate deciles
/// @param x vector of the dataset
/// @return deciles
vector<double> calculateDeciles(vector<double> &x);

/// @brief calculates skewness of uni-modal data 
/// @param x vector of the dataset
/// @return skewness
double calculateSkewnessUsingPearsonsFirstMeasure(vector<double> &x, double mode);

/// @brief calculates skewness of multi-modal data 
/// @param x vector of the dataset
/// @return skewness
double calculateSkewnessUsingPearsonsSecondMeasure(vector<double> &x);

/// @brief calculates Quartile Deviation
/// @param x vector of the dataset 
/// @return Quartile Deviation
double calculateQuartileDeviation(vector<double> &x);

/// @brief calculates kurtosis 
/// @param x vector of the dataset
/// @return kurtosis
double calculateKurtosis(vector<double> &x);

/// @brief detect outliers based on inter quartile range, if the dataset has any
/// @param x vector of the dataset
/// @return outliers 
vector<double> detectOutliersUsingInterQuartileRange(vector<double> &x);

/// @brief calculates z-score of a given value
/// @param value any value from the dataset
/// @return z-score
double calculateZScore(double value, double mean, double standardDeviation);

/// @brief detect outliers based on z-statistic, if the dataset has any
/// @param x vector of the dataset
/// @return outliers  
vector<double> detectOutliersUsingZScore(vector<double> &x);

/// @brief Summarizes One-Variable dataset
/// @param x vector of the dataset
/// @param size 
void summarizeOneVariableDataset(vector<double> &x,int size);

/// @brief summarizes Two-Variable dataset
/// @param x vector of the dataset of X-Variable
/// @param y vector of the dataset of Y-Variable
/// @param size 
void summarizeTwoVariableDataset(vector<double> &x, vector<double> &y, int size);