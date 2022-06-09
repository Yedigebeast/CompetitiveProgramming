//#pragma GCC target("avx2")
//#pragma GCC optimization("O3")
//#pragma GCC optimization("unroll-loops")
//assert(q==w) если q!=w --> runtime error
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define ub upper_bound
#define lb lower_bound
#define bit __builtin_popcount
#define memset(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vector<int>> matrix;

inline void boost(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll maxn=2e5+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
ll root[maxn],a[maxn],sz=0;

struct edik{
    ll add=0,sum=0,lv=0,rv=0;
}t[maxn*160];

ll build(ll tl,ll tr){
    sz++;
    ll v=sz;
    if(tl==tr){
        t[v].sum=a[tl];
    }
    else{
        ll tm=tl+tr>>1;
        t[v].lv=build(tl,tm);
        t[v].rv=build(tm+1,tr);
        t[v].sum=t[t[v].lv].sum+t[t[v].rv].sum;
    }
    return v;
}

ll push(ll v,ll tl,ll tr){
    if(tl==tr || t[v].add==0){
        return v;
    }
    sz++;
    ll nv=sz;
    t[nv]=t[v];
    sz++;
    ll nl=sz;
    t[nl]=t[t[v].lv];
    sz++;
    ll nr=sz;
    t[nr]=t[t[v].rv];
    ll tm=tl+tr>>1;
    t[nl].sum+=(tm-tl+1)*t[nv].add;
    t[nl].add+=t[nv].add;
    t[nr].sum+=(tr-tm)*t[nv].add;
    t[nr].add+=t[nv].add;
    t[nv].add=0;
    t[nv].lv=nl;
    t[nv].rv=nr;
    return nv;
}
ll get(ll v,ll tl,ll tr,ll l,ll r){
    if(l>tr || tl>r){
        return 0;
    }
    if(l<=tl && tr<=r){
        return t[v].sum;
    }
    v=push(v,tl,tr);
    ll tm=tl+tr>>1;
    return get(t[v].lv,tl,tm,l,r)+get(t[v].rv,tm+1,tr,l,r);
}

ll update(ll v,ll tl,ll tr,ll l,ll r,ll val){
    if(tl>r || l>tr){
        return v;
    }
    sz++;
    ll nv=sz;
    if(l<=tl && tr<=r){
        t[nv]=t[v];
        t[nv].add+=val;
        t[nv].sum+=(tr-tl+1)*val;
        return nv;
    }
    v=push(v,tl,tr);
    ll tm=tl+tr>>1;
    t[nv].lv=update(t[v].lv,tl,tm,l,r,val);
    t[nv].rv=update(t[v].rv,tm+1,tr,l,r,val);
    t[nv].sum=t[t[nv].lv].sum+t[t[nv].rv].sum;
    return nv;
}
int main(){
    //boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	exit(0);
}
