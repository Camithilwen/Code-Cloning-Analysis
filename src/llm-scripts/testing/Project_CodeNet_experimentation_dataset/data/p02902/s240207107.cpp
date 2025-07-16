    #include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
}

vector <vector <int> > g;
void dfs(int s,vector <int> &p,int &parent,int &child,set <int> &s2,vector <bool> &visited,vector <int> &depth,int &min,vector <int> &path);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt(),m=nxt();
    vector <int> row;
    g.resize(n+1,row);

    set <pair<int,int> > edges;
    for(int i=0;i<m;i++)
    {//cout<<"came3\n";
        int u=nxt(),v=nxt();
        g[u].push_back(v);
        edges.insert({u,v});
    }

    vector <int> p(n+1);
    int parent=0,child=0,min=INT_MAX;
    vector <int> path(n+1);
    for(int i=1;i<=n;i++)
    {//cout<<"came"<<endl;
        vector <bool> visited;
        visited.resize(n+1,0);
        set <int> s2;
        vector <int> depth(n+1);
        depth[i]=0;
        dfs(i,p,parent,child,s2,visited,depth,min,path);
        
    }

    if(parent!=0)
        {
            vector <int> test;
            int cur=child;
            test.push_back(cur);
            //cout<<cur<<" "<<parent<<endl;
            //return 0;
            while(cur!=parent)
            {//cout<<cur<<endl;
                cur=path[cur];
                test.push_back(cur);
            }
            cout<<test.size()<<endl;
            for(auto val:test)
                cout<<val<<endl;
            return 0;
        }
    cout<<"-1\n";
    
    
    return 0;   
}

void dfs(int s,vector <int> &p,int &parent,int &child,set <int> &s2,vector <bool> &visited,vector <int> &depth,int &min,vector <int> &path)
{
    visited[s]=1;
    int x=s;
    s2.insert(x);
        for(int i=0;i<g[x].size();i++)
        {
            if(!visited[g[x][i]])
            {
                p[g[x][i]]=x;
                depth[g[x][i]]=depth[x]+1;
                dfs(g[x][i],p,parent,child,s2,visited,depth,min,path);
        
            }
            else{
                if(s2.count(g[x][i])&&(depth[x]-depth[g[x][i]])<min)
                {
                    child=x;
                    parent=g[x][i];
                    min=depth[x]-depth[g[x][i]];
                    path=p;
                }
            }
        }
    s2.erase(x);

}

 
 
