class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        int i=0;
        stack<int> st;
        while(i<n){
            cout<<"intial i val: "<<i<<endl;
            if(!st.empty()){
                cout<<" top and arr is : "<<st.top()<<" "<<asteroids[i]<<endl;
            }
            
            if(st.empty()){
                st.push(asteroids[i]);
                cout<<"Pushing: "<<asteroids[i]<<endl;
                i++;
                cout<<"final i val: "<<i<<endl;

            }else if((st.top()<0 && asteroids[i]>0)){
                //this test case is imp. it is most negalcted case  asteroids =[-2,-1,1,2]
                //since negative will keep on moving left and positive will keep on moving right so they will never collide
                st.push(asteroids[i]);
                cout<<"Pushing: "<<asteroids[i]<<endl;
                i++;
                
            }else if(st.top()>0 && asteroids[i]<0){
                int n1=abs(st.top());
                int n2=abs(asteroids[i]);
                if(n1>n2){
                    i++;
                    cout<<"final i val el : "<<i<<endl;
                }else if(n1<n2){
                    cout<<"Poping : "<<st.top()<<endl;
                    st.pop();
                    cout<<"final i val el if 1 : "<<i<<endl;
                }else if(n1==n2 ){
                    cout<<"Poping : "<<st.top()<<endl;
                    st.pop();
                    i++;
                    cout<<"final i val el if 2 : "<<i<<endl;
                }
                
            }else if((st.top()>0 && asteroids[i]>0) || (st.top()<0 && asteroids[i]<0)){
                st.push(asteroids[i]);
                cout<<"Pushing: "<<asteroids[i]<<endl;
                i++;
                cout<<"final i val el if out : "<<i<<endl;
            }
        }

        vector<int> val;
        while(!st.empty()){
            val.push_back(st.top());
            st.pop();
        }
        reverse(val.begin(), val.end());
        return val;

    }
};