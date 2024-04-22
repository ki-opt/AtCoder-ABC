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
	ll N; cin >> N;
	ll n = N;
	string ans;
	while (n > 0) {
		if (n % 2 == 0) {
			n /= 2;
			ans = 'B' + ans; 
		} else if (n % 2 == 1) {
			n--;
			ans = 'A' + ans;
		}
	}
	cout << ans << endl;

	return 0;
}