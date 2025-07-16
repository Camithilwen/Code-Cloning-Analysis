#include<iostream>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
#include<iomanip>
using namespace std;
using ll=long long;

#include<complex>
namespace Geometry{
    using namespace std;
    using ld=double;
    using Point=complex<ld>;

    struct Line{
        Point a,b;
    };

    struct Circle{
        Point p;
        ld r;
    };
    const ld EPS=1e-6;
    inline bool EQ(Point a,Point b){return abs(a-b)<EPS;}
    ld dot(Point a,Point b){return real(a)*real(b)+imag(a)*imag(b);}
    ld cross(Point a,Point b){return real(a)*imag(b)-imag(a)*real(b);}

    const int CCW=1;
    const int CW=-1;
    const int BAC=2;
    const int ACB=-2;
    const int ABC=0;
    int ccw(Point a,Point b,Point c){
        b-=a,c-=a;
        if(cross(b,c)>EPS) return CCW; // counter clockwise
        if(cross(b,c)<-EPS) return CW; //clockwise
        if(dot(b,c)<-EPS) return BAC; //b-a-c
        if(abs(b)<abs(c)) return ACB; //a-c-b
        return ABC; //a-b-c (abs(b)>abs(c))
    }
}
#include<vector>
#include<algorithm>

namespace Geometry{
    vector<Point> convexFull(const vector<Point>& _ps){
        vector<Point> ps=_ps;
        int n=ps.size();
        if(n<=1) return ps;
        auto cmp=[](const Point &lhs,const Point &rhs){
            return real(lhs)==real(rhs) ? imag(lhs)<imag(rhs) : real(lhs)<real(rhs);
        };
        sort(ps.begin(),ps.end(),cmp);
        int k=0;
        vector<Point> qs(n*2);
        for(int i=0;i<n;i++){
            while(k>=2 && ccw(qs[k-2],qs[k-1],ps[i])<=0) --k;
            qs[k++]=ps[i];
        }
        int t=k;
        for(int i=n-2;i>=0;i--){
            while(k>t && ccw(qs[k-2],qs[k-1],ps[i])<=0) --k;
            qs[k++]=ps[i];
        }
        qs.resize(k-1);
        return qs;
    }
}
using namespace Geometry;

const double pi=acos(-1);
int main(){
    int n;
    cin>>n;
    vector<Point> ps(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ps[i]={x,y};
    }
    cout<<setprecision(10)<<fixed;

    
    vector<Point> cps=convexFull(ps);
    vector<double> res(n);
    if(cps.size()<=2){
        for(int j=0;j<cps.size();j++){
            for(int i=0;i<n;i++){
                if(cps[j]==ps[i]){
                    res[i]=1./cps.size();
                }
            }
        }
        for(int i=0;i<n;i++) cout<<res[i]<<endl;

        return 0;
    }
    auto divd=[&](Point lhs,Point rhs){
        return (lhs-rhs)*Point(0,1);
    };
    
    for(int i=0;i<cps.size();i++){
        auto pre=cps[(i+cps.size()-1)%cps.size()];
        auto nex=cps[(i+1)%cps.size()];
        auto t1=divd(pre,cps[i]);
        auto t2=divd(cps[i],nex);
        auto theta=arg(t2/t1);
        for(int j=0;j<n;j++){
            if(cps[i]==ps[j]){
                res[j]=theta/(2*pi);
            }
        }    
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<endl;
    }
    
    return 0;
}
