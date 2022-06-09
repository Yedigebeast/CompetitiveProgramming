// time complexity = q * sizeblock + n * n / sizeblock
#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define size(x) (int) x.size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF32 = INT_MAX;
const ll INF64 = ((ll)INF32 << 29ll);

void reflex() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

const int MAX = 1e5 + 1e2;

struct Query {
    int l, r, id;
}query[MAX];
int n, sizeblock = 320;
int f(int x) {
    return x/sizeblock;
}
bool cmp(Query x, Query y) {
    if (f(x.l) != f(y.l))
        return f(x.l) < f(y.l);
    if((x.l / blocksize) % 2 == 0){
        return x.r > y.r;
    }
    else{
        return x.r < y.r;
    } 
}

/*
bool cmp(Query x, Query y) {
    if (f(x.l) != f(y.l))
        return f(x.l) < f(y.l);
    if((x.l / blocksize) % 2 == 0){
        return x.r < y.r;
    }
    else{
        return x.r > y.r;
    } 
}
*/
int main() {
    reflex();
    cin >> n;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;
    int q;
    cin >> q;
    for (int l, r, i = 0; i < q; i++) {
        cin >> l >> r;
        l--, r--;
        query[i].id = i;
        query[i].l = l, query[i].r = r;
    }
    sort(query, query + q, cmp); /// magical sorting
    ll res = 0;
    auto add = [&](int x) { /// it's just a function in function
        res += a[x];
    };
    auto del = [&](int x) {
        res -= a[x];
    };
    int curl = query[0].l, curr = curl; /// for optimization we can start with first value of queries
    add(curl);
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        int id = query[i].id;
        int l = query[i].l, r = query[i].r;

        /// moving our current edges
        while (curl < l){
            del(curl);
            curl++;
        }
        while (curl > l){
            curl--;
            add(curl);
        }
        while (curr < r){
            curr++;
            add(curr);
        }
        while (curr > r){
            del(curr);
            curr--;
        }
        ans[id] = res;
    }
    for (ll x : ans)  /// outputting our answers
        cout << x << "\n";
    return false;
}
