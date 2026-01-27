class Solution {
public:
    typedef pair<int,int> P;

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<P>>adj;

        for(auto &edge : edges ){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt}); //reverse vali edge
        }


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n,INT_MAX);

        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(node==n-1){
                return dist[n-1];
            }

            for(auto & p : adj[node]){
                int adjnode=p.first;
                int dst=p.second;

                if(d+ dst<dist[adjnode]){
                    dist[adjnode]=d+dst;
                    pq.push({d+dst,adjnode});
                }
            }


        }
        return -1;

    }
};