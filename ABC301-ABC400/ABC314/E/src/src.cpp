#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <cctype>
#include <cstdlib>

using ll=long long;
using std::vector; using std::cin; using std::cout;
using std::pair; using std::string;
//using std::transform; using std::toupper; using std::tolower;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct input{
	int c, p;
	//vector<int>
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> C(N), P(N), score(N);
	vector<vector<int>> S(N,vector<int>());
	rep(i,N) {
		cin >> C[i] >> P[i];
		int sum = 0;
		rep(j,P[i]) {
			int tmp;
			cin >> tmp;
			S[i].push_back(tmp);
			sum += tmp;
		}
		score[i] = sum;
	}

	return 0;
}