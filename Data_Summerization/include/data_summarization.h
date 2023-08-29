#include <bits/stdc++.h>
using namespace std;

/// @brief summarize dataset based on the measures of Central Tendency
/// @param vector reference of that dataset
/// @return central tendencies(mean, median, mode)

double calculateMean(vector<double> &x);
double calculateMedian(vector<double> &x);
vector<double> calculateMode(vector<double> &x);


double getMinimum(vector<double> &x);
double getMaximum(vector<double> &x);

/// @brief summarize dataset based on the measures of Dispersion
/// @param vector reference of that dataset
/// @return measures of Dispersion(range, variance, standard deviation)

double calculateRange(vector<double> &x);
double calculateVariance(vector<double> &x);
double calculateStandardDeviation(vector<double> &x);

void summarizeDataset(vector<double> &x,int size);

