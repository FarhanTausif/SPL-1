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


double calculateCoefficientOfVariation(vector<double> &x){
    double standardDeviation = calculateStandardDeviation(x);
    double mean = calculateMean(x);
    double coefficientOfVariation = ( standardDeviation / mean ) * 100.0;
    return coefficientOfVariation;
}

double calculatePercentile(vector<double> &x, double percentile){
    double percentileValue = 0.0;
    if(percentile > 0.0 && percentile <=100.0){
        //sort
        sort(x.begin(), x.end());
        int sampleSize = x.size();
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
    return percentileValue;
}

vector<double> calculateQuartiles(vector<double> &x){
    
    vector<double> quartiles;
    quartiles.resize(3);

    double percentile;
    for(int i = 0, percentile = 25.0; i < quartiles.size(); ++i, percentile += 25.0){
        quartiles[i] = calculatePercentile(x, percentile);
    }

    return quartiles;
}

vector<double> calculateDeciles(vector<double> &x){

    vector<double> deciles;
    deciles.resize(9);
    double percentile;

    for(int i = 0, percentile = 10.0; i < deciles.size(); ++i, percentile += 10.0){
        deciles[i] = calculatePercentile(x, percentile);
    }

    return deciles; 
}

vector<double> detectOutliersUsingInterQuartileRange(vector<double>& x){
    
    vector<double> outliersUsingInterQuartileRange;

    vector<double> quartiles = calculateQuartiles(x);
    double q1 = quartiles[0];
    double q3 = quartiles[2];

    double interQuartileRange = q3 - q1;
    double lowerBound = q1 - 1.5 * interQuartileRange;
    double upperBound = q3 + 1.5 * interQuartileRange;
    
    for (double value : x) {
        if (value < lowerBound || value > upperBound) {
            outliersUsingInterQuartileRange.push_back(value);
        }
    }
    
    return outliersUsingInterQuartileRange;
}

double calculateZScore(double value, double mean, double standardDeviation){
    double zScore = (value - mean) / standardDeviation;
    return zScore;
}

vector<double> detectOutliersUsingZScore(vector<double> &x){
    
    vector<double> outliersUsingZScore; 
    double mean;
    double standardDeviation;
    double zScore;
    double thresholdStdDevUnit = 3.0;
    
    mean = calculateMean(x);
    standardDeviation = calculateStandardDeviation(x);

    for(double value : x){
        zScore = calculateZScore(value, mean, standardDeviation);  
        if(zScore > thresholdStdDevUnit){
            outliersUsingZScore.push_back(value);
        }
    }

    return outliersUsingZScore;
}


double calculateSkewnessUsingPearsonsFirstMeasure(vector<double> &x, double mode){
    double skewness;
    double mean = calculateMean(x);
    double standardDeviation = calculateStandardDeviation(x);
    skewness = (mean - mode)/standardDeviation; 
    return skewness;
}

double calculateSkewnessUsingPearsonsSecondMeasure(vector<double> &x){
    double skewness;
    double mean = calculateMean(x);
    double median = calculateMedian(x);
    double standardDeviation = calculateStandardDeviation(x);
    skewness = (3 * (mean - median))/standardDeviation; 
    return skewness;
}

double calculateQuartileDeviation(vector<double> &x){
    double quartileDeviation;
    vector<double> quartiles = calculateQuartiles(x);
    double q1 = quartiles[0];
    double q3 = quartiles[2];
    quartileDeviation = (q3 - q1)/2.0;
    return quartileDeviation;
}

double calculateKurtosis(vector<double> &x){
    double kurtosis;
    double quartileDeviation = calculateQuartileDeviation(x);
    double p90 = calculatePercentile(x, 90.0);
    double p10 = calculatePercentile(x, 10.0);
    kurtosis = quartileDeviation / (p90 - p10);
    return kurtosis;
}


void summarizeOneVariableDataset(vector<double> &x,int size){

    double mean = calculateMean(x);
    double median = calculateMedian(x);
    vector<double>modes = calculateMode(x);
    double range = calculateRange(x);
    double variance = calculateVariance(x);
    double standardDeviation = calculateStandardDeviation(x);
    double coefficientOfVariation = calculateCoefficientOfVariation(x);
    vector<double> quartiles = calculateQuartiles(x);
    vector<double> deciles = calculateDeciles(x);
    vector<double> outliersUsingInterQuartileRange = detectOutliersUsingInterQuartileRange(x);
    vector<double> outliersUsingZScore = detectOutliersUsingZScore(x);
    double skewness;
    if(modes.size() == 1){
        skewness = calculateSkewnessUsingPearsonsFirstMeasure(x, modes[0]);
    }
    else{
        skewness = calculateSkewnessUsingPearsonsSecondMeasure(x);
    }
    double kurtosis = calculateKurtosis(x);

    setprecision(4);
    cout << "\n::::Summary based on Measures of Central Tendency::::" << endl;
    cout << "Sample Mean: " << mean << endl;
    cout << "Sample Median: " << median << endl;

    if(!modes.empty()){
        
        cout << "Sample Mode(s): ";
        for(double mode : modes){
            cout << mode << " ";
        }
        cout << endl;

        if(modes.size() == 1){
            cout << "The Dataset is Uni-modal" << endl;
        }
        else if(modes.size() == 2){
            cout << "The Dataset is Bi-modal" << endl;
        }
        else{
            cout << "The Dataset is Tri-modal" << endl;
        }

    }
    else{
        cout << "No modes!" << endl;
    }

    cout << endl << endl;
    
    cout << "::::Summary based on Measures of Dispersion::::" << endl;
    cout << "Range of the dataset: " << range << endl; 
    cout << "Sample Variance: " << variance << endl;
    cout << "Sample Std. Deviation: " << standardDeviation << endl;
    cout << "Minimum data point: " << getMinimum(x) << endl; 
    cout << "Quartiles:" << endl;
    cout << "Lower Quartile, Q1 = " << quartiles[0] << "  Middle Quartile, Q2 = " << quartiles[1] << "  Upper Quartile, Q3 = " << quartiles[2] << endl;
    cout << "Maximum data point:" << getMaximum(x) << endl;
    cout << "Deciles:" << endl;
    for(double decile: deciles){
        cout << decile << " ";
    }
    
    cout << endl << endl;

    cout << "::::Measures of Asymmetry & Tails heaviness or lightness compared to normal distribution::::" << endl;
    if(skewness > -0.5 && skewness < 0.5){
        cout << "The dataset is nearly symmetrical" << endl;
    }
    else if(skewness > -1.0 && skewness < -0.5){
        cout << "The dataset is slightly negatively skewed!" << endl;
    }
    else if(skewness > 0.5 && skewness < 1.0){
        cout << "The dataset is slightly positively skewed!" << endl;
    }
    else if(skewness < -1.0){
        cout << "The dataset is extremely negatively skewed!" << endl;
    }
    else if(skewness > 1.0){
        cout << "The dataset is extremely positively skewed!" << endl;
    }

    if(kurtosis > 2.8 && kurtosis < 3.2){
        cout << "The distribution of the dataset is: Mesokurtic(Normal Distribution)" << endl;
    }
    else if(kurtosis > 3.2){
        cout << "The distribution of the dataset is: Leptokurtic(Long tailed distribution :: higher outliers)" << endl;
    }
    else if(kurtosis < 2.8){
        cout << "The distribution of the dataset is: Platykurtic(short tailed distribution :: fewer outliers)" << endl;
    }

    cout << endl;

    cout << "::::Outlier Detection::::" << endl;
    cout << "Outliers(" << outliersUsingInterQuartileRange.size() << " values)" << " Using inter quartile range:"   << endl;
    if(outliersUsingInterQuartileRange.empty()){
        cout << "No outliers detected using IQR method!" << endl;
    }
    else{
        for(double outlier : outliersUsingInterQuartileRange){
            cout << outlier << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Outliers(" << outliersUsingZScore.size() << " values)" << " Using z-score:"   << endl;
    if(outliersUsingZScore.empty()){
        cout << "No outliers detected using z-score method!" << endl;
    }
    else{
        for(double outlier : outliersUsingZScore){
            cout << outlier << " ";
        }
        cout << endl;
    }
}