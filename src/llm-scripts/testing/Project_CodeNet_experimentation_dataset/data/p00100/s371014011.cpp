#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;


int main(void){

long long n, bg, tn, su;
	
	while(cin >> n){
		if(n==0 || cin.eof()) break;
		map<int,long long> sk;
		vector<int> jun;
		rep(i,n){
			cin >> bg >> tn >> su;
			if(sk[bg]==0) jun.push_back(bg);
			sk[bg] += tn * su;
		}
		int cnt=0;
		rep(i,jun.size()){
			if(sk[jun[i]] >= 1000000){
				cout << jun[i] << endl;
				cnt++;
			}
		}	
		if(cnt==0) cout << "NA" << endl;
	}
	return 0;
	
}