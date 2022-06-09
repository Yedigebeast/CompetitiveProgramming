//http://acm.math.spbu.ru/~sk1/mm/lections/zksh2016-centroid/conspect.pdf
//https://www.geeksforgeeks.org/centroid-decomposition-of-tree/
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

const long long maxn = 3e5 + 123;
const long long inf = 1e9 + 123;
const long long linf = 1e18 + 123;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1);
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};

int d[maxn], level[maxn], parent[maxn], n;

vector<int> g[maxn];

void dfs(int v, int p){
    d[v] = 1;
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (to == p){
            continue;
        }
        dfs(to, v);
        d[v] += d[to];
    }
}

int find_center(int v){
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (level[to] != -1){
            continue;
        }
        if (d[to] > d[v] / 2){
            d[v] -= d[to];
            d[to] += d[v];
            return find_center(to);
        }
    }
    return v;
}

void build(int v, int depth, int p){
    v = find_center(v);
    level[v] = depth;
    parent[v] = p;
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (level[to] != -1){
            continue;
        }
        build(to, depth + 1, v);
    }
}

int main(){
    //freopen("input.cpp", "r", stdin);
    //freopen("output.cpp", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        level[i] = -1;
    }
    dfs(1, -1);
    build(1, 0, -1);
    exit(0);
}
