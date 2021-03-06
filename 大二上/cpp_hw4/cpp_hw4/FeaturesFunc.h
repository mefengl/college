#ifndef HW4_FEATURESFUNC_H
#define HW4_FEATURESFUNC_H
#include<vector>
using namespace std;

void CalcMeanAndVariance(const vector<double>& x,
    double& sampleMean, double& sampleVar);

void NormalizeFeature(vector<double>& x);

typedef vector<double> Feature;
void NormalizeFeatures(vector<Feature>& z);

void TransformFeature(double x, vector<double>& z, int dim);

void TransformFeatures(const vector<double>& x,
    vector<Feature>& Z, int dimension);

double CalcMSE(const vector<double>& errors, bool isArithmetic);

#endif