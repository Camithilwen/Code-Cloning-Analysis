#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int cards[5];

bool check ()
{
     for (int i = 0; i < 5; i++) if (cards[i] > 0) return true;
     return false;
}

void ref() { for (int i = 0; i < 5; i++) cards[i] = 0; }

int main()
{
     while (scanf("%d,%d,%d,%d,%d", &cards[0], &cards[1], &cards[2], &cards[3], &cards[4]) != EOF) {
          int yaku = 0;

          sort(cards, cards + 5);

          if (check() && cards[0] == cards[1] && cards[1] == cards[2] && cards[2] == cards[3]) {yaku = 6; ref();}
          if (check() && cards[1] == cards[2] && cards[2] == cards[3] && cards[3] == cards[4]) {yaku = 6; ref();}
          if (check() && cards[0] == cards[1] && cards[1] == cards[2] && cards[3] == cards[4]) {yaku = 5; ref();}
          if (check() && cards[2] == cards[3] && cards[3] == cards[4] && cards[0] == cards[1]) {yaku = 5; ref();}
          if (check() && cards[0] + 1 == cards[1] && cards[1] + 1 == cards[2] && cards[2] + 1 == cards[3] && cards[3] + 1 == cards[4]) {yaku = 4; ref();}
          if (check() && cards[0] == 1 && cards[1] == 10 && cards[2] == 11 && cards[3] == 12 && cards[4] == 13) {yaku = 4; ref();}

          int tmp = 0;
          for (int i = 0; i < 5 && check(); i++) {
               int t = cards[i];
               cards[i] = 0;
               if (t == 0) continue;
               for (int j = 0; j < 5; j++) {
                    if (i == j) continue;
                    if (cards[j] == 0) continue;
                    if (t == cards[j]) tmp++;
               }
               yaku = tmp;
          }

          switch (yaku) {
          case 1: cout << "one pair" << endl; break;
          case 2: cout << "two pair" << endl; break;
          case 3: cout << "three card" << endl; break;
          case 5: cout << "full house" << endl; break;
          case 6: cout << "four card" << endl; break;
          case 4: cout << "straight" << endl; break;
          default: cout << "null" << endl;
          }
     }

     return 0;
}