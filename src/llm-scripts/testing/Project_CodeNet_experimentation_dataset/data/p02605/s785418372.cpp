#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long  ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<double, double>  iidb;
typedef pair<ii, ll>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e18+7;
const double PI = acos(-1);
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 210000
#define offset 200
#define ptr nodo*

map<ll,vector<iii> > chocarx,chocary,flechader,flechaiz,flechader2,flechaiz2;
vector<pair<ii,string> >lst,lst2;
ll ANSWER;
void update(ii par1, ii par2)
{
	if (par1.fi==INF|| par2.fi==INF)return;
	ll dist=abs(par1.fi-par2.fi)+abs(par1.se-par2.se);
	ANSWER=min(ANSWER,dist*5);
}
void resolver1(map<ll,vector<iii> > & mapa)
{
	//<<"mira \n";
	for(auto ite:mapa)
	{
		sort(all(ite.se));
		ii actant={INF,INF};
		//<<ite.fi<<":\n";
		for(iii par:ite.second)
		{
			//<<par.fi.fi<<","<<par.fi.se<<" "<<par.se<<" - ";
			if (par.se==1)
			{
				actant=par.fi;
			}
			else
			{
				update(par.fi,actant);
			}
		}
		//<<endl;

	}
}
void resolver2(map<ll,vector<iii> > & mapa)
{
	for(auto ite:mapa)
	{
		sort(all(ite.se));
		ii actant={INF,INF};
		for(iii par:ite.second)
		{
			if (par.se==1)
			{
				actant=par.fi;
			}
			else
			{
				update(par.fi,actant);
			}
		}
	}
}
void solve(vector<pair<ii,string> >este)
{
	ll x,y;
	string tipo;
	chocarx.clear(),chocary.clear(),flechaiz.clear(),flechader.clear();
	flechaiz2.clear(),flechader2.clear();
	for(auto par:este)
	{
		x=par.fi.fi;
		y=par.fi.se;
		tipo=par.se;
		if (tipo=="U" || tipo=="D")
		chocarx[x].pb({{y,x},tipo=="U"});
		else
		chocary[y].pb({{y,x},tipo=="R"});

		if (tipo=="D"|| tipo=="U")
		{
			if (tipo=="U"){
				flechader[x-y].pb({{y,x},tipo=="U"});
				flechaiz[x+y].pb({{y,x},tipo=="U"});
			}
			else
			{
				flechader2[x-y].pb({{y,x},0});
				flechaiz2[x+y].pb({{y,x},0});
			}
		}
		else
		{
			if (tipo=="L")
			{
				flechader[x-y].pb({{y,x},tipo=="U"});
				flechaiz2[x+y].pb({{y,x},1});
			}
			else
			{
				flechaiz[x+y].pb({{y,x},tipo=="U"});
				flechader2[x-y].pb({{y,x},1});
			}
		}
	}

	resolver1(chocarx);
	resolver1(chocary);

	resolver1(flechaiz);
	resolver1(flechader);

	resolver1(flechaiz2);
	resolver1(flechader2);
}
int main()
{
	ANSWER=INF;
	ll n;
	cin>>n;
	ll x,y;
	string tipo;
	map<string,string> inv;
	inv["L"]="R";inv["R"]="L";inv["U"]="D";inv["D"]="U";
	forr(i,0,n)
	{
		cin>>x>>y>>tipo;
		lst.pb({{x,y},tipo});
		lst2.pb({{x,y},inv[tipo]});
	}
	solve(lst);
	//solve(lst2);
	if (ANSWER==INF)
		cout<<"SAFE\n";
	else
		cout<<ANSWER<<endl;
}