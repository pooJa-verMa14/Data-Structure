#include<iostream>
using namespace std;
#define MAX 100
#define none -999

char stack[MAX];
int top=-1;

void push(char x)
{
    if(top==MAX-1)
    {
        cout<<"STACK IS FULL\n";
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i];
    }
}

int pop()
{
    char item;
    if(top==-1)
    {
        return 0;
    }
    else
    {
        item=stack[top];
        top--;
        return item;
    }
}

class queue
{
    private:
    char arr[MAX];
    int front;
    int rear;
    int length;

    public:
    queue() //constructure
    {
        front=-1;
        rear=-1;
        length=0;
    }
    void size(int x);   //helps to make the of our desired length
    bool isEmpty();  //tells us if the queue is empty
    bool isFull();   //tells us if the queue is full
    void enqueue(int x);  //to insert an element from the queue it willl add the value from arr[rear] 
    int dequeue();  //to delet an element from the queue it willl delete the value from arr[front] 
    void display();  //to display the elements of queue
    int total();  //total number of elements in queue
};

void queue :: size(int x)
{
    length=x;
}

bool queue :: isEmpty()
{
    if(front==-1 && rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue :: isFull()
{
    if(rear==length-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void queue :: enqueue(int x)
{
    if(isFull())
    {
        cout<<"QUEUE IS FULL\n";
        return ;
    }
    else if(isEmpty())
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    arr[rear]=x;
}

int queue :: dequeue()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY";
        return none;
    }
    int temp=arr[front];
    if(front==rear)
    {
        front =-1;
        rear=-1;
    }
    else
    {
        front=front+1;
    }
    return temp;
}

void queue :: display()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY\n";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int queue :: total()
{
    if(isEmpty())
    {
        return 0;
    }
    else if(isFull())
    {
        return length;
    }
    else
    {
        int temp=rear - front +1;
        return temp;
    }
}

void fun1(char val)
{
    if( top==-1 || stack[top] < val)
    {
        push(val);
        return;
    }
    char c=pop();
    fun1(val);
    if(c!=stack[top])
    {
        push(c);
    }
}

int main(void)
{
    queue q;
    q.size(8);
    q.enqueue('D');
    q.enqueue('A');
    q.enqueue('T');
    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('A');
    q.enqueue('S');
    q.enqueue('E');
    q.display();
    while(!q.isEmpty())
    {
        fun1(q.dequeue());
    }
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i];
    }
    
}
