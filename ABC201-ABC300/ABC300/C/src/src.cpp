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
	vector<vector<char>> C(H,vector<char>(W));
	rep(i,H) rep(j,W) cin >> C[i][j];
	int N = min(H,W);
	vector<int> S(N+1,0);
	vector<vector<bool>> used(H,vector<bool>(W,false));
	repp(i,1,H-1) {
		repp(j,1,W-1) {
			if (C[i][j] == '.' && used[i][j]) continue;
			int k = 1;
			while(i - k >= 0 && i + k < H && j - k >= 0 && j + k < W) {
				if (C[i-k][j-k] == '#' && C[i-k][j+k] == '#' &&
						C[i+k][j-k] == '#' && C[i+k][j+k] == '#' &&
						!used[i-k][j-k] && !used[i-k][j+k] &&
						!used[i+k][j-k] && !used[i+k][j+k] ) {
					k++;
				} else {
					break;
				}
			}
			if (k == 1) continue;
			used[i][j] = true;
			repp(t,1,k) {
				used[i-t][j-t] = true; used[i-t][j+t] = true; 
				used[i+t][j-t] = true; used[i+t][j+t] = true;
			}
			S[k-1]++;
		}
	}

	repp(i,1,N+1) cout << S[i] << " ";
	return 0;
}