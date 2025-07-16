#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;


const long long int mod = 1000000007;
const long long int INF = 99999999999999999;



long long int N,M;

long long int H,W,A[210005]={},Q,sum[210005]={},res=INF;




int main()
{
    cout << fixed << setprecision(18);
   cin>>N;
   for(long long int i = 1; i <= N; i++){
       cin>>A[i];
   }
   for(long long int i = 1; i <= N; i++){
       sum[i]=sum[i-1]+A[i];
   }
   for(long long int i = 2; i <= N-2; i++){
       long long int p=1,q=i,pq;
       while(q-p>1){
           pq=(p+q)/2;
           if(sum[pq]*2>=sum[i]){
               q=pq;
           }else{
               p=pq;
           }
       }
       long long int P=sum[p],Q=sum[i]-sum[p];
        if(q!=i&&abs(sum[i]-2*sum[p+1])<=Q-P){
            P=sum[p+1];
            Q=sum[i]-sum[p+1];
        }
       long long int r=i+1,s=N,rs;
       while(s-r>1){
           rs=(r+s)/2;
           if((sum[rs]-sum[i])*2>=sum[N]-sum[i]){
               s=rs;
           }else{
               r=rs;
           }
       }
        long long int R=sum[r]-sum[i],S=sum[N]-sum[r];
        //cout<<R<<" "<<S<<endl;
        if(s!=N&&abs(sum[N]-2*sum[r+1]+sum[i])<=S-R){
            R=sum[r+1]-sum[i];
            S=sum[N]-sum[r+1];
        }
        //cout<<i<<" "<<P<<" "<<Q<<" "<<R<<" "<<S<<endl;
        res=min(res,max({P,Q,R,S})-min({P,Q,R,S}));
   }
   cout<<res<<endl;
}
