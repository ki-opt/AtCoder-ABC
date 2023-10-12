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
	int W, H, N;
	cin >> W >> H >> N;
	vector<int> x(N), y(N), a(N);
	rep(i,N) {
		cin >> x[i] >> y[i] >> a[i];
	}

	vector<vector<bool>> xy(W,vector<bool>(H,false));
	rep(i,N) {
		int lower_x = 0, lower_y = 0;
		int upper_x = W, upper_y = H;
		if (a[i] == 1) { upper_x = x[i]; } 
		else if (a[i] == 2) { lower_x = x[i]; }
		else if (a[i] == 3) { upper_y = y[i]; }
		else { lower_y = y[i]; }
		repp(i,lower_x,upper_x) {
			repp(j,lower_y,upper_y) {
				xy[i][j] = true;
			}
		}
	}
	int ans = 0;
	rep(i,W) {
		rep(j,H) {
			if (xy[i][j] == false) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}