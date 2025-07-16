#include <functional>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <type_traits>
namespace loquat {
template <int MOD>
class modulus_integer {
public:
	typedef modulus_integer<MOD> self_type;
private:
	int m_value;
	static self_type unsafe_construct(int x) noexcept {
		self_type y;
		y.m_value = x;
		return y;
	}
public:
	modulus_integer() noexcept
		: m_value(0)
	{ }
	modulus_integer(int x) noexcept
		: m_value(x % MOD)
	{
		if(m_value < 0){ m_value += MOD; }
	}
	int operator*() const noexcept { return m_value; }
	self_type& operator=(const self_type& x) noexcept {
		m_value = x.m_value;
		return *this;
	}
	self_type operator+(const self_type& x) const noexcept {
		const int y = m_value + x.m_value;
		return unsafe_construct(y >= MOD ? y - MOD : y);
	}
	self_type operator*(const self_type& x) const noexcept {
		return unsafe_construct(
			static_cast<long long>(m_value) * x.m_value % MOD);
	}
	self_type& operator+=(const self_type& x) noexcept {
		return (*this = *this + x);
	}
	self_type& operator*=(const self_type& x) noexcept {
		return (*this = *this * x);
	}
};
template <int MOD>
inline std::ostream& operator<<(
	std::ostream& os, const modulus_integer<MOD>& x)
{
	os << *x;
	return os;
}
}
using namespace std;
static const int MOD = 1000000007;
using mint = loquat::modulus_integer<MOD>;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	vector<int> b(n);
	b[0] = a[0];
	for(int i = 1; i < n; ++i){ b[i] = b[i - 1] ^ a[i]; }
	vector<int> c(n + 1);
	for(int i = 0; i < n; ++i){ c[i + 1] = c[i] + (b[i] == 0 ? 1 : 0); }
	vector<mint> dp0(1 << 20), dpx(1 << 20);
	vector<int> last(1 << 20);
	for(int i = 0; i < n; ++i){
		const int k = c[i] - c[last[b[i]]];
		dp0[b[i]] += dpx[b[i]] * k;
		dpx[b[i]] += dp0[b[i]] + 1;
		last[b[i]] = i;
	}
	mint answer = 0;
	if(b.back() == 0){
		for(int i = 1; i < (1 << 20); ++i){ answer += dpx[i]; }
		mint z = 1;
		for(int i = 1; i < c.back(); ++i){ z *= 2; }
		answer += z;
	}else{
		answer = dp0[b.back()] + 1;
	}
	cout << answer << endl;
	return 0;
}
