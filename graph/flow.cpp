#include<bits/stdc++.h>
using namespace std;      
const int N=300;   
int mp[N][N],flow[N][N],pre[N],minflow,s,t,ans=0;  
int bfs(){  
    int cur,u,v;     
    memset(flow,0,sizeof(flow)); 
    while(1){
        memset(pre,-1,sizeof(pre)); 
        minflow=1e9; 
        queue<int> q; 
        q.push(s);     
        while(!q.empty()){
           cur=q.front(); 
           q.pop(); 
           if(cur==t)break; 
           for(v=s;v<=t;v++){
               if(pre[v]<0 && mp[cur][v]-flow[cur][v]>0){
                   pre[v]=cur;                       
                   minflow=min(minflow,mp[cur][v]-flow[cur][v]); 
                   q.push(v); 
               }
           }
        }     
        if(pre[t]==-1){break;} 
        for(v=t;v!=s;v=pre[v]){
            u=pre[v]; 
            flow[u][v]+=minflow; 
            flow[v][u]-=minflow; 
        }       
        ans+=minflow;
    }   
    return ans;
}
int main(){      
    int n,m,sum=0,sum2=0; 
    cin>>n>>m;    
    int a[N],b[N];
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        sum+=a[i]; 
    }    
    for(int i=1;i<=n;i++){
        cin>>b[i];  
        sum2+=b[i]; 
    }    
    s=0,t=2*n+1; 
    for(int i=1;i<=n;i++){
        mp[s][i]=a[i]; 
        mp[i+n][t]=b[i]; 
        mp[i][i+n]=1e8;
    }
    for(int i=1,u,v;i<=m;i++){
       cin>>u>>v; 
       mp[u][v+n]=mp[v][u+n]=1e8;  
    }     
    if(sum!=sum2){
        cout<<"NO\n"; 
        return 0;
    }      
    if(bfs() != sum){
        cout<<"NO\n";  
        return 0;   
    } 
    else{
        cout<<"YES\n"; 
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<=n+n;j++){
                cout<<flow[i][j]<<" "; 
            } 
            cout<<"\n"; 
        }
    }
    return 0;
} 