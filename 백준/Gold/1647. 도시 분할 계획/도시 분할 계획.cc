#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[MAX];

int My_Find(int a)
{
    if (a == p[a])
    {
        return a;
    }
    return p[a] = My_Find(p[a]);
}

void My_Union(int a, int b)
{
    int pa = My_Find(a);
    int pb = My_Find(b);

    if (pa == pb)
    {
        return;
    }

    if (pa > pb)
    {
        p[pa] = pb;
    }
    else
    {
        p[pb] = pa;
    }
}

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first < b.first;
}

int main()
{
    FastIO();

    vector<pair<int, pair<int, int>>> v;
    vector<int> rel;
    int n, m;
    int answer = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].second.first, b = v[i].second.second;

        int pa = My_Find(a);
        int pb = My_Find(b);
        if (pa != pb)
        {
            My_Union(a, b);
            rel.push_back(v[i].first);
        }
    }

    for (int i = 0; i < rel.size() - 1; i++)
    {
        answer += rel[i];
    }

    cout << answer << '\n';

    return 0;
}