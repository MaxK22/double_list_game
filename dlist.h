#ifndef DOUBLY_LINKED_LIST_DLIST_H
#define DOUBLY_LINKED_LIST_DLIST_H

#include <iostream>

template <typename T>
class  Node
{
public:
    T src;
    Node<T>* previous;
    Node<T>* next;
    Node(T src)
    {
        this->src = src;
    }
};

template <typename T>
class DList
{
public:

    Node<T>* start;
    Node<T>* cursor;

    DList();

    void push_front(T new_element);
    void push_back(T new_element);
    void push_cursor(T new_element);

    void delete_front();
    void delete_back();
    void delete_cursor();
    void delete_before_cursor();

    void move_cursor();

    template<typename Type> friend std::ostream& operator<<(std::ostream&, const DList<Type>&);
};

template<typename T>
DList<T>::DList() {
    start = new Node<T>(0);
    cursor = start;
    start->next = start;
    start->previous = start;
}

template<typename T>
void DList<T>::push_back(T new_element) {
    Node<T>* x = new Node<T>(new_element);
    start->previous->next = x;
    x->previous = start->previous;
    x->next = start;
    start->previous = x;
}

template<typename T>
void DList<T>::push_front(T new_element) {
    Node<T>* x = new Node<T>(new_element);
    start->next->previous = x;
    x->next = start->next;
    x->previous = start;
    start->next = x;
}

template<typename T>
void DList<T>::push_cursor(T new_element) {
    Node<T>* x = new Node<T>(new_element);
    cursor->next->previous = x;
    x->next = cursor->next;
    x->previous = cursor;
    cursor->next = x;
    cursor = x;
}

template<typename T>
void DList<T>::delete_back() {
    if(start->previous != start) {
        Node<T> *x = start->previous;
        start->previous = start->previous->previous;
        start->previous->previous->next = start;
        delete x;
    }
}

template<typename T>
void DList<T>::delete_front() {
    if(start->next != start) {
        Node<T> *x = start->next;
        start->next = start->next->next;
        start->next->next->previous = start;
        delete x;
    }
}

template<typename T>
void DList<T>::delete_cursor() {
    if(cursor != start) {
        Node<T> *x = cursor->next;
        cursor->previous->next = x;
        x->previous = cursor->previous;
        delete cursor;
        cursor = x;
    }
}

template<typename T>
void DList<T>::delete_before_cursor() {
    cursor = cursor->previous;
    delete_cursor();
}

template<typename T>
void DList<T>::move_cursor() {
    if(cursor!=NULL)cursor = cursor->next;
}

template<typename Type>
std::ostream& operator<<(std::ostream& out, const DList<Type>& list)
{
    Node<Type> *x = list.start->next;
    while(x != list.start)
    {
        out << '(' << x->src << ')';
        if(x != list.start->previous)
        {
            out << '-';
        }
        x = x->next;
    }
    return out;
}
#endif //DOUBLY_LINKED_LIST_DLIST_H

/* (
                        (list.cursor->previous != list.start && list.cursor->previous->src == current)
                        && ((list.cursor->next != list.start && list.cursor->next->src == current)
                            || (list.cursor->previous->previous != list.start && list.cursor->previous->previous->src == current)
                        )
                    )

                    ||

                    (
                            (list.cursor->next != list.start && list.cursor->next->src == current)
                            && ((list.cursor->previous != list.start && list.cursor->previous->src == current)
                                || (list.cursor->next->next != list.start && list.cursor->next->next->src == current)
                            )
                    )
                    */
