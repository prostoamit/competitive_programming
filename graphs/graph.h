#include <vector>
using namespace std;

class Graph {
public:

    int nodes_count;

    vector<bool> visited; 
    vector<int> queue;
    vector<int> dist;

    int L, R;

    Graph(int nodes_count);

    void queuePush(int x);
    int queuePop();
    int queueSize();

    static vector<vector<int>> form_matrix(int nodes_count, int edges_count, bool directed = false, bool weighted = false);
    static vector<vector<int>> form_adjacency_list(int nodes_count, int edges_count, bool directed = false);

    void dfs(vector<vector<int>> graph, int v);
    void bfs(vector<vector<int>> graph, int v);

    static void print_matrix(vector<vector<int>> matrix);

    static void print_adjacency_list(vector<vector<int>> adjacency_list);


};
