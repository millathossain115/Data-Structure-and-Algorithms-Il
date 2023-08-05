#include <iostream>
#include <fstream>
#include <vector>

#define INF 999999
#define NIL -1

using namespace std;

int dist[100];
int parent[100];

void print_shortest_path(int src, int dest){
    if(src==dest){
        cout<<"----->"<<src;
    }
    else{
        print_shortest_path(src, parent[dest]);
        cout<<"----->"<<dest;
    }
}

bool Bellman_ford(vector< pair<int,int> > all_edge, vector<double> weight, int nodes, int startnode){
    ///initialize the graph
    for(int node=1;node<=nodes;node++){
        dist[node]=INF;
        parent[node]=NIL;
    }
    dist[startnode]=0;

    ///performing bellman ford iterations
    for(int loop=1;loop<=nodes-1;loop++){

        ///accessing all edge
        for(int ind=0;ind<all_edge.size();ind++){
            pair<int,int> current_edge=all_edge[ind];
            double edge_weight = weight[ind];


            int srcnode=current_edge.first;
            int destnode=current_edge.second;

            if( dist[destnode] > dist[srcnode]+edge_weight ){
                dist[destnode]=dist[srcnode]+edge_weight;
                parent[destnode]=srcnode;
            }
        }
    }

    ///negative cycle check
    ///accessing all edge
    for(int ind=0;ind<all_edge.size();ind++){
        pair<int,int> current_edge=all_edge[ind];
        double edge_weight = weight[ind];


        int srcnode=current_edge.first;
        int destnode=current_edge.second;

        if( dist[destnode] > dist[srcnode]+edge_weight ){
            ///cycle exists
            return false;
        }
    }

    return true;
}


int main()
{
    vector< pair<int,int> > all_edge; ///vector<>( (1,3), (2,5), (4,7)  )
    vector<double> weight;            ///vector<>(   5  ,  7            )

    ifstream file_obj;
    file_obj.open("graph.txt");

    if(file_obj.is_open()){
        int nodes, edges;

        file_obj>>nodes>>edges;

        for(int i=0;i<edges;i++){
            int s,d;
            double wt;

            file_obj>>s>>d>>wt;

            pair<int,int> p(s,d);

            all_edge.push_back(p);
            weight.push_back(wt);
        }


        ///all_edge vector contains all edges
        ///weight   vector contains all corresponding weights
        Bellman_ford(all_edge, weight, nodes, 1);

        print_shortest_path(1, 5);

    }
    else{
        cout<<"Couldn't open the file"<<endl;
    }

    return 0;
}
