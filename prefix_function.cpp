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
vector<int>prefix_function(string s){
    int n=s.size();
    vector<int>v(n);
    for(int i=1;i<n;i++){
        int j=v[i-1];
        while(j>0 && s[i]!=s[j]){
            j=v[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        v[i]=j;
    }
    return v;
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	exit(0);
}
