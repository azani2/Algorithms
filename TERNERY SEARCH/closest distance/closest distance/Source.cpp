#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define PO pair<double, double>

int t;
int ax, ay, bx, by, cx, cy, dx, dy;

double dist2P(PO p1, PO p2) {
	double x = p1.first - p2.first;
	double y = p1.second - p2.second;
	return sqrt(x*x + y*y);
}

double dist(double time) {
	PO p1;
	PO p2;
	p1.first = ax + (bx - ax) * time;
	p1.second = ay + (by - ay) * time;

	p2.first = cx + (dx - cx) * time;
	p2.second = cy + (dy - cy) * time;

	return dist2P(p1, p2);
}

double solve() {
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	double lo = 0, hi = 1;
	double t1, t2, d1, d2, d;

	for (int i = 0; i < 1000; i++) {

		t1 = lo + (hi - lo) * (1.0 / 3);
		t2 = lo + (hi - lo) * (2.0 / 3);

		d1 = dist(t1);
		d2 = dist(t2);

		if (d1 < d2) {
			hi = t2;
			d = d1;
		}
		else {
			d = d1;
			lo = t1;
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int i = 0; i < t; i++) 
		cout << "Case " << i + 1 << ": " 
			<< setprecision(11) << solve() << endl;

	cout << endl;
	return 0;
}