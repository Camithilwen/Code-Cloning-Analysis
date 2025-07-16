#include<bits/stdc++.h>

using namespace std;
typedef         long long int   ll;

#define         input           freopen("input.txt","r",stdin)
#define         output          freopen("output.txt","w",stdout)
#define         si(a)           scanf("%d",&a)
#define         sii(a,b)        scanf("%d%d",&a,&b)
#define         siii(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define         pi(a)           printf("%d",a)
#define         spc             printf(" ")
#define         bl              printf("\n")
#define         here(a)         printf("#### %d ####",a)
#define         pii             pair<int,int>
#define         fr(i,n)         for(int i=0;i<n;i++)
#define         case(num)       printf("Case %d:",num)
#define         inf             1000000050
#define         MAX             10010
#define         MOD             1000000007

vector<int>edge;
vector<vector<int> >triangle;
void npr(vector<int>v, int p){

    if(v.size()==3){
        triangle.push_back(v);
        //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        //cout<<endl;
        return;
    }
    if(p>=edge.size()) return;
    npr(v,p+1);
    v.push_back(edge[p]);
    npr(v,p+1);
    v.pop_back();
}


int main(){

    //input;
    //output;

    int n,tmp;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>tmp;
        edge.push_back(tmp);
    }

    vector<int>v;

    npr(v,0);
    int a,b,c;
    int cnt = 0;

    for(int i=0;i<triangle.size();i++){
        sort(triangle[i].begin(),triangle[i].end());
        a = triangle[i][0];
        b = triangle[i][1];
        c = triangle[i][2];
        if(a!=b && a!=c && b!=c){
            if(a+b>c) cnt++;
        }
    }


    cout<<cnt<<endl;




    return 0;
}
/**
*/
