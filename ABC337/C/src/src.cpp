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

int main() {
	int N; cin >> N;
	vector<int> A(N); 
	vector<int> narabi(N+1);
	int first;
	rep(i,N) {
		cin >> A[i];
		if (A[i] != -1) narabi[A[i]] = i+1;
		else { cout << i+1 << " ", first = i+1; }
	}

	int next = first;
	repp(i,1,N) {
		cout << narabi[next] << " ";
		next = narabi[next];
	}
	return 0;
}