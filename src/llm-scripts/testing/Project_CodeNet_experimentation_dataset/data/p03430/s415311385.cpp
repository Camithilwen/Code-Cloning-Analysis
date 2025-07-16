#include<bits/stdc++.h>
using namespace std;

char str[303]; int dp[303][303][303] , N , K;

int solve(int x , int y , int z){
	if(x > y) return 0;
	if(x == y) return 1;
	if(dp[x][y][z]) return dp[x][y][z];
	if(str[x] == str[y]) return dp[x][y][z] = solve(x + 1 , y - 1 , z) + 2;
	return dp[x][y][z] = max(solve(x + 1 , y , z) , max(solve(x , y - 1 , z) , z == 0 ? 0 : 2 + solve(x + 1 , y - 1 , z - 1)));
}

int main(){
	scanf("%s %d" , str + 1 , &K); N = strlen(str + 1);
	cout << solve(1 , N , K) << endl; return 0;
}