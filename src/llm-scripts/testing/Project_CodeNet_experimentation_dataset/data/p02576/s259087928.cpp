#include <bits/stdc++.h>

using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using usize = std::size_t;
template<typename T>
using Vector = std::vector<T>;
using String = std::string;
template<typename T>
using UniquePointer = std::unique_ptr<T>;
using namespace std;

#define rep(i, max) for(usize i = 0; i < max; ++i)
#define loop while(true)

UniquePointer<String> readLine() {
    UniquePointer<String> line(new String());
    getline(cin, *line);
    return line;
}

template<typename T>
UniquePointer<Vector<T>> readVector(usize num) {
    UniquePointer<Vector<T>> list(new Vector<T>(num));
    rep(i, num) {
        cin >> (*list)[i];
    }
    return list;
}


template<typename T>
void writeLine(T arg) {
    cout << arg << endl;
}

template<typename T>
void write(T arg) {
    cout << arg << std::flush;
}

void program();

int main()
{
    ios::sync_with_stdio(false);
    program();
}

void program() {
    i32 n, x, t;
    cin >> n;
    cin >> x;
    cin >> t;
    readLine();
    writeLine((i32)(ceil((double)n / x) * t));
}