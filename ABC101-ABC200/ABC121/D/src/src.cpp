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

ll func_zero_n(ll num) {
	if (num % 4 == 0) return num;
	else if (num % 4 == 1) return 1;
	else if (num % 4 == 3) return 0;
	else return 1 ^ num;
}

int main() {
	ll A, B; cin >> A >> B;
	if (A == 0) cout << func_zero_n(B) << endl;
	else cout << (func_zero_n(A-1) ^ func_zero_n(B)) << endl;
	return 0;
}