#include <cstdio>
#include <iostream>
#include <vector>
#include "beta.cpp"
#include "covariance_matrix.cpp"
//#include "proportions.cpp"



using namespace std;


struct securityAttributes {

	vector<string> sSymbol;
	vector<double> returns_i;
	vector<double> stddev_i;
	vector<double> beta_i;
	vector<vector<double> > covariance;

	vector<string> mSymbol;
	vector<double> returns_m;
	vector<double> stddev_m;
	


};


securityAttributes build_portfolio(vector<string> stocks, vector<string> market, double yearsAnnualized, double perYear, double horizon, double riskFree) {

	securityAttributes attributes;
	double tempR;
	double tempS;
	//double tempB;
	security parsedStock;
	string file;

	for (vector<string>::iterator it = market.begin(); it != market.end(); it++) {

		file = *it;
		attributes.mSymbol.push_back(file);

		parsedStock = parse_csv(file);

		tempR = ann_returns(parsedStock.close, yearsAnnualized, perYear, horizon);
		attributes.returns_m.push_back(tempR);

		tempS = ann_stddev(parsedStock.close, yearsAnnualized, perYear, horizon);
		attributes.stddev_m.push_back(tempS);

	}

	for (vector<string>::iterator it = stocks.begin(); it != stocks.end(); it++) {

		file = *it;
		attributes.sSymbol.push_back(file);

		parsedStock = parse_csv(file);

		tempR = ann_returns(parsedStock.close, yearsAnnualized, perYear, horizon);
		attributes.returns_i.push_back(tempR);

		tempS = ann_stddev(parsedStock.close, yearsAnnualized, perYear, horizon);
		attributes.stddev_i.push_back(tempS);

		//tempB = beta(tempR, attributes.returns_m, riskFree);
		//attributes.beta_i.push_back(tempB);

	}

	attributes.covariance = covariance_matrix(stocks, yearsAnnualized, perYear, horizon);

	return attributes;


}







