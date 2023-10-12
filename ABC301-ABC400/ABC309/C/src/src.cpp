#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> a(N), b(N);
	vector<pair<ll,ll>> pairs(N);
	ll nomu = 0;
	rep(i,N) {
		cin >> a[i] >> b[i];
		nomu += b[i];
		pairs[i] = make_pair(a[i],b[i]);
	}

	if (nomu <= K) {
		cout << 1 << endl;
		cerr << "???" << endl;
		return 0;
	}

	sort(pairs.begin(),pairs.end());
	ll day = 1;
	rep(i,N) {
		day = pairs[i].first;
		int flag = 0;
		while (1) {
			if (pairs[i].first == day) {
				nomu -= pairs[i].second;
				flag = 1;
				i++;
			} else {
				if (flag == 1) i--;
				break;
			}
		}
		if (nomu <= K) {
			cout << day + 1 << endl;
			return 0;
		}
	}



	return 0;
}