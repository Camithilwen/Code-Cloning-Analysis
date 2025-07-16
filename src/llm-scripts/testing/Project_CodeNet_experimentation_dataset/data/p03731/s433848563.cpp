#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int current_time=0;
    int result=0;
    for(int i=0;i<n;i++)
    {
        int start_time=v[i];
        current_time=v[i]+t;
        bool inside=false;
        while(i<n&&v[i]<current_time){
            current_time=v[i]+t;
            i++;
            inside=true;
        }
        if(inside)i--;
        result+=current_time-start_time;
    }
    cout<<result<<endl;
}