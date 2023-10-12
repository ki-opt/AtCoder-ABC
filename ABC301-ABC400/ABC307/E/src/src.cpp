#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N, M;
	cin >> N >> M;

	vector<vector<long int>> dp(N,vector<long int>(2,0));
	dp[0][1] = M;
	repp(i,N,1) {
		dp[i][0] = (M-1) * 
	}

	return 0;
}