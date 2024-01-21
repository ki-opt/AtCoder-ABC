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
	ll N, M;
	cin >> N >> M;
	vector<ll> L(N);
	ll total = 0;
	rep(i,N) {
		cin >> L[i];
		total += L[i];
	}
	
	ll W_min = *max_element(L.begin(),L.end())-1, W_max = total + (N-1);
	while(W_max - W_min > 1) {
		ll W = (W_min + W_max) / 2;
		ll m = 1;
		bool isFound = true;
		ll sum = L[0];
		repp(i,1,N) {
			if (sum <= W) {
				sum++;
				sum += L[i];
				if (sum > W) {
					sum = L[i];
					m++;
				}
			}
			if (m > M) {
				isFound = false;
				break;
			}
		}
		if (isFound) W_max = W;
		else W_min = W;
	}
	cout << W_max << endl;
				
	return 0;
}