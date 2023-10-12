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
	ll N, K, S;
	cin >> N >> K >> S;

	{
		if (S < (ll)pow(10,9)) {
			rep(i,N) {
				if (i < K) cout << S << " ";
				else cout << S + 1 << " ";
			}
		} else {
			rep(i,N) {
				if (i < K) cout << S << " ";
				else cout << 1 << " "; 
			}
		}
	}

	return 0;
}