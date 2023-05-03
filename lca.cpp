#include<bits/stdc++.h>
using namespace std;   
vector<int> g[100005];   
const int N=1e5+5;
int low=ceil(log2(N));   // possible number of ancestor of node defined at a distance of    
int x,y,a,b,k,n;         // 2^something;
int up[100005][20],level[100005];   
void dfs(int u,int p){     
    up[u][0]=p;     
    for(int i=1;up[u][i-1];i++)up[u][i]=up[up[u][i-1]][i-1]; //store jth ancestor at distance 
    for(int v: g[u]){                       // of 2^jth distance
        if(v!=p){
            level[v]=level[u]+1;       
            dfs(v,u);
        }
    }
}      
int lca(int u,int v){
    if(level[u]<level[v])swap(u,v);
    for(int i=19;i>=0;i--){
        if(level[u]-(1<<i)>=level[v]){
             u=up[u][i];            
        }
    }    
    if(u==v)return v;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }    
    return up[u][0];
}    
int dis(int a,int b){
    return level[a]+level[b]-2*level[lca(a,b)];
}
int main(){
    cin>>n;  
    int u,v;
    for(int i=0;i<n-1;i++){cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}     
    dfs(1,0); 
    cin>>a>>b;
    dis(a,b);
    return 0;
}