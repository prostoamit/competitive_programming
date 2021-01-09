#include <bits/stdc++.h>
using namespace std;

class Graph {
public:

    int nodes_count;

    vector<bool> visited; 
    vector<int> queue;
    vector<int> dist; // keeps distancces from original node to i node

    int L, R;

    Graph(int nodes_count) {

        this->nodes_count = nodes_count;

        visited.resize(nodes_count, false);

        queue.resize(nodes_count);
        dist.resize(nodes_count);

        L = 0, R = 0;
    }

    // working with BFS queues

    void queuePush(int x) {queue[R++] = x;} // add to the queue 
                                            // R++ - the next element
                                            // queue size increases by R++

    int queuePop() {return queue[L++];} // extract element from the start of the queue
                                        // queue size decreases by L++

    int queueSize() {return (R - L);} // returns queue size

    // keping graphs

    /* inputs connected nodes and edges weight forming an adjacency matrix */
    vector<vector<int>> form_matrix(int nodes_count, int edges_count, bool directed = false, bool weighted = false) {
        vector<vector<int>> matrix(nodes_count, vector<int>(nodes_count));

        for(int i = 0; i < edges_count; i++) {
            int n1, n2, weigth = 1;

            cin >> n1 >> n2; if(weighted) cin >> weigth; // for an unweighted graph

            matrix[n1-1][n2-1] = weigth;
            if(!directed) matrix[n2-1][n1-1] = weigth; // for an undirected graph
        }

        return matrix;

    }

    /*              ONLY FOR UNWEIGHTED GRAPHS          */
    /* inputs connected nodes forming an adjacence list */
    vector<vector<int>> form_adjacency_list(int nodes_count, int edges_count, bool directed = false) {
        vector<vector<int>> adjacency_list(nodes_count, vector<int>(0));
        
        for(int i = 0; i < edges_count; i++) {
            int n1, n2; cin >> n1 >> n2;

            adjacency_list[n1-1].push_back(n2-1);
            if(!directed) adjacency_list[n2-1].push_back(n1-1);
        }

        return adjacency_list;
    }

    // graph algorithms

    /*   DFS   */
    void dfs(vector<vector<int>> graph, int v) {
        // marking node
        visited[v] = true; 

        // for each unvisited node, connected to v
        for(int u : graph[v]) {
            if(!visited[u]) {

                // checking node u
                dfs(graph, u);
            }
        }
    }


    /*   BFS   */
    void bfs(vector<vector<int>> graph, int v) {
        // adding starting node to the queue
        queuePush(v);

        // marking node
        visited[v] = true;

        // distance from v to v = 0
        dist[v] = 0;

        // while there is something in the queue
        while(queueSize() > 0) {

            // x - next node
            // L increases 
            int x = queuePop();

            // checking all the edges from the x node to i nodes, that are not visited
            for(int i : graph[x]) {
                if(!visited[i]) {
                    // adding node i to the queue
                    queuePush(i);

                    visited[i] = true;

                    // distance from v to i
                    dist[i] = dist[x] + 1;
                }
            }
        }

    }

    // printing interpritations

    void print_matrix(vector<vector<int>> matrix) {
        for(auto i : matrix) {
            for(int j : i) {
                cout << j << ' ';
            }
            cout << '\n';
        }
    }

    void print_adjacency_list(vector<vector<int>> adjacency_list) {
        for(int i = 0; i < adjacency_list.size(); i++) {
            cout << i+1 << ": ";
            for(int j = 0; j < adjacency_list[i].size(); j++) {
                cout << adjacency_list[i][j] + 1 << ' ';
            }
            cout << '\n';
        }
    }


};
