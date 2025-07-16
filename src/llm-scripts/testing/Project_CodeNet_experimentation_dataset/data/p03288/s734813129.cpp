/**
 * auther: moririn_cocoa
 */
// #pragma GCC target("avx")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
// #define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
// #define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_)

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second

int main(int argc, char* argv[]) {
  
  int R;
  
  cin >> R;
  
  if ( R < 1200 ) {
    
    cout << "ABC" << endl;
  }
  
  else if ( R >= 1200 && R < 2800 ) {
    
    cout << "ARC" << endl;
  }
  
  else {
    
    cout << "AGC" << endl;
  }
  
  return 0;
}