#include "FeaturesFunc.h"
void CalcMeanAndVariance(const vector<double>& x,
    double& sampleMean, double& sampleVar) {
    int num = x.size();
    for (int i = 1; i < num; ++i) {
        sampleMean += x[i];
        sampleVar += x[i] * x[i];
    }
    num--;
    sampleMean /= num;
    sampleVar = sqrt(sampleVar / num - sampleMean * sampleMean);  // DX = EX^2 - (EX)^2
}

void NormalizeFeature(vector<double>& x) {
    const static double epsilon = 1e-5;
    double miu = 0, std = 0;
    CalcMeanAndVariance(x, miu, std);
    for (int i = 1; i < x.size(); ++i) {
        x[i] -= miu; // 减去均值
        x[i] /= (std + epsilon); // 除上标准差，做标准化
    }
}

typedef vector<double> Feature;
void NormalizeFeatures(vector<Feature>& z) {
    for (int i = 0; i < z.size(); ++i) {
        NormalizeFeature(z[i]);
    }
}

void TransformFeature(double x, vector<double>& z, int dim) {
    z.resize(dim, 0);
    z[0] = 1;
    for (int i = 1; i < dim; ++i) {
        z[i] = z[i - 1] * x;
    }
}


void TransformFeatures(const vector<double>& x,
    vector<Feature>& Z, int dimension) {
    int numExamples = x.size();
    Feature tempZ;
    Z.clear();
    for (int i = 0; i < numExamples; ++i) {
        TransformFeature(x[i], tempZ, dimension); // tempZ: 1, x, x^2, x^3...x^dim
        Z.push_back(tempZ);
    }
}

double CalcMSE(const vector<double>& errors, bool isArithmetic) {
    double mse = 0;
    for (int i = 0; i < errors.size(); ++i) {
        double err = errors[i];
        
        if (isArithmetic) {
            mse += err;
        }
        else {
            mse += err * err;
        }
        
    }
    mse /= errors.size();
    return mse;
}