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
	vector<ll> A(N), a;
	vector<ll> val((int)pow(10,6)+1,0);
	ll total = 0;
	rep(i,N) {
		cin >> A[i];
		val[A[i]]++;
		total += A[i];
	}
	a = A;
	sort(a.begin(),a.end());
	unordered_map<ll,ll> umap;
	rep(i,N) {
		if (umap.count(a[i]) == 0) {
			total -= val[a[i]] * a[i];
			umap[a[i]] = total;
		}
	}

	rep(i,N) {
		cout << umap[A[i]] << " ";
	}
	return 0;
}