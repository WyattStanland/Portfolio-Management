#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include "parse_csv.cpp"
#include "ann_stddev.cpp"
#include "utils/vect_ops.cpp"


using namespace std;


vector<vector<double> > covariance_matrix (vector<string> stocks, double yearsAnnualized, double perYear, double horizon) {

	vector<vector<double> > covariance;
	vector<double> tempS;
	vector<double> covTemp;
	vector<vector<double> > tempMat;
	security parsedStock;
	string file;
	double temp;


	vect_ops<vector<double>, double, vector<double> > vect;

	for (vector<string>::iterator it = stocks.begin(); it != stocks.end(); it++) {

		file = *it;

		parsedStock = parse_csv(file);

		tempS = stddev(parsedStock.close, yearsAnnualized, perYear, horizon);
		for (vector<double>::iterator it1 = tempS.begin(); it1 != tempS.end(); it1++) {
			*it1 = pow(*it1, 0.5);
		}
		tempMat.push_back(tempS);

	}


	for (vector<vector<double> >::iterator it = tempMat.begin(); it != tempMat.end(); it++){
		covTemp.clear();
		for (vector<vector<double> >::iterator it1 = it; it1 != tempMat.end(); it1++){

			temp = 0.0;
			temp = vect.vDot(*it, *it1);
			temp = temp / (tempMat[0].size() - 1);
			temp *= sqrt(perYear);
			covTemp.push_back(temp);
		}
		covariance.push_back(covTemp);
	}

	return covariance;

}
