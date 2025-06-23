
class DisjointSet{

    vector<int> parent ,size;

    public:
    DisjointSet(int n){
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

};
