/*
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
ordered_set -> less -> less_equal
ordered_set find_by_order(k) -> k element
ordered_set order_of_key(k) -> returns the number of elements in a set strictly smaller than k
*/
#include <bits/stdc++.h>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//template<typename T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const long long maxn = 1000;
const long long inf = 1e9 + 123;
const long long linf = 1e18 + 123;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1);
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};

long long dp[maxn][maxn], opt[maxn][maxn], n;

long long C(int l, int r){

}

void func(int k, int l = 1, int r = n, int optl = 0, int optr = n){
    if (l > r){
        return;
    }
    int m = (l + r) >> 1;
    long long optm;
    for(int j = optl; j < min(m, optr + 1); j ++){
        int x = dp[k - 1][j] + C(j + 1, m);
        if (x < dp[k][m]){
            dp[k][m] = x;
            optm = j;
        }
    }
    f(k, l, m - 1, optl, optm);
    f(k, m + 1, r, optm, optr);
}

int main(){
    freopen("input.cpp", "r", stdin);
    freopen("output.cpp", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    exit(0);
}
