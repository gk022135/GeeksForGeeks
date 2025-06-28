#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;



class Disjoint {
    vector<int> parent, rank;

public:
    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void u_v_union(int u, int v){
            int parent_u = find(u);
            int parent_v = find(v);

            if(parent[parent_u] > rank[parent_v]) parent[parent_v] = parent_u;
            if(parent[parent_v] > rank[parent_u]) parent[parent_u] = parent_v;
            else{
                parent[parent_v] = parent_u;
                rank[parent_u]++;
            }
        }
};

class Kruskal {
public:
    int minimumSpanningTree(vector<vector<int>> edges, int Nodes) {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        vector<vector<int>> mstEdges;

        Disjoint Obj(Nodes);
        int mstCost = 0;

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if(Obj.find(u) != Obj.find(v)){
                mstCost += wt;
                mstEdges.push_back({u,v,wt});
                Obj.u_v_union(u,v);
            }
        }
        return mstCost;
    }
};
