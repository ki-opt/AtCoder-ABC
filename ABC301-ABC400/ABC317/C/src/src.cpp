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
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M), C(M);
	vector<vector<ll>> dist(N+1,vector<ll>(N+1,-1));
	rep(i,M) {
		cin >> A[i] >> B[i] >> C[i];
		dist[A[i]][B[i]] = C[i];
		dist[B[i]][A[i]] = C[i];
	}

	ll ans = -1;
	vector<int> nums(N+1);
	repp(i,1,N+1) nums[i] = i;
	do {
		ll tmp = 0;
		bool flag = 0;
		repp(i,1,N) {
			if (dist[nums[i]][nums[i+1]] == -1) {
				flag = 1;
				ans = max(ans,tmp);
				break;
			}
			tmp += dist[nums[i]][nums[i+1]];
		}
		if (flag == 1) {
			continue;
		}
		ans = max(ans,tmp);
	} while (next_permutation(nums.begin(), nums.end()));
	cout << ans << endl;

	return 0;
}