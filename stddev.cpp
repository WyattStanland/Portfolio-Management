#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "ann_returns.cpp"



using namespace std;

vector<double> stddev(vector<double> prices, double years, double perYear, double horizon) {

	vector<double> stockReturns;
	vector<double> periodStdDev;
	double annualizedReturn;
	double periodReturn;

	stockReturns = returns(prices, years, perYear, horizon);
	annualizedReturn = ann_returns(prices, years, perYear, horizon);

	periodReturn = pow((annualizedReturn + 1), 1/perYear) - 1;
	
	for (vector<double>::iterator it = stockReturns.begin(); it != stockReturns.end(); it++){
		periodStdDev.push_back((*it - periodReturn) * (*it - periodReturn));
	}


	return periodStdDev;
	
}
