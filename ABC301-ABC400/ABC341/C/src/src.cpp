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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W, N; cin >> H >> W >> N;
	string T; cin >> T;
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	vector<pair<int,int>> move;
	rep(i,N) {
		if (T[i] == 'L') move.push_back({0,-1});
		else if (T[i] == 'R') move.push_back({0,1});
		else if (T[i] == 'U') move.push_back({-1,0});
		else if (T[i] == 'D') move.push_back({+1,0});
	}


	int ans = 0;
	repp(h,1,H-1) {
		repp(w,1,W-1) {
			if (S[h][w] == '#') continue;
			int h_dash = h, w_dash = w;
			bool isFound = true;
			rep(i,N) {
				h_dash += move[i].first;
				w_dash += move[i].second;
				if (S[h_dash][w_dash] == '#') {
					isFound =false;
					break;
				}
			}
			if (isFound) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}