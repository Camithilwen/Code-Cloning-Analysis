        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(int n_,F f,G g,H h,T ti,E ei,vector<T> v=vector<T>()):
    f(f),g(g),h(h),ti(ti),ei(ei){
init(n_);
    if(n_==(int)v.size()) build(n_,v);

    }

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }

  void build(int n_,const vector<T> &v){
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }

  inline void propagate(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }

  inline void thrust(int k){
    for(int i=height;i;i--) propagate(k>>i);
  }

  inline void recalc(int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }

  void update(int a,int b,E x){
    if(a>=b) return;
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    propagate(k);
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }

  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};
 SegmentTree<int,int> seg(200003, [](int a,int b){return max(a,b);},
			   [](int a,int b){return b;},[](int a,int b){return b;},0,0);
     signed main(){
 int n,q;

 cin>>n>>q;
 int x[q+2],y[q+2]={},ans=0;
 for(int i=0;i<q+2;i++)cin>>x[i];

auto f = [&](int a,int z) -> int{
     if(a==0)return 0;
     return abs(z-x[q+2-a])+y[q+2-a];
};
for(int i=1;i<=q;i++){
     y[q+2-i]+=f(seg.query(x[q+1-i],x[q+1-i]+1),x[q+1-i])-abs(x[q+2-i]-x[q+1-i]);
     ans+=abs(x[q+2-i]-x[q+1-i]);
     int ok=x[q+1-i],ng,mid;
     if(x[q+2-i]>x[q+1-i]){
          ng=n+1;
          while(abs(ok-ng)>1){
               mid=(ok+ng)/2;
               if(f(i,mid)<=f(seg.query(mid,mid+1),mid))ok=mid;
               else ng=mid;
          }
          seg.update(x[q+1-i],ng,i);
     }else{
          ng=0;
          while(abs(ok-ng)>1){
               mid=(ok+ng)/2;
               if(f(i,mid)<=f(seg.query(mid,mid+1),mid))ok=mid;
               else ng=mid;
          }
          seg.update(ok,x[q+1-i],i);
     }
     
}
cout<<ans+f(seg.query(x[0],x[0]+1),x[0])<<endl;
 }

 


 






    





      

        
