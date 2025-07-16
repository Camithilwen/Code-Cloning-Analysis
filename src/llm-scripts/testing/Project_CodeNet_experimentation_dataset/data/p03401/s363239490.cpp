#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            result+=abs(v[i]);
        }
        else
        {
            result+=abs(v[i]-v[i-1]);
        }
        if(i==n-1)
        {
            result+=abs(v[i]);
        }
    }
    int prev=0;
    int next=v[1];
    for(int i=0;i<n;i++)
    {
        if(i==0)
            prev=0;
        else
            prev=v[i-1];
        if(i==n-1)
            next=0;
        else
            next=v[i+1];
        int temp;
        temp=abs(v[i]-prev);
        temp+=abs(v[i]-next);
        int tempresult=result;
        tempresult-=temp;
        tempresult+=abs(next-prev);
        cout<<tempresult<<endl;
    }
}