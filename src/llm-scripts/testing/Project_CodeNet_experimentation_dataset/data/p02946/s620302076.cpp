#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<iterator>
#include<vector>
#include<map>
#include<utility>
#include<set>
#include<stack>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    int k,x;
    cin>>k>>x;
    for(int i=1;i<2*k;i++)cout<<x-k+i<<" ";
    return 0;
}
