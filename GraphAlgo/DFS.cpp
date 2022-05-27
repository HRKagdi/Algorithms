class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	int dfs(int ind,int i,vector<int>adj[],vector<int>&order,vector<bool>&vis){
	    vis[i]=true;
	    for(auto x:adj[i]){
	        if(!vis[x]){
	            ind=dfs(ind,x,adj,order,vis);
	        }
	    }
	    order[ind]=i;
	    return ind-1;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> order(V,0); vector<bool> vis(V,false);
	    int ind=V-1;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(ind,i,adj,order,vis);
	        }
	    }
	  //  for(int i=0;i<V;i++) cout<<order[i]<<" ";
	    return order;
	}
};
