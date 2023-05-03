#include<bits/stdc++.h>
using namespace std; 
int t,x,y,a,b;
int main(){
    cin>>t; 
    while(t--){
        cin>>x>>y>>a>>b;  
        int ans=0;
        if(a>b)swap(a,b);    
        int l=0,r=x/a; 
        while(l<=r){
            int mid=(l+r)>>1; 
            int cnt=mid; 
            if(a!=b)cnt=min(mid,(x-a*mid)/(b-a)); 
            if(1ll*cnt*a+1ll*(mid-cnt)*b<=y)ans=mid,l=mid+1; 
            else r=mid-1; 
        }       
        cout<<ans<<endl; 
    }   
    return 0;
}