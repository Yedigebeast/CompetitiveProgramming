//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int lg=17;
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
vector<int>g[maxn];
int p[maxn][lg+10];
int lvl[maxn];
bool used[maxn];
void dfs(int v,int pr){
    p[v][0]=pr;
    used[v]=1;
    lvl[v]=lvl[pr]+1;
    for(int i=1;i<=lg;i++){
        p[v][i]=p[p[v][i-1]][i-1];
    }
    for(auto to:g[v]){
        if(to != pr){
            dfs(to,v);
        }
    }
}
int lca(int a,int b){
    if(lvl[a]>lvl[b]){//12
        swap(a,b);
    }
    for(int i=lg;i>=0;i--){
        if(lvl[p[b][i]]>=lvl[a]){
            b=p[b][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=lg;i>=0;i--){
        if(p[a][i]!=p[b][i]){
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}
int main(){
    //boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
	exit(0);
}
