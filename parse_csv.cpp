#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

struct security {
		vector<string> day;
		vector<string> month;
		vector<string> year;
		vector<string> date;
		vector<double> close;
		vector<double> low;
		vector<double> high;
		vector<double> open;
	};


security parse_csv(string file){

	file = file + ".csv";
	ifstream ifs (file, ifstream::in);

	security issue;
	string temp;
	double temp_int;
	int i = 0;
	string delimiter = "/";
	string token;


	
	while(ifs.good() && (getline(ifs, temp, ',') || getline(ifs, temp, '\n'))){
		//getline(ifs, temp, ',');
		//getline(ifs, temp);

		//stringstream ss(temp);
       		//while(getline(ss, temp, ',') || getline(ss, temp, '\n')){

		if (temp == "Date" || temp == "Open" || temp == "High"|| temp == "Low" || temp == "Volume" || temp == "Close"){

		} else {
					
			if (i % 5 == 0) {
				issue.date.push_back(temp);
/*
				int j = 0; 
				size_t pos = 0;
				string token;
				while ((pos = temp.find(delimiter)) != std::string::npos) {
    					token = temp.substr(0, pos);
    					temp.erase(0, pos + delimiter.length());

					if (j == 0) {
						issue.month.push_back(token);
					} else if (j == 1) {
						issue.day.push_back(token);
					}
					j++;
				}
				*/
				//issue.year.push_back(token);


	//			cout << issue.date.back() << "  " << issue.month.back() << "  " << issue.day.back() << "   " << issue.year.back() << "\n";
				i = 0;		
			} else if (i % 4 == 0) {
				istringstream ss(temp);
				ss >> temp_int;
				issue.close.push_back(temp_int);
			} else if (i % 3 == 0) {
				istringstream ss(temp);
				ss >> temp_int;
				issue.low.push_back(temp_int);
			} else if (i % 2 == 0) {
				istringstream ss(temp);
				ss >> temp_int;
				issue.high.push_back(temp_int);
			} else {
				istringstream ss(temp);
				ss >> temp_int;
				issue.open.push_back(temp_int);
			}
		}
		i++;
	//	}
	

//				cout << issue.date.back() << "  " << issue.open.back() << "  " << issue.high.back() << "   " << issue.low.back() << "   " << issue.close.back() << "\n";


	}
	ifs.close();
	issue.date.pop_back();
//	issue.day.pop_back();
//	issue.month.pop_back();
//	issue.year.pop_back();

	//security.push_back(open);
	//security.push_back(high);
	//security.push_back(low);
	//security.push_back(close);

	return issue;
}

// Instructions to use this function below
/* 
	security BA;
	string file = "Chart-20171206-172420.csv";
	BA = parse_csv(file);
*/

