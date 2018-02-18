#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

double beta (double stockReturns, vector<double> marketReturns, double riskFree) {

	double stockBeta;

	stockBeta = (stockReturns - riskFree) / (marketReturns.front() - riskFree);

	return stockBeta;
}
