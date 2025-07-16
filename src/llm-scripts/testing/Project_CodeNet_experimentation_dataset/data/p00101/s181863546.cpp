#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;cin.get( );
    //n++;
    string ss;
    for(int j=0;j<n;j++)
    {
        getline(cin,ss);
        int len =ss.size();
        for(int i=6;i<len;i++)
        {
            //cout << ss[i];
            if(ss.substr(i-6,7)=="Hoshino")
            {
                ss[i]='a';
            }
            //if(ss[i]=='\0')break;
        }

        /*for(int i=0;i<len;i++){
            if(ss[i]=='\0')break;
            cout <<ss[i];
        }*/
        cout <<ss << endl;
    }
    return 0;
}