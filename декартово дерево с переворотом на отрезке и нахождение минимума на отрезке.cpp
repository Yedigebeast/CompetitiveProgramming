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
typedef vector<vector<int> > matrix;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ID=1;

struct point{
    int sz,pr,l,r,key,mn;
    bool rev;
}t[maxn];

void push(int v){
    if(v!=0 && t[v].rev==1){
        t[v].rev=0;
        swap(t[v].l,t[v].r);
        if(t[v].l!=0){
            t[t[v].l].rev^=1;
        }
        if(t[v].r!=0){
            t[t[v].r].rev^=1;
        }
    }
}

int merge(int l,int r){
    push(l);
    push(r);
    if(l==0 || r==0){
        if(l!=0){
            return l;
        }
        if(r!=0){
            return r;
        }
    }
    if(t[l].pr>=t[r].pr){
        t[l].r=merge(t[l].r,r);
        t[l].sz=t[t[l].l].sz+t[t[l].r].sz+1;
        t[l].mn=t[l].key;
        if(t[l].l!=0){
            t[l].mn=min(t[l].mn,t[t[l].l].mn);
        }
        if(t[l].r!=0){
            t[l].mn=min(t[l].mn,t[t[l].r].mn);
        }
        return l;
    }
    else{
        t[r].l=merge(l,t[r].l);
        t[r].sz=t[t[r].l].sz+t[t[r].r].sz+1;
        t[r].mn=t[r].key;
        if(t[r].l!=0){
            t[r].mn=min(t[r].mn,t[t[r].l].mn);
        }
        if(t[r].r!=0){
            t[r].mn=min(t[r].mn,t[t[r].r].mn);
        }
        return r;
    }
}

pii split(int v,int k){
    push(v);
    if(v==0){
        return {0,0};
    }
    int x=t[t[v].l].sz+1;
    if(x<=k){
        pii q=split(t[v].r,k-x);
        t[v].r=q.F;
        t[v].sz=t[t[v].l].sz+t[t[v].r].sz+1;
        t[v].mn=t[v].key;
        if(t[v].l!=0){
            t[v].mn=min(t[v].mn,t[t[v].l].mn);
        }
        if(t[v].r!=0){
            t[v].mn=min(t[v].mn,t[t[v].r].mn);
        }
        return {v,q.S};
    }
    else{
        pii q=split(t[v].l,k);
        t[v].l=q.S;
        t[v].sz=t[t[v].l].sz+t[t[v].r].sz+1;
        t[v].mn=t[v].key;
        if(t[v].l!=0){
            t[v].mn=min(t[v].mn,t[t[v].l].mn);
        }
        if(t[v].r!=0){
            t[v].mn=min(t[v].mn,t[t[v].r].mn);
        }
        return {q.F,v};
    }
}

int Reverse(int v,int l,int r){
    pii q=split(v,r);
    pii q1=split(q.F,l-1);
    t[q1.S].rev^=1;
    int q2=merge(q1.F,q1.S);
    q2=merge(q2,q.S);
    return q2;
}

pii Min(int v,int l,int r){
    pii q=split(v,r);
    pii q1=split(q.F,l-1);
    int ans=t[q1.S].mn;
    int q2=merge(q1.F,q1.S);
    q2=merge(q2,q.S);
    return {q2,ans};
}

int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    int v=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        t[ID].pr=rng();
        t[ID].key=x;
        t[ID].mn=x;
        t[ID].rev=0;
        t[ID].sz=1;
        v=merge(v,ID);
        ID++;
    }
    while(m--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            v=Reverse(v,l,r);
        }
        else{
            pii q=Min(v,l,r);
            v=q.F;
            cout<<q.S<<"\n";
        }
    }
	exit(0);
}
