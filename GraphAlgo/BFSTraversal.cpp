#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<bool>> &adj,int s,vector<bool>&vis){
    queue<int> q; int n=vis.size();
	q.push(s); vis[s]=true;
    while(q.size()>0){
        int ver=q.front(); cout<<ver<<" ";
        q.pop(); 
        for(int i=0;i<n;i++){
            if(i==ver) continue;
            if(adj[ver][i] && !vis[i]){ 
                q.push(i);
                vis[i]=true;
        	}
        }
    }
}
int main(){
    
    int v,e; cin>>v>>e;
    vector<vector<bool>> adj( v, vector<bool> (v, false));
   
    for(int i=1;i<=e;i++){
        int a,b; cin>>a>>b;
        adj[a][b]=true;
        adj[b][a]=true;
    }
    vector<bool> vis(v,false);
    
    for(int i = 0 ; i < v ; i++){
        if( !vis[i] )
    		bfs(adj,i,vis);
    }
    return 0;
}
