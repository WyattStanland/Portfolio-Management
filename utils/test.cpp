#include <cstdio>
#include <iostream>
#include <vector>
#include "vect_ops.cpp"


using namespace std;

int main (){
	//vector<int> a;
	vector<vector<double> > b; 
	vect_ops<vector<double>, double, vector<vector<double> > > vect;

	vector<double> d;
	d.push_back(1);
	d.push_back(8);
	d.push_back(0);
	/*
	b.push_back(d);
	d.clear();

	d.push_back(-2);
	d.push_back(-4);
	d.push_back(4);
	b.push_back(d);
	d.clear();

	d.push_back(5);
	d.push_back(-3);
	d.push_back(8);
	b.push_back(d);


	cout << "\n";

	for (vector<vector<double> >::iterator it = b.begin(); it != b.end(); it++){
		for (vector<double>::iterator it1 = (it)->begin(); it1 != (it)->end(); it1++){
			cout << *it1 << "  ";
		}
	}
	
	cout << "\n";
	*/

	double c;
	c = vect.vDot(d, d);
	
	//for (vector<vector<double> >::iterator it = c.begin(); it != c.end(); it++){
	//	for (vector<double>::iterator it1 = (it)->begin(); it1 != (it)->end(); it1++){
			cout << c << "\n";
	//	}
	//}
	cout << "\n";

}
