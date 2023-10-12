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

double distance_func(int a1, int a2, int b1, int b2) {
	return pow((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2),0.5);
}

int main() {
	int N, D;
	cin >> N >> D;
	vector<int> X(N), Y(N);
	rep(i,N) cin >> X[i] >> Y[i];

	//cout << "Yes" << endl;
	vector<int> queue;
	vector<int> check(N,0);
	queue.push_back(0);
	while(queue.size() > 0) {
		int i = queue.front();
		check[i] = 1;
		queue.erase(queue.begin());

		int x = X[i], y = Y[i];
		rep(j,N) {
			if (i != j && check[j] == 0) {
				double tmp = distance_func(x,y,X[j],Y[j]);
				if (tmp <= D) {
					check[j] = 1;
					queue.push_back(j);
				}
			}
		}
	}
	rep(i,N) {
		if (check[i] == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}