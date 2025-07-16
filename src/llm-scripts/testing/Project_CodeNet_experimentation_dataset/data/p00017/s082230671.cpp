#include <iostream>
#include <string>
using namespace std;

const int ALPHA = 26;

int main(){
	string input;
	while(cin && getline(cin, input)){
		string cand[ALPHA];
		for(int i=0; i<ALPHA; i++){
			cand[i] = "";
			for(int n=0; n<input.size(); n++){
				if('a'<=input[n]&&input[n]<='z'){
					cand[i] += (input[n]-'a'+i)%ALPHA + 'a';
				} else {
					cand[i] += input[n];
				}
			}
			if(cand[i].find("the") != string::npos
				|| cand[i].find("this") != string::npos
				|| cand[i].find("that") != string::npos){
				cout<<cand[i]<<endl;
			}
		}
	}
	return 0;
}