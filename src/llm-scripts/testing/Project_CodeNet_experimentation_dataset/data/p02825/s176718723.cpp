/*************************************
 * @contest:      AGC041.
 * @user_name:    hkxadpall.
 * @time:         2019-12-28.
 * @language:     C++.
 * @upload_place: AtCoder.
*************************************/ 

#include <bits/stdc++.h>
using namespace std;

typedef signed char          int8;
typedef unsigned char       uint8;
typedef short                int16;
typedef unsigned short      uint16;
typedef int                  int32;
typedef unsigned            uint32;
typedef long long            int64;
typedef unsigned long long  uint64;

template <typename Int>
inline Int read()       
{
    Int flag = 1;
    char c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
	return init * flag;
}

template <typename Int>
inline Int read(char &c)       
{
    Int flag = 1;
    c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
	return init * flag;
}

template <typename Int>
inline void write(Int x)
{
    if (x < 0) putchar('-'), x = ~x + 1;
    if (x > 9) write(x / 10);
    putchar((x % 10) | 48);
}  

template <typename Int>
inline void write(Int x, char nextch)
{
    write(x);
    putchar(nextch);
}

int n;
char a[1007][1007];
// bool col[1007];
int now = 0;

void set3(int i, int j) // sum = 1
{
    a[i][j] = a[i][j + 1] = 'o';
    a[i + 1][j + 2] = a[i + 2][j + 2] = 'p';
}

void set4(int i, int j) // sum = 3
{
    a[i + 0][j + 0] = 'a'; a[i + 0][j + 1] = 'a'; a[i + 0][j + 2] = 'c'; a[i + 0][j + 3] = 'd';
    a[i + 1][j + 0] = 'b'; a[i + 1][j + 1] = 'b'; a[i + 1][j + 2] = 'c'; a[i + 1][j + 3] = 'd';
    a[i + 2][j + 0] = 'e'; a[i + 2][j + 1] = 'f'; a[i + 2][j + 2] = 'g'; a[i + 2][j + 3] = 'g';
    a[i + 3][j + 0] = 'e'; a[i + 3][j + 1] = 'f'; a[i + 3][j + 2] = 'h'; a[i + 3][j + 3] = 'h';
}

void set5(int i, int j)
{
    a[i + 0][j + 0] = 'a'; a[i + 0][j + 1] = 'a'; a[i + 0][j + 2] = 'b'; a[i + 0][j + 3] = 'b'; a[i + 0][j + 4] = 'c';
    a[i + 1][j + 0] = 'd'; a[i + 1][j + 1] = 'e'; a[i + 1][j + 2] = 'e'; a[i + 1][j + 3] = '.'; a[i + 1][j + 4] = 'c';
    a[i + 2][j + 0] = 'd'; a[i + 2][j + 1] = '.'; a[i + 2][j + 2] = '.'; a[i + 2][j + 3] = 'e'; a[i + 2][j + 4] = 'a';
    a[i + 3][j + 0] = 'a'; a[i + 3][j + 1] = '.'; a[i + 3][j + 2] = '.'; a[i + 3][j + 3] = 'e'; a[i + 3][j + 4] = 'a';
    a[i + 4][j + 0] = 'a'; a[i + 4][j + 1] = 'b'; a[i + 4][j + 2] = 'b'; a[i + 4][j + 3] = 'c'; a[i + 4][j + 4] = 'c';
}

void set7(int x, int y)
{
    static const char tpr[7 + 3][7 + 3] = {
        "aa..bba", 
        "b.cc..a", 
        "bc.dd..", 
        ".cd.cc.", 
        "..dc..b", 
        "a..c..b", 
        "abb..aa", 
    };
    for (int i = 0; i < 7; i++) {
        strncpy(a[x + i] + y, tpr[i], 7);
    }
}

void outputMat() 
{
    for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < n; j++) {
            if (a[i][j]) putchar(a[i][j]);
            else putchar('.');
        }
        putchar('\n');
    }
}

int main()
{
    n = read<int>();
    if (n % 4 == 0) {
        for (register int i = 0; i < n; i += 4) set4(i, i);
        outputMat();
    } else if (n % 3 == 0) {
        for (register int i = 0; i < n; i += 3) set3(i, i);
        outputMat(); 
    } else if (n % 4 == 1 && n >= 5) {
        for (int i = 0; i < n - 5; i += 4) set4(i, i);
        set5(n - 5, n - 5);
        outputMat(); 
    } else if (n % 4 == 2 && n >= 10) {
        for (int i = 0; i < n - 10; i += 4) set4(i, i);
        set5(n - 10, n - 10);
        set5(n - 5, n - 5);
        outputMat(); 
    } else if (n % 4 == 3 && n >= 7) {
        for (int i = 0; i < n - 7; i += 4) set4(i, i);
        set7(n - 7, n - 7);
        outputMat(); 
    } else puts("-1");
    return 0;
}