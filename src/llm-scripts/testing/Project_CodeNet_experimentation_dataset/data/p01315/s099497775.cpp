#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class crop{
public:
  string name;
  int price,seeding,youngL,L,flower,
    fruit,numFruit,fruitPrice,times;
  int StoL,LtoFruit,totaltime;
  double sum;
  crop();
  crop(string name,int price,int seeding,int youngL,
       int L,int flower,int fruit,
       int numFruit,int fruitPrice,
       int times):name(name),price(price),
		  seeding(seeding),youngL(youngL),L(L),
		  flower(flower),fruit(fruit),numFruit(numFruit),
		  fruitPrice(fruitPrice),times(times){
    this->StoL= seeding + youngL + L;
    this->LtoFruit = flower + fruit;
    this->totaltime=StoL + LtoFruit * times;
    this->sum = ((times * numFruit  * fruitPrice) - price) / (double)totaltime;
  }
  ~crop(){}
  
  bool operator<(const crop &a)const{
    if(this->sum != a.sum){
      return this->sum > a.sum;
    }else{
      return this->name < a.name;
    }
  }
};

void printCrop(crop &a){
  cout << "name:" << a.name << endl;
  cout << "price:" << a.price << " sum:" << a.sum << 
    " totaltime:"<< a.totaltime<< endl;
}
int main(){
  int n;
  while(cin>>n,n){
    vector<crop> C;
    for(int i=0;i<n;i++){
      string l;
      int p,a,b,c,d,e,f,s,m;
      cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
      C.push_back(crop(l,p,a,b,c,d,e,f,s,m));
    }
    sort(C.begin(), C.end());

    for(int i=0;i<n;i++){
      //printCrop(C[i]);
      cout << C[i].name << endl;
    }
    cout << "#" << endl;
  }
  return 0;
}