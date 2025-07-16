//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
	struct Test {
		ll b;
		ll l;
		ll u;
	};
	ll N, X;
	vector<Test> tests;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int bi, li, ui;
		cin >> bi >> li >> ui;
		tests.push_back({bi, li, ui});
	}
	auto full_score = [X](Test test) {
		return (X - test.b) * test.u - (0 - test.b) * test.l;
	};
	sort(tests.begin(), tests.end(), [&full_score](Test lhs, Test rhs) {
		return full_score(lhs) > full_score(rhs);
	});
	vector<ll> full_score_sum;
	{
		ll sum = 0;
        full_score_sum.push_back(sum);
		for (Test test : tests) {
			sum += full_score(test);
			full_score_sum.push_back(sum);
		}
	}
	ll zero_score = 0;
	for (Test test : tests) {
		zero_score += (0 - test.b) * test.l;
	}
	ll lower = -1;
	ll upper = N * X;
	while (lower + 1 < upper) {
		ll time = (lower + upper) / 2;
		ll full_cnt = time / X;
		ll residue = time % X;
		ll score_max = numeric_limits<ll>::min();
		if (residue == 0) {
			ll score = 0;
            score = full_score_sum[full_cnt];
			score_max = max(score_max, score);
		} else {
			for (int i = 0; i < tests.size(); i++) {
				ll score = 0;
				if (residue < tests[i].b) {
					score = (residue - tests[i].b) * tests[i].l
						- (0 - tests[i].b) * tests[i].l;
				} else {
					score = (residue - tests[i].b) * tests[i].u
						- (0 - tests[i].b) * tests[i].l;
				}
                if (i >= full_cnt) {
                    score += full_score_sum[full_cnt];
                } else {
                    score += full_score_sum[i];
                    score += full_score_sum[full_cnt + 1] - full_score_sum[i + 1];
                }
				score_max = max(score_max, score);
			}
		}
        if (score_max + zero_score >= 0) {
            upper = time;
        } else {
            lower = time;
        }
	}
	cout << upper << endl;
}
