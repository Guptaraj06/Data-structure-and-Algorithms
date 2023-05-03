#include <bits/stdc++.h>
using namespace std;  
#define segment 1 
#define recur 1 
#define builtin 1 
#define BIT 1
#define dis 1 
#define swap1 1 
#define lift 1 
#define range 1
#define lazy 1
#define dijks 1 
#define rabin 1
#define KMP 1
#define warshall 1 
#define fermat 1
#define trie 1
#ifndef segment 
const int N = 100000;
int n;
int tree[2*N];
void build(int arr[])
{   for (int i=0;i<n;i++)
		tree[n+i]=arr[i];
	for (int i=n-1;i>0;--i)
		tree[i]=tree[i<<1]+tree[i<<1|1];
}
void updateTreeNode(int p, int value)
{   tree[p+n]=value;
	p=p+n;
    for (int i=p;i>1;i>>=1)
		tree[i>>1]=tree[i]+tree[i^1];
}
int query(int l,int r)
{   int res=0;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1)
	{   if(l&1)               //we have asssign left child as 2*i
			res+=tree[l++];
		if(r&1)               // we have  assign right child as 2*i+1
			res+=tree[--r];
	}
	return res;
}
void solve()
{   int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	n = sizeof(a)/sizeof(a[0]);
	build(a);
	cout<<query(1,3)<<endl;    // print the sum in range(1,2) index-based (0 index based structure);
	updateTreeNode(2,1);                   // modify element at 2nd index
	cout<<query(1,3)<<endl;        // print the sum in range(1,2) index-based
	return 0;
} 
#endif
#ifndef recur
 void update(int ind, int val){
		update(1,1,n,ind,val);
	}
	void update(int cur, int tl, int tr, int ind, int val){
		if(tl>ind || tr<ind) return;
		sa[cur] += val;
		if(tl==tr) return;
		int mid = (tl+tr)>>1;
		update(2*cur, tl, mid, ind, val);
		update(2*cur+1, mid+1, tr, ind, val);
	}
	int query(int l, int r){
		return query(1,1,n,l,r);
	}
	int query(int cur, int tl, int tr, int ql, int qr){
		if(tl>qr || tr<ql) return 0;
		if(tl>=ql && tr<=qr) return sa[cur];
		int mid = (tl+tr)>>1;
		int la = query(2*cur, tl, mid, ql, qr), ra = query(2*cur+1, mid+1, tr, ql, qr);
		return la+ra;
	}
#endif
#ifndef builtin 
int tree[MAX];
void constructutil(int arr[],int n) {
    construct(arr,0,n-1,0);
}
void construct(int arr[],int s,int e,int si){
   if(s>e)return;
   if(s==e){
    tree[si]=arr[s];
    return;
   }
   int mid=(s+e)>>1;
   construct(arr,s,mid,si*2+1);   //it is storing sum of element form s to mid at node si*2+1;
   construct(arr,mid+1,e,si*2+2);  //it is storing sum of element form mid+1 to e at node si*2+2;
   tree[si]=tree[si*2+1]+tree[si*2+2];
}    

int query(int n,int q1,int q2){
     return query1(0,n-1,q1,q2,0);
}

int query1(int s,int e,int q1,int q2,int si){
     if(s>e||q1>e||q2<s)return 0;
     if(s>=q1&&e<=q2)return tree[si];
     int mid=s+e>>1;
     return query1(s,mid,q1,q2,si*2+1)+query1(mid+1,e,q1,q2,si*2+2);
}
void update(int n,int ind,int value){
  int diff=value-arr[ind];
  arr[ind]=value;
  update1(0,n-1,ind,diff,0);
}
void update1(int s,int e,int i,int diff,int si){
   if(i<s||i>e)return;
   tree[si]+=diff;
   if(s!=e){
    int mid=(s+e)/2;
    update1(s,mid,i,diff,si*2+1);
    update1(mid+1,e,i,diff,si*2+2);
   }
} 
#endif
#ifndef BIT 
int add(int ind){
   ind+=1;
   ll sum=0;
   while(ind){
     sum+=bit[ind];
     ind-=ind&(-ind);
   }
   return sum;
}
void update(int ind,int val){
    ind+=1;
   while(ind<M){
    bit[ind]+=val;
    ind+=ind&(-ind);      //-x is 2's complement of x;
   }
}
#endif
#ifndef dis
int find1(int parent[],int i){
    if(parent[i]!=i){
        parent[i]=find1(parent,parent[i]);  //making every node between i and root as a child of root
    }
    return parent[i];
}
void union(int rank1[],int x,int y){
  if(rank1[x]>rank1[y])parent[y]=x;
  else if(rank1[x]<rank1[y]) parent[x]=y;
  else{
    parent[y]=x;
    rank1[x]++;
  }
} 
#endif
#ifndef swap1
//To produce no. of minimum swap from 1,2,3,5,7,6,4..... etc.
int cycle(vector<int> p,int n){
 vector<int> used(n);
 int ans=0;
 for(int i=0;i<n;i++)p[i]--;      //we can ignore it by using size of vector(n+1)
 for(int i=0;i<n;i++){             //leveraging above lead to start from i=1;
    if(used[i]==1)continue;
    int j=i;
    while(used[j]==0){
        used[j]=1;
        j=p[j];
    }
    ans++;
  }
  ans;
}

no. of swap=n-ans;  
#endif
#ifndef lift 
int log=ceil(log2(n));
int level[n+1];                   //used to store level of node
int memo[n+1][log+1];            // used to store 2^jth ancestor of node
vector<int> graph[n+1];

void dfs(int u,int p,vector<int>*graph){
   memo[u][0]=p;
   for(int i=1;i<=log;i++)memo[u][i]=memo[memo[u][i-1]][i-1];
   for(int v:g[u]){
    if(v!=p){
        level[v]=level[u]+1;
        dfs(v,u,graph);
     }
   }
}
int lca(int u,int v){
    if(level[u]<level[v])swap(u,v);
    for(int i=log;i>=0;i--){
       if(level[u]-pow(2,i)>=level[v]){   // used to set level of u same as v
            u=memo[u][i];
       }
    }
    if(u==v)return u;
    for(int i=log;i>=0;i--){             // try to find first uncommon node after ancestor as
        if(memo[u][i]!=memo[v][i]){                 // parent of it is lca
            u=memo[u][i];
            v=memo[v][i];
        }
    }
    return memo[u][0];
} 
#endif
#ifndef range 
void update1(int si,int s,int e,int us,int ue,int diff){
   if(s>e||e<us||s>ue)return ;
   if(s==e){tree[si]+=diff;return;}
   int mid=s+e>>1;
   update1(si*2+1,s,mid,us,ue,diff);
   update1(si*2+2,mid+1,e,us,ue,diff);
   tree[si]=tree[si*2+1]+tree[si*2+2];
} 
#endif
#ifndef lazy
void update1(int si,int s,int e,int us,int ue ,int diff){
   if(lazy[si]!=0){                         // also update lazy array in query fuction definition
     tree[si]+=(e-s+1)*lazy[si];           // otherwise it will led to some update operation
     if(s!=e){                             // which will not be add to their value
        lazy[si*2+1]+=lazy[si];
        lazy[si*2+2]+=lazy[si];
     }
     lazy[si]=0;
   }
   if(s>e||e<us||s>ue)return ;
   if(s>=us&&e<=ue){
     tree[si]+=(e-s+1)*diff;
     if(s!=e){
     lazy[si*2+1]+=diff;
     lazy[si*2+2]+=diff;
     }
     return ;
   }
   int mid=s+e>>1;
   update1(si*2+1,s,mid,us,ue,diff);
   update1(si*2+2,mid+1,e,us,ue,diff);
   tree[si]=tree[si*2+1]+tree[si*2+2];
} 
#endif
#ifndef dijks
typedef long long ll;
vector<ll>v[100050];
ll d[100050],p[100050];
priority_queue<ll,vector<ll>,greater<ll>>q;
map<pair<ll,ll>,ll> mp;
ll a,b,w,n,m;
void f(int i){
   if(i!=1)f(p[i]);
   cout<<i<<" ";
}
void solve(){
  cin>>n>>m;
  while(m--){
    cin>>a>>b>>w;
    v[a].push_back(b);
    v[b].push_back(a);
    mp[{a,b}]=w;
    mp[{b,a}]=w;
  }
  for(int i=2;i<=n;i++)d[i]=1e15;
  q.push(1);
  while(q.size()){
    int k=q.top();
    q.pop();
    for(int i=0;i<v[k].size();i++){
       int z=v[k][i];
       w=mp[{k,z}];
       if(d[k]+w<d[z])d[z]=d[k]+w,p[z]=k,q.push(z);
    }
  }
  if(d[n]==1e15)cout<<-1;
  else f(n);
} 
#endif
#ifndef rabin
string txt=" ";pat=" ";
#define D 256             // this algo. is recommended for pattern searching in the context
#define mod 1000000007    // of hashing
void hash1(){
  int n=txt.size();
  int p=pat.size();
  int u=0,v=0,h=1;
  for(int i=0;i<p-1;i++)h=h*D%mod;
  for(int i=0;i<p;i++){
    u=(u*D+txt[i])%mod;
    v=(v*D+pat[i])%mod;
  }
  for(int i=0;i<=n-p;i++){
    if(u==v){
        for(int j=0;i<p;j++){
            if(txt[i+j]!=pat[j])
                break;
        }
        if(j==p)cout<<"pattern found at"<<i<<endl;
    }
    if(i<n-p){
       u=((u-txt[i]*h)*D+txt[i+p])%q;
       if(t<0)t+=q;
    }
  }
} 
#endif
#ifndef KMP 
vector<int> prefix_function(string s){
  int n=int(s.size());         // this function  is used to calculate pi-table or longest prefix suffix
  vector<int> p(n,0);          // in pattern string  and then it will  compare with text
  for(int i=1;i<n;i++){           // string (for that we have to define a function )
    int j=p[i-1];
    while(j>0&&s[i]!=s[j]){
        j=p[j-1];
    }
    if(s[i]==s[j]){
        j++;
    }
    p[i]=j;
  }
  return p;
}
string pi(string x,string y){
    int mx=0,c=0;
    string s=y+"#"+x;
    vector<int>pi(s.length());
    for(int i=1,j=0;i<s.length();i++){
        while(j&&s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
        if(j==(int)y.size())return x;
    }
    return x.substr(0,x.size()-pi.back())+y;
} 
#endif 
#ifndef warshall
for (int k = 0; k < n; ++k) {        // to calculate shortest distance between every pair of
    for (int i = 0; i < n; ++i) {      // graph it is used,prior to others,prepare 2d array
        for (int j = 0; j < n; ++j) { // storing edge weight and infinity denote no edge exist
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // g[i][i]=0;as from i to i
        }                                               // distance=0;
    }
}
#endif  
#ifndef fermat
mod=p;
int kkr(int a,int m){
  int res=1;
  while(m>0){
    if(m&1)res=(res*a)%p;
    a=(a*a)%mod;
    m=(m>>1);
  }
  return res;
} 
#endif
#ifndef trie 
int sze=0;
void add(string s){           //searching is similar to it;code it yourself
  int v=root;                          // by using end of leaf;
  for(int i=0;i<s.length();i++){
    int c=s[i]-'a';
    if(t[v][c]==0)t[v][c]=newt();
    v=t[v][c];
  }
}
int newt(){
return sze++;}
bool search1(string s){
  int v=root;
   for(int i=0;i<s.length();i++){
    int c=s[i]-'a';
    if(!t[v][c])return false;
    v=t[v][c];
   }
   return true;
}    
 //   OR 
struct trie{
    trie *key[26];
    bool ends;  
    trie(){
        fill(key,key+26,nullptr);   
        ends=false;
    }
};   
trie root; 
void insert(string s){
     trie *cursor=&root; 
     for(int i=0;i<s.length();i++){ 
         if(!cursor->key[c-'a']){
            cursor->key[c-'a']=new trie;
         }   
         cursor=cursor->key[c-'a'];
     }  
     cursor->ends=true;
}
#endif 
int main(){
  cout<<"hello";
  return 0; 
}