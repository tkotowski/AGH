#ifndef LISTA_H_
#define LISTA_H_

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<exception>
using namespace std;

template<typename T>
class double_clist;

template<typename T>
class node;

template<typename T>
class node
{
private:
    T data;
    node<T> *next;
    node<T> *prev;
    friend class double_clist<T>;
public:
    node(T value): data(value){};
};

 template<typename T>
class double_clist
{
    private:
        int elem;
        node<T> *start = NULL, *cursor = NULL, *endr = NULL;

    public:
        double_clist(): elem(0){};
        ~double_clist(){};
        void insert_(const T data) throw ( bad_alloc );
        void remove_(); //throw ( logic_error );
        void clear_();
        void replace_(T data) ;//throw (std::logic_error);
        bool isEmpty();
        bool gotoBeginning();// throw (std::logic_error);
        bool gotoPrior() ;//throw (std::logic_error);
        bool gotoNext() ;//throw (std::logic_error);
        bool gotoEnd() ;//throw (std::logic_error);
        T getCursor() const;// throw (std::logic_error);
        void show_();
        int count(){return elem;}

};

template<typename T>
void double_clist<T>::insert_(const T data) throw ( bad_alloc )
{
    node<T> *nowy = new node<T>(data);
    node<T> *wsk;
    if (elem == 0)
    {
        start = nowy;
        cursor = nowy;
        start->next = NULL;
        start->prev = NULL;
    }
    else
    {
        if(elem == 1)
        {
            cursor->next = nowy;
            cursor->prev = nowy;
            nowy->next = cursor;
            nowy->prev = cursor;
            cursor = cursor->next;
            cursor = nowy;
        }
        else
        {
            wsk = (cursor->next);
            cursor->next = nowy;
            wsk->prev = nowy;
            nowy->prev = cursor;
            nowy->next = wsk;
            cursor = cursor->next;
            cursor = nowy;
        }
    }
    elem++;
}

template<typename T>
void double_clist<T>::remove_() //throw ( logic_error )
{
    node<T> *wsk_after, *wsk_before, *wsk;
    //if(elem == 0) throw std::logic_error("Odwolanie do nieistniejacego elementu \n");
    if(elem == 1)
    {
        delete cursor;
        cursor = NULL;
        start = NULL;
        elem = 0;
    }
    else if(elem == 2)
    {
        wsk = cursor;
        cursor = cursor->prev;
        start = cursor;
        start->next = NULL;
        start->prev = NULL;
        delete wsk;
        elem = 1;
    }
    if(elem > 2)
    {
        wsk_after = cursor->next;
        wsk_before = cursor->prev;
        wsk = cursor;
        wsk_before->next = wsk_after;
        wsk_after->prev = wsk_before;
        cursor = cursor->prev;
        start = cursor;
        delete wsk;
        elem--;
    }
}

template<typename T>
void double_clist<T>::clear_()
{
    node<T>* wsk;
    if(elem == 0) cout<<"Lista jest pusta!"<<endl;
    else if(elem == 1) remove_();
    else
    {
        wsk = start;
        for(cursor = start->prev; cursor != wsk;) remove_();
        cursor = wsk;
        remove_();
    }
}

template<typename T>
void double_clist<T>::show_()
{
    node<T>* wsk;
    if(elem == 0)
    {
        cout<<"Lista jest pusta!"<<endl;
        return;
    }
    cout<<(start->data)<<"";
    if(elem > 1)
    for(wsk = start->next; wsk != start; wsk=wsk->next)
        cout<<(wsk->data)<<"";
    cout<<endl;
}

template<typename T>
void double_clist<T>::replace_(T datat)//throw (std::logic_error)
{
    //if (cursor==NULL) throw (std::logic_error("Odwolanie do nieistniejacego elementu \n"));
    cursor->data = datat;
}

template<typename T>
bool double_clist<T>::isEmpty()
{
    return (start == NULL) ? true : false;
}

template<typename T>
bool double_clist<T>::gotoBeginning() //throw (std::logic_error)
{
    //if (start==NULL) throw (std::logic_error("Odwolanie do nieistniejacego elementu \n"));
    cursor = start;
    return (start == NULL) ? false : true;
}

template<typename T>
bool double_clist<T>::gotoPrior() //throw (std::logic_error)
{
    //if(cursor->prev == NULL)throw (std::logic_error("Odwolanie do nieistniejacego elementu \n"));
    cursor = cursor->prev;
    return (cursor->prev != NULL) ? true : false;
}

template<typename T>
bool double_clist<T>::gotoNext() //throw (std::logic_error)
{
    //if(cursor->next == NULL) throw (std::logic_error("Odwolanie do nieistniejacego elementu \n"));
    cursor = cursor->next;
    return (cursor->next != NULL) ? true : false;
}

template<typename T>
bool double_clist<T>::gotoEnd()// throw (std::logic_error)
{
    //if(start->prev == NULL) throw (std::logic_error("Odwolanie do nieistniejacego elementu \n"));
    cursor = start->prev;
    return (start->prev != NULL) ? true : false;
}

template<typename T>
T double_clist<T>::getCursor() const// throw (std::logic_error)
{
    return cursor->data;
}

#endif
