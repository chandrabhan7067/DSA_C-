#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> input, output;

    void enqueue(int value)
    {
        input.push(value);
    }

    int dequeue()
    {
        if (input.empty())
        {
            return -1;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }

            int ans = output.top();
            output.pop();

            while (!output.empty())
            {
                input.push(output.top());
                output.pop();
            }
            return ans;
        }
    }
};

main()
{
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    cout << Q.dequeue();
}