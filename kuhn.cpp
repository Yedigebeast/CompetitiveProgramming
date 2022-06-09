#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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

const ll maxn=5e5+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
bool kuhn(int v){
    if(used[v]==timer){
        return 0;
    }
    used[v]=timer;
    for(int to:g[v]){
        if(mt[to]==-1){
            mt[to]=v;
            return 1;
        }
    }
    for(int to:g[v]){
        if(kuhn(mt[to])==1){
            mt[to]=v;
            return 1;
        }
    }
    return 0;
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(int i=1;i<=n;i++){
        if(kuhn(i)){
            timer++;
        }
    }
	exit(0);
}
