#include <bits/stdc++.h>
using namespace std;
int main(){


int k;
string s;
cin>>k>>s;



if(s.length()<=k) cout<<s<<endl;

else{

        for(int i=0;i<k;i++)   cout<<s[i];



        cout<<"."<<"."<<"."<<endl;


}

}
