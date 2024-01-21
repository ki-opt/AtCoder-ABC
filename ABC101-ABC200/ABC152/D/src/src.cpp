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
	int N;
	cin >> N;

	vector<vector<ll>> cnt(10,vector<ll>(10,0));
	repp(i,1,N+1) {
		int left, right = i % 10;
		int tmp = i;
		while (tmp != 0) { left = tmp % 10; tmp /= 10; }
		cnt[left][right]++;
	}

	ll ans = 0;
	rep(i,10) rep(j,10) ans += cnt[i][j] * cnt[j][i];
	cout << ans << endl;
	return 0;
}