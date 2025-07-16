#ifdef __GNUC__ 
#include <bits/stdc++.h>
auto & in = std::cin;
#pragma GCC optimize ("O3") 
#pragma GCC target ("avx")

#else
std::istringstream in;
#endif
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/dynamic_bitset.hpp>
using namespace std;
#define ALL(v) std::begin(v),std::end(v)
using u6 = std::uint64_t;
using u3 = std::uint32_t;
constexpr u6 moduloNo = 1'000'000'000+7; //'

struct State {
	array<u3, 3> buf;
	//State() :buf{ 1,0,1 } {}
	State() {}
	State(u3 zerocount) :buf{ 1,0,zerocount } { addX(zerocount); }
	void addX(u3 zero) {
		if (zero != buf[2]){
			u6 zerodiff = zero - buf[2];
			buf[0] = (u3)(((u6)buf[0] + zerodiff * buf[1])%moduloNo);
			buf[2] = zero;

		}
		
		buf[1] = buf[0]+buf[1];
		buf[1] = (buf[1] >= moduloNo) ?buf[1] - moduloNo: buf[1];
	}
};
u6 pow2(u6 n) {
	if (n < 64)return (u6(1) << n)% moduloNo;
	else if (n == 64)return (u6(0) - moduloNo) % moduloNo;
	u6 tmp = pow2(n / 2);
	tmp=tmp * tmp;
	if (n & 1)tmp *= 2;
	return tmp % moduloNo;
}

struct Calc {
	u6 N;
	
	unordered_map<u3, State> stmap;
	Calc() {
		in >> N;
	}
	u6 calc() {
		u3 st = 0;
		u3 tmp;
		u3 zerocount = 0;
		for (u3 index = 0; index < N; ++index) {
			in >> tmp;
			st ^= tmp;
			if (!st) {
				++zerocount;
				//cout << index << endl;
			}
			else {
				auto ite = stmap.find(st);
				if (ite == stmap.end()) {
					stmap.emplace(st, zerocount);
				}
				else {					
					ite->second.addX(zerocount);
				}
			}
		}
		if (st != 0) {
			return stmap[st].buf[0];
		}
		else {
			u6 result = pow2(zerocount-1);
			for (auto & stv: stmap) {
				result = (result + stv.second.buf[1])%moduloNo;
			}
			
			/*u6 sum0 = 0, sum1 = 0;
			for (auto & stv : stmap) {
				cout << stv.second.buf[0] << " " << stv.second.buf[1]  <<  " " << stv.second.buf[2] << endl;
				sum0 += stv.second.buf[0];
				sum1 += stv.second.buf[1];
			}
			cout << sum0 << " " << sum1 << endl;*/
			return result;
		}
	}
};

int main() {

#ifndef __GNUC__ 
	in.str("32\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
#endif
	Calc calc;

	cout << calc.calc() << endl;
	/*
	u6 i = 0; u6 maxnum = 0;
	for (auto & v : tbl.buf) {
		for (auto n : v.buf) {
			if (n > maxnum)maxnum = n;
		}
	}
	cout << maxnum << endl;
	for (auto & v : tbl.buf) {
		cout << i << "=" << v << endl;
		++i;
	}
	cout << maxnum << endl;*/
}
