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
	int N, S, M, L;
	cin >> N >> S >> M >> L;

	int ans = INT_MAX;
	for (int i = 0; i * 6 <= N + 14; i++) {
		for (int j = 0; i * 6 + j * 8 <= N + 14; j++) {
			int tmp = i * 6 + j * 8;
			int val = i * S + j * M;
			if (tmp < N) {
				if ((N-tmp) % 12 == 0) {
					val += ((N-tmp) / 12) * L;
				} else {
					val += (((N-tmp) / 12) + 1) * L;
				}
			}
			ans = min(ans,val);
		}
	}
	cout << ans << endl;

	return 0;
}