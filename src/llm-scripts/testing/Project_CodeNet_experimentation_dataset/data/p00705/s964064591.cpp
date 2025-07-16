#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<iomanip>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{"; for(auto nth : list){ cout << nth << " ";}cout << "}" << endl;

using namespace std;

string table[]={"qwertasdfgzxcvb","yuiophjklnm"};


int main(){

	while(true){
		int n,q;
		vector<int> date;
		
		cin >> n >> q;

		
		if(n==0&&q==0) break;


		for(int i=0;i<=100;i++){
			date.push_back(0);
		}

		for(int i=0;i<n;i++){
			int m,d;
			cin >> m;
			for(int k=0;k<m;k++){
				cin >> d;
				date[d]++;				
			}
		}

		int decide=0,day=0;

		for(int i=0;i<100;i++){
			if(date[i]>decide && date[i] >= q){
				decide=date[i];	
				day=i;
			}
		}

		cout << day << endl;
	}

}