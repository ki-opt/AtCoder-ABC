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
	//vector<vector<ll>> D(N-1,vector<ll>()), w(N,vector<ll>(N,0));
	vector<vector<ll>> w(N,vector<ll>(N,0));
	rep(i,N-1) {
		repp(j,i+1,N) {
			ll tmp;
			cin >> tmp;
			w[i][j] = tmp;
			w[j][i] = tmp;
		}
		//D[i] = vector<ll>(N-(i+1));
		//rep(j,N-(i+1)) cin >> D[i][j];
	}

	ll ans = 0;
	vector<ll> dp(1 << N, 0);
	rep(b,(1<<N)-1) {
		rep(i,N) {
			repp(j,i+1,N) {
				if ((b >> i & 1) || (b >> j & 1)) {
					continue;
				}
				int nb = b | (1 << i) | (1 << j);
				dp[nb] = max(dp[nb], dp[b] + w[i][j]);
				ans = max(ans, dp[nb]);
			}
		}
	}
	cout << ans << endl;

	// BFSでやろうとしたけどうまくいかない><
	/*
	vector<pair<int,int>> pairs;
	rep(i,N) {
		//repp(j,i+1,N) pairs.push_back({i,j});
		rep(j,N) if (i != j) pairs.push_back({i,j});
	}

	queue<pair<ll,vector<bool>>> que;
	ll ans = -1;
	for (int i = 0; i < pairs.size(); i++) {
		vector<bool> check(N,false);
		check[pairs[i].first] = true;	check[pairs[i].second] = true;
		que.push({w[pairs[i].first][pairs[i].second],check});
		ans = max(ans, w[pairs[i].first][pairs[i].second]);
	}

	while(que.empty() == false) {
		pair<ll,vector<bool>> tmp = que.front(); que.pop();
		for (int i = 0; i < pairs.size(); i++) {
			int iti = pairs[i].first, ni = pairs[i].second;
			if (tmp.second[iti] == false && tmp.second[ni] == false) {
				tmp.second[iti] = true; tmp.second[ni] = true;
				ll score = tmp.first+w[iti][ni];
				que.push({score, tmp.second});
				ans = max(ans, score);
			}
		}
	}*/
	
	return 0;
}