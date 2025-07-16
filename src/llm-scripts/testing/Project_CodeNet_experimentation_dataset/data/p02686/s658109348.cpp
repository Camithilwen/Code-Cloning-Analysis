#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

// chmax, chmin
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
function<T(T, T)> op_max = [](T a, T b) -> T { return max(a, b); };
template <typename T>
function<T(T, T)> op_min = [](T a, T b) -> T { return min(a, b); };

template <typename T>
function<T(T, T)> op_sum = [](T a, T b) -> T { return a + b; };

using namespace std;
//********************  dumps ************************//

template <typename T>
void dump(const T &data, vector<int> &iter)
{
  cout << data << " ";
}
template <typename T>
void dump(const vector<T> &data, vector<int> &iter)
{
  for (auto elem : data)
    dump(elem, iter);
  cout << endl;
}

template <typename T>
void dump(const vector<vector<T>> &data, vector<int> &iter)
{
  for (auto elem : iter)
  {
    cout << "[" << elem << "]";
  }
  cout << endl;
  for (int i = 0; i < data.size(); i++)
  {
    iter.push_back(i);
    dump(data[i], iter);
    iter.pop_back();
  }
  cout << endl;
}

template <typename T>
void dump(const vector<T> &data, int dummy)
{
  for (int i = 0; i < data.size(); i++)
  {
    cout << "[" << i << "] " << data[i] << endl;
  }
}
template <typename T>
void dump(const T &data)
{ // T : data, U = base type val.
  vector<int> iter;
  dump(data, iter);
}
///////////////////////////////////////////////

const string YES = "Yes";
const string NO = "No";

// up, down, l or r
vector<int> parse(string s)
{
  int cur = 0;
  int minim = 0;
  for (auto c : s)
  {
    if (c == '(')
      cur++;
    else
      cur--;
    chmin(minim, cur);
  }
  if (cur > 0)
  {
    return vector<int>({cur, minim, true});
  }
  return vector<int>({-cur, min(minim - cur, 0), false});
}

bool can_construct(vector<PII> input)
{

  priority_queue<PII> ord;
  for (auto elem : input)
  {
    ord.push(PII(elem.second, elem.first));
  }

  LL cur = 0;
  while (!ord.empty())
  {
    auto val = ord.top();

    if (cur + val.first < 0)
      return false;
    ord.pop();
    cur += val.second;
  }
  return true;
}

bool solve(long long N, std::vector<std::string> S)
{

  vector<PII> left, right;

  LL parity = 0;
  for (auto s : S)
  {
    auto ret = parse(s);
    if (ret[2])
      left.emplace_back(ret[0], ret[1]);
    else
      right.emplace_back(ret[0], ret[1]);
    if (ret[2])
      parity += ret[0];
    else
      parity -= ret[0];
  }
  if (parity != 0)
    return false;

  return can_construct(left) && can_construct(right);
}

int main()
{
  cout << setprecision(10);
  long long N;
  scanf("%lld", &N);
  std::vector<std::string> S(N);
  for (int i = 0; i < N; i++)
  {
    std::cin >> S[i];
  }
  if (solve(N, std::move(S)))
    cout << YES << endl;
  else
    cout << NO << endl;
  return 0;
}
