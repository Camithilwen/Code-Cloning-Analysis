#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}
struct maxhist{
  vector<int> hist;
  struct rect{int height,idx;};

  void add_hist(int a){
    hist.push_back(a);
  }

  int get_max(){
    int res=0;
    stack<rect> s;
    for(int j=0;j<hist.size();j++){
      if((!s.size())||s.top().height<hist[j])s.push({hist[j],j});
      else if(s.top().height>hist[j]){
        int left;
        while(s.top().height>hist[j]){
          rect tmp=s.top();s.pop();
          left=tmp.idx;
          //chmax(res,tmp.height*(j-left));
          chmax(res,(tmp.height+1)*(j-left+1));
          if(!s.size())break;
        }
        s.push({hist[j],left});
      }
    }
    while(s.size()){
      rect tmp=s.top();s.pop();
      //chmax(res,tmp.height*(hist.size()-tmp.idx));
      chmax(res,(tmp.height+1)*((int)hist.size()-tmp.idx+1));
    }
    return res;
  }
};
struct maxrect{
  vector<vector<bool>> rect;

  void add_line(vector<bool> &v){
    rect.push_back(v);
  }
  void add_dot(int h,bool f){
    if(rect.size()<=h)rect.resize(h+1);
    rect[h].push_back(f);
  }

  int get_max(){
    int res=0;
    int h=rect.size();
    vector<vector<int>> hist(h);
    for(int i=0;i<h;i++)hist[i].resize(rect[i].size());
    for(int i=0;i<h;i++){
      maxhist mh;
      for(int j=0;j<hist[i].size();j++){
        if(i){
          if(hist[i-1].size()<=j)hist[i][j]=rect[i][j];
          else hist[i][j]=(hist[i-1][j]+rect[i][j])*rect[i][j];
        }
        else hist[i][j]=rect[i][j];
        mh.add_hist(hist[i][j]);
      }
      chmax(res,mh.get_max());
    }
    return res;
  }
};

signed main(){
  int h,w;cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin>>s[i];
  maxrect m;
  vector<bool> f(w-1);
  for(int i=1;i<h;i++){
    for(int j=0;j<w-1;j++){
      int a=(s[i-1][j]=='#')+(s[i-1][j+1]=='#')+(s[i][j]=='#')+(s[i][j+1]=='#');
      f[j]=(a&1)^1;
    }
    m.add_line(f);
  }
  cout<<max({h,w,m.get_max()})<<endl;
}

/*
解説AC
広義唐草模様の面積求めたくなって、どこがダメな場所かも分かったけど最大長方形のアルゴリズムを知らず
時間かければ自分で思いつきそうな気もするけどコスパ悪いし見ていいでしょ
面白かった
*/
