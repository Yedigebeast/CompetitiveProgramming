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
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
int timer=1,tin[maxn],fup[maxn];
vector<int>g[maxn];
bool used[maxn];
set<int>V;
void dfs(int v,int p){
    used[v]=1;
    tin[v]=timer;
    fup[v]=timer;
    timer++;
    int c=0;
    for(auto to:g[v]){
        if(to==p){
            continue;
        }
        if(used[to]==1){
            fup[v]=min(fup[v],tin[to]);
        }
        else{
            c++;
            dfs(to,v);
            fup[v]=min(fup[v],fup[to]);
            if(fup[to]>=tin[v] && p!=-1){
                V.insert(v);
            }
        }
    }
    if(p==-1 && c>=2){
        V.insert(v);
    }
}
int main(){
    boost();
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,-1);
    cout<<V.size()<<"\n";
    for(auto i:V){
        cout<<i<<"\n";
    }
	exit(0);
}
