
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>


#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s

typedef long long ll;

using namespace std;

ll modd = 1000 * 1000 * 1000 + 7;

template<class T>
class SegmentTree2 {
    public:
     
      SegmentTree2(const vector<T>& data, function<T(T,T)> f_, T zero_value = 0) : zv(zero_value), f(f_) {   
          Initialize(data);
      }

      SegmentTree2(int n, function<T(T,T)> f_, T zero_value = 0) : zv(zero_value), f(f_) {
          vector<T> temp(n, zv);
          Initialize(temp);
      }

      T operator[](int i) {
          return tree[B+i];
      }

      T GetEvaluation(int L, int R) {   // "min/max" on interval [L,R); 0-based indexing, as usual
        if (R<=L) {  return zv;  }
        return GetEvaluationHelper(L, R, 0, B, 1);
      }


      void SetVal(int i, T val) {
			tree[B+i] = val;
			for(int j = (B + i) / 2; j >= 1; j /= 2) {
				tree[j] = f(tree[2*j], tree[2*j+1]);
			}
      }

      private:
        vector<T> tree;
        int B;  // power of two greater than size of input data
        T zv;
        function<T(T,T)> f;

        void Initialize(const vector<T>& data) {
    	  B = 1;
          while(B < data.size()) {B *= 2;  }
          tree = std::move(vector<T>(2*B, zv));
          copy(data.begin(), data.end(), next(tree.begin(), B));
          for(int i = B - 1; i >= 1; --i) {
  	  	     tree[i] = f(tree[2*i], tree[2*i+1]);
          }
        }

      T GetEvaluationHelper(int L, int R, int start, int length, int tree_index) {
          if (L==R) {  return zv; }
          if ((L==start) && (R==start+length)) {   return tree[tree_index];  }
          int midpoint = start + length/2;

          T left_ = zv, right_ = zv;
          if (L<=min(midpoint,R)) {
            left_ = GetEvaluationHelper(L, min(midpoint,R), start, length/2, 2*tree_index);
          }
          if (max(midpoint,L)<=R) {
            right_ = GetEvaluationHelper(max(midpoint,L), R, midpoint, length/2, 2*tree_index+1);
          }
          return f(left_, right_);
      }

};




int main()   {

      ios_base::sync_with_stdio(false);

      cout.precision(17);
      mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
      uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no

//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n); readint(q);
        vector<ll> data;
        forr(i,0,n) {
            readint(dd); data.push_back(dd);
        }
        SegmentTree2<ll> seg(data, [](ll x, ll y){return x+y;}, 0);
        forr(i,0,q) {
            readint(a); readint(b); readint(c);
            if (a==0) {
                seg.SetVal(b, seg[b] + c);
            }
            if (a==1) {
                cout << seg.GetEvaluation(b,c) << endl;
            }
        }
    }
    return 0;
}
