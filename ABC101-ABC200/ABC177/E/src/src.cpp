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

int MAX = 1e6+1;
vector<int> spf(MAX,0);
void prepare_factorize() {
	rep(i,MAX)  spf[i] = i;
	for (int p=2; p*p <= MAX; p++) for (int i=p; i<MAX; i+=p) if (spf[i]==i) {
		spf[i] = p;
	}
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	prepare_factorize();
	vector<int> c(MAX+1,0);
	bool isPairwise = true;
	rep(i,N) {
		int a = A[i];
		map<int,int> mp;
		while(a != 1) {
			int p = spf[a];
			if (c[p] != 0) isPairwise = false;
			mp[p]++;
			a /= p;
		}
		for (auto m : mp) c[m.first]++;
		//c[A[i]]++;
	}
	if (isPairwise) {
		cout << "pairwise coprime" << endl;
	} else {
		rep(i,MAX+1) {
			if (c[i] == N) {
				cout << "not coprime" << endl;
				return 0;
			}
		}
		cout << "setwise coprime" << endl;
	}



	/*
	vector<ll> c(1000001,0);
	bool isPairwise = true;
	rep(i,N) {
		for (int j = 2; j * j <= A[i]; j++) {
			if (A[i] % j == 0) {
				if (c[j] != 0) isPairwise = false;
				c[j]++;
				if (A[i]/j != j) c[A[i]/j]++;
			}
		}
		c[A[i]]++;
	}
	if (isPairwise) {
		cout << "pairwise coprime" << endl;
	} else {
		rep(i,1000002) {
			if (c[i] == N) {
				cout << "not coprime" << endl;
				return 0;
			}
		}
		cout << "setwise coprime" << endl;
	}
	*/

	return 0;
}

