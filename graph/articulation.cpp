#include<bits/stdc++.h> 
using namespace std; 
vector<int> adj[100005]; 
vector<int> vis,tin,low;            
set<int> ans; 
int timer;   
void dfs(int u,int p=-1){
    int child=0; 
    vis[u]=1; 
    tin[u]=low[u]=timer++; 
    for(int v:adj[u]){
        if(v==p)continue;
        if(vis[v]==-1){
            dfs(v,u); 
            low[u]=min(low[u],low[v]);     
            if(low[v]>=tin[u] && p!=-1){
                ans.insert(u); 
            }
            ++child;      
        }        
        else{
            low[u]=min(low[v],low[u]); 
        }        
    }         
    if(p==-1 && child>1){
        ans.insert(u); 
    }
}
int main(){      
    int n; 
    timer=0; 
    vis.assign(n,-1); 
    tin.assign(n,-1); 
    low.assign(n,-1);         
    for(;;){
        int u,v; 
        cin>>u>>v; 
        --u,--v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }     
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            dfs(i); 
        }
    }           
    return 0; 
}