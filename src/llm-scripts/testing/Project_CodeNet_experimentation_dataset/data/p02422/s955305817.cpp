#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    char buf[1<<10];
    size_t q;
    scanf("%s %zu", buf, &q);
    string str(buf);

    for (size_t i=0; i<q; ++i) {
        size_t a, b;
        scanf("%s %zu %zu", buf, &a, &b);
        string instr(buf);

        if (instr == "print") {
            printf("%s\n", str.substr(a, b-a+1).c_str());
        } else if (instr == "reverse") {
            reverse(str.begin()+a, str.begin()+b+1);
        } else if (instr == "replace") {
            scanf("%s", buf);
            string p(buf);
            str.replace(a, b-a+1, p);
        }
    }

    return 0;
}