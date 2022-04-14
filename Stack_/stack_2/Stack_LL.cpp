#include<iostream>
using namespace std;

class Stack{
    public:
    int data;
    Stack *next;
    Stack *top = NULL;

    void push(int value){
        Stack *temp = new Stack();
        temp->data = value;
        temp->next = NULL;

        temp->next = top;
        top = temp;
    }

    int pop(){
        if(top == NULL){
            return -1;
        }
        else{
            int ans = top->data;
            Stack *ptr = top;
            top = top->next;
            delete ptr;
            return ans;
        }
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        return false;
    }

    int peek(){
        if(top == NULL){
            return -1;
        }
        else{
            return top->data;
        }
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl;

    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;


    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}