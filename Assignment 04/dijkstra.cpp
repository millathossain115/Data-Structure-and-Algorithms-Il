#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MX 105
#define INF 1000000000
#define NIL -9999

struct node
{
    int val;
    int cost;
};

vector<node> G[MX];
bool vis[MX];
int dist[MX];

class cmp
{
public:
    bool operator()(node &A, node &B)
    {
        if (A.cost > B.cost)
            return true;
        return false;
    }
};

void dijkstra(int source, int n, int s)
{
    priority_queue<node, vector<node>, cmp> PQ;

    PQ.push({source, 0});

    int parent[n];

    while (!PQ.empty())
    {
        node current = PQ.top();
        PQ.pop();

        int val = current.val;
        int cost = current.cost;

        if (vis[val] == 1)
            continue;

        dist[val] = cost;
        vis[val] = 1;

        for (int i = 0; i < G[val].size(); i++)
        {
            int nxt = G[val][i].val;
            int nxtCost = G[val][i].cost;

            if (vis[nxt] == 0 && dist[nxt] > dist[val] + cost)
            {
                PQ.push({nxt, cost + nxtCost});
                parent[nxt] = val;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        int x = i;
        cout<<"Shortest path from 1 to ";
        while (x != -1)
        {

            if (parent[x] == NIL)
                break;
            cout<<"<--"<<x;
            x = parent[x];
        }

        cout << endl;
    }
}

int main()
{

    int nodes, edges,source;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++)
    {
        
        int n, e, w;
        cin >> n >> e >> w;
        G[n].push_back({e, w});
    }

    cout << "enter source: ";
    cin >> source;

    dijkstra(source, edges, nodes);

    return 0;
}