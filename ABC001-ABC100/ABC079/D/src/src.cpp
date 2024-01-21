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
	int H, W;
	cin >> H >> W;
	vector<vector<int>> c(10,vector<int>(10));
	rep(i,10) rep(j,10) cin >> c[i][j];
	vector<vector<int>> A(H,vector<int>(W));
	rep(i,H) rep(j,W) cin >> A[i][j];

	vector<vector<int>> min_arr(10,vector<int>(10,INT_MAX));
	rep(i,10) {
		vector<int> cost(10,INT_MAX);
		cost[i] = 0;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pque;
		rep(j,10) if (i != j) { pque.emplace(c[i][j],j); cost[j] = c[i][j]; }
		while(!pque.empty()) {
			int distance = pque.top().first;
			int from = pque.top().second;
			pque.pop();

			if (cost[from] < distance) continue;

			rep(j,10) {
				if (j == from) continue;
				int d = (distance + c[from][j]);
				if (d < cost[j]) {
					pque.emplace(d, j);
					cost[j] = d;
				}
			}
		}
		min_arr[i] = cost;
	}
	
	int ans = 0;
	rep(i,H) {
		rep(j,W) {
			if (A[i][j] == -1) continue;
			ans += min_arr[A[i][j]][1];
		}
	}
	cout << ans << endl;

	return 0;
}