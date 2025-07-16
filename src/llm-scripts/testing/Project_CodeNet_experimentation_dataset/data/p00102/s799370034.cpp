#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

int main(){
  int n;
  while(cin>>n, n){
    int allsum = 0;
    vector<int> v(n);
    REP(i, n){
      int sum = 0;
      REP(j, n){
        int tmp;
        cin >> tmp;
        printf("%5d",tmp);
        allsum += tmp; sum += tmp;
        v[j] += tmp;
      }
      printf("%5d\n",sum);
    }
    REP(i, n)
      printf("%5d",v[i]);
    printf("%5d\n",allsum);
  }
  return 0;
}