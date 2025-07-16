#ifdef _WIN32
#include "XOR.h"
#endif

#include <stdio.h>

#include <iostream>
#include <vector>
#include <array>

constexpr int64_t MOD = 1'000'000'007;
constexpr int64_t help = 1;

#define ll long long int

#define o(X) ll bits##X = 0
//#define ok(X) bits##X += !!(d & (help << X))
#define ok(X) bits##X += d & 1; d >>= 1;

#define oke(X) ans += (bits##X * (n - bits##X) % MOD) *((help << X) % MOD); ans %= MOD;
//ll p = (help << b) % MOD;
//ans += (bits[b] * (n - bits[b]) % MOD) * p;
//ans %= MOD;

void fastscan(ll& number) {
	//variable to indicate sign of input number 
	int c;

	number = 0;

	// extract current character from buffer 
	c = getchar();

	// Keep on extracting characters if they are integers 
	// i.e ASCII Value lies from '0'(48) to '9' (57) 
	for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;

	// if scanned input has a negative sign, negate the 
	// value of the input number 
}
#ifdef _WIN32
namespace XOR
{
#endif 

	int main() {
		ll n;

		fastscan(n);

		o(0);
		o(1);
		o(2);
		o(3);
		o(4);
		o(5);
		o(6);
		o(7);
		o(8);
		o(9);
		o(10);
		o(11);
		o(12);
		o(13);
		o(14);
		o(15);
		o(16);
		o(17);
		o(18);
		o(19);
		o(20);
		o(21);
		o(22);
		o(23);
		o(24);
		o(25);
		o(26);
		o(27);
		o(28);
		o(29);
		o(30);
		o(31);
		o(32);
		o(33);
		o(34);
		o(35);
		o(36);
		o(37);
		o(38);
		o(39);
		o(40);
		o(41);
		o(42);
		o(43);
		o(44);
		o(45);
		o(46);
		o(47);
		o(48);
		o(49);
		o(50);
		o(51);
		o(52);
		o(53);
		o(54);
		o(55);
		o(56);
		o(57);
		o(58);
		o(59);
		o(60);
		o(61);
		o(62);

		std::array<ll, 62> bits{};
		for (ll i = 0; i < n; i++) {
			ll d;
			fastscan(d);
			ok(0);
			ok(1);
			ok(2);
			ok(3);
			ok(4);
			ok(5);
			ok(6);
			ok(7);
			ok(8);
			ok(9);
			ok(10);
			ok(11);
			ok(12);
			ok(13);
			ok(14);
			ok(15);
			ok(16);
			ok(17);
			ok(18);
			ok(19);
			ok(20);
			ok(21);
			ok(22);
			ok(23);
			ok(24);
			ok(25);
			ok(26);
			ok(27);
			ok(28);
			ok(29);
			ok(30);
			ok(31);
			ok(32);
			ok(33);
			ok(34);
			ok(35);
			ok(36);
			ok(37);
			ok(38);
			ok(39);
			ok(40);
			ok(41);
			ok(42);
			ok(43);
			ok(44);
			ok(45);
			ok(46);
			ok(47);
			ok(48);
			ok(49);
			ok(50);
			ok(51);
			ok(52);
			ok(53);
			ok(54);
			ok(55);
			ok(56);
			ok(57);
			ok(58);
			ok(59);
			ok(60);
			ok(61);
			ok(62);
		}

		ll ans = 0;

		oke(0);
		oke(1);
		oke(2);
		oke(3);
		oke(4);
		oke(5);
		oke(6);
		oke(7);
		oke(8);
		oke(9);
		oke(10);
		oke(11);
		oke(12);
		oke(13);
		oke(14);
		oke(15);
		oke(16);
		oke(17);
		oke(18);
		oke(19);
		oke(20);
		oke(21);
		oke(22);
		oke(23);
		oke(24);
		oke(25);
		oke(26);
		oke(27);
		oke(28);
		oke(29);
		oke(30);
		oke(31);
		oke(32);
		oke(33);
		oke(34);
		oke(35);
		oke(36);
		oke(37);
		oke(38);
		oke(39);
		oke(40);
		oke(41);
		oke(42);
		oke(43);
		oke(44);
		oke(45);
		oke(46);
		oke(47);
		oke(48);
		oke(49);
		oke(50);
		oke(51);
		oke(52);
		oke(53);
		oke(54);
		oke(55);
		oke(56);
		oke(57);
		oke(58);
		oke(59);
		oke(60);
		oke(61);
		oke(62);
		//for (ll b = 0; b < 62; b++) {
		//	ll p = (help << b) % MOD;
		//	ans += (bits[b] * (n - bits[b]) % MOD) * p;
		//	ans %= MOD;
		//}

		std::cout << ans;
		return 0;
	}
#ifdef _WIN32
}
#endif 
