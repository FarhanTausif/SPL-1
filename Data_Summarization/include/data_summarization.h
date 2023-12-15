#ifndef DATA_SUMMARIZATION_H
#define DATA_SUMMARIZATION_H

#include<iostream>
#include<cmath>
#include<algorithm>
#include <vector>
#include<climits>
#include<iomanip> // to use setPrecision(value)

using namespace std;

/// @brief calculates sample mean
/// @param x vector of the single-variable dataset
/// @return mean
double calculateMean(vector<double> &x);

/// @brief calculates sample median
/// @param x vector of the single-variable dataset
/// @return median
double calculateMedian(vector<double> &x);

/// @brief calculates sample mode
/// @param x vector of the single-variable dataset
/// @return mode
vector<double> calculateMode(vector<double> &x);

/// @brief find the minimum value
/// @param x vector of the single-variable dataset
/// @return minimum value
double getMinimum(vector<double> &x);

/// @brief find the maximum value
/// @param x vector of the single-variable dataset
/// @return maximum value
double getMaximum(vector<double> &x);

/// @brief calculates range
/// @param x vector of the single-variable dataset
/// @return measures of Dispersion(range, variance, standard deviation)
double calculateRange(vector<double> &x);

/// @brief calculates sample variance
/// @param x vector of the single-variable dataset
/// @return variance
double calculateVariance(vector<double> &x);

/// @brief calculates sample standard deviation
/// @param x vector of the single-variable dataset
/// @return standard deviation
double calculateStandardDeviation(vector<double> &x);

/// @brief calculates the CV
/// @param x vector of the single-variable dataset
/// @return coefficient of variation 
double calculateCoefficientOfVariation(vector<double> &x);

/// @brief calculates percentile 
/// @param x vector of the single-variable dataset
/// @param percentile 
/// @return percentileValue
double calculatePercentile(vector<double> &x, double percentile);

/// @brief calculates quartile 
/// @param x vector of the single-variable dataset 
/// @return quartiles
vector<double> calculateQuartiles(vector<double> &x);

/// @brief calculates deciles
/// @param x vector of the single-variable dataset
/// @return deciles
vector<double> calculateDeciles(vector<double> &x);

/// @brief calculates skewness of uni-modal data 
/// @param x vector of the single-variable dataset
/// @return skewness
double calculateSkewnessUsingPearsonsFirstMeasure(vector<double> &x, double mode);

/// @brief calculates skewness of multi-modal data 
/// @param x vector of the single-variable dataset
/// @return skewness
double calculateSkewnessUsingPearsonsSecondMeasure(vector<double> &x);

/// @brief Applies Empirical Rules on Normal Dataset
/// @param x vector of the single-variable dataset
void applyEmpiricalRule(vector<double> &x);

/// @brief calculates Quartile Deviation
/// @param x vector of the single-variable dataset 
/// @return Quartile Deviation
double calculateQuartileDeviation(vector<double> &x);

/// @brief calculates Coefficient Of Quartile Deviation 
/// @param x vector of the single-variable dataset
/// @return Coefficient of Quartile Deviation
double calculateCoefficientOfQuartileDeviation(vector<double> &x);

/// @brief calculates kurtosis 
/// @param x vector of the single-variable dataset
/// @return kurtosis
double calculateKurtosis(vector<double> &x);

/// @brief detect outliers based on inter quartile range
/// @param x vector of the single-variable dataset
/// @return outliers 
vector<double> detectOutliersUsingInterQuartileRange(vector<double> &x);

/// @brief calculates z-score of a given value
/// @param value any value from the dataset
/// @return z-score
double calculateZScore(double value, double mean, double standardDeviation);

/// @brief detect outliers based on z-score
/// @param x vector of the single-variable dataset
/// @return outliers  
vector<double> detectOutliersUsingZScore(vector<double> &x);


/// @brief calculates sample covariance
/// @param x vector of X variable
/// @param y vector of Y variable 
/// @return covariance
double calculateCovariance(vector<double> &x, vector<double> &y);

/// @brief calculates Pearson's corelation coefficient 
/// @param x vector of X variable
/// @param y vector of Y variable
/// @return pearson's corelation coefficient
double calculatePerasonsCorelationCoefficient(vector<double> &x, vector<double> &y);  

/// @brief calculates Cohen's d as an effect size measure
/// @param x vector of X variable
/// @param y vector of Y variable 
/// @return cohen's d
double calculateCohensD(vector <double> &x, vector<double> &y);

/// @brief calculates Hedge's g as an effect size measure
/// @param x vector of X variable
/// @param y vector of Y variable 
/// @return hedge's g
double calculateHedgesG(vector<double> &x, vector<double> &y);

/// @brief calculates z-score
/// @param xValue x value from the pair
/// @param yValue y value from the pair
/// @param Sx standard deviation of X vector
/// @param Sy standard deviation of Y vector
/// @return z-score
double calculateZScore(double xValue, double yValue, double Sx, double Sy);

/// @brief detects outliers based on z-score
/// @param x vector of X variable
/// @param y vector of Y variable 
/// @return pairedOutliers
vector<double> detectOutliersUsingZScore(vector<double> &x, vector<double> &y);

/// @brief Summarizes One-Variable dataset
/// @param x vector of the single-variable dataset
/// @param size 
void summarizeOneVariableDataset(vector<double> &x,int size);

/// @brief summarizes Two-Variable dataset
/// @param x vector of the single-variable dataset of X-Variable
/// @param y vector of the single-variable dataset of Y-Variable
/// @param size size of each vector
void summarizeTwoVariableDataset(vector<double> &x, vector<double> &y, int size);

#endif