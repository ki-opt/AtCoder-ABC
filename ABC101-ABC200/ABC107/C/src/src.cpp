#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> x_p, x_m;
	rep(i,N) {
		ll tmp;
		cin >> tmp;
		if (tmp >= 0) x_p.push_back(tmp);
		else x_m.push_back(-tmp);
	}
	reverse(x_m.begin(), x_m.end());
	
	ll tmp;
	ll ans = INT_MAX;
	if (x_p.size() >= K) { tmp = x_p[K-1]; ans = min(ans,tmp); }
	if (x_m.size() >= K) { tmp = x_m[K-1]; ans = min(ans,tmp);}

	if (x_m.size() > 0) {
		for (int i = 0; i < K-1 && i < x_m.size(); i++) {
			ll left = x_m[i];
			if (K-(i+1)-1 >= x_p.size()) continue;
			ll right = x_p[K-(i+1)-1];
			if (left < right) tmp = left * 2 + right;
			else tmp = left + right * 2;
			ans = min(ans,tmp);
		}
	}
	if (x_p.size() > 0) {
		for (int i = 0; i < K-1 && i < x_p.size(); i++) {
			ll right = x_p[i];
			if (K-(i+1)-1 >= x_m.size()) continue;
			ll left = x_m[K-(i+1)-1];
			if (left < right) tmp = left * 2 + right;
			else tmp = left + right * 2;
			ans = min(ans,tmp);
		}
	}
	cout << ans << endl;
	
	return 0;
}