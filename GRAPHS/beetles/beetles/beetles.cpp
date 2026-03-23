#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000

int n, x, y, ans;
pair<int, int> pos[MAX];
struct coord {
	int x, y;
};
coord a[MAX];
int dist(coord p1, coord p2) {
	return sqrt(p1.x - p2.x) + sqrt(p1.y - p2.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
}
