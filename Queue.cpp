#include "Queue.h"



template<class T>
Queue<T>::Queue()
{
    tail = nullptr;
    head = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
    MakeEmpty();
}

template<class T>
void Queue<T>::MakeEmpty()
{
    while(head!= nullptr){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<class T>
bool Queue<T>::IsEmpty() const
{
    return (head == nullptr && tail == nullptr);
}

template<class T>
bool Queue<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    try {
        Node* tmp = new Node;
        delete tmp;
    }
    catch (std::bad_alloc error) {
        return true;
    }

    return false;
}

template<class T>
void Queue<T>::Enqueue(T newItem)
{
    if(IsFull() == true)
        throw "Full";
    Node* item = new Node;
    item->value = newItem;
    item->next = nullptr;
    tail->next = item;
    tail = item;
    if(IsEmpty() == true){
    head = item;
    }
}

template<class T>
T Queue<T>::Dequeue()
{
    if(IsEmpty()==true)
        throw "empty";
    T itemDe = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;
    return itemDe;
}
