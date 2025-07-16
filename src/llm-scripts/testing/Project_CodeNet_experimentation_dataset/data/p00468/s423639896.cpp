#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Edge
{
	int MFrom;
	int MTo;
};

void solve()
{
	int n, m;
	while(cin >> n >> m, n || m)
	{
		vector< vector<int> > Vertex(n);
		vector<Edge> Vec(m);
		for(int i = 0; i < m; ++i)
		{
			cin >> Vec[i].MFrom >> Vec[i].MTo;
			Vec[i].MFrom--; Vec[i].MTo--;
		}
		for(int i = 0; i < m; ++i)
		{
			Edge e = Vec[i];
			Vertex[e.MFrom].push_back(e.MTo);
			Vertex[e.MTo].push_back(e.MFrom);
		}
		set<int> Set;
		for(int i = 0; i < Vertex[0].size(); ++i)
		{
			int To = Vertex[0][i];
			Set.insert(To);
			for(int j = 0; j < Vertex[To].size(); ++j)
			{
				Set.insert(Vertex[To][j]);
			}
		}
		Set.count(0) ? cout << Set.size() - 1 : cout << Set.size();
		cout << endl;
	}
}

int main()
{
	solve();
	return(0);
}