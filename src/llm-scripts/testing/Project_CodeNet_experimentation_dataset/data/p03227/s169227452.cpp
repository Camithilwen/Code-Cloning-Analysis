#include <bits/stdc++.h>
using namespace std;
char s[100];
int main(){
    scanf("%s", s+1);   
    if(strlen(s+1) == 3) reverse(s+1, s+1+strlen(s+1));
    printf("%s", s+1);
}