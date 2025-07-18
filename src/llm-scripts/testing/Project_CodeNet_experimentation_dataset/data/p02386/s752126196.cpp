#include <iostream>
#include <vector>
using namespace std;

// http://www.prefield.com/algorithm/misc/dice.html
enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };
class dice {
public:
  dice() {
    id[TOP] = 1; id[FRONT] = 2; id[LEFT] = 3;
    id[RIGHT] = 4; id[BACK] = 5; id[BOTTOM] = 6;
  }
  dice(int top,int front,int right,int left,int back,int bottom) {
    id[TOP] = top; id[FRONT] = front; id[LEFT] = right;
    id[RIGHT] = left; id[BACK] = back; id[BOTTOM] = bottom;
  }
  int& operator[] (FACE f) { return id[f]; }
  const int& operator[] (FACE f) const { return id[f]; }
  bool operator==(const dice &b) const {
    const dice &a = *this;
    return a[TOP] == b[TOP] && a[BOTTOM] == b[BOTTOM] &&
           a[FRONT] == b[FRONT] && a[BACK] == b[BACK] &&
           a[LEFT] == b[LEFT] && a[RIGHT] == b[RIGHT];
  }
  void roll_x() { roll(TOP, BACK, BOTTOM, FRONT); }
  void roll_x2() { roll(TOP, FRONT, BOTTOM, BACK); }
  void roll_y() { roll(TOP, LEFT, BOTTOM, RIGHT); }
  void roll_y2() { roll(TOP, RIGHT, BOTTOM, LEFT); }
  void roll_z() { roll(FRONT, RIGHT, BACK, LEFT); }
  void roll_z2() { roll(FRONT, LEFT, BACK, RIGHT); }
  bool equivalent_to(const dice& di) {
    for (int k = 0; k < 6; (k&1?roll_y():roll_x()),++k)
      for (int i = 0; i < 4; roll_z(), ++i)
        if (*this == di) return true;
    return false;
  }
private:
  void roll(FACE a, FACE b, FACE c, FACE d) {
    int tmp = id[a];
    id[a] = id[b]; id[b] = id[c];
    id[c] = id[d]; id[d] = tmp;
  }
  int id[6];
};

int main(){
	int n,d[6];
	cin>>n;
	vector<dice>v(n);
	for(int j=0;j<n;j++){
		for(int i=0;i<6;i++)cin>>d[i];
		v[j]=dice(d[0],d[1],d[2],d[3],d[4],d[5]);
	}
	for(int j=0;j<n-1;j++)for(int i=j+1;i<n;i++)if(v[j].equivalent_to(v[i])){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
}