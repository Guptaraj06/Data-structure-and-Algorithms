#include<bits/stdc++.h> 
#define foa(i,a,b) for(int i=a;i<b;i++)      
#define fob(i,a,b) for(int i=b;i>=a;i--)          
#define all(x) x.begin(),x.end() 
#define X first 
#define Y second   
#define rect pair<pair<ll,ll>,pair<ll,ll>> 
#define pb push_back   
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;} return false;} 
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;} return false;}  
using namespace std;  
const int mod=998244353;    
typedef long long ll; 
typedef long long int lli;
typedef vector<int> vi;  
typedef vector<long long> vll; 
typedef vector<long long int> vli;           
int rad(ll m,ll n){    
  int res=1; 
  while(n>0){
    if(n&1){res=(1ll*res*m)%mod;} 
    m=(1ll*m*m)%mod; 
    n>>=1; 
  }  
  return res;
}    
void solve(){          

} 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout << fixed << setprecision(9);     
  int t = 1;
  cin >> t;
  while (t--) {
     solve();
  } 
}