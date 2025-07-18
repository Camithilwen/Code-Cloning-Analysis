/**
 * ???????????? I

?¬?????±??????????????????????????????????????????¢??????????????\??¬????????§????????????????????°????????????????????????????????????






????????????????????¢??????????????¨????????? 1 ?????? 6 ????????????????????????????????????????????????

??\?????¨??????????????????????????¢?????????????????????????????°?????¨?????¢?????????????????????????????????????????§???????????????????????¢?????°?????????????????????????????????????????\??¬????????§??????????????¶?????????????????¨?????????????????????????????§?????????????????????????????????????????¨????????????

Input
?????????????????¢?????°???????????????????????????????????????????????????????????§?????????????????????

???????????????????????¨????????????????????????????????????????????????????????????????????????????????????????????¨?????????
E???N???S???W ????????????????????§??????

Output
???????????????????????????????????????????????????????????¢?????°???????????????????????????????????????

Constraints
0??? ??\?????????????????????????????¢?????°??? ???100
0??? ???????????¨????????????????????? ???100

Note
?¶???????????????? Dice III, Dice IV
??§???????????°????????????????????±????????§???????????????????????????????§?????????§?????????????????????????????????

Sample Input 1
1 2 4 8 16 32
SE
Sample Output 1
8
?????¢??? 1, 2, 4, 8, 16, 32 ??¨??????????????????????????? S ??????????????¢???????????????E
??????????????¢????????¨????????¢?????°?????? 8 ??????????????????



Sample Input 2
1 2 4 8 16 32
EESWN
Sample Output 2
32
 */

#include <iostream>
#include <sstream>

class Dice {
private:
  unsigned short Top = 1;
  unsigned short Back = 2;
  unsigned short Right = 3;
  unsigned short Left = 4;
  unsigned short Front = 5;
  unsigned short Bottom = 6;

public:
  Dice() {
  }

  Dice(std::string Param) {
    setNumbers(Param);
  }

  unsigned short getTop();
  void lotate(std::string);
  void setNumbers(std::string);
};

unsigned short Dice::getTop() { return Top; }

void Dice::lotate(std::string Direction) {
  for (const auto &e : Direction) {
    unsigned int Tmp;
    if (e == 'N') {
      Tmp = Front;
      Front = Top;
      Top = Back;
      Back = Bottom;
      Bottom = Tmp;
    } else if (e == 'E') {
      Tmp = Right;
      Right = Top;
      Top = Left;
      Left = Bottom;
      Bottom = Tmp;
    } else if (e == 'W') {
      Tmp = Left;
      Left = Top;
      Top = Right;
      Right = Bottom;
      Bottom = Tmp;
    } else if (e == 'S') {
      Tmp = Back;
      Back = Top;
      Top = Front;
      Front = Bottom;
      Bottom = Tmp;
    }
  }
}

void Dice::setNumbers(std::string Str) {
  std::istringstream iss(Str);
  unsigned short n;
  size_t i = 0;

  while (iss >> n) {
    switch (i++) {
    case 0:
      Top = n;
      break;
    case 1:
      Back = n;
      break;
    case 2:
      Right = n;
      break;
    case 3:
      Left = n;
      break;
    case 4:
      Front = n;
      break;
    case 5:
      Bottom = n;
      break;
    }
  }
}

int main(int argc, char const *argv[]) {
  std::string Param;
  getline(std::cin, Param);

  Dice D(Param);
  getline(std::cin, Param);

  D.lotate(Param);
  std::cout << D.getTop() << std::endl;
  return 0;
}