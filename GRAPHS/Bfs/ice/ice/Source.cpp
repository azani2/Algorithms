#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 5000;
const pair<int, int> deltas[4] = { {-1, 0}, { +1, 0}, {0, -1}, {0, 1} };
//make pair has implicit conversion between types

int n;
string grid[MAXN + 3];
queue<pair<int, int>> q;

bool isInside(int i, int j)
{
    return (0 <= i && 0 <= j && i < n && j < n);
}

int adjCnt[MAXN + 3][MAXN + 3];
int dist[MAXN + 3][MAXN + 3];

int bfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '0')
            {
                dist[i][j] = 0;
                q.push({ i, j });
            }
            else
            {
                dist[i][j] = -1;
            }
        }
    }

    int maxDist = -1;
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        maxDist = dist[pos.first][pos.second];

        for (pair<int, int> delta : deltas)
        {
            pair<int, int> newPos = make_pair(pos.first + delta.first, pos.second + delta.second);
            if (isInside(newPos.first, newPos.second))
            {
                adjCnt[newPos.first][newPos.second]++; //we only go through zero cells and 
                                                       //gather information about their neighbours
                if (adjCnt[newPos.first][newPos.second] >= 2 && dist[newPos.first][newPos.second] == -1)
                {
                    q.push({ newPos.first, newPos.second });
                    dist[newPos.first][newPos.second] = dist[pos.first][pos.second] + 1;
                }
            }
        }
    }

    return maxDist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    cout << bfs() << endl;
}