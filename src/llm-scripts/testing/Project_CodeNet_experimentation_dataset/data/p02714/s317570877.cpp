#include<bits/stdc++.h>
using namespace std;

long long ara[3][4007];

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x,y=0,z=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld",&n);
        cin>>str;

        if(n<=3)printf("0\n");
        else
        {

            for(i=0;i<n;i++)
            {
                if(str[i]=='R')cnt++;
                else if(str[i]=='G')y++;
                else{  z++; }

                ara[0][i+1]=cnt; ara[1][i+1]=y; ara[2][i+1]=z;
            }

            char ch,th,rh;

            for(i=0;i<n-2;i++)
            {
                ch=str[i];

                for(j=i+1;j<n-1;j++)
                {
                    if(str[j]!=ch)
                    {
                        th=str[j];

                        if(ch!='R' && th!='R')x=0;
                        else if(ch!='G' && th!='G')x=1;
                        else{ x=2;  }

                        fr=ara[x][n]-ara[x][j+1-1];

                        p=j-i; h=j+p;

                        if(h<=n-1)
                        {
                            if(x==2)rh='B';
                            else if(x==1)rh='G';
                            else{ rh='R';  }

                            if(str[h]==rh)fr--;

                        }

                        ans=ans+fr;

                    }

                }

            }

            printf("%lld\n",ans);

        }




    return 0;

}



