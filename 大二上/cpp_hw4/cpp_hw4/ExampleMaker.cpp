#include "ExampleMaker.h"
void ExampleMaker::make(vector<double>& x, vector<double>& y, int numExample)
{
	default_random_engine generator;
	uniform_real_distribution<double> uniDistribution(-5, 5);
	normal_distribution<double> gaussDistribution(-0.1, 0.1);

	x.clear();
	y.clear();
	for (int i = 0; i < numExample; ++i) {
		double input = uniDistribution(generator);
		double noise = gaussDistribution(generator);
		x.push_back(input);
		y.push_back(f(input) + noise);
	}
}

inline double ExampleMaker::f(double x)
{
	return 1 - 2 * x + 3 * x * x + 4 * x * x * x * x;
}