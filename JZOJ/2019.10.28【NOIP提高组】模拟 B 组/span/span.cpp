// A.span
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std; int T, N, M, ans; struct __edge {int u, v, w;} edge[10000]; int _cmp_sort(__edge x, __edge y) {return x.w < y.w;} struct __bin {int fa[200], size[200], cnt, siz; int& operator[](int x) {return fa[x];} void operator<<(int x) {siz = cnt = x; for (int i = 1; i <= x; ++i)fa[i] = i, size[i] = 1;} int _root(int x) {if (fa[x] != x)fa[x] = _root(fa[x]); return fa[x];} int operator()(int x) {return _root(x);} void _merge(int x, int y) {x = _root(x), y = _root(y); if (x != y && 0 < x && x <= siz && 0 < y && y <= siz) {if (size[x] < size[y])fa[x] = y, size[y] += size[x]; else fa[y] = x, size[x] += size[y]; cnt--;}} void operator()(int x, int y) {_merge(x, y);} bool operator()() {return cnt > 1;}} bin; int _solve(int n, int m, int s, __edge e[]) {bin << n; int i; for (i = s; i <= m && bin(); ++i)bin(e[i].u, e[i].v); return (bin()) ?  ((1e9)) : (e[i - 1].w - e[s].w);} int main() {freopen("A.in", "r", stdin); cin >> T; while (T-- > 0) {cin >> N >> M; for (int i = 1; i <= M; ++i)cin >> edge[i].u >> edge[i].v >> edge[i].w; sort(&edge[1], &edge[M + 1], _cmp_sort); ans = (1e9); for (int i = 1; i <= M; ++i)ans = min(ans, _solve(N, M, i, edge)); cout << ((ans == (1e9)) ? (-1) : (ans)) << endl;} return 0;}