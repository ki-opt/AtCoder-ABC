#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int func(int n) {
	if (n % 2 == 0) {
		return n / 2;
	} else {
		return 3 * n + 1;
	}
}

int main() {
	int s;
	cin >> s;

	int i = 1;
	vector<int> a(1000000);
	unordered_map<int,int> check;
	a[0] = s;
	check[a[0]] = 1;
	while(1) {
		a[i] = func(a[i-1]);
		if (check.count(a[i])) {
			cout << i + 1 << endl;
			return 0;
		}
		check[a[i]] = 1;
		i++;
	}

	return 0;
}