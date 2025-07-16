#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

using std::accumulate;
using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::getline;
using std::replace;
using std::string;
using std::stringstream;

int main() {
	string input;
	while (getline(cin,input)) {
		replace(input.begin(),input.end(),',',' ');
		array<int,10> len; // length of each section
		stringstream str_in(input);
		for_each(len.begin(),len.end(),[&str_in](int& l){str_in >> l;});
		int v1,v2; // velocity of each train
		str_in >> v1 >> v2;

		double total_time = accumulate(len.begin(),len.end(),0)/static_cast<double>(v1+v2);
		double total_len = total_time*v1; // total length the train passes
		int pass_len = 0; // the length the train passes
		int section = 0; // the number of section where the train passes
		while (pass_len < total_len) {
			pass_len += static_cast<double>(len[section++]);
		}
		cout << section << endl;
	}
}