#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;

class prims_without_pri_que {
public:
    int prism_noPriority(vector<vector<int>> &edges, int Nodes) {
        vector<vector<pair<int, int>>> adjList(Nodes);
        for (auto &i : edges) {
            int u = i[0], v = i[1], wt = i[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt}); // Undirected graph
        }

        vector<int> key(Nodes, INT_MAX);  // Min edge weight to connect each node
        vector<bool> inMST(Nodes, false); // Track nodes in MST
        vector<int> parent(Nodes, -1);    // Store MST edges

        key[0] = 0;

        for (int count = 0; count < Nodes - 1; ++count) {
            // Find the node with the minimum key not in MST
            int u = -1;
            for (int i = 0; i < Nodes; ++i) {
                if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }

            inMST[u] = true;

            for (auto &[v, weight] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        // Sum the MST weights
        int mstCost = 0;
        for (int i = 1; i < Nodes; ++i) {
            if (parent[i] != -1)
                mstCost += key[i];
        }

        return mstCost;
    }
};



//approach 2
class prims_without_pri_que {
public:
    int prism_noPriority(vector<vector<int>> &edges, int Nodes) {
        vector<vector<pair<int, int>>> adjList(Nodes);

        for (auto &i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt}); // undirected
        }

        vector<vector<int>> mstEdges;
        vector<bool> visited(Nodes, false);
        int mstCost = 0;

        queue<int> que;
        visited[0] = true;
        que.push(0);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            // Store all candidate edges from current MST set
            vector<tuple<int, int, int>> candidates; // (wt, u, v)

            for (int i = 0; i < Nodes; ++i) {
                if (visited[i]) {
                    for (auto &[v, wt] : adjList[i]) {
                        if (!visited[v]) {
                            candidates.push_back({wt, i, v});
                        }
                    }
                }
            }

            // Pick the minimum weight edge
            if (!candidates.empty()) {
                auto minEdge = *min_element(candidates.begin(), candidates.end());
                int wt = get<0>(minEdge);
                int from = get<1>(minEdge);
                int to = get<2>(minEdge);

                visited[to] = true;
                que.push(to);

                mstCost += wt;
                mstEdges.push_back({from, to, wt});
            }
        }

        return mstCost;
    }
};


/*
step:1. start from any node and keep going with selecting the minimum weighted neighbour
untill traverse the entire graph


how to select the minimum weighted neighbour ---> add
*/