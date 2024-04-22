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

struct Node{ll i, j;};
struct NodeEnergy{ll i, j, e;};

int main() {
	ll H, W; cin >> H >> W;
	vector<string> A(H);
	rep(i,H) cin >> A[i];
	ll N; cin >> N;
	vector<ll> R(N), C(N), E(N);
	rep(i,N) {
		cin >> R[i] >> C[i] >> E[i];
		R[i]--, C[i]--;
	}

	Node s, t;
	rep(i,H) rep(j,W) {
		if (A[i][j] == 'S') s = {i,j};
		else if (A[i][j] == 'T') t = {i,j};
	}

	// スタート地点に補給物資があるか確認
	bool isFound = false;
	vector<vector<ll>> energy_spot(H,vector<ll>(W,-1));
	rep(i,N) energy_spot[R[i]][C[i]] = E[i];
	if (energy_spot[s.i][s.j] == -1) {
		cout << "No" << endl;
		return 0;
	}

	// 探索開始
	vector<Node> move = {{-1,0},{1,0},{0,-1},{0,1}};
	queue<NodeEnergy> que;
	que.push({s.i,s.j,energy_spot[s.i][s.j]});
	vector<vector<ll>> seen(H,vector<ll>(W,-1));
	seen[s.i][s.j] = energy_spot[s.i][s.j];
	while (!que.empty()) {
		NodeEnergy tmp = que.front(); que.pop();
		if (tmp.i == t.i && tmp.j == t.j) {
			cout << "Yes" << endl;
			return 0;
		}
		for (auto m : move) {
			Node next = {tmp.i+m.i, tmp.j+m.j};
			ll energy = tmp.e - 1;
			if (next.i >= H || next.i < 0 || next.j >= W || next.j < 0) continue;
			if (A[next.i][next.j] == '#') continue;
			if (energy < 0 && energy_spot[next.i][next.j] == -1) continue;
			if (energy < energy_spot[next.i][next.j]) energy = energy_spot[next.i][next.j];
			if (energy <= seen[next.i][next.j]) continue;
			que.push({next.i,next.j,energy});
			seen[next.i][next.j] = energy;
		}
	}
	cout << "No" << endl;
	return 0;
}