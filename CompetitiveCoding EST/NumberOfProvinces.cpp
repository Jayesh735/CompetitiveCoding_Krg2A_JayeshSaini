#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define forloop(i,a,b) for (int i = a; i <= b; i++)

void dfs(int i,vector<vector<int>> &adj,vector<bool> &visited){
    visited[i] = true;
    for(int j : adj[i]){
        if(!visited[j]){
            dfs(j,adj,visited);
        }
    }
}

int numOfProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1 && i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<bool> visited(n,false);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i,adj,visited);
            count++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << numOfProvinces(isConnected) << endl;
    return 0;
}