#include <stdio.h>
struct Dice {
  int face1, face2, face3, face4, face5, face6;
};

void roll_for_E(struct Dice *dice);
void roll_for_N(struct Dice *dice);
void roll_for_S(struct Dice *dice);
void roll_for_W(struct Dice *dice);


int main(void)
{
  struct Dice dice;
  char ch;
  scanf("%d%d%d%d%d%d", &(dice.face1), &(dice.face2), &(dice.face3), &(dice.face4), &(dice.face5), &(dice.face6));

  (void)getchar();

  while((ch=getchar())!='\n') {
    if(ch=='E')
      roll_for_E(&dice);
    if(ch=='N')
      roll_for_N(&dice);
    if(ch=='S')
      roll_for_S(&dice);
    if(ch=='W')
      roll_for_W(&dice);
  }
  printf("%d\n", dice.face1);
  return 0;
}

void roll_for_E(struct Dice *dice)
{
  int temp;
  temp = dice->face1;
  dice->face1=dice->face4;
  dice->face4=dice->face6;
  dice->face6=dice->face3;
  dice->face3=temp;
}

void roll_for_N(struct Dice *dice)
{
  int temp;
  temp = dice->face1;
  dice->face1=dice->face2;
  dice->face2=dice->face6;
  dice->face6=dice->face5;
  dice->face5=temp;
}

void roll_for_S(struct Dice *dice)
{
  int temp;
  temp = dice->face1;
  dice->face1=dice->face5;
  dice->face5=dice->face6;
  dice->face6=dice->face2;
  dice->face2=temp;
}

void roll_for_W(struct Dice *dice)
{
  int temp;
  temp = dice->face1;
  dice->face1=dice->face3;
  dice->face3=dice->face6;
  dice->face6=dice->face4;
  dice->face4=temp;
}