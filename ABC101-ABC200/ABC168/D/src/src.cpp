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

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M), B(M);
	vector<vector<ll>> room(N+1);
	rep(i,M) {
		cin >> A[i] >> B[i];
		room[A[i]].push_back(B[i]);
		room[B[i]].push_back(A[i]);
	}

	vector<ll> ans(N+1);
	vector<bool> seen(N+1);
	queue<ll> que;
	rep(i,room[1].size()) {
		que.push(room[1][i]);
		seen[room[1][i]] = true;
		ans[room[1][i]] = 1;
	}
	while (!que.empty()) {
		ll tmp = que.front(); que.pop();
		rep(i,room[tmp].size()) {
			if (seen[room[tmp][i]]) continue;
			que.push(room[tmp][i]);
			seen[room[tmp][i]] = true;
			ans[room[tmp][i]] = tmp;
		}
	}

	repp(i,2,N+1) {
		if (!seen[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	repp(i,2,N+1) {
		cout << ans[i] << endl;
	}
	return 0;
}