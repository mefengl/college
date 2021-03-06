#include "Fittting.h"
double Fitting(int dimension, int numExample, double alpha, int maxLoopNum) {
    vector<double> weight(dimension, 0);

    vector<double> errors(numExample, 0);

    vector<double> x, y;
    ExampleMaker maker;
    maker.make(x, y, numExample);

    vector<Feature> z;
    TransformFeatures(x, z, dimension);

    NormalizeFeatures(z);

    vector<double> losses;
    losses.push_back(0);
    double geometricLoss = 0;
    double arithmeticLoss = 0;

    for (int time = 0; time < maxLoopNum; time++)
    {
        for (int i = 0; i < numExample; i++)
        {
            errors[i] = 0;
            for (int j = 0; j < dimension; j++)
            {
                errors[i] += weight[j] * z[i][j];
            }
            errors[i] -= y[i];
        }
        arithmeticLoss = CalcMSE(errors, true);
        geometricLoss = CalcMSE(errors, false);
        if (time % 100 == 0) {
            cout << "iter=" << time << ", geometricLoss=" << geometricLoss << endl;
            cout << "iter=" << time << ", arithmeticLoss=" << arithmeticLoss << endl;
            cout << "weight:" << endl;
            for (int i = 0; i < dimension; i++)
            {
                cout << weight[i] << ' ';
            }
            cout << endl << endl;
        }
        if (abs(geometricLoss - losses.back()) < FLT_EPSILON) break;
        losses.pop_back();
        losses.push_back(geometricLoss);


        for (int i = 0; i < dimension; i++)
        {
            double sum = 0;
            for (int j = 0; j < numExample; j++)
            {
                sum += errors[j] * z[j][i];
            }
            weight[i] = weight[i] - 2 * alpha * sum / numExample;
        }
        
    }
    return geometricLoss;
}