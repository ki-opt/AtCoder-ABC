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
	ll N, H;
	cin >> N >> H;
	vector<ll> a(N), b(N);
	vector<pair<ll,ll>> katana(N);
	rep(i,N) {
		cin >> a[i] >> b[i];
		katana[i] = {b[i],i};
	}

	sort(katana.rbegin(),katana.rend());
	auto itr = max_element(a.begin(),a.end());
	ll max_a = *itr, max_a_index = distance(a.begin(),itr);
	ll ans = 0;
	int index = 0;
	while (H > 0) {
		if (max_a < katana[index].first) {
			H -= katana[index].first;
			ans++;
			index++;
		} else if (max_a == katana[index].first) {
			if (max_a_index != katana[index].second) {
				H -= katana[index].first;
				ans++;
			}
			index++;
		} else {
			if (H % max_a == 0) ans += H / max_a;
			else ans += H / max_a + 1;
			break;
		}
	}
	cout << ans << endl;	return 0;
}