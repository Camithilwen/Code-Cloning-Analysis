#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<double,string> pa;
vector<pa> vec;
bool my (pa i,pa j) { return (i.first==j.first?i.second>j.second:i.first<j.first); }
int main(){
    int n;
    while(cin >>  n && n){
        while(n--){
            string na;
            double p,a,b,c,d,e,f,s,m;
            cin>>na>>p>>a>>b>>c>>d>>e>>f>>s>>m;
            vec.push_back(pa((f*s*m-p)/(a+b+c+(d+e)*m),na));
        }
        sort(vec.begin(),vec.end(),my);
        for(long long i=vec.size()-1;i>=0;i--){
            cout<<vec[i].second<<endl;
        }
        cout<<"#"<<endl;
        vec.clear();
    }
}