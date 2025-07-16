# include <iostream>
using namespace std;

static const int ans[] = {
    0, 3, 14, 39, 84, 155, 258, 399, 584, 819, 1110
};

int main() {
    int a;
    cin >> a;
    cout << ans[a] << endl;
    return 0;
}