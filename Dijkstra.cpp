// g++ Dijkstra.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

#define INF 1e5
class compare
{
  public:
    bool operator()(const pair<int, int> &x, const pair<int, int> &y)
    {
        return x.second > y.second;
    }
};

map<int, int> Dijkstra(map<int, vector<pair<int, int>>> &G, set<int> &V, int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> Q;
    map<int, int> dist;
    map<int, int> prev;

    dist[source] = 0;
    for (auto i : V)
    {
        if (i != source)
        {
            dist[i] = INF;
            prev[i] = INF;
        }
        Q.push(make_pair(i, dist[i]));
    }

    int cnt = 0;
    while (cnt < V.size())
    {
        int u = Q.top().first;
        Q.pop();
        cnt++;

        vector<pair<int, int>> edge = G[u];
        for (auto edge : G[u])
        {
            int v = edge.first;
            int w = edge.second;
            int alt = dist[u] + w;
            if (alt < dist[v])
            {
                dist[v] = alt;
                prev[v] = u;
                Q.push(make_pair(v, alt));
            }
        }
    }

    return dist;
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

    cout << "Dijkstra...." << endl;
    map<int, int> d = Dijkstra(G, V, 1);

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