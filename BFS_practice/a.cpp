#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(N);
  rep(i,M){
    int a,b;
    cin>>a>>b;
    a--;b--;
    A[a].emplace_back(b);
    A[b].emplace_back(a);
  }
  rep(i,N) sort(A[i].begin(),A[i].end());
  queue<int> q;
  vector<bool> used(N);
  vector<int> ans(N,-1);
  q.push(0);
  int cnt = 1;
  used[0] = true;
  while(!q.empty()){
    int a = q.front();
    ans[a] = cnt++;
    for(int x:A[a]){
      if(used[x]) continue;
      q.push(x);
      used[x] = true;
    }
    q.pop();
  }
  for(int x:ans) cout<<x<<"\n";
}
