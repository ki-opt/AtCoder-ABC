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
	vector<int> a(N+1);//, ball(N,0);
	repp(i,1,N+1) cin >> a[i];
		
	vector<int> ans, b(N+1,0);
	for (int i = N; i > 0; i--) {
		int ball = 0;
		for (int j = i * 2; j <= N; j += i) {
			ball += b[j];
		}
		if (a[i] == 0) {
			if (ball % 2 == 1) { 
				b[i]++; ans.push_back(i); 
			}
		} else if (a[i] == 1) {
			if (ball % 2 == 0) { 
				b[i]++; ans.push_back(i); 
			}
		}
	}

	cout << ans.size() << endl;
	rep(i,ans.size()) cout << ans[i] << " ";

	

	//if (a[0] == 1) b.push_back(1);

	/*int ball = 0;
	rep(i,N) {
		if (a[i] == 1) {
			ball++;
		}
	}*/

	return 0;
}