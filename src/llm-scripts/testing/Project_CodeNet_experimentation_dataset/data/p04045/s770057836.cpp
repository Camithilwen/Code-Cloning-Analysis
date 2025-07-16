#include <iostream>

#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
//const char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.


int solver() {
    // Write your code here
    int n;
    cin>>n;

    int l;
    cin>>l;
    //vector<int> my;
    int freq[10];
    for(int i=0;i<=9;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        int x;
        cin>>x;
      //  my[i]=x;
        freq[x]=1;
    }
    //cout<<my[0];
    for(int j=n;j<100000;j++)
    {
        int num=j;
        bool k=true;
        while(num>0)
        {
            int m=num%10;
            if(freq[m]==1)
            {
                k=false;
                break;
            }
            num=num/10;
        }
        if(k)
        {
            return j;
        }


    }
    return 0;























}


int main() {
    int n=1;
    //cin>>n;
    while(n--)
    {
        cout<<solver();
    }
}
