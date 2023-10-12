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


ull gcd(ull a, ull b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

ull lcm(ull a, ull b) {
	return (a/gcd(a,b))*b;
}

ull lcm_arr(vector<ull> &a) {
	int n = a.size();
	if (n==2) {
		return lcm(a[0],a[1]);
	} else {
		a[n-2] = lcm(a[n-2],a[n-1]);
		a.pop_back();
		return lcm_arr(a);
	}
}

int main() {
	int N;
	cin >> N;
	vector<ull> T(N);
	rep(i,N) cin >> T[i];
	if (N == 1) { cout << T[0] << endl; return 0; }

	sort(T.begin(),T.end(),greater<ull>());
	ull ans = lcm_arr(T);
	cout << ans << endl;
	
	return 0;
}