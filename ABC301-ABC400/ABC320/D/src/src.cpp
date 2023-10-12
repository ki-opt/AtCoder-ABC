#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Edge {
	ll B, X, Y;
};

void DFS(vector<pair<ll,ll>> &pos, vector<bool> &seen,
			vector<vector<Edge>> &edge, ll node) { //, ll x, ll y) {
	rep(i,edge[node].size()) {
		Edge tmp = edge[node][i];
		if (seen[tmp.B]) continue;
		seen[tmp.B] = true;
		pos[tmp.B].first = pos[node].first + tmp.X;
		pos[tmp.B].second = pos[node].second + tmp.Y;
		DFS(pos, seen, edge, tmp.B);
	}
}

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M), B(M), X(M), Y(M);
	vector<vector<Edge>> edge(N+1);
	rep(i,M) {
		cin >> A[i] >> B[i] >> X[i] >> Y[i];
		edge[A[i]].push_back({B[i],X[i],Y[i]});
		edge[B[i]].push_back({A[i],-X[i],-Y[i]});
	}

	vector<bool> seen(N+1,false);
	vector<pair<ll,ll>> pos(N+1,{LLONG_MAX,LLONG_MAX});
	pos[1] = {0,0};
	seen[1] = true;
	DFS(pos,seen,edge,1);

	repp(i,1,N+1) {
		if (pos[i].first == LLONG_MAX && pos[i].second == LLONG_MAX) cout << "undecidable" << endl;
		else cout << pos[i].first << " " << pos[i].second << endl;
	}
	return 0;
}