#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;
#define MAXN 100005

template<int dim>
struct Point {
	double x[dim];
};

template<int dim>
double dist(const Point<dim>& p1, const Point<dim>& p2) {
	double res = 0;
	for (int i = 0; i < dim; i++)
	{
		res += (p1.x[i] - p2.x[i]) * (p1.x[i] - p2.x[i]);
	}
	return sqrt(res);
}

long n;
Point<3> a[MAXN];
Point<3> ans;

double maxD(const Point<3>& P) {
	double maxDist = -1;
	for (int i = 0; i < n; i++)
	{
		maxDist = max(dist(P, a[i]), maxDist);
	}
	return maxDist;
}

double opt(int dim, Point<3> P) {
	double l = -1e4, r = 1e4;
	for (int i = 0; i < 100; i++)
	{
		double m1 = l + (r - l) / 3;
		double m2 = r- (r - l) / 3;
		P.x[dim] = m1;
		double d1 = maxD(P);
		P.x[dim] = m2;
		double d2 = maxD(P);
		if (d1 < d2) {
			r = m2;
		}
		else {
			l = m1;
		}
	}
	return l;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for(int j = 0;j < 3;j++) cin >> a[i].x[j];
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			ans.x[j] = opt(j, ans);
		}
	}

	for (int i =0;i<3;i++)
		cout << fixed << setprecision(11) << ans.x[i] << " ";
	cout << endl;
}