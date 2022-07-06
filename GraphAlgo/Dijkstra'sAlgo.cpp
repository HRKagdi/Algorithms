#include<bits/stdc++.h>
using namespace std;
int minDistance(vector<int>&dist,vector<bool>&vis){
    int minDist=INT_MAX; int ind=-1;
    for(int i=0;i<dist.size();i++){
        if(!vis[i] && minDist>dist[i]){
            minDist=dist[i];
            ind=i;
        }
    }
    return ind;
}
void dijkstra(vector<pair<int,pair<int,int>>> &g,vector<bool> &vis,vector<int> &dis,int n){
        // Dijkstra's ALgo.
    	for(int i=0;i<n;i++){
            int m=minDistance(dis,vis);
            if(m==-1) continue;
            vis[m]=true;
            for(int i=0;i<g.size();i++){
                if(g[i].second.first==m){
                    dis[g[i].second.second]=min(dis[g[i].second.second], dis[m]+g[i].first);
                }
            }
        }
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,e; cin>>n>>e;
        vector<pair<int,pair<int,int>>> g;
        for(int i=1;i<=e;i++){
            int a,b,w; cin>>a>>b>>w;
            g.push_back(make_pair(w,make_pair(a,b)));
            g.push_back(make_pair(w,make_pair(b,a)));

        }
        vector<bool> vis(n,false); vector<int> dis(n,INT_MAX);
    	dis[0]=0;
        dijkstra(g,vis,dis,n);

        for(int i=0;i<n;i++) cout<<i<<" "<<dis[i]<<endl;
    }
    
    return 0;
}
