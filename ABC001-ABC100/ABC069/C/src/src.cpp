#include <queue>
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
	long int N;
	cin >> N;
	vector<long int> a(N);
	rep(i,N) cin >> a[i];

	//vector<long int> sorted(N);
	int cnt = 0;
	queue<long int> sorted, que;
	rep(i,a.size()) {
		if (a[i] % 4 == 0) {
			que.push(a[i]);
			a.erase(a.begin()+i);
			i--;
		} else if (a[i] % 2 == 0) {
			sorted.push(a[i]);
			a.erase(a.begin()+i);
			i--;
			cnt++;
		}
	}

	if (que.empty() && a.size() != 0) {
		cout << "No" << endl;
		cerr << 1 << endl;
		return 0;
	}
	if (cnt > 0) {
		sorted.push(que.front());
		que.pop();
	}
	rep(i,a.size()) {
		sorted.push(a[i]);
		if (que.empty() && i + 1 != a.size()) {
			cout << "No" << endl;
			cerr << 2 << endl;
			return 0;
		} else {
			sorted.push(que.front());
			que.pop();
		}
	}
	cout << "Yes" << endl;

	/*
	vector<long int> check(N,0), sorted(N);
	int ans_2 = 0, ans_4 = 0;
	rep(i,N) { 
		if (a[i] % 4 == 0) {
			check[i] = 1; 
			ans_4++; 
		} else if (a[i] % 2 == 0) {
			
			ans_2++;
		}
	}

	if (N % 2 == 1) {
		if (ans_4 >= ((N - ans_2) / 2 + 1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	} else {
		if (ans_4 >= ((N - ans_2) / 2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}*/
	return 0;
}