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

const ll maxn=1e6+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1000003;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
ll fact[maxn],rev[maxn];
ll binpow(int a,int b){
    if(b==0){
        return 1ll;
    }
    if(b%2==0){
        ll t=binpow(a,b/2);
        return (t*t)%mod;
    }
    else{
        return (binpow(a,b-1)*a)%mod;
    }
}
int main(){
    //boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    fact[0]=1;
    for(int i=1;i<=1000002;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int cntr=0;
    while(t--){
        cntr++;
        int n,k;
        cin>>n>>k;
        cout<<"Case "<<cntr<<": "<<(((fact[n]*binpow(fact[k],mod-2))%mod)*binpow(fact[n-k],mod-2))%mod<<"\n";
    }
	exit(0);
}
