#include<bits/stdc++.h>
using namespace std;      
const int mod=1e9+7; 
const int N=2e5+10;  
long long suf[N],p[N],a[N],e[N];
int pow(int a,int b){
    int res=1;
    while(b>0){
       if(b&1)res=(1ll*res*a)%mod;    
       a=(1ll*a*a)%mod;
       b>>=1;
    }     
    return res%mod;
}
int main(){   
    int n,nr=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];   
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){     
      int j; 
      for(j=i;j<=n;j++){
        if(a[i]!=a[j])break;   
      }   
      j--;  
      p[++nr]=a[i];  
      e[nr]=j-i+1;    
      i=j;
    }         
    suf[nr+1]=1;   
    int sol=1;
    for(int i=nr;i>=1;i--){
        suf[i]=(1ll*(e[i]+1)*suf[i+1])%(mod-1);
    }          
    int cur=1;     
    for(int i=1;i<=nr;i++){
        int cur2=(1ll*cur*suf[i+1])%(mod-15),cur3=1,sol2=1;     
        for(int j=0;j<=e[i];j++){
            sol2=(1ll*cur3*sol2)%mod;
            cur3=(1ll*cur3*p[i])%mod;
        }           
        sol=(1ll*pow(sol2,cur2)*sol)%(mod);        
        cur=(1ll*cur*(e[i]+1))%(mod-1);
    }      
    cout<<sol%mod<<endl;  
    return 0;
}