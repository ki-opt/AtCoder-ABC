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

bool check(vector<ll> &sum, ll n) {
	bool isFound = true;
	rep(i,n) if (sum[i] == 0) return false;
	rep(i,n-1) 
		if ((sum[i] < 0 && sum[i+1] < 0) || (sum[i] > 0 && sum[i+1] > 0)) return false;
	return true;
}

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
		
	/*, val;
	int index = 0;
	while (a[index] == 0 && index < n) index++;
	if (index == n) {
		ans = 1;
		val = 1;
	} else if (index != 0) {
		if (a[index] > 0) {
			if (index % 2 == 0) val = 1;
			else val = -1;
			ans = 1;
		} else if (a[index] < 0) {
			if (index % 2 == 0) val = -1;
			else val = 1;
			ans = 1;
		}
	} else if (index == 0) {
		val = a[index];
	}*/

	ll ans = LLONG_MAX;
	rep(iter,2) {
		vector<ll> a_tmp = a;
		ll val, tmp;
		if (iter == 0) {
			if (a_tmp[0] <= 0) {
				val = 1;
				tmp = abs(a_tmp[0]) + 1;
			} else {
				val = a_tmp[0];
				tmp = 0;
			}
		} else if (iter == 1) {
			if (a_tmp[0] >= 0) {
				val = -1;
				tmp = a_tmp[0] + 1;
			} else {
				val = a_tmp[0];
				tmp = 0;
			}
		}
	
		repp(i,1,n) {
			if (val > 0) {
				if (a_tmp[i] + val >= 0) {
					tmp += val + a_tmp[i] + 1;
					a_tmp[i] += -(val + a_tmp[i] + 1);
				}
			} else if (val < 0) {
				if (a_tmp[i] + val <= 0) {
					tmp += -(val + a_tmp[i]) + 1;
					a_tmp[i] += -(val + a_tmp[i]) + 1;
				}
			}
			val += a_tmp[i];
		}
		
		ans = min(ans,tmp);
	}

	cout << ans << endl;
	return 0;
}