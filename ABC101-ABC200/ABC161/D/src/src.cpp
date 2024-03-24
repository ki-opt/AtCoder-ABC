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
	ll K; cin >> K;
	vector<ll> ans = {1,2,3,4,5,6,7,8,9};
	int cnt = 0;
	for (int i = 0; cnt < 200000; i++) {
		ll tmp = ans[i] % 10;
		if (tmp == 0) {
			ans.push_back(ans[i]*10);
			ans.push_back(ans[i]*10+1);
			cnt += 2;
		} else if (tmp == 9) {
			ans.push_back(ans[i]*10+8);
			ans.push_back(ans[i]*10+9);
			cnt += 2;
		} else {
			ans.push_back(ans[i]*10+tmp-1);
			ans.push_back(ans[i]*10+tmp);
			ans.push_back(ans[i]*10+tmp+1);
			cnt += 3;
		}
	}	
	sort(ans.begin(),ans.end());
	cout << ans[K-1] << endl;

	return 0;
}