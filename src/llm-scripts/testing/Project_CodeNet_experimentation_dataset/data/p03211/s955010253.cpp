#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
typedef long long ll;

using namespace std;

int main(){
	string s;
	cin>>s;
	int d,mins=1000;
	for(int i=0;i<(s.size()-2);i++){
		d=((s[i]-'0')*100)+((s[i+1]-'0')*10)+(s[i+2]-'0');
		mins=min(mins,(abs(d-753)));
	}
	cout<<mins;
}

