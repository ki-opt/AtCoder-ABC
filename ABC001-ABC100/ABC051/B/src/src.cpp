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
	int K, S;
	cin >> K >> S;
	int ans = 0;
	rep(i,K+1) {
		rep(j,K+1) {
			int k = S - (i + j);
			if (k >= 0 && k <= K) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}