#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


template <class T, class D, class M> class support_ops {
protected:
	pair <T, T > zero_pad(T &a, T &b){
		// Check if the vectors are the same size. If not, zero pad the 
		// smaller one to avoid accessing memory in the great unknown
		if (a.size() > b.size()){                   
			int pad = a.size() - b.size();
			for (int i = 0; i < pad; i++) b.push_back(0);
		} else if (b.size() > a.size()){
			int pad = b.size() - a.size();
			for (int i = 0; i < pad; i++) a.push_back(0);
		} else {
		}
		pair <T, T > ab;
		ab = make_pair (a, b);
	
		return ab;
	}

	D determinant(M m){
		
		M mod = m;
		D det = 0;
		D prod = 1;
		D d = m.size();
		int i = 0;

		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;
		
		for (it = m.begin(); it != (m.end() - 1); it++){
			mod.push_back(*it);
		}

    		if (d == 1){
    		    return m[0].at(0);
		}

		if (d == 2){
			return m[0].at(0)*m[1].at(1) - m[1].at(0)*m[0].at(1);

		} else {
			for (int j = 0; j != d; j++){
				i = 0;
				prod = 1;
				for (it = (mod.begin() + j); it != (mod.end() - (d - 1) + j); it++) {
					it1 = it->begin() + i;
				prod = prod * (*it1);
					i++;
				}
				det += prod;
			}

			for (int j = 0; j != d; j++){
				i = 0;
				prod = 1;
				for (it = (mod.end() - 1 - j); it != (mod.begin() + (d - 2) - j); it--) {
				it1 = it->begin() + i;
					prod = prod * (*it1);
				i++;
				}
				det -= prod;
			}
			return det;
		}


	}

	M minor_matrix(M m){

		M temp;
		D detOfMinor;
		M minors;
		T tVect;
		T tVect2;
		D i = 0; D j = 0; D k = 0; D n = 0;

		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;
		typename vector<vector<D> >::iterator it2;
		typename vector<D>::iterator it3;

		for (it = m.begin(); it != m.end(); it++){
			j = 0;
			tVect2.clear();
			for(it1 = it->begin(); it1 != it->end(); it1++){
				k = 0;	
				temp.clear();
				for (it2 = m.begin(); it2 != m.end(); it2++){
					n = 0;
					tVect.clear();
					for(it3 = it2->begin(); it3 != it2->end(); it3++){
						if (i == k || j == n) {
						} else {
							tVect.push_back(*it3);
						}
						n++;	
					}
					if (i == k || j == n) {
					} else {
						temp.push_back(tVect);
					}
					k++;
				}
				detOfMinor = this->determinant(temp);
				tVect2.push_back(detOfMinor);
				j++;
			}
			minors.push_back(tVect2);
			i++;
		}

		return minors;
	}

	
	M cofactors(M m){
		int i = 0;
		int j = 0;

		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;

		for (it = m.begin(); it != m.end(); it++){
			j = 0;
			for(it1 = it->begin(); it1 != it->end(); it1++){
				if ((i+j)%2 == 0){
				} else {
					*it1 = -(*it1);
				}
				j++;
			}
			i++;
		}
		return m;
	}

	M transpose(M m){
		M trans;
		T temp;
		D i = 0;
		D j = 0;

		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;

		for (it = m.begin(); it != m.end(); it++){
			temp.clear();
			for(it1 = it->begin(); it1 != it->end(); it1++){
				temp.push_back(0);
			}
			trans.push_back(temp);
		}
	
		for (it = m.begin(); it != m.end(); it++){
			j = 0;
			for(it1 = it->begin(); it1 != it->end(); it1++){
				trans[j].at(i) = *it1;
				j++;
			}
			i++;
		}
		return trans;
	}


};
