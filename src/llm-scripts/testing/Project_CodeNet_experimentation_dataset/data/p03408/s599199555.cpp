#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<string,int>bmp,rmp;
    for(int i=0;i<n;i++)
    {
        string element;
        cin>>element;
        if(bmp.find(element)==bmp.end()){
            bmp[element]=1;
        }
        else
        {
            bmp[element]++;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string element;
        cin>>element;
        if(rmp.find(element)==rmp.end()){
            rmp[element]=1;
        }
        else
        {
            rmp[element]++;
        }
    }
    int finalresult=0;
    for(auto it=bmp.begin();it!=bmp.end();it++)
    {
        int result=0;
        if(rmp.find(it->first)==rmp.end()){
            result+=it->second;
        }
        else
        {
            int red=rmp.find(it->first)->second;
            result+=max(0,it->second-red);
        }
        if(finalresult<result)
        {
            finalresult=result;
        }
    }
    cout<<finalresult;
}