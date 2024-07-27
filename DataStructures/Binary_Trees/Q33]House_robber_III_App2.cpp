class Solution {
public:

    int find(TreeNode* root, int pick, vector<int>& in, int sum){

        if(root==NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            if(pick==1){
                sum=sum+0;
            }else{
                sum=sum+root->val;
            }
            cout<<"sum is : "<<sum<<" ";
            return sum;
        }

        if(pick==1){//last one was picked now we will not pick
            int sum_left=find(root->left, 0, in, sum);
            int sum_right=find(root->right, 0, in, sum);

            return (sum_left+sum_right);
        }else{//last one was not picked so current one we will pick or not pick
            //not pick
           int not_sum_left= find(root->left, pick, in, sum);
            int not_sum_right=find(root->right, pick, in, sum);
            int no=not_sum_left+ not_sum_right;
            //pick
           
           int sum_left= find(root->left, 1, in, sum);
            int sum_right=find(root->right, 1, in, sum);
            
            int yes= sum_left+sum_right+root->val;

            return max(no,yes);
            // return yes;
        } 
        return 0;  
    }

    int rob(TreeNode* root) {
        int pick=0;
        vector<int> in;
        int sum=0;
        int val=find(root, pick, in, sum);

        
        return val;
    }
};


//this code also will go in TLE on the follwing test case due to recaulculation of subproblems
// [79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null]

//there is one more optimal solution usingrecursion only from chatgpt