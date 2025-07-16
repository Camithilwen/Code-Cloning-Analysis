#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 3e5 + 5;

struct State {
  int pc, sl, sv;

  State (int _pc, int _sl, int _sv) :
    pc(_pc), sl(_sl), sv(_sv) {}
};

ostream& operator<< (ostream &out, State s) {
  out << "(" << s.pc << " " << s.sl << " " << s.sv << ")";
  return out;
}

State nxt (State s, int c) {
  if (s.pc == 2) return s;

  if (s.sl == 0) {
    if (c == 0) return State(s.pc, s.sl + 1, 0);
    if (c == 1) return State(s.pc + 1, 0, 0);
  }

  if (s.sl == 1) {
    return State(s.pc, s.sl + 1, 2 * s.sv + c);
  }

  if (c == 0) {
    if (s.sv == 0) {
      return State(s.pc, 1, 0);
    } else {
      return State(s.pc, 1, 0);
    }
  } else {
    if (s.sv == 0) {
      return State(s.pc, 1, 0);
    } else {
      return State(s.pc + 1, 0, 0);
    }
  }
};

Modint _dp [MAX_N][3][3][4];

Modint& dp (int i, State s) {
  return _dp[i][s.pc][s.sl][s.sv];
}

int main () {
  string s;
  cin >> s;

  int n = s.size();
  
  vector<State> alls;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        alls.push_back(State(i, j, k));
      }
    }
  }

  dp(0, State(0, 0, 0)) = Modint(1);
  for (int i = 0; i < n; i++) {
    for (State st : alls) {
      if (s[i] != '1') {
        dp(i + 1, nxt(st, 0)) += dp(i, st);
      }
      if (s[i] != '0') {
        dp(i + 1, nxt(st, 1)) += dp(i, st);
      }
    }
  }

  Modint ans (0);
  ans += dp(n, State(2, 0, 0));
  ans += dp(n, State(1, 2, 1));
  ans += dp(n, State(1, 0, 0));
  cout << ans << endl;
}
