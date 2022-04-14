#include<iostream>
using namespace std;

class Stack{
    public:
    int data;
    Stack *next;
    Stack *top  = NULL;

    Stack(int data){
        this->data = data;
        this->next = NULL;
        // this->top = NULL;
    }

    void push(int value){
        Stack *temp = new Stack(value);
        // temp->data = value;
        // temp->next = NULL;

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
};

int main()
{
    Stack st(1);
    st.push(10);
    st.push(20);

    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}