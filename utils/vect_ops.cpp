#include <cstdio>
#include <iostream>
#include <vector>
#include "support_ops.cpp"

using namespace std;


template <class T, class D, class M> class vect_ops : public support_ops<T, D, M> {
public:
	
	T vAdd (T v1, T v2) {

		pair <T, T > vv;
        	vv = this->zero_pad(v1, v2);
        	v1 = vv.first;
        	v2 = vv.second;

		typename vector<D>::iterator it;
		typename vector<D>::iterator it1 = v2.begin();
		
		for (it = v1.begin(); it != v1.end(); it++) {
			*it += *it1;
			it1++;
		}
	return v1;
	}

	T vSubtract (T v1, T v2) {

		pair <T, T > vv;
	        vv = this->zero_pad(v1, v2);
	        v1 = vv.first;
	        v2 = vv.second;
		typename vector<D>::iterator it;
		typename vector<D>::iterator it1 = v2.begin();
		
		for (it = v1.begin(); it != v1.end(); it++) {
			*it -= *it1;
			it1++;
		}
	return v1;
	}

	T vScale (T v1, D a) {
		
		typename vector<D>::iterator it;
		
		for (it = v1.begin(); it != v1.end(); it++) {
			*it *= a;
		}

	return v1;
	}

	D vDot (T v1, T v2) {
		
		typename vector<D>::iterator it;
		typename vector<D>::iterator it1 = v2.begin();
		D result = 0;

		for (it = v1.begin(); it != v1.end(); it++) {
			
			result += (*it) * (*it1);
			it1++;

		}

		return result;
	}

	T v_mult_m (T v, M m) {
		
		T result;
		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;
		typename vector<D>::iterator it3 = v.begin();


		for (it1 = v.begin(); it1 != v.end(); it1++){
			result.push_back(D(0));
		}
		typename vector<D>::iterator it2 = result.begin();
		
		if (v.size() == m[0].size()){
			for (it = m.begin(); it != m.end(); it++) {
				it3 = v.begin();
				for (it1 = it->begin(); it1 != it->end(); it1++) {
					*it2 += ((*it3) * (*it1));
					it3++;
				}
				it2++;
			}
		} else {
			cout << "Vector and Matrix of incompatible size\n";
		}
		return result;
	}

	M mScale(M m, D a){

		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;

		for (it = m.begin(); it != m.end(); it++){
			for (it1 = it->begin(); it1 != it->end(); it1++){
				*it1 *= a;
				cout << *it1 << "\n";
			}
		}

		return m;
	}

	M m_inverse (M m) {
		
		M minors;
		M cofactors;
		M trans;
		M inverse;
		M dTrans;
		T temp;
		D invDet;
		D num = 1;

		minors = this->minor_matrix(m);
		cofactors = this->cofactors(minors);
		trans = this->transpose(cofactors);
		invDet = num / this->determinant(m);

		cout << invDet << "\n";

		typename vector<vector<D> >::iterator it;
		typename vector<D>::iterator it1;

		for (it = trans.begin(); it != trans.end(); it++){
			temp.clear();
			for(it1 = it->begin(); it1 != it->end(); it1++){
				temp.push_back(D(*it1));
			}
			dTrans.push_back(temp);
		}


		return this->mScale(dTrans, invDet);
		
	}

};




