#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
const double EPS=1e-8;
struct data{
    double b;string Name;
    data(double b_,string Name_):b(b_),Name(Name_){}
    data(){}
    bool operator<(const data &d)const{
        return (b-d.b<EPS&&b-d.b>-EPS)?Name>d.Name:b<d.b;
    }
};
int main(){
    int n;
    while(cin>>n,n){
        vector<data>V;
       for(int i=0;i<n;i++){
            string l;
            int p,a,b,c,d,e,f,s,m;
            cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
            int t=a+b+c+(d+e)*m;
            int val=f*s*m-p;
            V.push_back(data(1.0*val/t,l));
       }
        sort(V.rbegin(),V.rend());
        for(int i=0;i<n;i++){
            cout<<V[i].Name<<endl;
        }
        cout<<"#"<<endl;
    }
    return 0;
}