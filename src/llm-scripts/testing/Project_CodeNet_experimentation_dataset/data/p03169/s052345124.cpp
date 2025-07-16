#include<bits/stdc++.h>
#define ll long long

using namespace std;

double dp[301][301][301];

double sushi(int n, int x, int y, int z){
	if(x==0 && y==0 && z==0){
		return 0;
	}

	if(x<0 || y<0 || z<0){
		return 0;
	}

	if(dp[x][y][z] > -0.9){
		return dp[x][y][z];
	}

	double res = n + x*sushi(n, x-1, y, z) + y*sushi(n, x+1, y-1, z) + z*sushi(n, x, y+1, z-1);
	return dp[x][y][z] = res/(x+y+z);
}

int main(){
	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	int a[n];
	int ones=0, twos=0, threes=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		switch(a[i]){
			case 1:
				ones++;
				break;
			case 2:
				twos++;
				break;
			case 3:
				threes++;
				break;
		}
	}

	cout << setprecision(10) << sushi(n, ones, twos, threes);
	return 0;
}