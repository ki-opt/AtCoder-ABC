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
#include <math.h>
#include <bitset>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ull a, b, C; cin >> a >> b >> C;

	bitset<60> z(C);
	/*
	int most_left = 0;
	rep(i,z.size()) {
		if (z[i] == '1') {
			most_left = i;
		}
	}
	string x, y;
	rep(i,most_left) x += '0', y += '0';
	*/

	string x, y;
	int zero_cnt = 0;
	rep(i,z.size()) {
		if (z[i] == 1) {
			if (a > b) {
				if (a <= 0) {
					cout << -1 << endl;
					return 0;
				} else {
					x += '1'; y += '0';
					a--;
				}
			} else {
				if (b <= 0) {
					cout << -1 << endl;
					return 0;
				} else {
					x += '0'; y += '1';
					b--;
				}
			}
		} else {
			x += '0'; y += '0';
			zero_cnt++;
		}
	}

	if (a == b) {
		if (a <= zero_cnt) {
			int j = 0;
			rep(i,a) {
				while (j < 60 && (x[j] == '1' || y[j] == '1')) j++;
				if (j == 60) break;
				x[j] = '1'; y[j] = '1';
			}
			if (j != 60) {
				//reverse(x.begin(), x.end()); reverse(y.begin(), y.end());
				ll ans_x = 0, ans_y = 0;
				rep(i,60) {
					if (x[i] == '1') ans_x += (ll)pow(2,i);
					if (y[i] == '1') ans_y += (ll)pow(2,i);
				}
				cout << ans_x << " " << ans_y << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}