#ifndef ANOVA_H
#define ANOVA_H

#include <bits/stdc++.h>
using namespace std;

/// @brief reads group data from file
/// @param groups group data
void read_groups(vector<vector<double>> &groups);

/// @brief performs anova test on a group data
/// @param groups group data
void anova_test(vector<vector<double>> &groups);

#endif
