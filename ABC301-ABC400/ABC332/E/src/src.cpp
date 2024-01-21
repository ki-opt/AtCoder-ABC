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

int H, W;

int main() {
	int D, N;
	cin >> N >> D;
	vector<double> W(N);
	rep(i,N) cin >> W[i];

	vector<vector<vector<ll>>> dp(N,vector<vector<ll>>(D));
	
	rep(i,D) dp[0][i].push_back()
	repp(i,1,N) {
		rep(j,D) {	
		}
	}

}