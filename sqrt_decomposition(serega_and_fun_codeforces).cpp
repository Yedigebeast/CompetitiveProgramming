//time complexity -> 2 * sizeblock + n / sizeblock
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

const ll maxn=1e5+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
int a[maxn],kol[320][maxn];
deque<int>d[320];
int blocksize=500,n;
void update(int l,int r){
    int l1=l/blocksize,l2=l%blocksize,r1=r/blocksize,r2=r%blocksize;
    if(l1==r1){
        int x=d[r1][r2];
        d[r1].erase(d[r1].begin()+r2);
        d[l1].insert(d[l1].begin()+l2,x);
    }
    else{
        int x=d[r1][r2];
        d[r1].erase(d[r1].begin()+r2);
        kol[r1][x]--;
        for(int i=r1;i!=l1;i--){
            int y=d[i-1].back();
            d[i].push_front(y);
            kol[i][y]++;
            kol[i-1][y]--;
            d[i-1].pop_back();
        }
        d[l1].insert(d[l1].begin()+l2,x);
        kol[l1][x]++;
    }
}
int get(int l,int r,int k){
    int l1=l/blocksize,l2=l%blocksize,r1=r/blocksize,r2=r%blocksize,cntr=0;
    if(l1==r1){
        for(int i=l2;i<=r2;i++){
            if(d[l1][i]==k){
                cntr++;
            }
        }
    }
    else{
        for(int i=0;i<=r2;i++){
            if(d[r1][i]==k){
                cntr++;
            }
        }
        for(int i=r1-1;i!=l1;i--){
            cntr+=kol[i][k];
        }
        for(int i=l2;i<d[l1].size();i++){
            if(d[l1][i]==k){
                cntr++;
            }
        }
    }
    return cntr;
}
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[i/blocksize].push_back(a[i]);
        kol[i/blocksize][a[i]]++;
    }
    int q;
    cin>>q;
    int lastans=0;
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        l=(l+lastans-1)%n;
        r=(r+lastans-1)%n;
        if(l>r){
            swap(l,r);
        }
        if(type==1){
            update(l,r);
        }
        else{
            int k;
            cin>>k;
            k=(k+lastans-1)%n+1;
            lastans=get(l,r,k);
            cout<<lastans<<"\n";
        }
    }
	exit(0);
}
