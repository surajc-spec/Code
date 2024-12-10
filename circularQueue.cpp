#include <iostream>
using namespace std;

class Circularq
{

public:
    int queue[30];
    int front, rear, n;

    Circularq()
    {
        n = 5;
        front = -1;
        rear = -1;
    }
    //  eneueue function

    void enqueue(int data)
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = data;
        }

        else if ((rear + 1) % n == front)
        {
            cout << "queue if full";
        }
        else
        {
            rear = (rear + 1) % n;
            queue[rear] = data;
        }
    }

    // dequeue function

    void dequeue()
    {
        if (front == -1)
        {
            cout << "underflow" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
            cout << "queue is empty";
        }
        else
        {
            cout << "deleted element is " << queue[front] << endl;
            front = (front + 1) % n;
        }
    }

    // display function

    void display()
    {
        if (front == -1 && rear == -1)
        {

            cout << "queue is empty";
        }

        else
        {
            cout <<"Queue is :";
            int i = front;
            while (i != rear + 1)
            {
                cout << queue[i] << " ";
                i = (i + 1) % n;
            }
        }
    }
};

int main()
{
    Circularq q;
    int data;
    int ch;

    do
    {
        cout << " \nThe choices are"<< endl;
        cout<<"-----------------------------------------------"<<endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        cout<<"-----------------------------------------------"<<endl;

        switch (ch)
        {
        case 1:
            cout << "Enter the data to enqueue" << endl;
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            cout << endl;
            break;
        };

    } while (ch != 4);

    return 0;
}


