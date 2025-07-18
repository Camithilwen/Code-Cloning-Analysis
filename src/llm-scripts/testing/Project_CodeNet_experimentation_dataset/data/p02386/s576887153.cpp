#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}

int main(){
    struct dice{int u,e,w,n,s,d;
    void rotate(char c){
        int temp=u;
        if(c=='E'){u=w;w=d;d=e;e=temp;}
        else if(c=='W'){u=e;e=d;d=w;w=temp;}
        else if(c=='N'){u=s;s=d;d=n;n=temp;}
        else if(c=='S'){u=n;n=d;d=s;s=temp;}
    }
    bool hikaku(dice q){
        int counter=0;
        if(u==q.u)counter++;
        if(s==q.s)counter++;
        if(e==q.e)counter++;
        if(w==q.w)counter++;
        if(n==q.n)counter++;
        if(d==q.d)counter++;
        if(counter==6)return true;else return false;
    }
    };
    int n;
    in(n);
    vector<dice> vec(n);
    rep(i,n){
        in(vec[i].u,vec[i].s,vec[i].e,vec[i].w,vec[i].n,vec[i].d);
    }
    string s="NNNNENNNN";
    for(int j=0;j<n-1;j++){
        for(int k=j+1;k<n;k++){
            dice a=vec[j];
            dice b=vec[k];
        rep(i,9){
            if(a.s==b.s)break;
            b.rotate(s[i]);
        }
        int counter=0;
        while(!a.hikaku(b)){
            b.rotate('E');
            counter++;
            if(counter>=5){
                goto skip;
            }
        }
        out("No");
        return 0;
        skip: ;
        }
    }
    out("Yes");
}
