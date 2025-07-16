#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string s;

int main(){
	getline(cin,s);
	while(getline(cin,s)){
		int a=s.find("Hoshino");
		while(a!=string::npos){
			s=s.substr(0,a)+"Hoshina"+s.substr(a+7);
			a=s.find("Hoshino");
		}
		cout<<s<<endl;
	}
}