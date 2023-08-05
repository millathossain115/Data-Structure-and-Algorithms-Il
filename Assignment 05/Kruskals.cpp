#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int parent[100];
int rnk[100];
vector<pair<int, pair<int, int>>> all_edge;

void make_set(int node_number)
{
    parent[node_number] = node_number;
    rnk[node_number] = 0;
}

int find_set(int node_number)
{
    if (node_number == parent[node_number])
    {
        return node_number;
    }
    else
    {

        int myparent = parent[node_number];
        int neta = find_set(myparent);
        parent[myparent] = neta;

        return neta;
    }
}

void union_set(int node1, int node2)
{
    int neta1 = find_set(node1);
    int neta2 = find_set(node2);

    if (rnk[neta1] > rnk[neta2])
    {

        parent[neta2] = neta1;
    }
    else if (rnk[neta1] < rnk[neta2])
    {

        parent[neta1] = neta2;
    }
    else
    {

        parent[neta2] = neta1;
        rnk[neta1] = rnk[neta1] + 1;
    }
}
bool myfun()
{

    // if(all_edge.first>all_edge.second){
    //     return false;
    // }else{
    //     return true;
    // }
}

void kruskals(int leftnode, int rightnode)
{

    vector<pair<int, int>> A;

    if (find_set(leftnode) != find_set(rightnode))
    {
        union_set(leftnode, rightnode);
        A.push_back({leftnode, rightnode});
    }

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i].first << " " << A[i].second << endl;
    }
}

int main()
{
    ifstream file_obj;
    file_obj.open("a.txt", ios::in);

    if (file_obj.is_open())
    {
        int n, e, result = 0;
        file_obj >> n >> e;

        for (int node = 1; node <= n; node++)
        {
            make_set(node);
        }

        for (int edge = 0; edge < e; edge++)
        {
            int leftnode, rightnode, weight;

            file_obj >> leftnode >> rightnode >> weight;

            pair<int, int> innerpair(leftnode, rightnode);
            pair<int, pair<int, int>> finalpair(weight, innerpair);
        }

        sort(all_edge.begin(), all_edge.end());

        for (int edge = 0; edge < e; edge++)
        {

            pair<int, pair<int, int>> curedge_weight = all_edge[edge];
            pair<int, int> curedge = curedge_weight.second;

            int leftnode = curedge.first;
            int rightnode = curedge.second;

            kruskals(leftnode, rightnode);

            if (find_set(leftnode) != find_set(rightnode))
            {
                result += curedge_weight.first;
            }
        }

        cout << "Minimum weight of MST" << endl;
        cout << result << endl;
    }
    else
    {
        cout << "Couldn't open the file" << endl;
    }

    return 0;
}