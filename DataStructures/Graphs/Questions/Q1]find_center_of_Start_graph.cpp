class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       int u1=edges[0][0];
       int v1=edges[0][1];

       int u2=edges[1][0];
       int v2=edges[1][1];

       if(u1==u2 || u1==v2){
            cout<<"Returning from here: "<<endl;
            return u1;
       }
       cout<<"not"<<endl;
       return v1;
    }
};