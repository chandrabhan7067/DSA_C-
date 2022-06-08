#include<iostream>
#include<queue>
using namespace std;

class StackQueue{
    public:
        queue<int>q1,q2;

    void push(int value){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(value);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        if(q1.empty()){
            return -1;
        }

        int ans = q1.front();
        q1.pop();
        return ans;
    }
};

int main()
{
    StackQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";

}