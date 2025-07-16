#include<bits/stdc++.h>
using namespace std;

bool check(vector<string> board)
{
	for (int i=0;i<8;i++)
	{
		if (count(board[i].begin(),board[i].end(),'Q')!=1) return false;
		int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		for (int j=0;j<8;j++)
		{
			if (board[i][j]=='Q') cnt++;
		}
		if (cnt!=1) return false;
		for (int j=0;j<i+1;j++)
		{
			if (board[i-j][j]=='Q') cnt1++;
			if (board[i-j][7-j]=='Q') cnt2++;
		}
		if (cnt1>1 || cnt2>1) return false;
		for (int j=0;j<8-i;j++)
		{
			if (board[i+j][j]=='Q') cnt3++;
			if (board[i+j][7-j]=='Q') cnt4++;
		}
		if (cnt3>1 || cnt4>1) return false;
	}
	return true;
}

int main()
{
	int K;cin >> K;
	vector<pair<int,int>> state(K);
	int x,y;
	for (int i=0;i<K;i++)
	{
		cin >> x >>y;
		state[i]=make_pair(x,y);
	}
	vector<int> num={0,1,2,3,4,5,6,7};
	do
	{
		bool can=true;
		for (int i=0;i<K;i++)
		{
			x=state[i].first;
			y=state[i].second;
			if (num[x]!=y) can=false;;
		}
		if (!can) continue;
		vector<string> board(8,"........");
		for (int i=0;i<8;i++) board[i][num[i]]='Q';
		if (check(board))
		{
			for (int i=0;i<8;i++)
			{
				cout << board[i] << endl;
			}
			break;
		} 
	} while (next_permutation(num.begin(),num.end()));
	
	return 0;
}

