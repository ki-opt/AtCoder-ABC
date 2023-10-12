#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, K;
	cin >> N >> K;

	double ans = 0;
	repp(i,N+1,1) {
		int tmp = i;
		int cnt = 0;
		while(tmp < K) {
			tmp *= 2;
			cnt++;
		}
		ans += (1.0 / (double)N) * pow(0.5,cnt);
	}
	//cout << ans << endl;
	printf("%.15f\n",ans);

	return 0;
}