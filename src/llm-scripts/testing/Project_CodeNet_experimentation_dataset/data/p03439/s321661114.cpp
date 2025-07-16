#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N;
    cin >> N;
    int first = 0, last = (N - 1);
    vector<string> mem(N);
    string str1, str2;
    if (mem[first] == "")
    {
        cout << first << endl;
        cin >> str1;
        if (str1 == "Vacant")
            return 0;
        mem[first] = str1;
    }

    if (mem[last] == "")
    {
        cout << last << endl;
        cin >> str2;
        if (str2 == "Vacant")
            return 0;
        mem[last] = str2;
    }
    for (size_t i = 0; i < 18; i++)
    {
        int mid = (first + last) / 2;
        string str;
        if(mem[mid]=="")
        {
            cout<<mid<<endl;
            cin>>str;
            if(str == "Vacant")
            return 0 ;
            mem[mid]=str;
        }

        if (abs(first - mid) % 2 == 0)
        {
            if (mem[first] == mem[mid])
                first = mid;
            else
                last = mid;
        }
        else if (abs(first - mid) % 2 != 0)
        {
            if (mem[first] == mem[mid])
                last = mid;
            else
                first = mid;
        }
    }

    return 0;
}