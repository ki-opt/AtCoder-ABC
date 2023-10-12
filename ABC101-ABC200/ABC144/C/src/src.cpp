#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N;
	cin >> N;

	long int cnt = 0;
	vector<long int> yakusu;//((long int)powl(N,0.5));
	for (long int i=1; i<(long int)powl(N,0.5)+1; i++) {
		if (N % i == 0) {
			//yakusu[cnt] = i;
			yakusu.push_back(i);
			cnt++;
		}
	}

	long int ans = LONG_MAX;
	for (long int i = 0; i < yakusu.size(); i++){
		long int tmp = N / yakusu[i];
		if (yakusu[i] + tmp - 2 < ans) ans = yakusu[i] + tmp - 2;
	}
	cout << ans << endl;

	return 0;
}