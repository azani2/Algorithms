#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long n;
long ax, ay, bx, by;
int current, ans;

struct point {
    long x, type;

    bool operator<(const point& other) {
        if (x != other.x) return x < other.x;
        return type > other.type;
    }
};

vector<point> x, y;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ax >> ay >> bx >> by;
        if (ax > bx) swap(ax, bx);
        if (ay > by) swap(ay, by);
        x.push_back(point{ ax, 1 });
        x.push_back(point{ bx, -1 });

        y.push_back(point{ ay, 1 });
        y.push_back(point{ by, -1 });
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (point p : x)
    {
        current += p.type;
        ans = max(ans, current);
    }

    for (point p : y)
    {
        current += p.type;
        ans = max(ans, current);
    }

    cout << ans << endl;
}