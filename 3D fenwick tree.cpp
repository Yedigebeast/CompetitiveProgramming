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

const ll maxn=130;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
int n;
ll t[maxn][maxn][maxn];
void update(int x,int y,int z,int k){
    for(int i=x;i<=n;i=(i|(i+1))){
        for(int j=y;j<=n;j=(j|(j+1))){
            for(int q=z;q<=n;q=(q|(q+1))){
                t[i][j][q]+=k;
            }
        }
    }
}
ll get(int x,int y,int z){
    ll res=0;
    for(int i=x;i>0;i=(i&(i+1))-1){
        for(int j=y;j>0;j=(j&(j+1))-1){
            for(int q=z;q>0;q=(q&(q+1))-1){
                res+=t[i][j][q];
            }
        }
    }
    return res;
}
ll solve(int x,int y,int z,int x1,int y1,int z1){
    ll q=get(x1,y1,z1)-get(x-1,y1,z1)-get(x1,y-1,z1)+get(x-1,y-1,z1);
    ll w=get(x1,y1,z-1)-get(x-1,y1,z-1)-get(x1,y-1,z-1)+get(x-1,y-1,z-1);
    return q-w;
}
int main(){
    boost();
    //freopen("stars.in","r",stdin);
    //freopen("stars.out","w",stdout);
    cin>>n;
    while(1==1){
        int t;
        cin>>t;
        if(t==3){
            return 0;
        }
        if(t==1){
            int x,y,z,k;
            cin>>x>>y>>z>>k;
            x++,y++,z++;
            update(x,y,z,k);
        }
        else{
            int x,y,z,x1,y1,z1;
            cin>>x>>y>>z>>x1>>y1>>z1;
            x++,y++,z++,x1++,y1++,z1++;
            cout<<solve(x,y,z,x1,y1,z1)<<"\n";
        }
    }
	exit(0);
}
