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

const ll maxn=1e5+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
vector<int>g[maxn];

int sz=0,root[maxn],a[maxn],c[maxn];
pii b[maxn];

struct edik{
    int sum=0,lv=0,rv=0;
}t[maxn*30];

int build(int tl,int tr){
    sz++;
    int v=sz;
    if(tl==tr){
        t[v].sum=a[tl];
    }
    else{
        int tm=tl+tr>>1;
        t[v].lv=build(tl,tm);
        t[v].rv=build(tm+1,tr);
        t[v].sum=t[t[v].lv].sum+t[t[v].rv].sum;
    }
    return v;
}

int update(int v,int tl,int tr,int pos,int val){
    sz++;
    int nv=sz;
    t[nv]=t[v];
    t[nv].sum+=val;
    if(tl==tr){
        return nv;
    }
    int tm=tl+tr>>1;
    if(pos<=tm){
        t[nv].lv=update(t[v].lv,tl,tm,pos,val);
    }
    else{
        t[nv].rv=update(t[v].rv,tm+1,tr,pos,val);
    }
    return nv;
}

int get(int v,int tl,int tr,int k){
    if(tl==tr){
        return tl;
    }
    int tm=tl+tr>>1;
    if(t[t[v].lv].sum>=k){
        return get(t[v].lv,tl,tm,k);
    }
    else{
        return get(t[v].rv,tm+1,tr,k-t[t[v].lv].sum);
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    root[b[0].F]=build(1,n);
    for(int i=1;i<=n;i++){
        root[b[i].F]=update(root[b[i-1].F],1,n,b[i].S,1);
    }
    exit(0);
}
