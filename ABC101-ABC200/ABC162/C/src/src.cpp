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
#include <numeric>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int K; cin >> K;
	int ans = 0;
	repp(i,1,K+1) {
		repp(j,1,K+1) {
			repp(k,1,K+1) {
				ans += gcd(gcd(i,j),k);
			}
		}
	}
	cout << ans << endl;

	return 0;
}