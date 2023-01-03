/* Evaluate the expression. Return an integer that represents the value of the expression.
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22 */


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;                   // Using stack for postfix notations
        int n = tokens.size();
        int temp1, temp2;

        for(int i = 0; i < n; i++){
          
          //// check if element is an operator
            if(tokens[i] == "+"){
                temp2 = st.top();  
                st.pop();
                temp1 = st.top();
                st.pop();                  //pop previous two integers and do the given operation and push back the result in stack
                st.push(temp1 + temp2);
            }
            else if(tokens[i] == "-"){
                temp2 = st.top();
                st.pop();
                temp1 = st.top();
                st.pop();
                st.push(temp1 - temp2);
            }
            else if(tokens[i] == "*"){
                temp2 = st.top();
                st.pop();
                temp1 = st.top();
                st.pop();
                st.push(temp1 * temp2);
            }
            else if(tokens[i] == "/"){
                temp2 = st.top();
                st.pop();
                temp1 = st.top();
                st.pop();
                st.push(temp1 / temp2);
            }
          //if not an element push it into the stack
            else{
                st.push(stoi(tokens[i]));         //Converting string to int using "stoi"
            }
        }
        return st.top();
    }
};


// T.C. => O(n)
// S.C. => O(n)
