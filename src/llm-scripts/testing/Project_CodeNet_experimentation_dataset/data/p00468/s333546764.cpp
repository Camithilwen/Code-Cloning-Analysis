#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> to[600];//[]の中の人がどこに行けるか
bool res[600] = {};

void bfs()
{
	queue<int> q;

	for(int i=0;i<to[1].size();++i){
		q.push(to[1][i]);
	}
	for(int i=0;i<2;++i)
	{
		int size = q.size();
		for(int i=0;i<size;++i)
		{
			int now = q.front();q.pop();
			if(res[now]) continue;
			res[now] = true;
			for(int i=0;i<to[now].size();++i){
				q.push(to[now][i]);
			}
		}
	}
}

int main(void)
{
	while(1)
	{
		for(int i=0;i<501;++i){
			to[i].clear();
			res[i] = false;
		}
		int n;
		int m;
		cin >> n >> m;
		if(n == 0 || m == 0) return 0;
		for(int i=0;i<m;++i){
			int a,b;
			cin >> a >> b;
			to[a].push_back(b);
			to[b].push_back(a);
		}
		bfs();
		int count = 0;
		for(int i=2;i<501;++i){
			if(res[i])
				++count;
		}
		cout << count << endl;
	}
	return 0;
}