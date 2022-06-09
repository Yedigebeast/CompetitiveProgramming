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
vector<int>g[maxn],gr[maxn],topsort;
int color[maxn];
bool used[maxn];
void dfs(int v){
    used[v]=1;
    for(auto to:g[v]){
        if(used[to]==0){
            dfs(to);
        }
    }
    topsort.pb(v);
}
void dfs2(int v,int cntr){
    used[v]=1;
    color[v]=cntr;
    for(auto to:gr[v]){
        if(used[to]==0){
            dfs2(to,cntr);
        }
    }
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        g[v].pb(u);
        gr[u].pb(v);
    }
    int cntr=0;
    for(int i=1;i<=n;i++){
        if(used[i]==0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        used[i]=0;
    }
    reverse(all(topsort));
    for(auto i:topsort){
        if(used[i]==0){
            cntr++;
            dfs2(i,cntr);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
	exit(0);
}
