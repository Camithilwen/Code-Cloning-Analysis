#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<string>

using namespace std;

int main(){
	
	while(1){
		int n;
		cin >> n;
		if(n==0) break;
		int pre[n];
		string str;
		for(int i=0;i<n;i++){
			cin >> pre[i];
		}

		cin >> str;
			
		for(int i=0;i<str.size();i++){	
			for(int j=pre[i%n];j>0;j--){
				str[i]--;
				if(str[i]<=('A'-1)) str[i]='z';	
				if(str[i]==96 ) str[i] = 'Z';
			}
		}
		cout << str << endl;
	}
}