#include<bits/stdc++.h>   
using namespace std; 
vector<int> g[100005]; 
vector<pair<int,int>> ans; 
vector<int>tin,low,vis; 
int timer=0;       
void dfs(int u,int p){
   vis[u]=1; 
   tin[u]=low[u]=timer++; 
   for(int v:g[u]){
       if(v==p)continue; 
       if(vis[v]){
           low[u]=min(low[u],low[v]); 
       }       
       else{
           dfs(v,u); 
           low[u]=min(low[u],low[v]); 
           if(low[v]>tin[u]){
               ans.push_back({u,v}); 
           }
       }
   }
}
int main(){  
    int n;   
    tin.assign(n,-1); 
    low.assign(n,-1); 
    vis.assign(n,-1); 
    for(;;){
        int u,v;
        cin>>u>>v; 
        --u,--v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    }           
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            dfs(i,-1); 
        }
    }    
    return 0;            
}