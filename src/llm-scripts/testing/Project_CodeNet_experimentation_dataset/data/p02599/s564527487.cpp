#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

pair <int,int> T_z[500100], T_or[500100];
int T_l[500100], T_najb[500100], tree[1048576], sts[500100];

bool comparison(const pair<int,int> &a,const pair<int,int> &b){
    return ((a.first>b.first)||((a.first==b.first)&&(a.second>b.second)));
}
void wstaw(int x, int indx, int drz[])
{
    drz[indx]=x;
    while (indx!=1)
    {
        indx/=2; drz[indx]=drz[indx*2]+drz[indx*2+1];
    }
}
int suma_prz(int l, int p, int drz[])
{
    if (l==p) return drz[l];
    if (l/2==p/2) return drz[l/2];
    int res=drz[l]+drz[p];
    if (l%2==0) res+=drz[l+1];
    if (p%2==1) res+=drz[p-1];
    while (l/2/2!=p/2/2)
    {
        l/=2; p/=2;
        if (l%2==0) res+=drz[l+1];
        if (p%2==1) res+=drz[p-1];
    }
    return res;
}
int su_bin(int p1, int p2, int poc, int kon,  pair <int,int> T_wys[])
{
    int res, sr;
    while (poc<=kon)
    {
    sr=(poc+kon)/2;
    if (T_wys[sr].first<p1) {res=sr; kon=sr-1; continue;}
    if ((T_wys[sr].first==p1)&&(T_wys[sr].second<=p2)) {res=sr; kon=sr-1; continue;}
    poc=sr+1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    for (int i=0;i<n;i++) cin>>T_l[i];
    for (int i=0;i<q;i++)
    {
    cin>>T_z[i].first>>T_z[i].second;
    T_or[i].first=T_z[i].first; T_or[i].second=T_z[i].second;
    }
    sort(T_z, T_z+q, comparison);
    int pot;
    for (int i=1;;i=i*2)
    {
        if (i>=n) { pot=i; break; }
    }
    int kt_q=0; bool prz=false;
    for (int i=n-1;i>=0;i--)
    {
       if (prz) break;
       if (T_najb[T_l[i]]!=0) wstaw(0, pot+T_najb[T_l[i]], tree);
       wstaw(1, pot+i, tree);
       T_najb[T_l[i]]=i;
       while (T_z[kt_q].first==i+1)
       {
           sts[kt_q]=suma_prz(T_z[kt_q].first+pot-1, T_z[kt_q].second+pot-1, tree);
           kt_q++;
           if (kt_q==q)  {prz=true; break;}
       }
    }
    for (int i=0;i<kt_q;i++)
    {
        cout<<sts[su_bin(T_or[i].first,T_or[i].second, 0, kt_q, T_z)]<<"\n";
    }

}
