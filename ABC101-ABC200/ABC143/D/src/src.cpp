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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N; cin >> N;
	vector<int> L(N);
	rep(i,N) cin >> L[i];
	sort(L.begin(),L.end());
	ll ans = 0;
	rep(i,N) {
		int a = L[i];
		repp(j,i+1,N-1) {
			int b = L[j];
			int c_max = a + b;
			auto itr_max = lower_bound(L.begin(),L.end(),c_max);
			ll tmp = distance(L.begin()+j,itr_max) - 1;
			ans += tmp;
			/*auto itr_min = upper_bound(L.begin(),L.end(),c_min);
			auto itr_max = upper_bound(L.begin(),L.end(),c_max);
			//cout << *itr_min << " " << *itr_max << endl;
			if (itr_max == L.end()) continue;
			ll tmp = distance(itr_min,itr_max) - 1;
			ans += tmp;*/
		}
	}
	cout << ans << endl;

	return 0;
}