#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000007
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


int main(){
string s ;
cin>>s;
int ans = s[0]-'0';
for(int op1 = 0 ;op1 < 2;op1++)
{
     if(op1)
        {
            ans+=(s[1]-'0');
        }
        else ans-=(s[1]-'0');
    for(int op2 = 0;op2<2;op2++)
    {
       if(op2)
        {
            ans+=(s[2]-'0');
        }
        else ans-=(s[2]-'0');
        for(int op3 = 0 ; op3<2;op3++)
        {
              if(op3)
            {
            ans+=(s[3]-'0');
            }
             else ans-=(s[3]-'0');

             if(ans==7)
             {
                 cout<<s[0];
                 if(op1)cout<<"+";
                 else cout<<"-";
                 cout<<s[1];
                 if(op2)cout<<"+";
                 else
                    cout<<"-";
                 cout<<s[2];
                  if(op3)cout<<"+";
                 else
                    cout<<"-";
                cout<<s[3] <<"=7"<<endl;
                 return 0;
             }


             if(op3)
            {
            ans-=(s[3]-'0');
            }
             else ans+=(s[3]-'0');

        }
          if(op2)
        {
            ans-=(s[2]-'0');
        }
        else ans+=(s[2]-'0');
    }

    if(op1)
        {
            ans-=(s[1]-'0');
        }
        else ans+=(s[1]-'0');
}

 return 0;
}
