#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b, c;
	cin >> a >> b >> c;
	char judge='a';
	int numa=a.size();
	int numb=b.size();
	int numc=c.size();
	bool fin=true;
	while(fin){
		if(judge=='a'){
			if(numa==0){
				fin=false;
			}
			if(numa>0){
				judge=a.at(a.size()-numa);
				numa--;
			}
		}
		if(judge=='b'){
			if(numb==0) fin=false;
			if(numb>0){
				judge=b.at(b.size()-numb);
				numb--;
			}
		}
		if(judge=='c'){
			if(numc==0) fin=false;
			if(numc>0){
				judge=c.at(c.size()-numc);
				numc--;
			}
		}
	}
	if(judge=='a') cout << "A" << endl;
	if(judge=='b') cout << "B" << endl;
	if(judge=='c') cout << "C" << endl;
}
