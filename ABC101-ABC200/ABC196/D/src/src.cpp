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
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
int ans = 0;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int H, W;
vector<pair<int,int>> pairs = {{2,1},{1,2},{1,1}};

void dfs(vector<vector<bool>> seen, int A, int B) {
	int i_dash = -1, j_dash = -1;
	rep(i,H) rep(j,W) if (!seen[i][j]) { i_dash = i; j_dash = j; goto to; }
to:
	if (i_dash == -1 && j_dash == -1) { ans++; return; }
	if (A == 0 && B == 0) return;

	rep(index,pairs.size()) {
		auto p = pairs[index];
		if (index == 2) { if (B == 0) continue; }
		else { if (A == 0) continue; }
		// 範囲外
		if (i_dash + p.first > H || j_dash + p.second > W) continue;
		// update
		bool isFound = true;
		repp(i,i_dash,i_dash+p.first) repp(j,j_dash,j_dash+p.second) {
			if (seen[i][j]) isFound = false;
		}
		if (!isFound) continue;
		repp(i,i_dash,i_dash+p.first) repp(j,j_dash,j_dash+p.second) seen[i][j] = true;
		// dfs
		if (index == 2) dfs(seen,A,B-1);
		else dfs(seen,A-1,B);
		// rollback 
		repp(i,i_dash,i_dash+p.first) repp(j,j_dash,j_dash+p.second) seen[i][j] = false;
	}
}

int main() {
	int A, B;
	cin >> H >> W >> A >> B;
	vector<vector<bool>> seen(H,vector<bool>(W,false));
	dfs(seen,A,B);
	cout << ans << endl;

	return 0;
}