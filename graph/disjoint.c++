#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DisjointSet{

    vector<int> parent ,size, rank;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(parent[node] == node )return node;

        return parent[node] = findUParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int uParent = findUParent(u);
        int vParent = findUParent(v);

        if(uParent == vParent)return ;
        if(size[uParent] < size[vParent]){
            parent[uParent] = vParent;
            size[vParent] += size[uParent] ;
        }else{
            parent[vParent] = uParent;
            size[uParent] += size[vParent] ;
        }
    }

    void unionByRank(int u, int v){
        int uParent = findUParent(u);
        int vParent = findUParent(v);

        if(uParent == vParent)return ;
        if(rank[uParent] < rank[vParent]){
            parent[uParent] = vParent;
        }else if(rank[uParent] > rank[vParent]){
            parent[vParent] = uParent;
        }else{
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }

};

int main(){

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    //By SIZE:

    // cout<<"BY Size: \n";
    // if(ds.findUParent(3) == ds.findUParent(7))
    // cout<<"Same\n";
    // else cout<<"Not same\n";

    // ds.unionBySize(3,7);
    // if(ds.findUParent(3) == ds.findUParent(7))
    // cout<<"Same\n";
    // else cout<<"Not same\n";

    //By Rank:
    
    cout<<"BY Rank: \n";
    if(ds.findUParent(3) == ds.findUParent(7))
    cout<<"Same\n";
    else cout<<"Not same\n";

    ds.unionByRank(3,7);
    if(ds.findUParent(3) == ds.findUParent(7))
    cout<<"Same\n";
    else cout<<"Not same\n";

    return 0;
}