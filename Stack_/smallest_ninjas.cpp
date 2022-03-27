#include<iostream>
#include<stack>
using namespace std;

class SpecialStack {
    // Define the data members.
    stack<int>s;
    int min;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
      
    void push(int data) {
	// for first element
        if(s.empty()){
            s.push(data);
            min = data;
        }
        
        else{
            if(data < min){
                int val = 2*data - min;
                s.push(val);
                min = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        
        if(curr > min){
            return curr;
        }
        else{
            int prevmin = min;
            int val = 2*min - curr;
            min = val;
            return prevmin;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < min){
            return min;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        
        if(s.empty()){
            return -1;
        }
        return min;
    }  
};