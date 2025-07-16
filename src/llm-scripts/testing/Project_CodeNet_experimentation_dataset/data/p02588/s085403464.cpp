#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>

using ll = long long ;
#define MAXN 200009
#define MAXL 29 
std::map<std::pair<int,int>, int> bucket;

class Rat
{
    private:
        int cofp2,cofp5;
    public:
        Rat(){}
        Rat(ll nn,ll dd)
        {
           ll tn = nn;
           ll td = dd;
           cofp2 = 0;
           while( tn%2==0){
               cofp2++;
               tn/=2;
           } 
           while(td%2==0){
               cofp2--;
               td/=2;
           }
           cofp5=0;
           while(tn%5==0){
               cofp5++;
               tn/=5;
           }
           while(td%5==0){
               cofp5--;
               td/=5;
           }
        }
        void output() 
        { 
            printf("2^{%d}*5^{%d}\n",cofp2,cofp5); 
        } 
        int getcofp2()
        {
            return cofp2;
        }
        int getcofp5()
        {
            return cofp5;
        }
}; 
        

int main(void) 
{ 
    char theNumber[MAXL]; 
    int N,i,j;
    scanf("%d",&N);
    Rat *a ;

    for (i=0;i<N;i++){
        scanf("%s",theNumber);
        char* ret = strchr(theNumber,'.');
        if (ret==NULL){
            a = new Rat(atoi(theNumber),1); 
        } else {
            int lenOfDen = strlen(&theNumber[ret-&theNumber[0]+1]);
            ll den = pow(10,lenOfDen); 
            ll num = atoi(theNumber)*den
            +atoi(&theNumber[ret-&theNumber[0]+1]);
            a = new Rat(num,den);
        }
        bucket[std::make_pair(a->getcofp2(),a->getcofp5())] ++;
    }

    ll s=0;
    for (auto it:bucket) {
        int x1 = it.first.first;
        int y1 = it.first.second;
        int r1 = it.second;
        for (auto it2:bucket) {
            int x2 = it2.first.first;
            int y2 = it2.first.second;
            int r2 = it2.second;

            if(x1+x2>=0 && y1+y2>=0)
            {
                if(it<it2){
                    s+=((ll)r1)*r2;
                } else if (it==it2) {
                    s+=((ll)r1*(r1-1))/2;
                }
            }
        }
    }

    printf("%lld\n",s);

    return 0;
}
