#include <bits/stdc++.h>

using namespace std;

const int INF=INT_MAX;

struct lst
{
    private:
        int n;
        vector<int> node;
        vector<int> lazy;
        vector<bool> lflg;
    public:
        lst(int sz)
        {
            n=1; while(n<sz) n*=2;
            node.resize(2*n-1, INF);
            lazy.resize(2*n-1, 0);
            lflg.resize(2*n-1, false);
        }
    void lazy2node(int k, int l, int r)
    {
        if(lflg[k])
        {
            node[k]=lazy[k];
            lflg[k]=false;
            prop(k, l, r);
        }
    }
    void prop(int k, int l, int r)
    {
        if (r-l>0)
        {
            lazy[2*k+1]=lazy[2*k+2]=node[k];
            lflg[2*k+1]=lflg[2*k+2]=true;
        }
    }

    void update(int qa, int qb, int v, int k=0, int l=0, int r=-1)
    {
        if(r<0) r=n-1;
        lazy2node(k, l, r);
        if(qb<l || r<qa) return;
        if(qa<=l && r<=qb) 
        {
            node[k] = v;
            prop(k, l, r);
        }
        else
        {
            int m=(l+r)/2;
            update(qa, qb, v, 2*k+1, l, m);
            update(qa, qb, v, 2*k+2, m+1, r);
        }
    }

    int get(int qa, int qb, int k=0, int l=0, int r=-1)
    {
        if(r<0) r=n-1;
        lazy2node(k, l, r);
        if(qb<l || r<qa) return INF;
        if(qa<=l && r<=qb) return node[k];
        else
        {
            int m=(l+r)/2;
            int lv = get(qa, qb, 2*k+1, l, m);
            int lr = get(qa, qb, 2*k+2, m+1, r);
            return min(lv, lr);
        }
    }
};

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    lst tree = lst(n);
    for(int i=0; i<q; i++)
    {
        int t;
        scanf("%d", &t);
        if(t)
        {
            int s;
            scanf("%d", &s);
            printf("%d\n", tree.get(s,s));
        }
        else
        {
            int s, t, v;
            scanf("%d %d %d", &s, &t, &v);
            tree.update(s, t, v);
        }
    }
    return 0;
}
