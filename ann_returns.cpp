#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "returns.cpp"
#include "mean.cpp"

// This function computes the annualized return of a security over a specified time horizon

using namespace std;


double ann_returns(vector<double> prices, double years, double perYear, double horizon) {
	
	vector<double> stockReturns;
	double annualizedReturn;
	double gmean;
	char toggle = 'g';

	stockReturns = returns(prices, years, perYear, horizon);
	gmean = mean(stockReturns, toggle);

	annualizedReturn = pow((gmean + 1), perYear) - 1;

	
	return annualizedReturn;
	
}





