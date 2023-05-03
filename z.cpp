#include<bits/stdc++.h>
using namespace std;  
string s; 
vector<int> z_function(){                  //this fuction is used to create longest 
   int n=(int)s.length();       //substring from index i which is prefix
   vector<int> z(n,0); 
   for(int i=1,l=0,r=0;i<n;i++){
       if(i<=r){
           z[i]=min(z[i-l],r-i+1);        
       }  
       while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
           ++z[i];
       }   
       if(i+z[i]-1>r){
           l=i,r=i+z[i]-1;
       }
   }     
   return z;
}
int main(){    
    cin>>s;
    vector<int> p=z_function(); 
    int n=s.length();  
    vector<int> cnt(n+1,0);  // cnt array is used to store all occurence of prefix
    p[0]=n;
    for(int i=0;i<n;i++){    
        cnt[p[i]]++;
    }   
    for(int i=n-1;i>0;i--){
        cnt[i]+=cnt[i+1];
    }  
    vector<pair<int,int>> ans;  
    for(int i=0;i<n;i++){
        if(p[n-1-i]==i+1){
           ans.push_back({i+1,cnt[i+1]});
        }
    }  
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
