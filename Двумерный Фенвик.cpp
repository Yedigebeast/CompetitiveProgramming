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

#define x1 asd
#define y1 asdasd

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

const ll maxn=1e3+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
int n,t[maxn][maxn];
void update(int x,int y){
    for(int i=x;i<=n;i=(i|(i+1))){
        for(int j=y;j<=n;j=(j|(j+1))){
            t[i][j]++;
        }
    }
}
int get(int x,int y){
    int res=0;
    for(int i=x;i>0;i=(i&(i+1))-1){
        for(int j=y;j>0;j=(j&(j+1))-1){
            res+=t[i][j];
        }
    }
    return res;
}
ll solve(int x,int y,int x1,int y1){
    ll res=get(x1,y1);
    res-=get(x-1,y1);
    res-=get(x1,y-1);
    res+=get(x-1,y-1);
    return res;
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        if(s=="add"){
            int x,y;
            cin>>x>>y;
            update(x,y);
        }
        else{
            int x,y,x1,y1;
            cin>>x>>y>>x1>>y1;
            cout<<solve(x,y,x1,y1)<<"\n";
        }
    }
	exit(0);
}
