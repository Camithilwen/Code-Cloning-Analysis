#define _CRT_SECURE_NO_WARNINGS
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i,n) for(int i=0;i<(lint)(n);i++)
#define REP(i,n) for(int i=1;i<=(lint)(n);i++)
#define all(V) V.begin(),V.end()
#define stackReplaceBegin(size)\
	void* p=malloc(size);\
	esp_new=(lint)p+size-1;\
	void * stack_extend_memory_ = malloc(size);\
	void * stack_extend_origin_memory_;\
	char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);\
	*stack_extend_dummy_memory_ = 0;\
	asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
typedef long long lint;
typedef unsigned long long ulint;
typedef std::pair<int, int> P;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;
constexpr double eps = DBL_EPSILON;
constexpr double PI = 3.141592653589793238462643383279;
lint esp_new;
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b; b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) {
	return a / gcd(a, b) * b;
}
bool isprime(lint n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
template<typename T>
T mypow(T a, unsigned int b) {
	T res(1),now(a);
	while(b){
		if(b&1)res*=now;
		b>>=1;
		now*=now;
	}
	return res;
}
template<typename T>
void printArray(std::vector<T>& vec) {
	rep(i, (int)vec.size() - 1)std::cout << vec[i] << " ";
	if(!vec.empty())std::cout << vec.back() << std::endl;
}
template<typename T>
void printArray(T l, T r) {
	T rprev = r;
	rprev--;
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
int h,w,a[510][510];
std::vector<std::pair<P,P>> vec;
int main(){
	std::cin>>h>>w;
	rep(i,h){
		rep(j,w)std::cin>>a[i][j];
	}
	rep(i,h){
		if(i%2==0){
			rep(j,w-1){
				if(a[i][j]%2){
					vec.push_back({{i,j},{i,j+1}});
					a[i][j]--;
					a[i][j+1]++;
				}
			}
			if(a[i][w-1]%2&&i!=h-1){
				vec.push_back({{i,w-1},{i+1,w-1}});
				a[i][w-1]--;
				a[i+1][w-1]++;
			}
		}
		else{
			for(int j=w-1;j>0;j--){
				if(a[i][j]%2){
					vec.push_back({{i,j},{i,j-1}});
					a[i][j]--;
					a[i][j-1]++;
				}
			}
			if(a[i][0]%2&&i!=h-1){
				vec.push_back({{i,0},{i+1,0}});
				a[i][0]--;
				a[i+1][0]++;
			}
		}
	}
	std::cout<<vec.size()<<std::endl;
	for(auto i:vec)std::cout<<i.first.first+1<<" "<<i.first.second+1<<" "<<i.second.first+1<<" "<<i.second.second+1<<std::endl;
	return 0;
}
