//https://classroom.codingninjas.com/app/classroom/me/8017/content/121835/offering/1424052/problem/7990



#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
    	int n,m; cin>>n>>m;
        int src,des; cin>>src>>des;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=1;i<=m;i++){
            int a,b,w; cin>>a>>b>>w;
            edges.push_back({w,{a,b}});
        }
        
        vector<int>dist(n+1,1e9);
        dist[src]=0;
        
        for(int i=1;i<=n-1;i++){
            for(auto it:edges){
                if(dist[it.second.first]+it.first<dist[it.second.second]){
                    dist[it.second.second]=dist[it.second.first]+it.first;
                }
            }
        }
        bool b=true;
        for(auto it:edges){
            if(dist[it.second.first]+it.first<dist[it.second.second]){
                	b=false;  break;
                    dist[it.second.second]=dist[it.second.first]+it.first;
                }
        }
        if(!b) cout<<1000000000<<endl;
        else cout<<dist[des]<<endl;
    }
    return 0;
}
