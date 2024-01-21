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
	ll N, Q;
	cin >> N >> Q;
	vector<string> P(N);
	rep(i,N) cin >> P[i];

	//vector<vector<ll>> row(N,vector<ll>(N,0));
	vector<ll> row(N,0);
	vector<vector<ll>> row_forward(N,vector<ll>(N,0)), row_back(N,vector<ll>(N,0));
	rep(i,N) {
		rep(j,N) {
			if (P[i][j] == 'B') {
				row[i]++;
				if (j == 0) row_forward[i][j] = 1;
				else row_forward[i][j] = row_forward[i][j-1] + 1;
			}
		}
		for(int j = N-1; j >= 0; j--) {
			if (P[i][j] == 'B') {
				if (j == N-1) row_back[i][j] = 1;
				else row_back[i][j] = row_back[i][j+1] + 1;
			}
		}
	}

	rep(i,Q) {
		ll A, B, C, D;
		cin >> A >> B >> C >> D;
		ll a = A % N, b = B % N, c = C % N, d = D % N;
		ll ans = 0;
		repp(j,a,) {
			ans += row[j] - row_forward[j][b-1] - row_back[j][c];
		}
		cout << ans << endl;
	}

	return 0;
}