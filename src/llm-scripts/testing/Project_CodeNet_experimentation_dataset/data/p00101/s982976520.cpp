
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<complex>
#include<cstdio>
using namespace std ;
typedef vector<int> vi ;
typedef vector<vi> vvi ;
typedef vector<string> vs ;
typedef pair<int, int> pii; 
typedef long long ll ;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()


int main(void){
	string num;
	getline(cin,num);
	int n = atoi(&num[0]);
	while(n--){
		string s;
		getline(cin,s);
		rep(i,s.size()){
			if(s[i]=='H'&&s[i+1]=='o'&&s[i+2]=='s'&&s[i+3]=='h'&&s[i+4]=='i'&&s[i+5]=='n'&&s[i+6]=='o'){
				s[i+6]='a';
			}
			if(s[i]=='\n'){cout<<endl;n--;break;cout<<"test"<<n<<endl;}
			}
		cout<<s<<endl;
	}
}