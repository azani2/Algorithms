#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y;
double ans;

struct point {
    int x, y, idx;
};

vector<point> p;
vector<point> a;
vector<point> b;
point ansp1, ansp2;

double dist(point p1, point p2) {
	double a = (p1.x - p2.x);
	double b = (p1.y - p2.y);
	return sqrt(a*b + b*b);
}

long double minDist(vector<point> a, vector<point>b) {
	if (a.size() <= 1 && b.size() <= 1) {
		return INT_MAX;
	}

	vector<point> al;
	vector<point> ar;
	vector<point> bl;
	vector<point> br;

	for (int i = 0; i < a.size(); i++) {
		if (i <= a.size() / 2 - 1) { // da se opravi
			al.push_back(a[i]); // problem s tova che vuv vseki nov vektor indexite se promenqt i veche b[i].idx ne sochi kum idx v a, a nqkakvo staro a
		}
		if (i >= a.size() / 2) ar.push_back(a[i]);
	}

	for (int i = 0; i < a.size(); i++) {
		if (b[i].idx <= a.size() / 2 - 1) bl.push_back(b[i]);
		if (b[i].idx >= a.size() / 2) br.push_back(b[i]);
	}

	int dl = minDist(al, bl);
	int dr = minDist(ar, br);

	int d = min(dl, dr);

	double dm = INT_MAX;
	int m = (a[a.size() / 2 - 1].x + a[a.size() / 2 ].x) / 2;

	vector<point> midPointsA;
	for (point p : a) {
		if (abs(p.x - m) <= d) midPointsA.push_back(p);
		else if (p.x - m > d) break;
	}

	vector<point> midPointsB;
	for (point p : b) {
		if (abs(p.x - m) <= d) midPointsB.push_back(p);
	}

	
	for (point pl : midPointsA) { // good?
			for (point pr : midPointsB) {

				if (pl.x <= m && pr.x >= m) {
					double dst = dist(pl, pr);
					if (dst == 0) continue;

					dm = min(dm, dst);
					if (dst == dm) {
						ansp1 = pl;
						ansp2 = pr;
					}
				}
			}
	}

	return dm;
}

int main()
{
    //cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> x >> y;
	//	p.push_back(point{ x, y , i});
	//}
	n = 11;
	p.push_back(point{ 29, 54, 0 });
	p.push_back(point{ 41, 47, 1 });
	p.push_back(point{ 45, 34, 2 });
	p.push_back(point{ 21, 36, 3 });
	p.push_back(point{ 36, 20, 4 });
	p.push_back(point{ 56, 10, 5 });
	p.push_back(point{ 62, 52, 6 });
	p.push_back(point{ 78, 63, 7 });
	p.push_back(point{ 12, 46, 8 });
	p.push_back(point{ 69, 33, 9 });
	p.push_back(point{ 86, 44, 10 });


	a = p; // idx v a[i] = idx na a[i] v p
	sort(a.begin(), a.end(), [](point p1, point p2) { return p1.x <= p2.x; });
	
	for (int i = 0; i < n; i++)
	{
		p[a[i].idx].idx = i; //idx na p[i] = i v a
	}

	//p e mejdinen masiv
	b = p;
	sort(b.begin(), b.end(), [](point p1, point p2) { return p1.y <= p2.y; });
	// idx na b[i] = i na b[i] v a

	ans = minDist(a, b);
	cout << ans << endl << ansp1.x << ansp1.y << endl << ansp2.x << ansp2.y;
}