//CODED BY : Super_KAZAKH(-:  >---->  Yedige
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define sz size
#define s second
#define fr for(set<int>::iterator it=st.begin();it!=st.end();it++)
#define allv v.begin(),v.end()
#define alls s.begin(),s.end()
using namespace std;
inline void boost(){
    ios_base::sync_with_stdio();
    cin.tie(0);
}
const ll MAXN=2e5+123;
const ll INF=1e9+123;
vector<pii>g[MAXN];
set<int>ve;
bool used[MAXN];
int tin[MAXN],fup[MAXN];
int timer=0;
void dfs(int v, int p){
    used[v]=1;
    tin[v]=fup[v]=++timer;
    for(int i=0;i<g[v].size();i++){
        int u=g[v][i].first;
        if (u == p) continue;
        if(!used[u]){
            dfs(u, v);
            fup[v]=min(fup[v],fup[u]);
            if(fup[u]>tin[v]){
                ve.insert(g[v][i].second);
            }
        }
        else{
            fup[v]=min(fup[v],tin[u]);
        }
    }
}
int main(){
    boost();
    freopen("bridges.in","r",stdin);
    freopen("bridges.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    g[x].pb({y,i});
    g[y].pb({x,i});
    }
    dfs(1,-1);
    cout<<ve.sz()<<endl;
    for(;!ve.empty(); ve.erase(ve.begin())){
        cout<<*ve.begin()<<" ";
    }
    exit(0);
}
