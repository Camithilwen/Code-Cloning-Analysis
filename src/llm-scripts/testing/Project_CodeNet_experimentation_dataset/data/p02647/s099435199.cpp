#include <cstdio>
#include <algorithm>

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

i32 a[200000];

auto main() -> i32 {
	i32 n, k;
	scanf("%d%d", &n, &k);
	for (i32 i = 0; i < n; i += 1) {
		scanf("%d", a + i);
	}
	i32 b[200001];
	for (i32 step = 0; step < std::min(64, k); step += 1) {
		std::fill(b, b + n + 1, 0);
		for (i32 i = 0; i < n; i += 1) {
			b[std::max(0, i - a[i])] += 1;
			b[std::min(n, i + a[i] + 1)] -= 1;
		}
		a[0] = b[0];
		for (i32 i = 1; i < n; i += 1) {
			b[i] += b[i - 1];
			a[i] = b[i];
		}
	}
	for (i32 i = 0; i < n; i += 1) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
