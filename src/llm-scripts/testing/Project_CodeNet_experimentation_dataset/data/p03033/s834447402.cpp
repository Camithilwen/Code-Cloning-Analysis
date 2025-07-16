#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
#include<map>
using namespace std;
typedef long long LL; 
typedef pair<LL,LL> P;//Pでpair<-,->を表す。
typedef map<LL,LL>::iterator Itr;
LL MOD=1000000007;

struct S{
    LL x;LL y;LL z;
    bool operator<(const S&a)const{
        return x<a.x||(x==a.x&&y<a.y)||(x==a.x&&y==a.y&&z<a.z);
    }
    bool operator==(const S&a)const{
        return (x==a.x)&&(y==a.y)&&(z==a.z);
    }
};

int main()
{ 
    LL n,Q;
    cin>>n>>Q;
    vector<S> v;
    for(int i=0;i<n;i++){
        LL a,b,c;
        cin>>a>>b>>c;
        S s;
        s.x=c;s.y=a;s.z=b;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    /*for(int i=0;i<v.size();i++){
        S s=v[i];
        cout<<s.x<<' '<<s.y<<' '<<s.z<<endl;
    }*/

    map<LL,LL> m;
    for(int i=0;i<Q;i++){
        LL a;
        cin>>a;
        m.insert(P(a,i));
    }
    LL ans[Q];
    for(int i=0;i<n;i++){
        S s=v.back();
        v.pop_back();
        LL begin=s.y-s.x;
        LL end=s.z-s.x;
        vector <LL>d;
        for(Itr itr=m.lower_bound(begin);itr!=m.lower_bound(end);advance(itr,1)){
            ans[(*itr).second]=s.x;
            d.push_back((*itr).first);
        }
        while(!d.empty()){m.erase(d.back());d.pop_back();}
    }
    for(Itr itr=m.begin();itr!=m.end();advance(itr,1)){
        ans[(*itr).second]=-1;
    }
    for(int i=0;i<Q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}