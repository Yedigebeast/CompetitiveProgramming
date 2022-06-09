//#pragma GCC target("avx2")
//#pragma GCC optimization("O3")
//#pragma GCC optimization("unroll-loops")
//assert(q==w) если q!=w --> runtime error
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
ll a[maxn],b[25][maxn];

int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<=20;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=linf;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[0][i]=a[i];
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j+(1<<(i-1))<=n;j++){
            b[i][j]=min(b[i-1][j],b[i-1][j+(1<<(i-1))]);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int i,j;
        cin>>i>>j;
        i++;
        j++;
        int dist=j-i+1,kol=0;
        while(dist>1){
            kol++;
            dist/=2;
        }
        cout<<min(b[kol][i],b[kol][j-(1<<kol)+1])<<"\n";
    }
    exit(0);
}
