#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int k;
  	string s, r;
  	cin >> k >> s;
  	if(s.size()<=k) cout << s << endl;
  	else{
    	for(int i=0;i<k;i++){
        	r += s.at(i);
        }
      	cout << r << "..." << endl;
    }
 
}