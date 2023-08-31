#include "../include/data_summarization.h"

double calculateMean(vector<double> &x){

    double sum = 0.0;
    int sampleSize  = x.size();
    double mean;
    
    for(double value : x){
        sum += value;
    }

    mean = sum/sampleSize;
    
    return mean;
}

double calculateMedian(vector<double> &x){

    int sampleSize = x.size();
    double median;

    //sort
    sort(x.begin(), x.end());

    // sampleSize & 1  = 1 --> odd
    if(sampleSize & 1){
        median = x[sampleSize/2];
    }
    else{
        median = ( x[sampleSize/2 - 1] + x[sampleSize/2] ) / 2.0;
    }
    
    return median;
}

vector<double> calculateMode(vector<double> &x){
    
    vector<double> modes;
    int maxFrequency = 0, frequency;
    bool hasModes = false;

    for(int i = 0; i < x.size();++i){
        frequency = 0;

        //checking if the value has already been counted as a mode
        for(double value : modes){
            if(value == x[i]){
                continue;
            }
        }
        
        for(int j = i+1; j < x.size(); ++j){
            if(x[i] == x[j]){
                ++frequency;
            }
        }

        if(frequency > maxFrequency){
            maxFrequency = frequency;
            modes.clear();
            modes.push_back(x[i]);
            hasModes = true;
        }
        else if(frequency == maxFrequency){
            modes.push_back(x[i]);
        }
    }

    if(!hasModes){
        modes.clear();
    }

    return modes;
}

double getMinimum(vector<double> &x){
    
    double min = INT_MAX - 0.1;

    for(double value : x){
        if(value < min){
            min = value;
        }
    }

    return min;
}

double getMaximum(vector<double> &x){

    double max = INT_MIN + 0.1;

    for(double value : x){
        if(value > max){
            max = value;
        }
    }
    
    return max;
}

double calculateRange(vector<double> &x){
    
    double maxValue = getMaximum(x); 
    double minValue = getMinimum(x);
    double range = (maxValue-minValue);
    
    return range;
}

double calculateVariance(vector<double> &x){
    
    int sampleSize = x.size();
    double mean = calculateMean(x);
    double sumSquaredValues = 0.0; 
    double variance;

    for(double value : x){
        sumSquaredValues += value * value;
    }

    variance = (sumSquaredValues - (sampleSize * mean * mean) )/ (sampleSize - 1);

    return variance;
}

double calculateStandardDeviation(vector<double> &x){

    double variance = calculateVariance(x);
    double standardDeviation = sqrt(variance);

    return standardDeviation;
}


double calculatePercentile(vector<double> &x, double percentile){
    //sort
    sort(x.begin(), x.end());
    int sampleSize = x.size();
    double percentileValue;
    double rank = (sampleSize + 1) * (percentile / 100.0);
    //check whether rank is a whole number or not 
    if(rank - floor(rank) == 0.0){
        percentileValue = x[rank-1];
    }
    else{
        percentileValue = (x[rank-1] + x[rank]) / 2.0;
    }

    return percentileValue;
}

vector<double> calculateQuartiles(vector<double> &x){
    
    vector<double> quartiles;
    quartiles.resize(3);

    quartiles[0] = calculatePercentile(x, 25.0);
    quartiles[1] = calculatePercentile(x, 50.0);
    quartiles[2] = calculatePercentile(x, 75.0);

    return quartiles;
}

vector<double> detectOutliers(vector<double>& x){
    
    vector<double> outliers;
    double q1 = calculatePercentile(x, 25.0);
    double q3 = calculatePercentile(x, 75.0);
    
    // Calculate Inter-Quartile Range(IQR)
    double IQR = q3 - q1;
    
    // Define lower and upper bounds for outliers
    double lowerBound = q1 - 1.5 * IQR;
    double upperBound = q3 + 1.5 * IQR;
    
    // Detect outliers
    for (double value : x) {
        if (value < lowerBound || value > upperBound) {
            outliers.push_back(value);
        }
    }
    
    return outliers;
}


void summarizeDataset(vector<double> &x,int size){
    
    double mean = calculateMean(x);
    double median = calculateMedian(x);
    vector<double>modes = calculateMode(x);
    double range = calculateRange(x);
    double variance = calculateVariance(x);
    double standardDeviation = calculateStandardDeviation(x);
    vector<double> quartiles = calculateQuartiles(x);
    vector<double> outliers = detectOutliers(x);

    setprecision(4);
    //cout << setprecision(4) << endl;
    cout << "\n::::Summary based on Measures of Central Tendency::::" << endl;
    cout << "Sample Mean: " << mean << endl;
    cout << "Sample Median: " << median << endl;

    if(!modes.empty()){
        cout << "Sample Mode(s): ";
        for(double mode : modes){
            cout << mode << " ";
        }
        cout << endl;
    }
    else{
        cout << "No modes!" << endl;
    }

    cout << endl << endl;
    
    cout << "::::Summary based on Measures of Disperse::::" << endl;
    cout << "Range of the dataset: " << range << endl; 
    cout << "Sample Variance: " << variance << endl;
    cout << "Sample Std. Deviation: " << standardDeviation << endl;
    cout << "Quartiles:" << endl;
    cout << "Q1 = " << quartiles[0] << " Q2 = " << quartiles[1] << " Q3 = " << quartiles[2] << endl;

    cout << "Outliers:" << endl;

    if(outliers.empty()){
        cout << "No outliers detected!" << endl;
    }
    else{
        for(double outlier : outliers){
            cout << outlier << " ";
        }
        cout << endl;
    }
}