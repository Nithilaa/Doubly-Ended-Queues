#include<iostream>
using namespace std;

#define max_size 10

class Doublyended_Queue
{
    int  arr[max_size];
    int  head;
    int  rear;
    int  queue_size;

    public :
        Doublyended_Queue(int queue_size) {
        head = -1;
        rear = 0;
        this->queue_size = queue_size;
    }

    void  insertfront(int value);
    void  insertrear(int value);
    void  deletefront();
    void  deleterear();
    int  getFront();
    int  getRear();

    bool  isFull(){
        return ((head == 0 && rear == queue_size-1)||head == rear+1);
    }
    bool  isEmpty(){
        return (head == -1);
    }
};

void Doublyended_Queue::insertfront(int value)
{
    if (isFull())  {
        cout << "Overflow!!\n" << endl;
        return;
    }

    if (head == -1)  {
        head = 0;
        rear = 0;
    }

    else if (head == 0)
        head = queue_size - 1 ;

    else
        head = head-1;

    arr[head] = value ;
}

void Doublyended_Queue ::insertrear(int value)
{
    if (isFull()) {
        cout << " Queue is FULL\n " << endl;
        return;
    }

    if (head == -1) {
        head = 0;
        rear = 0;
    }

    else if (rear == queue_size-1)
        rear = 0;

    else
        rear = rear+1;

    arr[rear] = value ;
}

void Doublyended_Queue ::deletefront()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY\n" << endl;
        return ;
    }

    if (head == rear)
    {
        head = -1;
        rear = -1;
    }

    else {
        if (head == queue_size -1)
            head = 0;
        else
            head = head+1;
    }
}

void Doublyended_Queue::deleterear()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY\n" << endl ;
        return ;
    }

    if (head == rear)
    {
        head = -1;
        rear = -1;
    }

    else if (rear == 0)
        rear = queue_size-1;

    else
        rear = rear-1;
}

int Doublyended_Queue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY\n" << endl;
        return -1 ;
    }

    return arr[head];
}

int Doublyended_Queue::getRear()
{
    if(isEmpty() || rear < 0)
    {
        cout << "Queue is EMPTY\n" << endl;
        return -1 ;
    }

    return arr[rear];
}

int main()
{
    Doublyended_Queue dq(5);

    int choice = 1;
    int option, val;
    while(choice==1)
    {
        cout<<"Enter your choice : \n\t1. Insert at front\n\t2. Insert at rear\n\t3. Delete at front\n\t4. Delete at rear\n\t5. Exit\n\nYour choice : ";
        cin>>option;

        switch(option) {
         case 1:
            cout<<"Enter value for inserting at front : "<<endl;
            cin>>val;
            dq.insertfront(val);
            cout<<"Front element of dequeue is : "<<dq.getFront();
            cout<<"\n";
            break;

         case 2:
            cout<<"Enter value for inserting at rear : "<<endl;
            cin>>val;
            dq.insertrear(val);
            cout<<"Rear element of dequeue is : "<<dq.getRear();
            cout<<"\n";
            break;

         case 3:
            dq.deletefront();
            cout<<"After deleting front, the new front is : "<<dq.getFront();
            cout<<"\n";
            break;

         case 4:
            dq.deleterear();
            cout<<"After deleting rear, the new rear is : "<<dq.getRear();
            cout<<"\n";
            break;

         case 5:
            cout<<"Exit\n";
            choice = 0;
            break;

         default: cout<<"Error!\n";
      }

    }


return 0;
}
