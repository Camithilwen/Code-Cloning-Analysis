#include<iostream>
#include<string>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	string s;
	int n;
	cin>>n;
	cin.ignore();
	rep(i,n){
		getline(cin,s);
		int size=s.size();
		rep(j,size-6){
			string point=s.substr(j,7);
			if(point=="Hoshino"){
				point="Hoshina";
				s.replace(j,7,point);
			}
		}
		cout<<s<<endl;
	}
	return 0;
}