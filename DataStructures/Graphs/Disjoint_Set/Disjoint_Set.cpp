#include<iostream>
#include<vector>

using namespace std;

class DisJointSet{
    vector<int> rank, parent,size;
public:
    DisJointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<n+1; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    void printVector(vector<int>& v){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }

    void findUnionByRank(int u, int v){ //union is operation of joining
        //finding ultimate parent of both numbers
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);

        if(ulp_u==ulp_v){ //if both have same ultimate parent means they are already joined
            return;
        }

        //below we are joinging smaller to larger beacuse it will not make any change in rank of larger
        if(rank[ulp_u]>rank[ulp_v]){ 
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }else{  //both have same reank means it gonna increse the rank of the node to which we are joining another node here we are joining u to v so rank of v gonna increase
            parent[ulp_v]=ulp_u;  
            rank[ulp_u]++;
        }
        cout<<"Rank vector   : ";
        printVector(rank);
        cout<<"Parent vector : ";
        printVector(parent);
    }


    void findUnionBySize(int u, int v){ //union is operation of joining
        //finding ultimate parent of both numbers
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);

        if(ulp_u==ulp_v){ //if both have same ultimate parent means they are already joined
            return;
        }

        if (size[ulp_v] > size[ulp_u]) { 
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        cout << "Size vector   : ";
        printVector(size);
        cout << "Parent vector : ";
        printVector(parent);
    }

};


int main(){
    DisJointSet ds(7);
    ds.findUnionBySize(1,2);
    ds.findUnionBySize(2,3);
    ds.findUnionBySize(4,5);
    ds.findUnionBySize(6,7);
    ds.findUnionBySize(5,6);
    ds.findUnionBySize(3,7);
    cout<<ds.findUltimateParent(1)<<endl;
    cout<<ds.findUltimateParent(2)<<endl;
    cout<<ds.findUltimateParent(3)<<endl;

    
    return 0;
}