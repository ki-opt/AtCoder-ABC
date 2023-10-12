#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <bitset>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> k(M), p(M);
	vector<vector<int>> s(M,vector<int>());
	rep(i,M) {
		cin >> k[i];
		s[i] = vector<int>(k[i]);
		rep(j,k[i]) cin >> s[i][j];
	}
	rep(i,M) cin >> p[i];

	int ans = 0;
	for (int tmp = 0; tmp < (1 << N); tmp++) {
		bitset<100> bits(tmp);
		vector<int> check(N,0);
		int on = 0;
		rep(i,M) {
			int sum = 0;
			rep(j,k[i]) {
				if (bits[s[i][j]-1]) sum++;
			}
			if (sum % 2 == p[i]) {
				on++;
			} else {
				break;
			}
		}
		if (on == M) ans++;
	}
	cout << ans << endl;
	return 0;
}