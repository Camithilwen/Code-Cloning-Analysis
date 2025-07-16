#include <iostream>
#include<algorithm>
#include <vector>
#include <functional>
#include <limits.h>

template<typename T, typename S>
struct LazySegTree{
    int size;
    std::vector<T> nod;
    std::vector<S> monoid;
    std::vector<bool> flag;
    T t0;
    S s0;
    std::function<T(T,T)> operation;
    std::function<S(S,S)> merge;
    std::function<T(T,S,int)> calc;
    LazySegTree(int n, T _t0, S _s0, std::function<T(T,T)> _operation, std::function<S(S,S)> _merge, std::function<T(T,S,int)> _calc){
        t0 = _t0;
        s0 = _s0;
        operation = _operation;
        merge = _merge;
        calc = _calc;
        size = 1;
        while(n > size) size *= 2;
        nod = std::vector<T> (size*2-1, t0);
        monoid = std::vector<S> (size*2-1, s0);
        flag = std::vector<bool> (size*2-1);
    }
    void disassembly(int k, int l, int r){
        if(r-l>1){
            monoid[k*2+1] = merge(monoid[k*2+1], monoid[k]);
            monoid[k*2+2] = merge(monoid[k*2+2], monoid[k]);
            flag[k*2+1] = true;
            flag[k*2+2] = true;
        }
        nod[k] = calc(nod[k],monoid[k],r-l);
        monoid[k] = s0;
        flag[k] = false;
    }
    S update_query(int a,int b,int k,int l,int r,S x){
        //[a,b)について
        //kは節点の番号,[l,r)はその節点がカバーする範囲
        if(r<=a||b<=l){ //[a,b)と[l,r)が重なって無いとき
            if(flag[k]) return calc(nod[k], monoid[k], r-l);
            return nod[k];
        }
        if(a<=l && r<=b){ //[a,b)が[l,r)を完全に含んでいるとき
            monoid[k] = merge(monoid[k], x);
            flag[k] = true;
            return calc(nod[k], monoid[k],r-l);
        }
        else{
            if(flag[k]) disassembly(k,l,r);
            nod[k] = operation(update_query(a,b,k*2+1,l,(l+r)/2,x), update_query(a,b,k*2+2,(l+r)/2,r,x));
            return nod[k];
        }
    }
    void update(int a, int b, S x){
        // [a,b)をxに更新
        update_query(a,b,0,0,size,x);
    }
    T sum_query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l){
            return t0;
        }
        if(a<=l && r<=b){
            if(flag[k]) return calc(nod[k],monoid[k],r-l);
            else return nod[k];
        }
        if(flag[k]) disassembly(k, l, r);
        return operation(sum_query(a,b,k*2+1,l,(l+r)/2),sum_query(a,b,k*2+2,(l+r)/2,r));
    }
    T sum(int a, int b){
        return sum_query(a,b,0,0,size);
    }
   void deb(){ //全ノードの出力
		for(int i=0;i<size*2-1;i++){
			if(i==size*2-2){
				std::cout << nod[i] <<std:: endl;
			}
			else{
				std::cout << nod[i] << ' ';
			}
		}
        for(int i=0;i<size*2-1;i++){
			if(i==size*2-2){
				std::cout << monoid[i] <<std:: endl;
			}
			else{
				std::cout << monoid[i] << ' ';
			}
		}
		return;
	}
};

int main(){
    int n,q; std::cin >> n >> q;
    std::vector<int> ans(0);
    LazySegTree<long long, long long> lst(n,INT_MAX,0,[](long long a, long long b){return std::min(a,b);}, [](long long a, long long b){return b;},[](long long a, long long b, long long c){return b;});
    for(int i= 0;i<q;i++){
        int w; std::cin >> w;
        if(w == 0){
            int s,t,x; std::cin >> s >> t >> x;
            lst.update(s, t+1, x);
        }
        else{
            int s,t; std::cin >> s;
            ans.push_back(lst.sum(s,s+1));
        }
        //lst.deb();
    }
    for(int i = 0;i<ans.size();i++) std::printf("%d\n", ans[i]);
}
