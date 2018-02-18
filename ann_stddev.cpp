#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "stddev.cpp"

using namespace std;

double ann_stddev (vector<double> prices, double years, double perYear, double horizon){

	double annualizedStdDev;
	double stdDev;
	char toggle = 'a';
	vector<double> stockStdDev;


	stockStdDev = stddev(prices, years, perYear, horizon);
	stdDev = mean(stockStdDev, toggle);
	annualizedStdDev = stdDev * sqrt(perYear);


	return 100 * annualizedStdDev;
}
