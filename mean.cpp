#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// This function computes the annualized geometric mean of a vector

using namespace std;


double mean(vector<double> vect, char toggle){

	double product = 1;
	double mean;
	double gmeanCorrection = 1;
	int i = 0;
	double num = 0;


	for (vector<double>::iterator it = vect.begin(); it != vect.end(); it++){

		num = num + (*it);		
		product = product * (*it + gmeanCorrection);

		i++;
	}	

	if (toggle == 'G' || toggle == 'g') {
		mean = pow(product, 1/(double(vect.size()))) - gmeanCorrection;
	} else if (toggle == 'A' || toggle == 'a') {
		mean = num/(double(vect.size()));
	} else {
		cout << "Invalid toggle input to mean.cpp. Choose either arithmetic mean 'a', or geometric mean 'g'.\n";
		double invalid = 0;
		return invalid;
	}

	return mean;
}
