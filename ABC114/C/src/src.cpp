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
	ll N;
	cin >> N;

	ll keta = 0;
	ll n = N;
	while(n != 0) { keta++; n /= 10; }

	ll ans = 0;
	repp(i,1,keta-1) {

		repp(j,1,keta-(i+1)) {
			
		}
	}
	return 0;
}