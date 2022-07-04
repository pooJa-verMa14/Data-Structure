#include<iostream>
using namespace std;
#define MAX 100
#define none -999

class queue
{
    private:
    int arr[MAX];
    int front;
    int rear;
    int length;

    public:
    queue() //constructure
    {
        front=0;
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
    if(front==0 && rear==-1)
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
    if(front==(rear+1)%length && rear !=-1)
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
    }
    else
    {
        rear=(rear+1)%length;
        arr[rear]=x;
    }
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
        front =0;
        rear=-1;
    }
    else
    {
        front=(front+1)%length;
    }
    return temp;
}

int queue :: total()
{
    if(isEmpty())
    {
        return 0;
    }
    
    int i=0;
    while((front+i)%length!=rear)
    {
        i=i+1;
    }
    return i+1;
}

void queue :: display()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY\n";
        return ;
    }
    else
    {
        for(int i=0;i<total();i++)
        {
            cout<<arr[(front+i)%length]<<" ";
        }
    }
}



int main(void)
{
    queue q;
    q.size(4);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.dequeue();
    q.dequeue();

    q.enqueue(70);
    q.enqueue(80);
    q.display();

}
