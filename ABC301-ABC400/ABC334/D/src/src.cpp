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
	ll N, Q;
	cin >> N >> Q;
	vector<ll> R(N);
	rep(i,N) cin >> R[i];
	sort(R.begin(),R.end());
	vector<ll> total(N,0);
	total[0] = R[0];
	repp(i,1,N) total[i] = total[i-1] + R[i]; 

	rep(i,Q) {
		ll X;
		cin >> X;
		auto itr = upper_bound(total.begin(),total.end(),X);
		int ans = itr - total.begin();
		//if (ans == total.size() || total[ans] == X) cout << ans << endl;
		//else cout << ans + 1 << endl;
		cout << ans << endl;
	}

	return 0;
}