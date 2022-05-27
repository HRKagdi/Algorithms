#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> edges;
int parent(vector<int>&par,int w){
    int temp=w;
    while(temp!=par[temp]){
        temp=par[temp];
    }
    return temp;
}
void unionFind(vector<int>&par,int a,int b){
    int t1=parent(par,a);
    int t2=parent(par,b);
    par[t2]=par[t1];
}
int krushkal(int n){
    int tw=0;
    vector<int> par(n);
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=0;i<edges.size();i++){
        if(parent(par,edges[i].second.first)!=parent(par,edges[i].second.second)){
            tw+=edges[i].first;
            unionFind(par,parent(par,edges[i].second.first),parent(par,edges[i].second.second));
        }
    }
    return tw;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,e; cin>>n>>e;
        for(int i=0;i<e;i++){
            int a, b, w; cin>>a>>b>>w;
            edges.push_back(make_pair(w,make_pair(a,b)));
        }
        sort(edges.begin(),edges.end());
        cout<<krushkal(n)<<endl;
        edges.clear();
    }
    return 0;
}
