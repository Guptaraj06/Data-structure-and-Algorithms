#include<bits/stdc++.h> 
using namespace std;      
vector<int> g1[100005],g2[100005]; 
vector<int> vis,comp,order; 
void dfs1(int u){
    vis[u]=1; 
    for(int v:g1[u]){
        if(vis[v]==-1){
            dfs1(v); 
        }
    }   
    comp.push_back(u); 
}              
void dfs2(int u){
    vis[u]=1; 
    order.push_back(u); 
    for(int v:g2[u]){
        if(vis[v]==-1){
            dfs2(v); 
        }
    }
}
int main(){   
    int n;  
    vis.resize(n,-1); 
    for(;;){ 
        int u,v; 
        cin>>u>>v; 
        --u,--v;  
        g1[u].push_back(v); 
        g2[v].push_back(u);     
    }                
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            dfs1(i);       
        }               
    }          
    vis.assign(n,-1);   
    reverse(comp.begin(),comp.end()); 
    for(int i=0;i<n;i++){
        if(vis[comp[i]]==-1){
            dfs2(comp[i]);    
            for(int j=0;j<order.size();j++){
                cout<<order[j]<<" "; 
            }                     
            order.clear(); 
        }
    }
    return 0; 
}