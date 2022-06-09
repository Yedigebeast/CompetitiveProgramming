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
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
struct st {
    int a, b, c;
}g[maxn];
int n, m;
int par[maxn];
bool cmp (st f, st s) {
    return (f.c < s.c);
}
int get (int v) {
    if (par[v] == v) return v;
    return par[v] = get (par[v]);
}
void union_set (int f, int s) {
    f = get (f);
    s = get (s);
    if (f != s) par[f] = s;
}

int main (){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> g[i].a >> g[i].b >> g[i].c;
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) par[i] = i;
    sort (g + 1, g + m + 1, &cmp);
    for (int i = 1; i <= m; i ++) {
        if (get (g[i].a) != get (g[i].b)) {
            union_set (g[i].a, g[i].b);
            sum += g[i].c;
        }
    }
    cout << sum;
	exit(0);
}
