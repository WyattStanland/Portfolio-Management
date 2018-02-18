#include <cstdio>
#include <iostream>
#include <vector>
#include "zero_pad.cpp"

using namespace std;


template <class T> 
T vSubtract (T v1, T v2) {

	T result;
	pair <T, T > vv;
        vv = zero_pad(v1, v2);
        v1 = vv.first;
        v2 = vv.second;

	for (int i = 0; i != v1.size(); i++){
		result.push_back(v1.at(i) - v2.at(i));
	}

	
return result;
}

