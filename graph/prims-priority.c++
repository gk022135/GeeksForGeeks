#include<iostream>
#include<bits/stdc++.h>

#include<vector>
#include<queue>

using namespace std;

class Prims{
    public:
        int prims_mst(vector<vector<int>> edges, int V) {
            vector<bool> visited(V, false);
            int mstCost = 0;
            vector<vector<int>> mstEdge;

            // Adjacency list: node -> [(neighbor, weight)]
            vector<vector<pair<int, int>>> adjList(V);
            for (auto i : edges) {
                int u = i[0], v = i[1], wt = i[2];
                adjList[u].push_back({v, wt});
                // adjList[v].push_back({u, wt}); // If undirected
            }
        
            // Min-heap: (weight, from, to)
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
            pq.push({0, -1, 0}); // weight, from, to
        
            while (!pq.empty()) {
                auto [wt, from, u] = pq.top();
                pq.pop();
            
                if (visited[u]) continue;
                visited[u] = true;
            
                mstCost += wt;
                if (from != -1)
                    mstEdge.push_back({from, u, wt});
            
                for (auto [v, w] : adjList[u]) {
                    if (!visited[v]) {
                        pq.push({w, u, v});
                    }
                }
            }
        
            return mstCost;
        }       

};