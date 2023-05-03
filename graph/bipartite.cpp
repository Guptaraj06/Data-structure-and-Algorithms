#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
    int n;  
    vector<int> adj[n]; 
    vector<int> vis(n,-1); 
    bool ok=true;  
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            queue<int> q;  
            q.push(i);     
            vis[i]=0; 
            while(!q.empty()){
                int v=q.front(); 
                q.pop();  
                for(int u:adj[v]){
                    if(vis[u]==-1){
                        vis[u]=vis[v]^1; 
                        q.push(u);
                    } 
                    else{
                       ok&=(vis[u]!=vis[v]); 
                    }
                }
            }
        }
    } 
    cout<<ok<<"\n"; 
    return 0; 
}