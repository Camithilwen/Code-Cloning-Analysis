#include<iostream>
using namespace std;
int main(){
    int A,B,h=100,w=100;
    char g[100][100];
    for(int i=0;i<h*w;i++)g[i/w][i%w]=(i<h*w/2?'#':'.');
    cin>>A>>B;
    cout<<"100 100"<<endl;
    for(int i=0;i<A-1;i++)g[2*(i/50)+1][2*(i%50)]='.';
    for(int i=0;i<B-1;i++)g[98-2*(i/50)][2*(i%50)]='#';
    for(int i=0;i<h*w;i++)cout<<g[i/w][i%w]<<(i%w+1==w?"\n":"");
    return 0;
}