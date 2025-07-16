#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    unordered_map<int,int>ump1,ump2;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i+=2){
        ump1[v[i]]++;
    }
    for(int i=1;i<n;i+=2){
        ump2[v[i]]++;
    }
    int max1=0;
    int max2=0;
    int index1=0;
    int index2=0;
    for(auto it=ump1.begin();it!=ump1.end();it++){
        if(max1<=it->second){
            max2=max1;
            index2=index1;
            max1=it->second;
            index1=it->first;
        }
        else
        if(max2<it->second){
            max2=it->second;
            index2=it->first;
        }
    }
    int m1=0;
    int m2=0;
    int mindex1=0;
    int mindex2=0;
    for(auto it=ump2.begin();it!=ump2.end();it++){
        if(m1<=it->second){
            m2=m1;
            mindex2=mindex1;
            m1=it->second;
            mindex1=it->first;
        }
        else
        if(m2<it->second){
            m2=it->second;
            mindex2=it->first;
        }
    }
    int result=0;
    if(index1==mindex1){
        int f1=max1+m2;
        int f2=max2+m1;
        int result1=(v.size()-f1);
        int result2=(v.size()-f2);
        result=min(result1,result2);
    }
    else
    {
        result=(v.size()-m1-max1);
    }
    cout<<result;
}