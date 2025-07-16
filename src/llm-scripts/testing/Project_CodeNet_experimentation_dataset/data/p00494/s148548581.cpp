#include <bits/stdc++.h>

using namespace std;

ifstream fi("JJOOII.INP");
ofstream fo("JJOOII.OUT");

#define fi cin
#define fo cout

string S;
int demJ,demO,demI,res;

void xuli()
{
    int i=0;
    while (1)
    {
        while (S[i]=='J') ++i,++demJ;
        while (S[i]=='O') ++i,++demO;
        while (S[i]=='I') ++i,++demI;
        if (demJ>=demO && demI>=demO) res=max(res,demO);
        demJ=demO=demI=0;
        if (S[i]=='@') return;
    }
}

int main()
{
    fi>>S;
    S+='@';
    xuli();
    fo<<res<<'\n';
}