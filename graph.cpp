#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    unsigned int vertex;
    double weight;
};

class Graph {
    vector<vector<Edge> > adj_list;

    void dfs(unsigned int, vector<bool> &, bool);
    void bfs(unsigned int, vector<bool> &, bool);

public:
    Graph(unsigned int size) {
        adj_list.resize(size);
    }
    void dfs(unsigned int);
    void bfs(unsigned int);
    void add_edge(unsigned int, unsigned int, double);
};

void Graph::add_edge(unsigned int u, unsigned int v, double w) {
    Edge edge;

    edge.vertex = v;
    edge.weight = w;
    adj_list[u].push_back(edge);
}

void Graph::dfs(unsigned int v, vector<bool> &visited, bool print=false) {
    visited[v] = true;

    if (print) {
        cout << v + 1 << endl;
    }

    for (auto to : adj_list[v]) {
        unsigned int u = to.vertex;
        if (!visited[u]) {
            dfs(u, visited);
        }
    }
}

void Graph::dfs(unsigned int v) {
    vector<bool> visited(adj_list.size(), false);

    dfs(v, visited);
}

void Graph::bfs(unsigned int v, vector<bool> &visited, bool print=false) {
    if (visited[v]) {
        return;
    }

    queue<unsigned int> myQueue;
    myQueue.push(v);
    visited[v] = true;

    if (print) {
        cout << v + 1 << endl;
    }

    while (!myQueue.empty()) {
        unsigned int node = myQueue.front();
        for (auto to : adj_list[node]) {
            unsigned int u = to.vertex;
            if (!visited[u]) {
                visited[u] = true;

                if (print) {
                    cout << u + 1 << endl;
                }

                myQueue.push(u);
            }

        }
        myQueue.pop();
    }
}

void Graph::bfs(unsigned int v) {
    vector<bool> visited(adj_list.size(), false);

    bfs(v, visited);
}

int main(int argc, char **argv) {
    unsigned int n, m;
    unsigned int u, v;
    double w;

    cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph.add_edge(u - 1, v - 1, w);
    }

    graph.bfs(0);
    return 0;
}
