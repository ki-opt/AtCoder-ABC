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

long int combination(long int n, long int k) {
	long int r = 1;
	for (long int d = 1; d <= k; d++) {
		r *= n--;
		r /= d;
	}
	return r;
}

int main() {
	int N;
	cin >> N;
	vector<long int> A(N);
	vector<long int> tyohuku(N+1,0);// num(N+1,0);
	vector<long int> num(N+1,0);
	rep(i,N) {
		cin >> A[i];
		tyohuku[A[i]]++;
	}
	
	long int total = 0;
	repp(i,N+1,1) {
		if (tyohuku[i] >= 2) {
			num[i] = combination(tyohuku[i],2);
			total += num[i];
			//num[i] = tyohuku[i];
		}
	}

	rep(k,N) {
		long int tmp = 0;
		if (tyohuku[A[k]] > 2) tmp = combination(tyohuku[A[k]]-1,2);
		cout << total - num[A[k]] + tmp << endl; 
	}

	return 0;
}