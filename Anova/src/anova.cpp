#ifndef ANOVA_CPP
#define ANOVA_CPP

#include <bits/stdc++.h>
#include "../include/anova.h"
#include "../../Hypothesis_Testing/src/hypothesis_testing.cpp"

void read_groups(vector<vector<double>> &groups){
    ifstream input;
    input.open("anova.txt");
    string str;
    string tmp;
    vector<double> row;
    while(input.peek() != EOF){
        str.clear();
        getline(input, tmp, '\n');
        for(auto c : tmp){
            if(c != ' '){
                str += c;
            }else{
                row.push_back(stod(str));
                str.clear();
            }
        }
        row.push_back(stod(str));
        groups.push_back(row);
        row.clear();
    }
}

void anova_test(vector<vector<double>> &groups){
    double overall_mean = 0.0;
    double sum = 0.0;
    int m = groups.size();
    int n = groups[0].size();
    int total = m * n;
    for(auto row : groups){
        for(auto val : row){
            sum += val;
        }
    }
    overall_mean = sum / total;
    vector<double> group_specific_mean;
    
    for(int i = 0; i <  n; ++i){
        sum = 0.0;
        for(int j = 0; j < m; ++j){
            sum += groups[j][i];
        }
        group_specific_mean.push_back(sum/m);
    }

    double SSb;
    double between_grp_ss = 0.0;
    for(auto mu : group_specific_mean){
        between_grp_ss += pow((mu - overall_mean),2);
    }
    SSb = n * between_grp_ss;

    double SSw;
    double within_grp_ss = 0.0;

    for(auto grp : groups){
        for(auto val : grp){
            within_grp_ss += pow((val - overall_mean),2);
        }
    }

    SSw = within_grp_ss - SSb;

    double MSb;
    double MSw;

    MSb = SSb / (m - 1);
    MSw = SSw / (total - m);

    double f_statistic = MSb / MSw;
    double f_alpha = calculateFAlpha((total - m), (m-1));

    cout << "F Statistic: " << f_statistic << endl;
    cout << "Critical value: " << f_alpha << endl;
    
    if(f_statistic < f_alpha){
        cout << "We fail to reject the null hypothesis that all the groups have the mean!" << endl;
    }else{
        cout << "We can reject the null hypothesis that all the groups have the mean!" << endl;
    }
}

#endif