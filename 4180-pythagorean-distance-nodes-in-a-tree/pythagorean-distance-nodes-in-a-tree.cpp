#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(int n,const vector<vector<int>>& g,int start){
        vector<int> d(n,-1);
        queue<int> q;
        d[start]=0;
        q.push(start);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u]){
                if(d[v]==-1){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d;
    }

    int specialNodes(int n,vector<vector<int>>& edges,int x,int y,int z){
        vector<vector<int>> g(n);
        for(auto& e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> dx=bfs(n,g,x);
        vector<int> dy=bfs(n,g,y);
        vector<int> dz=bfs(n,g,z);
        int res=0;
        for(int i=0;i<n;i++){
            long long a=dx[i],b=dy[i],c=dz[i];
            if(a==-1||b==-1||c==-1) continue;
            long long m=max({a,b,c});
            if(a*a+b*b+c*c==2*m*m) res++;
        }
        return res;
    }
};
