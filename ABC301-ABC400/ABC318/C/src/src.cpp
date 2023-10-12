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
	ll N, D, P;
	cin >> N >> D >> P;
	vector<ll> F(N);
	rep(i,N) cin >> F[i];

	sort(F.begin(),F.end(),greater<ll>());
	ll ans = 0;
	rep(i,N) {
		int j = i;
		ll total = 0;
		while(j < N) {
			total += F[j];
			j++;
			if (j - i >= D) {	
				break; 
			}
		}
		if (total >= P) {
			ans += P;
			i = j - 1;
		} else {
			j = i;
			while (j < N) {
				ans += F[j];
				j++;
				if (j >= N) break;
			}
			break;
		}
	}
	cout << ans << endl;
	return 0;
}