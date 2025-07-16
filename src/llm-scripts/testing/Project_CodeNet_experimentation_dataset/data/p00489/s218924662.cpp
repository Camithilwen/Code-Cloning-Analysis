#include <iostream>
using namespace std;

int main()
{
	int n;
	int a,b,c,d;
	int team[100];
	int p[100];
	int sum=0;

	cin >> n;
	for(int i=1 ;i<n+1 ;i++){
		team[i] = 0;
		p[i] = 1;
	}

	for(int i=0 ;i<(n*(n-1))/2 ;i++){
		cin >> a >> b >> c >> d;
		if(c > d)
			team[a] += 3;
		else if(c < d)
			team[b] += 3;

		else if(c == d){
			team[a]++;
			team[b]++;
		}
	}
	for(int i=1 ;i<n+1 ;i++){
		for(int j=1 ;j<n+1 ;j++){
			if(team[i] < team[j]){
				p[i]++;
			}
		}
	}
	for(int i=1 ;i<n+1 ;i++){
		cout << p[i] << endl;
	}


	return 0;
}