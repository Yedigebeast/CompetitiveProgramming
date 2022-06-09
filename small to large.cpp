//https://codeforces.com/problemset/problem/375/D?locale=ru
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

const int N = (int)1e5 + 123;

int n, m, sz[N], c[N], cnt[N], cnt2[N], ans[N];
vector <int> g[N];
vector <pair <int, int> > s[N];

void calc(int v, int pr){
    sz[v] = 1;
    for(int to : g[v])
        if(to != pr){
            calc(to, v);
            sz[v] += sz[to];    
        }
}

void add(int v){
    cnt[c[v]]++;
    cnt2[cnt[c[v]]]++;
}

void del(int v){
    cnt2[cnt[c[v]]]--;
    cnt[c[v]]--;
}

void dfsAdd(int v, int pr, bool addOrdel){
    if(addOrdel)
        add(v);
    else del(v);
    for(int to : g[v])
        if(to != pr)
            dfsAdd(to, v, addOrdel);
}

void dfs(int v, int pr, bool keep){
    int mx = -1, bigChild = -1;
    for(int to : g[v])
        if(to != pr && mx < sz[to])
            mx = sz[to], bigChild = to;

    for(int to : g[v])
        if(to != pr && to != bigChild)
            dfs(to, v, 0);
    
    if(bigChild != -1)
        dfs(bigChild, v, 1);

    add(v);
    for(int to : g[v])
        if(to != pr && to != bigChild)
            dfsAdd(to, v, 1);
    //calc Ans
    for(auto i : s[v]){
        int k = i.f, num = i.s;
        ans[num] = cnt2[k];
    }
    //
    if(keep == 0)
        dfsAdd(v, pr, 0);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= m; ++i){
        int v, k;
        cin >> v >> k;
        s[v].pb(mp(k, i));
    }
    calc(1, -1);
    dfs(1, -1, 0);
    for(int i = 1; i <= m; ++i)
        cout << ans[i] << endl;
    return 0;
}