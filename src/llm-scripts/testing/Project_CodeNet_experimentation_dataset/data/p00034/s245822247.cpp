#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    float l[11];
    float v1,v2;
    char s;
    while(1)
    {
        for(int i=1;i<=10;i++){
            cin >> l[i] >> s;
        }
        cin >> v1 >> s >> v2;
        if(cin.eof()) break;
       

        float t,la;
        float lsum=0;
        for(int i=1;i<=10;++i){
            lsum+= l[i];
        }

        t = lsum/(v1+v2);
        la = v1*t;
        lsum = 0;
        for(int i=1;i<10;i++)
        {
            lsum += l[i];
            if(lsum >= la){ cout << i << endl; break;}
        }
        if(lsum < la)cout << 10 << endl;
    }

    return 0;
}