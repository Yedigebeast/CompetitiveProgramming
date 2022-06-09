//https://codeforces.com/contest/768/problem/E
#include <bits/stdc++.h>
#define ll long long
using namespace std;

map <ll, int> g[61];

int grundy(int x, ll mask){
	if(g[x].count(mask))
		return g[x][mask];
	bool used[61];
	memset(used, 0, sizeof used);
	for(int i = 1; i <= x; ++i){
		if(!((mask >> i) & 1)){
			int gi = grundy(x - i, (mask ^ (1LL << i)));
			used[gi] = 1;
		}
	}
	for(int i = 0; i <= 60; ++i)
		if(!used[i]){
			g[x][mask] = i;
			break;
		}
	return g[x][mask];
}

int main(){
	int n;
	cin >> n;
	int G = 0;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		G ^= grundy(x, 0);
	}
	if(G == 0)
		cout << "YES";
	else cout << "NO";
}