#include<bits/stdc++.h>    
using namespace std;  
int n; 
vector<int> adj[100005]; 
vector<int> ans,vis;     
void dfs(int u){
   vis[u]=1; 
   for(int v:adj[u]){
       if(vis[v]==-1){
           dfs(v); 
       }
   }    
   ans.push_back(u); 
}
int main(){ 
    vis.resize(n,-1); 
    ans.clear(); 
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            dfs(i); 
        }
    }   
    reverse(ans.begin(),ans.end()); 
    return 0; 
}