#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

vector<bool> seen;
vector<ll> num;
vector<vector<ll>> graph;
vector<ll> C;
vector<ll> ans;

ll dfs_total(ll node, ll edge) {
	ll val = edge * C[node];
	for (auto g : graph[node]) {
		if (seen[g]) continue;
		seen[g] = true;
		val += dfs_total(g, edge+1);
	}
	return val;
}

int main() {
	ll N; cin >> N;
	graph.resize(N);
	rep(i,N-1) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	C.resize(N);
	rep(i,N) cin >> C[i];

	ll total = 0;
	rep(i,N) total += C[i];
	double center = (double)total / (double)N;

	ll index = -1;
	double min_val = DBL_MAX;
	rep(i,N) {
		if (fabs((double)C[i] - center) < min_val) {
			min_val = fabs((double)C[i] - center);
			index = i;
		}
	}

	seen.resize(N);
	rep(i,N) seen[i] = false;
	seen[0] = true;	
	cout << dfs_total(index,0) << endl;
	return 0;
}
/*
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

ll dfs_num(ll node) {
	bool isFound = false;
	for (auto g : graph[node]) {
		if (seen[g]) continue;
		seen[g] = true;
		isFound = true;
		num[node] += dfs_num(g);
	}
	return num[node] + C[node];
}


ll dfs_total(ll node, ll edge) {
	ll val = edge * C[node];
	for (auto g : graph[node]) {
		if (seen[g]) continue;
		seen[g] = true;
		val += dfs_total(g, edge+1);
	}
	return val;
}

void dfs_ans(ll node, ll total) {
	for (auto g : graph[node]) {
		if (seen[g]) continue;
		seen[g] = true;
		ll tmp = total + num[0] - 2*C[g] + C[node] - 2*num[g];//total + num[node] - 2*num[g] - 2*C[g] + C[node];
		ans[g] = tmp;
		dfs_ans(g, tmp);
	}
}

int main() {
	ll N; 
	long long n; cin >> n; N = n;
	graph.resize(N);
	rep(i,N-1) {
		long long a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	C.resize(N);
	rep(i,N) {
		long long c;
		cin >> c;
		C[i] = c;
	}

	seen.resize(N); num.resize(N);
	rep(i,N) {
		seen[i] = false;
		num[i] = 0;
	}

	// 各ノードでの子ノードの値の取得
	seen[0] = true;
	dfs_num(0);

	// f(0)の取得
	rep(i,N) seen[i] = false;
	seen[0] = true;
	ll total = dfs_total(0,0);

	rep(i,N) seen[i] = false;
	seen[0] = true;
	ans.resize(N);
	ans[0] = total;
	dfs_ans(0,total);

	ll v = 1e25;
	for (auto a : ans) {
		if (a < v) v = a;
	}
	cout << v << endl;

	return 0;
}
*/