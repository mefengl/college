#ifndef HW4_EXAMPLEMAKER_H
#define HW4_EXAMPLEMAKER_H
#include<random>
#include<vector>
using namespace std;

class ExampleMaker
{
public:
	void make(vector<double>& x, vector<double>& y, int numExample);
private:
	inline double f(double x);
};

#endif