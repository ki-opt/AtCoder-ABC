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
	int N, K; cin >> N >> K;
	vector<int> P(N);
	rep(i,N) cin >> P[i];
	
	priority_queue<int,vector<int>,greater<int>> pque;
	rep(i,K) pque.push(P[i]);
	cout << pque.top() << endl;
	int tmp = pque.top();
	repp(i,K,N) {
		if (P[i] > tmp) {
			pque.pop();
			pque.push(P[i]);
			tmp = pque.top();
		}
		cout << pque.top() << endl;
	}
	
	return 0;
}