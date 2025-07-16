#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;
          
vector<int> A;
vector<int> g;

int n, m;
int cnt;

auto prn=[=](){
    for(auto a : A)
        cout<<a<<"\n";
};

void _insSort(int g){
    for(int i=g-1;i<n;i++){
        int maxi=i;
        for(int j=i+g;j<n;j+=g){
            if(A[j] < A[maxi]){
                maxi=j;
            }
        }
        if(i!=maxi){
            swap(A[i],A[maxi]);
            cnt++;
        }
    }
 //   cout<<"----"<<g<<"-----\n";
 //   prn();
}

void insSort(int g){
    for(int i=g;i<n;i++){
        int v = A[i];
        int j = i - g;
        while(j>=0 && A[j] > v){
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void  ShellSort(){
    int i;    
    cnt=0;
    m = n;
    if(m>100)
	m=100;
    g.push_back(1);
    for(i=1;pow(4,i)+3*pow(2,i-1)+1<n&&i<=m;i++){
        g.push_back(pow(4,i)+3*pow(2,i-1)+1);
    }
    if(i!=m)
	m=i;
    for(i=g.size()-1;i>=0;i--)
        insSort(g[i]);
}

int main(){
    ios::sync_with_stdio(false);
    int  t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        A.push_back(t);
    }
    ShellSort();    
    cout<<m<<"\n";
    for(int i=g.size()-1;i>0;i--)
        cout<<g[i]<<" ";
    cout<<g[0]<<"\n";
    cout<<cnt<<endl;
    prn();
    return 0;
}