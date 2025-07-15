//Queue traverse, addition and deletion.
#include<iostream>
using namespace std;
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) 
{
    if (rear == SIZE - 1) 
    {
        cout << "Queue is full (Overflow)\n";
    } 
    else 
    {
        if (front == -1) front = 0; //first insertion
        rear++;
        queue[rear] = value;
    }
}

void dequeue() 
{
    if (front == -1 || front > rear) 
    {
        cout << "Queue is empty (Underflow)";
    } 
    else 
    {
        cout << "Dequeued: " << queue[front] << "\n";
        front++;
    }
}

void traverse() 
{
    if (front == -1 || front > rear) 
    {
        cout << "Queue is empty\n";
    } 
    else 
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) 
        {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
}

int main() 
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    traverse();

    dequeue();
    dequeue();
    traverse();

    return 0;
}
