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

struct Node{int x,y,z;};

int main() {
	int V1, V2, V3; cin >> V1 >> V2 >> V3;
	
	int x1 = 7, x2 = 7, x3 = 7;
	rep(x2,8) {
		rep(y2,8) {
			rep(z2,8) {
				repp(x3,x2,x2+8) {
					repp(y3,y2,y2+8) {
						repp(z3,z2,z2+8) {
							int c3 = max(0,7-x3) * max(0,7-y3) * max(0,7-z3);
							int c1 = x2 * y2 * z3 + 
										(7 - x2) * (7 - y2) * (7 - z2) + 
										(x3+7 - max(7,x2+7)) * (y3+7 - max(7,y2+7)) * (z3+7 - max(7,z2+7));
							int c2 = 3 * 7 * 7 * 7 - (c1 + c3);
							if (c1 == V1 && c2 == V2 && c3 == V3) {
								cout << "Yes" << endl;
								printf("%d %d %d %d %d %d %d %d %d\n",0,0,0,x2,y2,z3,x3,y3,z3);
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "No" << endl;

	return 0;
}