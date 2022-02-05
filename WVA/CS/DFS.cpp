#include <bits/stdc++.h>

using namespace std;

bool notin(int n, vector<int> v){
    for (auto&entry: v){
        if (entry==n){return false;}    
    }
    return true;
}

void DFS (map<int, vector<int>> graph, int root){
    vector<int> visited;
    stack<int> stack;
    stack.push(root);
    visited.push_back(root);
    while (stack.size()>0){
        int current = stack.top();
        cout<<current<<" ";
        stack.pop();
        vector<int> neighbors = graph[current];
        for (auto&neighbor: neighbors){
            if (notin(neighbor, visited)){
                visited.push_back(neighbor);
                stack.push(neighbor);
            }
        }
    }
}

int main(){
    int root = 1;
    map<int, vector<int>> graph = {{1,{2,3,4}}, {2,{1,5,3}}, {3, {2,5,6}}, {4, {7,8}}, {5, {2,3}}, {6, {7,9,10}}, {7, {4,6,10}}, {8, {4,9}}, {9, {6,8}}, {10, {6,7}}};
    DFS (graph, root);
}
