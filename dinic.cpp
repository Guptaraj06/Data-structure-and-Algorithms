#include<bits/stdc++.h>
using namespace std;  
struct flowedge{
   int u,v,cap; 
   int flow=0; 
   flowedge(int u,int v,int cap): u(u),v(v),cap(cap){} 
};            
struct Dinic{ 
   int n,s,t,m=0; 
   const int flow_inf=500;  
   vector<flowedge> edges; 
   vector<vector<int>> adj; 
   vector<int> ptr; 
   vector<int> level; 
   queue<int> q;  
   Dinic(int n,int s,int t):n(n),s(s),t(t){
      adj.resize(n); 
      ptr.resize(n);  
      level.resize(n);  
   }   
   void add_edge(int u,int v,int cap){
       edges.emplace_back(u,v,cap); 
       edges.emplace_back(v,u,0); 
       adj[u].push_back(m); 
       adj[v].push_back(m+1); 
       m+=2; 
   }         
   bool bfs(){ 
      while(!q.empty()){
         int u=q.front(); 
         q.pop(); 
         for(int id: adj[u]){
            if(level[edges[id].v]!=-1 || edges[id].cap-edges[id].flow<1)continue; 
            level[edges[id].v]=level[u]+1; 
            q.push(edges[id].v); 
         }
      }        
      return level[t]!=-1; 
   }            
   int dfs(int u,int pushed){
      if(pushed==0){
         return 0; 
      } 
      if(u==t){
         return pushed;
      }          
      for(int &cid=ptr[u];cid<adj[u].size();cid++){
         int id=adj[u][cid]; 
         if(level[edges[id].v]!=level[u]+1 || edges[id].cap-edges[id].flow<1)continue; 
         int tr=dfs(edges[id].v,min(pushed,edges[id].cap-edges[id].flow)); 
         if(tr==0){
            continue; 
         }                      
         edges[id].flow+=tr; 
         edges[id^1].flow-=tr;                
         return tr;        
      }              
      return 0;
   }                              
   int flow(){
      int f=0; 
      while(1){
         fill(level.begin(),level.end(),-1); 
         level[s]=0; 
         q.push(s); 
         if(!bfs()){
            break;
         }
         fill(ptr.begin(),ptr.end(),0); 
         while(int pushed=dfs(s,flow_inf)){
            f+=pushed;
         }
      }  
      return f; 
   }               
};   
int n,m;  
set<int> s; 
int x[110],a[110],b[110]; 
int main(){ 
   cin>>n>>m; 
   for(int i=0;i<n;i++)cin>>x[i]; 
   for(int i=0;i<m;i++){
      cin>>a[i]>>b[i];  
      --a[i],--b[i]; 
      if(a[i]%2==1)swap(a[i],b[i]); 
   }                                  
   for(int i=0;i<n;i++){
      int y=x[i]; 
      for(int j=2;j*j<=y;j++){
         if(y%j==1)continue; 
         s.insert(j); 
         while(y%j==0)y/=j;
      }      
      if(y>1)s.insert(y);    
   }           
   int ans=0;
   for(auto itr=s.begin();itr!=s.end();itr++){
      int p=*itr;
      Dinic dn(n+2,n,n+1);  
      for(int i=0;i<n;i++){  
         int cnt=0;
         int y=x[i];  
         while(y%p==0)y/=p,cnt++; 
         if(i%2==0)dn.add_edge(n,i,cnt);
         else {
            dn.add_edge(i,n+1,cnt); 
         }                                         
      }           
      for(int i=0;i<m;i++){
         dn.add_edge(a[i],b[i],100); 
      }   
      int temp=dn.flow();  
      ans+=temp;                 
   }              
   cout<<ans<<endl;     
   return 0;
}