// 去吧！皮卡丘! 把AC带回来！
//      へ　　　　　／|
// 　　/＼7　　　 ∠＿/
// 　 /　│　　 ／　／								AC		AC		AC		AC
//    │　Z ＿,＜　／　　 /`ヽ						AC		AC		AC		AC
//    │　　　　　ヽ　　 /　　〉					AC		AC		AC		AC
// 　Y　　　　　`　 /　　/  /						AC		AC		AC		AC
// 　亻●　.　●　　〈　/　/						AC		AC		AC		AC
// 　()　 へ　　　　|　＼〈							AC		AC		AC		AC
// 　　>- ._　 ィ　 │ ／／							AC		AC		AC		AC
// 　 / へ　　 /　/＜| ＼＼							AC		AC		AC		AC
// 　 ヽ_/　　(_／　 │／／							AC		AC		AC		AC
// 　　 7　　　　　　　|／							AC		AC		AC		AC
// 　　 ＞―r￣￣`-―＿/							AC		AC		AC		AC
//**************************************Accepted*****************************************//

#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define Unique(x) x.erase(unique(all(x)),x.end());

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define Pig (OO)

using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

const int Days[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};

inline int read()
{
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	
	return f?ans:-ans;
	
	#undef gc
}

typedef long long ll;

int n,m;
vector<int> v[1010];
int vis[1010];
vector<int> path;
int indeg[1010],outdeg[1010];
bool edges[1010][1010];

bool OK()
{
	memset(indeg,0,sizeof(indeg));
	memset(outdeg,0,sizeof(outdeg));
	
	for(int i=0;i<path.size();i++)for(int j=0;j<path.size();j++)
	{
		if(indeg[path[i]]>1||outdeg[path[j]]>1)return 0;
		
		if(edges[path[i]][path[j]])indeg[path[i]]++,outdeg[path[j]]++;
	}
	
	for(int i=0;i<path.size();i++)if(indeg[path[i]]!=1||outdeg[path[i]]!=1)return 0;
	
	return 1;
}

void pprint()
{
	if(!OK())return;
	
	cout<<path.size()<<endl;for(int i=0;i<path.size();i++)cout<<path[i]<<endl;
	
	exit(0);
}

void DFS(int x)
{
	path.pb(x);
	vis[x]=2;
	
	for(int i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]]==0)DFS(v[x][i]);
		if(vis[v[x][i]]==2)pprint();
	}
	
	path.pop_back();
	vis[x]=1;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		v[x].pb(y);
		
		edges[x][y]=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		path.clear();
		
		if(!vis[i])DFS(i);
	}
	
	cout<<-1;
	
	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}

/*  GOD BLESS  */
