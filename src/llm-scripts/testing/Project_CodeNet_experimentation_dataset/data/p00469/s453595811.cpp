#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first1,
	BidirectionalIterator last1,
	BidirectionalIterator first2,
	BidirectionalIterator last2)
{
	if ((first1 == last1) || (first2 == last2)) {
		return false;
	}
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;
	while (--m1 != first1 && !(*m1 < *m2)) {
	}
	bool result = (m1 == first1) && !(*first1 < *m2);
	if (!result) {
		// ???
		while (first2 != m2 && !(*m1 < *first2)) {
			++first2;
		}
		first1 = m1;
		std::iter_swap(first1, first2);
		++first1;
		++first2;
	}
	if ((first1 != last1) && (first2 != last2)) {
		// ???
		m1 = last1; m2 = first2;
		while ((m1 != first1) && (m2 != last2)) {
			std::iter_swap(--m1, m2);
			++m2;
		}
		// ??¢
		std::reverse(first1, m1);
		std::reverse(first1, last1);
		std::reverse(m2, last2);
		std::reverse(first2, last2);
	}
	return !result;
}

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first,
	BidirectionalIterator middle,
	BidirectionalIterator last)
{
	return next_combination(first, middle, middle, last);
}

int main() {
	while (1) {
		int N; cin >> N; int K; cin >> K;
		if (!N)break;
		vector<string>sts;
		for (int i = 0; i < N; ++i) {
			string st; cin >> st;
			sts.emplace_back(st);
		}
		vector<int>nums(N);
		iota(nums.begin(), nums.end(), 0);
		set<string>anss;
		do {
			vector<int>anums(K);
			iota(anums.begin(), anums.end(), 0);
			do {
				string ans;
				for (int i = 0; i < K; ++i) {
					ans += sts[nums[anums[i]]];
				}
				anss.emplace(ans);
			} while (next_permutation(anums.begin(), anums.end()));
		} while (next_combination(nums.begin(),nums.begin()+K, nums.end()));
		cout << anss.size() << endl;
	}
	return 0;
}