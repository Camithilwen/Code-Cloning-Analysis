#include<iostream>
using namespace std;
class dice
{
  private:
  int status[6];
  public:
  dice();
  int showfront(void);
  bool is(int,int);
  bool isfront(int);
  void rotate(char);
  bool rtfront(int);
  bool operator==(dice);
  bool eqv(dice);
};

bool dice::eqv(dice di2)
{
  if(!di2.rtfront((*this).showfront()))
    return false;
  else
  {
    int i;
    for(i=0;i<4;i++)
    {
      if ((*this)==di2)
      {
        return true;
      }
      di2.rotate('E');
    }
    if(i==4) return false;
  }
}



bool dice::rtfront(int a)
{
  int j;
  for(j=0;j<=3;j++)
  {
    if((*this).isfront(a)) break;
    (*this).rotate('N');
  }
  if(j==4)
  {
    (*this).rotate('E');
    (*this).rotate('S');
  }
  if(!(*this).isfront(a))
  {
    (*this).rotate('N');
    (*this).rotate('N');
  }
  if(!(*this).isfront(a))
    return false;
  else
    return true;
}

bool dice::operator==(dice d)
{
  int i=0;
  for(i=0;i<6;i++)
    if((*this).status[i]!=d.status[i]) break;
  if(i==6) return true;
  else return false;
}

dice::dice()
{
  for(int i=0;i<6;i++)
    cin>>status[i];
}

bool dice::isfront(int a)
{
  if(status[1]==a) return true;
  else return false;
}

bool dice::is(int a,int b)
{
  if((status[0]==a)&&(status[1]==b)) return true;
  else return false;
}

int dice::showfront()
{
  return status[1];
}

void dice::rotate(char s)
{
  switch(s)
  {
    int tmp;
    case 'N':
      tmp=status[0];
      status[0]=status[1];
      status[1]=status[5];
      status[5]=status[4];
      status[4]=tmp;
      break;
    case 'E':
      tmp=status[0];
      status[0]=status[3];
      status[3]=status[5];
      status[5]=status[2];
      status[2]=tmp;
      break;
    case 'W':
      tmp=status[0];
      status[0]=status[2];
      status[2]=status[5];
      status[5]=status[3];
      status[3]=tmp;
      break;
    case 'S':
      tmp=status[0];
      status[0]=status[4];
      status[4]=status[5];
      status[5]=status[1];
      status[1]=tmp;
      break;
  }
}

int main()
{
  int n;
  cin>>n;
  dice di[n];
  bool ans=true;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(di[i].eqv(di[j]))
      {
        ans=false;
        break;
      }
  if(ans==true)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

}