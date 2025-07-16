//#define _USE_MATH_DEFINES
//#include <cmath>
#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iomanip>
#include <vector>
#include <string>
//#include <algorithm>
//#include <functional>
//#include <time.h>
#include <sstream>

using namespace std;

bool isthe(string str){
	//?????????????????????????????? the this that?????¢??? ????????°ture

	int d1, d2, d3;

	d1 = (str[1] - str[0] + 26) % 26;

	if (d1 != 14){
		return false;
	}
	else{
		d2 = (str[2] - str[0] + 26) % 26;
		if (d2 != 11 && d2 != 15 && d2 != 7){
			return false;
		}
		else{
			if (d2 == 11 && str.size() == 3){
				return true;
			}
			else{
				d3 = (str[3] - str[0] + 26) % 26;
				if (d2 == 15 && d3 == 25) return true;
				if (d2 == 7 && d3 == 0) return true;
			}
		}
	}

	return false;

}


int main(){
	
	string s,sc, buf;
	stringstream ss;
	vector <string> as;
	int dif = 0;


	while (getline(cin, s)){
		dif = 0;
		buf = "";
		sc = "";
		ss.str("");
		ss.clear();

		sc += s;
		for (int i = 0; i < sc.size(); i++){
			if (sc[i] == '.')sc[i] = ' ';
		}
		ss << sc;

		while (ss >> buf){
			//the this that???????´¢
			if (buf.size() == 4){
				if (isthe(buf)){
					dif = (buf[0] - 't' + 26)%26;
					break;
				}
			}
			if (buf.size() == 3){
				if (isthe(buf)){
					dif = (buf[0] - 't' + 26) % 26;
					//break;
				}
			}
		}

		for (int i = 0; i < s.size(); i++){
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] -= dif;
				if (s[i] < 'a') s[i] += 26;
				if (s[i] > 'z') s[i] -= 26;
			}
		}

		cout << s << endl;
	}


	return 0;
}