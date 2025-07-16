#include <bits/stdc++.h>
using namespace std;
#define data_type int
#define endl "\n"

int  main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    data_type x1=-2,y1=-2,n;
    bool check=0;
    string str;
    cin>>str;
    n=str.size();
    for(int i=0; i<n-1; i++)
        {
            if(str[i]==str[i+1])
                {
                    x1=i,y1=i+1;
                    check=1;
                    break;
                }

        }

    if(!check)
        {
            for(int i=1; i<n-1; i++)
                {
                    if(str[i-1]==str[i+1])
                        {
                            x1=i-1,y1=i+1;
                            check=1;
                            break;
                        }

                }
        }


    cout<<x1+1<<" "<<y1+1<<endl;

    return 0;
}
