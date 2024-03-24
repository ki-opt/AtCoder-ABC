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
#include <set>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node{ull val, x, y;};

int main() {
	ull X, Y, A, B; cin >> X >> Y >> A >> B;
	vector<Node> ans;
	ull a = 0, x = X, y = Y;
	ans.push_back({a,x,y});
	while (x <= y / A) {
		a++;
		x *= A;
		ans.push_back({a,x,y});
	}
	
	ull keikenti = 0;
	for (auto n : ans) {
		if ((n.y - n.x) % B == 0) n.val += ((n.y - n.x) / B) - 1;
		else n.val += (n.y - n.x) / B;
		keikenti = max(keikenti, n.val);
	}

	cout << keikenti << endl;

	return 0;
}