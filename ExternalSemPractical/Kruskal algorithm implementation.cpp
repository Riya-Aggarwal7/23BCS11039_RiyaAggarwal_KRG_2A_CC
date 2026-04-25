#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a, int b) {
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;

        if(rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

int main() {
    vector<pair<int,int>> points = {
        {0,0},{2,2},{3,10},{5,2},{7,0}
    };

    int n = points.size();
    vector<Edge> edges;

    // Create all edges
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int cost = abs(points[i].first - points[j].first) +
                       abs(points[i].second - points[j].second);

            edges.push_back({i,j,cost});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);
    int mstCost = 0;

    for(auto e : edges) {
        if(dsu.unite(e.u, e.v)) {
            mstCost += e.wt;
            cout << e.u << " - " << e.v
                 << " : " << e.wt << endl;
        }
    }

    cout << "Total Cost = " << mstCost << endl;
}
