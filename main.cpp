#include <cstdio>
#include <iostream>
#include <vector>
#include "build_portfolio.cpp"


using namespace std;


int main () {
	
	vector<string> assets;
	vector<string> market;
	double yearsAnnualized = 1;
	double perYear = 261;
	double horizon;
	//double annualizedRet;
	//double annualizedStdDev;
	int i = 0;

	//current risk free rate is rate on 10 year treasury bond (annualized)
	//
	//https://fixedincome.fidelity.com/ftgw/fi/FIIndividualBondsSearch?prodmajor=TREAS&requestpage=FISearchTreasury&pageName=FISearchTreasury&sortby=MA&operation=&minmaturity=12%2F2026&maxmaturity=01%2F2028&askYield=ALL&minyield=&maxyield=&prodminor=BOND&dummybondtierind=All&bondotherind=Y&bondtierind=Y&askQuantity=ALL&minQuantity=&maxQuantity=&bidQuantity=ALL&minQuantityBid=&maxQuantityBid=&zerocpn=&askPrice=ALL&minprice=&maxprice=&coupon=ALL&mincoupon=&maxcoupon=&callind=&displayChartFormat=TABLE&displayFormat=GRAPH&isAdvSearch=Y&advDataId=REQ5a3c4e010a08481520004a7f0005aa33
	double riskFree = .02469;
	
	market.push_back("SPY");
	assets.push_back("BA");
	assets.push_back("V");
	assets.push_back("K");
	assets.push_back("COP");

	if (perYear == 261) {
		horizon = 1;
	} else if (perYear == 52) {
		horizon = 5;
	} else if (perYear == 12) {
		horizon = 22;
	} else if (perYear == 1) {
		horizon = 261;
	} else {
		horizon = 0;
		cout << "\nBad initialization of perYear\n";
	}

	securityAttributes attributes;
	attributes = build_portfolio(assets, market, yearsAnnualized, perYear, horizon, riskFree);


	// 
	//
	// Print stock data
	//
	//
	for (vector<string>::iterator it = attributes.sSymbol.begin(); it != attributes.sSymbol.end(); it++) {

		cout << *it << ":\n" << yearsAnnualized << " year annualized return = " << attributes.returns_i.at(i) * 100 << "% \n";

		cout << yearsAnnualized << " year annualized standard deviation = " << attributes.stddev_i.at(i) << "\n\n";

		//cout << yearsAnnualized << " year annualized beta = " << attributes.beta_i.at(i) << "\n\n";

		i++;
	}
	//
	//
	//
	//
	//

	
	// 
	//
	// print covariance
	//
	//
	cout << yearsAnnualized << " year annualized covariance matrix for: ";
	for (vector<string>::iterator it = attributes.sSymbol.begin(); it != attributes.sSymbol.end(); it++) {
		cout << *it;
		if (it != (attributes.sSymbol.end() - 1)){
			cout << ", ";
		}
	}
	cout << "\n";

	/*
	for (vector<vector<double> >::iterator it = attributes.covariance.begin(); it != attributes.covariance.end(); it++){
		for (vector<double>::iterator it1 = (it)->begin(); it1 != (it)->end(); it1++){
			cout << *it1 << "   ";
		}
		cout << "\n";
	}
	cout << "\n";
*/


	for (vector<vector<double> >::iterator it = attributes.covariance.begin(); it != attributes.covariance.end(); it++) {
		for (vector<double>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++) {
			cout << *it1 << "    ";
		}
		cout << "\n";
	}
	cout << "\n";

	//
	//
	//
	//
	//


	//
	//
	// Print S&P 500 data
	//
	//
	cout << "S&P 500:\n" << yearsAnnualized << " year annualized return = " << attributes.returns_m.front() * 100 << "% \n";

	cout << yearsAnnualized << " year annualized standard deviation = " << attributes.stddev_m.front() << "\n\n";
	//
	//
	//
	//
	//
}
