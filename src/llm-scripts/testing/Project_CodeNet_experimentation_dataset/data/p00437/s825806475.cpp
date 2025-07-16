#include<cstdio>
 
int main()
{
while(true) {

int a, b, c, n;
int test[3000], r[1000];
int ans[1000];
scanf("%d%d%d", &a, &b, &c);
if(a == 0)
break;
scanf("%d", &n);
for(int i = 0; i < n; ++i) {
scanf("%d%d%d%d", test + i * 3, test + i * 3 + 1, test + i * 3 + 2, r + i);
test[i * 3] -= 1, test[i * 3 + 1] -= 1, test[i * 3 + 2] -= 1;
}

for(int i = 0; i < a + b + c; ++i)
ans[i] = 2;
for(int i = 0; i < n; ++i) {
if(r[i] != 1)
continue;
for(int j = i * 3; j < i * 3 + 3; ++j)
ans[test[j]] = 1;
}
for(int i = 0; i < n; ++i) {
if(r[i] != 0)
continue;
int correct = 0;
for(int j = i * 3; j < i * 3 + 3; ++j)
correct += (ans[test[j]] == 1);
if(correct != 2)
continue;
for(int j = i * 3; j < i * 3 + 3; ++j) {
if(ans[test[j]] != 1)
ans[test[j]] = 0;
}
}
for(int i = 0; i < a + b + c; ++i)
printf("%d\n", ans[i]);
}
return 0;
}