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
string s[maxn];
struct edik{
    int next[30];
    bool leef;
}t[maxn*5];
int id=2;
void add(string s){
    int v=1;
    for(int i=0;i<s.size();i++){
        int si=s[i]-'a'+1;
        if(t[v].next[si]==0){
            t[v].next[si]=id;
            id++;
        }
        v=t[v].next[si];
    }
    t[v].leef=1;
}
bool check(string s){
    int v=1;
    bool ok=1;
    for(int i=0;i<s.size();i++){
        int si=s[i]-'a'+1;
        if(t[v].next[si]==0){
            ok=0;
            break;
        }
        v=t[v].next[si];
    }
    return ok;
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        add(s[i]);
    }
    int q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        if(check(t)==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
	exit(0);
}
