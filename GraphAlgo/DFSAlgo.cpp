class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void dfs(vector<int> adj[], int V, vector<bool>& vis){
        vis[V]=true;
        ans.push_back(V);
        for(auto it:adj[V]){
            if(!vis[it]) dfs(adj,it,vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(adj[0].size(),false);
        dfs(adj,V,visited);
        return ans;
    }
};
