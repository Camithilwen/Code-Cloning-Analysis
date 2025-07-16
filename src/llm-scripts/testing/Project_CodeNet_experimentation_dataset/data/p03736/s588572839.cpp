#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long MAXN = 2e5+5;
long long q[MAXN];
struct segtree{
    long long seg[5*MAXN];
    long long lazy[5*MAXN];
    void push(long long curr){
        if(lazy[curr]){
            seg[2*curr]+=lazy[curr];
            seg[2*curr+1]+=lazy[curr];
            lazy[2*curr] += lazy[curr];
            lazy[2*curr+1]+=lazy[curr];
            lazy[curr] = 0;
        }
    }
    void build(long long curr,long long l,long long r){
        if(l==r){
            seg[curr] = 1e18;
            lazy[curr] = 0;
            return;
        }
        long long mid = (l+r)/2;
        build(2*curr,l,mid);
        build(2*curr+1,mid+1,r);
        seg[curr] = min(seg[2*curr],seg[2*curr+1]);
    }
    void insert(long long curr,long long l,long long r,long long ind,long long val){
        if(l==r){
            seg[curr] = min(seg[curr],val);
            return;
        } 
        if(l!=r){
            push(curr);
        }
        long long mid = (l+r)/2;
        if(ind<=mid){
            insert(2*curr,l,mid,ind,val);
        }else{
            insert(2*curr+1,mid+1,r,ind,val);
        }
        seg[curr] = min(seg[2*curr],seg[2*curr+1]);
    }
    void update(long long curr,long long l,long long r,long long tl,long long tr,long long val){
        if(l>tr||r<tl){
            return;
        }
        if(l!=r){
            push(curr);
        }
        if(l>=tl && r<=tr){
            seg[curr] += val;
            lazy[curr]+=val;
            return;
        }
        long long mid = (l+r)/2;
        update(2*curr,l,mid,tl,tr,val);
        update(2*curr+1,mid+1,r,tl,tr,val);
        seg[curr] = min(seg[2*curr],seg[2*curr+1]);
    }
    long long query(long long curr,long long l,long long r,long long tl,long long tr){
        if(l>tr||r<tl){
            return 1e18;
        }
        if(l!=r){
            push(curr);
        }
        if(l>=tl && r<=tr){
            return seg[curr];
        }
        long long mid = (l+r)/2;
        return min(query(2*curr,l,mid,tl,tr),query(2*curr+1,mid+1,r,tl,tr));
    }
};
segtree seg1,seg2,seg3;
int main(){
    long long n,Q,a,b;
    cin>>n>>Q>>a>>b;
    for(long long i=1;i<=Q;i++){
        cin>>q[i];
    }
    seg1.build(1,1,n);
    seg2.build(1,1,n);
    seg3.build(1,1,n);
    seg1.insert(1,1,n,a,abs(b-q[1]));
    seg2.insert(1,1,n,a,abs(b-q[1])+a);
    seg3.insert(1,1,n,a,abs(b-q[1])-a);
    seg1.insert(1,1,n,b,abs(a-q[1]));
    seg2.insert(1,1,n,b,abs(a-q[1])+b);
    seg3.insert(1,1,n,b,abs(a-q[1])-b);
    //cout<<seg1.query(1,1,n,1,n)<<endl;
    for(long long i=2;i<=Q;i++){
        long long val = seg2.query(1,1,n,q[i],n)-q[i];
        val = min(val,seg3.query(1,1,n,1,q[i]-1)+q[i]);
        seg1.update(1,1,n,1,n,abs(q[i]-q[i-1]));
        seg2.update(1,1,n,1,n,abs(q[i]-q[i-1]));
        seg3.update(1,1,n,1,n,abs(q[i]-q[i-1]));
        seg1.insert(1,1,n,q[i-1],val);
        seg2.insert(1,1,n,q[i-1],val+q[i-1]);
        seg3.insert(1,1,n,q[i-1],val-q[i-1]);
    }
    cout<<seg1.query(1,1,n,1,n)<<endl;
}