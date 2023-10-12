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
	int M;
	vector<string> S(3);
	cin >> M >> S[0] >> S[1] >> S[2];

	int ans = INT_MAX;
	vector<int> array = {0,1,2};
	do {
		repp(i,0,10) {
			int max_val = 0;
			bool found = true;
			unordered_map<int,int> umap;
			rep(j,3) {
				bool is_found = false;
				rep(t,3*M) {
					if (S[array[j]][t%M] - '0' == i && umap.count(t) == 0) {
						max_val = max(max_val,t);
						umap[t] = 1;
						is_found = true;
						break;
					}
				}
				if (!is_found) { found = false; break; }
			}
			if (found) ans = min(ans,max_val);
		}
	} while (next_permutation(array.begin(),array.end()));
	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}