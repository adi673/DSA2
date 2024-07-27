class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    stack<int> st;
    queue<int> qu;

    for(int i=sandwiches.size()-1; i>=0; i--){
        st.push(sandwiches[i]);
    }

    for(int i=0; i<students.size(); i++){
        qu.push(students[i]);
    }
    int attempts=0;
    while(!qu.empty() && attempts<qu.size()){
        if(st.top()==qu.front()){
            attempts=0;
            st.pop();
            qu.pop();
        }else{
            
            int student=qu.front();
            qu.pop();
            qu.push(student);
            attempts++;
            
        }
    }
    return qu.size();


    }
};