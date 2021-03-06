#include "Fittting.h"
int main() {
    int dimension = 5;
    int numExample = 1;
    double alpha = 0.003;
    int maxLoopNum = 100000;
    cout << "geometricLoss: " << Fitting(dimension, numExample, alpha, maxLoopNum) << endl;
    return 0;
}