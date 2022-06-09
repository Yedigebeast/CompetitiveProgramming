int n, m;
int p[MaxN], sz[MaxN];

void make_set (int v) {
    p[v] = v;
    sz[v] = 0;
}

int get (int x) {
    if (x == p[x])
        return x;
    return p[x] = get(p[x]);
}

void add (int x, int y) {
    x = get (x);
    y = get (y);
    if (x == y)
        return;
    if (sz[x] < sz[y]) //12
        swap(x, y);
    p[y] = x;
    sz[x] += sz[y];
}

int main () {
    
    return 0;
}
