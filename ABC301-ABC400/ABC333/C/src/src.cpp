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
	int N;
	cin >> N;
	vector<ll> ans;
	unordered_map<ll,int> umap;
	for (ll i = 1; i < (ll)pow(10,17); i = 10 * i + 1) {
		for (ll j = 1; j < (ll)pow(10,17); j = 10 * j + 1) {
			for (ll k = 1; k < (ll)pow(10,17); k = 10 * k + 1) {
				if (umap.count(i+j+k) > 0) continue;
				ans.push_back(i+j+k);
				umap[i+j+k] = 1;
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans[N-1] << endl;

	return 0;
}