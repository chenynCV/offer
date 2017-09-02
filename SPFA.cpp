#include <bits/stdc++.h>
using namespace std;

#define INF 1e5

map<int, int> SPFA(map<int, vector<pair<int, int>>> &G, set<int> &V)
{
    unordered_set<int> q;
    map<int, int> d;

    for (auto i : V)
    {
        d[i] = INF;
    }

    d[1] = 0;
    q.insert(1);
    while (!q.empty())
    {
        int u = *q.begin();
        q.erase(q.begin());
        cout << u << endl;

        vector<pair<int, int>> edge = G[u];
        for (auto edge : G[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;

                if (q.count(v) == 0)
                    q.insert(v);
            }
        }
    }

    return d;
}

int main()
{
    int numCities, numRoads, numDeliveries;
    cin >> numCities;
    cin >> numRoads;

    vector<vector<int>> travelTime(numRoads, vector<int>(3, 0));
    for (int i = 0; i < numRoads; i++)
    {
        cin >> travelTime[i][0] >> travelTime[i][1] >> travelTime[i][2];
    }

    cin >> numDeliveries;
    vector<vector<int>> timeLimit(numDeliveries, vector<int>(2, 0));
    for (int i = 0; i < numDeliveries; i++)
    {
        cin >> timeLimit[i][0] >> timeLimit[i][1];
    }

    map<int, vector<pair<int, int>>> G;
    set<int> V;
    V.insert(1);
    for (int i = 0; i < numRoads; i++)
    {
        V.insert(travelTime[i][0]);
        V.insert(travelTime[i][1]);
        G[travelTime[i][0]].push_back(make_pair(travelTime[i][1], travelTime[i][2]));
        G[travelTime[i][1]].push_back(make_pair(travelTime[i][0], travelTime[i][2]));
    }
    cout << "V:";
    for (auto i : V)
        cout << i << " ";
    cout << endl;

    cout << "SPFA...." << endl;
    map<int, int> d = SPFA(G, V);

    vector<int> restTime(numDeliveries);
    for (int i = 0; i < timeLimit.size(); i++)
    {
        if (2 * d[timeLimit[i][0]] < timeLimit[i][1])
            restTime[i] = timeLimit[i][1] - 2 * d[timeLimit[i][0]];
        else
            restTime[i] = 0;

        cout << timeLimit[i][0] << " " << timeLimit[i][1] << " " << d[timeLimit[i][0]] << " " << restTime[i] << endl;
    }

    return 0;
}