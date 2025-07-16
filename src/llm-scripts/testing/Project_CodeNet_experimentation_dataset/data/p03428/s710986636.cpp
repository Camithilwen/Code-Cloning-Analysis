#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string.h>
using namespace std;

struct node
{
    double x,y;
};

double PI=acos(-1.0);
int n;
node p[111];
double ans[111];

void merge(double &from,double &to,double ff,double tt)
{
    if(from>ff)
    {
        swap(from,ff);
        swap(to,tt);
    }
    
    
    if(to==-2.0*PI)
    {
        from=ff;to=tt;
        return ;
    }
    
    double f0,t0;
    
    
    f0=max(from,ff);
    t0=min(to,tt);
    
    if(f0<=t0)
    {
         from=f0;to=t0;
         return ;
    }
    
    if(tt>PI)
    {
        ff-=2.0*PI;
        tt-=2.0*PI;
        f0=max(from,ff);
        t0=min(to,tt);
    }
    
    from=f0;to=t0;
    return ;
}


int main()
{
    int i,j,k;
    double from,to;
    
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    for(i=1;i<=n;i++)
    {
        from=-PI*4.0;
        to=-PI*2.0;
            
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;
            
            
            node l;
            l.x=p[j].x-p[i].x;
            l.y=p[j].y-p[i].y;
            
            double e=atan2(l.x,l.y);
            //cout<<atan2(0,-1)<<endl;
            e+=PI/2.0;
            if(e>PI)e-=2.0*PI;
            double ff,tt;
            ff=e;tt=e+PI;
            
            //cout<<ff<<' '<<tt<<"   %%%"<<endl;
            merge(from,to,ff,tt); 
            //cout<<from<<' '<<to<<endl;
        }
        
        cout.precision(7);
        cout.setf(ios::fixed);
        cout<<max((to-from)/(PI*2.0),0.0)<<endl;
    }
    return 0;
}
