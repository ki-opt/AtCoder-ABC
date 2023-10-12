#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> p(N);
	map<int,vector<int>> mp;
	repp(i,1,N) {
		cin >> p[i];
		mp[p[i]].push_back(i+1);
	}
	vector<int> x(M), y(M);
	//vector<pair<int,int>> pairs(M);
	rep(i,M) {
		cin >> x[i] >> y[i];
		//pairs[i] = {x[i],y[i]};
	}
	
	//vector<vector<Node>> par;
	//par.push_back(vector<int>());
	//par[0].push_back(1);

	//sort(pairs.begin(),pairs.end(),)
	vector<int> dp(N+1,-1);
	rep(i,M) {
		if (y[i] > dp[x[i]]) dp[x[i]] = y[i];
	}

	int ans = 0;
	repp(i,1,N+1) {
		rep(j,mp[i].size()) {
			dp[mp[i][j]] = max(dp[mp[i][j]],dp[i]-1) ;
		}
		if (dp[i] >= 0) ans++;
	}
	cout << ans << endl;

	return 0;
}