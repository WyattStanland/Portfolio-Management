#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

vector<double> returns(vector<double> prices, double years, double perYear, double horizon){

	double price_ti;
	double price_ti_1;
	int i = 0;
	double temp;
	vector<double> vectOfReturns;



	for (vector<double>::reverse_iterator rit = prices.rbegin(); rit != prices.rbegin()+(perYear * years); rit++){
		
		price_ti = *(rit + (horizon*i) - i);
		price_ti_1 = *((rit+1) + (horizon*(i+1)) - (i+1));
		temp = (price_ti - price_ti_1) / price_ti_1;

		vectOfReturns.push_back(temp);
		i++;

	}

	return vectOfReturns;

}
