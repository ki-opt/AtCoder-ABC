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
	vector<ll> A(N);
	priority_queue<ll> que;
	rep(i,N) {
		cin >> A[i];
		que.push(A[i]);
	}

	rep(i,M) {
		ll tmp = que.top(); que.pop();
		tmp /= 2;
		que.push(tmp);
	}
	ll ans = 0;
	rep(i,N) {
		ans += que.top();
		que.pop();
	}
	cout << ans << endl;

	return 0;
}