#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define ub upper_bound
#define lb lower_bound
#define bit __builtin_popcount

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
vector<int> z_function(string s){
    int n=s.size();
    vector<int>z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	exit(0);
}
