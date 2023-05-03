#include<bits/stdc++.h>  
#define ll long long 
#define pll pair<ll,ll>  
using namespace std;  
vector<pair<ll,ll>> g[100005];  
priority_queue<pll,vector<pll>,greater<pll>> q; 
vector<ll> dis,p; 
void f(int i){
    if(i!=0)f(p[i]); 
    cout<<i<<" "; 
}     
int main(){ 
    int n; 
    for(;;){
        int u,v,w; 
        --u,--v; 
        g[u].push_back({v,w}); 
        g[v].push_back({u,w}); 
    }
    dis.resize(n,1e18); 
    p.resize(n,-1); 
    p[0]=0; 
    dis[0]=0; 
    q.push({0,0}); 
    while(!q.empty()){
       int k=q.top().second; 
       q.pop(); 
       for(auto i:g[k]){
          ll v=i.first; 
          ll w=i.second; 
          if(dis[v]>dis[k]+w){
              dis[v]=dis[k]+w; 
              p[v]=k; 
              q.push({dis[v],v}); 
          }
       }
    }                     
    return 0;
}