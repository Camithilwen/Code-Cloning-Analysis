#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

#define N 40
#define BIT (1<<17)
#define mod 1000000007

int add(int x,int y) {
  int ret = x+y;
  if(ret<0) {
    ret += mod;
  } else if(ret>=mod) {
    ret -= mod;
  }
  return ret;
}
int n,x[3],maxi;

int dp[N][BIT][2];
map<int,int> failure;
int ar[1000],tot = 0;

int failureCall(int bit) {
  if(bit==0) {
    return 0;
  }
  int nbit;
  if(failure.count(bit)) {
    return failure[bit];
  }
  for(int i=0;;++i) {
    if(bit&(1<<i)) {
      nbit = bit>>(i+1);
      break;
    }
  }
  if(nbit==0) {
    return 0;
  }
  if(nbit>=BIT) {
    return failure[bit] = failureCall(nbit);
  }
  int ret = 0;
  int sum = 0,cur = 0;
  int lastBit = -1;
  bool isGood = true;
  for(int i=0;;++i) {
    if((1<<i) >nbit) {
      break;
    }
    if(nbit&(1<<i)) {
      int a = i-lastBit;
      lastBit = i;
      sum += a;
      if(sum==x[cur]) {
        ++cur;
        sum = 0;
      }else if (sum>x[cur]) {
        isGood = false;
        break;
      }
    }
  }
  if(isGood) {
    return failure[bit] = nbit;
  } else {
    return failure[bit] = failureCall(nbit);
  }
}

map<int,pair<int,int> > BB;
pair<int,int> newBit(int bit,int num) {
  tot = 0;
  int lastBit = -1;
  int pos = 0;
  for(int i=0;i<17;++i) {
    if(bit&(1<<i)) {
      ar[pos++] = i-lastBit;
      lastBit = i;
    }
  }
  if(num!=-1) {
    ar[pos++] = num;
    bit |= (1<<(lastBit + num));
  }
  if(bit>=BIT) {
    return newBit(failureCall(bit),-1);
  }
  int cur = 0,sum = 0;
  for(int i=0;i<pos;++i) {
    sum += ar[i];
    tot += ar[i];
    if(sum==x[cur]) {
      ++cur;
      sum = 0;
    } else if(sum>x[cur]) {
      return newBit(failureCall(bit),-1);
    }
  }
  if( cur!=3) {
    return make_pair(0, bit);
  } else {
    //success but need failure
    return make_pair(1 , failureCall(bit));
  }
}
int solveDp(int ind,int bit,int isSatisfy) {
  if(ind==n) {
    if(isSatisfy) {
      return 1;
    } else {
      return 0;
    }
  }
  int &ret = dp[ind][bit][isSatisfy];
  if(ret!=-1) {
    return ret;
  }
  ret = 0;
  for(int num=1;num<=10;++num) {
    pair<int,int> nBit;
    if(num>maxi) {
      nBit = make_pair(0,0);
    } else {
      nBit = newBit(bit,num);
    }
    ret = add(ret, solveDp(ind+1,nBit.second, isSatisfy | nBit.first));
  }
  return ret;
}
void solve() {
  scanf("%d ", &n);
  for(int i=0;i<3;++i) {
    scanf("%d ", &x[i]);
    maxi = max(maxi,x[i]);
  }
  memset(dp,-1,sizeof(dp));
  printf("%d\n", solveDp(0,0,0));
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
