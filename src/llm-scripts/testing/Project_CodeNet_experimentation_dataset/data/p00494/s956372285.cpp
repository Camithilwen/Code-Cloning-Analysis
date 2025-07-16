#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
static char str[1200000];
int len;
vector<pair<char, int> > x;
scanf("%s", str);
len = strlen(str);
x.reserve(len);
for(int i = 0; i < len; ++i) {
int it = i + 1;
while(it < len && str[it] == str[i]) ++it;
x.push_back(make_pair(str[i], it - i));
i = it - 1;
}
int ans = 0;
for(int i = 0; i < (int)x.size() - 2; ++i) {
pair<char, int> jjj = x[i], ooo = x[i + 1], iii = x[i + 2];
if(jjj.first != 'J' || ooo.first != 'O' || iii.first != 'I')
continue;
if(ooo.second > jjj.second || ooo.second > iii.second)
continue;
ans = max(ans, min(min(jjj.second, ooo.second), iii.second));
}

printf("%d\n", ans);
return 0;
}