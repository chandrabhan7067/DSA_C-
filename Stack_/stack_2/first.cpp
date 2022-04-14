#include<iostream>
using namespace std;

class stack{
    public:
        int size;
        int top;
        int *arr;

        stack(int n){
            this->size = n;
            this->top = -1;
            arr = new int[size];
        }

    void push(int value){
        if(top < size -1){
            top++;
            arr[top] = value;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    int pop(){
        if(top == -1){
            return -1;
        }
        else{
            int ans = arr[top];
            top--;
            return ans;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int peek(){
        if(top == -1){
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};

int main()
{
    stack st(3);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.pop();
    // st.pop();


    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    cout<<st.peek();
}