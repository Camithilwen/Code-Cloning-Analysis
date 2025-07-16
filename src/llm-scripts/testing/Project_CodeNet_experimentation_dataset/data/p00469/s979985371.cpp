#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main(void){
	int a,b,c,d;
	int n,k;
	while(1){
		cin >> n;
		cin >> k;
		if(n==0 && k==0)break;
		vector<string> num;
		set<string> str;
		for(a=0;a<n;a++){
			string s;
			cin >> s;
			num.push_back(s);
		}
		if(k==2){
			for(a=0;a<n;a++){
				for(b=0;b<n;b++){
					if(a!=b)str.insert(num[a]+num[b]);
				}
			}
		}
		if(k==3){
			for(a=0;a<n;a++){
				for(b=0;b<n;b++){
					if(a!=b)for(c=0;c<n;c++){
						if(a!=c && b!=c)str.insert(num[a]+num[b]+num[c]);
					}
				}
			}
		}
		if(k==4){
			for(a=0;a<n;a++){
				for(b=0;b<n;b++){
					if(a!=b)for(c=0;c<n;c++){
						if(a!=c && b!=c)for(d=0;d<n;d++){
							if(a!=d && b!=d && c!=d)str.insert(num[a]+num[b]+num[c]+num[d]);
						}
					}
				}
			}
		}
		cout << str.size() << endl;
	}
	return 0;
}