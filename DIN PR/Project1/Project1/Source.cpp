#include <iostream>
using namespace std;

#define MAX 50

long long a[MAX];
int n;

long long fibb(int x) {
	if (x <= 1) return 1;
	if (a[x] != 0) return a[x];
	return a[x] = fibb(x - 1) + fibb(x - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cout << fibb(n) << endl;

	return 0;
}