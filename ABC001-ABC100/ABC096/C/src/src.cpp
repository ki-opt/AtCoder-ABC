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
	int H, W;
	cin >> H >> W;
	vector<string> s(H);
	rep(i,H) cin >> s[i];

	rep(i,H) {
		rep(j,W) {
			int tmp = 0;
			if (s[i][j] == '#') {
				if (j + 1 >= W) tmp++;
				else if (s[i][j+1] == '.') tmp++;
				if (j - 1 < 0) tmp++;
				else if (s[i][j-1] == '.') tmp++;
				if (i + 1 >= H) tmp++;
				else if (s[i+1][j] == '.') tmp++;
				if (i - 1 < 0) tmp++;
				else if (s[i-1][j] == '.') tmp++;
			}
			if (tmp >= 4) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

	return 0;
}