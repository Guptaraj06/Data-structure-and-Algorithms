#include<bits/stdc++.h>  
#define ll long long   
const int inf=1e9; 
using namespace std;    
vector<int> dis,par;  
struct node{
    int u,v,w; 
}; 
int main(){ 
    int n; 
    dis.assign(n,1e9); 
    par.assign(n,-1);          
    node edge[n];  
    for(int i=0;;){
        cin>>edge[i].u>>edge[i].v>>edge[i].w; 
        --edge[i].u,--edge[i].v;  
    }                 
    dis[0]=0; 
    int x; 
    for(int v=0;v<n;v++){ 
        x=-1;  
        for(auto i:edge){
           if(dis[i.u]<inf){
               if(dis[i.v]>dis[i.u]+i.w){
                   dis[i.v]=dis[i.u]+i.w; 
                   par[i.v]=i.u;  
                   x=i.v; 
               }
           }
        }
    }     
    if(x==-1){
       cout<<"No negative cycle found\n"; 
    }                
    else{
        int y=x; 
        for(int i=0;i<n;i++){
            y=par[y]; 
        }      
        vector<int> path; 
        for(int cur=y;;cur=par[cur]){
            path.push_back(cur); 
            if(cur==y && path.size()>1){
                break; 
            }
        }      
        reverse(path.begin(),path.end()); 
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" "; 
        } 
    }

    return 0;
}