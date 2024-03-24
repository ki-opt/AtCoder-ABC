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
	int A, B, D; cin >> A >> B >> D;
	int i = 0;
	while(1) {
		int tmp = A + D * i;
		cout << tmp << " ";
		if (tmp == B) break;
		i++;
	}
	return 0;
}