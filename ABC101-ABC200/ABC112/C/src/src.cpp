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
	int N;
	cin >> N;
	vector<ll> x(N), y(N), h(N);
	rep(i,N) cin >> x[i] >> y[i] >> h[i];

	int not_zero_i;
	rep(i,N) { if (h[i] != 0) not_zero_i = i; }

	rep(cx,101) {
		rep(cy,101) {
			/*
			ll H_min = LLONG_MAX;
			rep(i,N) {
				if (h[i] == 0) {
					H_min = min(H_min,abs(x[i]-cx)+abs(y[i]-cy));
				}
			}
			*/

			bool isFound = true;
			//ll tmp = -abs(x[0]-cx)-abs(y[0]-cy);
			//ll H = h[0] - tmp;
			//if (H > H_min) continue;
			ll H = h[not_zero_i] + abs(x[not_zero_i]-cx) + abs(y[not_zero_i]-cy);
			repp(i,0,N) {
				ll tmp = -abs(x[i]-cx)-abs(y[i]-cy); 
				if ((h[i] > 0 && H != h[i] - tmp) ||
						(h[i] == 0 && H + tmp > 0)) {//h[i] - tmp > H_min || H != h[i] - tmp) { 
					isFound = false;
					break; 
				}
			}
			if (isFound) {
				cout << cx << " " << cy << " " << H << endl;
				return 0;
			}
		}
	}

	return 0;
}