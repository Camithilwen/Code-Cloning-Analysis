#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		int p,a,b,c,d,e,f,s,m;
		string l;
		vector<pair<double,string> > vpii;
		for(int i = 0; i < n; i++){
			cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
			int time = a+b+c+d+e;
			for(int j = 1; j < m; j++)
				time+=d+e;
			int income=-p;
			for(int j = 0; j < m; j++)
				income+=s*f;
			double rate=(double)income/time;
			vpii.push_back(make_pair(-rate,l));
		}
		sort(vpii.begin(),vpii.end());
		for(int i = 0; i < vpii.size(); i++){
			cout<<vpii[i].second<<endl;
		}
		cout<<"#"<<endl;
	}

	return 0;
}