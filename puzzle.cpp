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




class Puzzle
{
public:
Puzzle( char answ[], char init[] ); // Konstruuje puzzle
void shiftLeft();
void swapEnds();
void display();
bool isSolved();
private:
double_clist<char> solution, puzzle;
};

Puzzle::Puzzle(char answ[], char init[])
{
    for(int i = 0; answ[i] != '\0'; i++)
    {
        solution.insert_(answ[i]);
        puzzle.insert_(init[i]);
    }
}

void Puzzle::shiftLeft()
{
    char temp;
    char first = puzzle.getCursor();
    for(int i = 0; i < puzzle.count() - 1; i++)
    {
        puzzle.gotoNext();
        temp = puzzle.getCursor();
        puzzle.gotoPrior();
        puzzle.replace_(temp);
        puzzle.gotoNext();
    }
    puzzle.replace_(first);
}

void Puzzle::swapEnds()
{
    char tempS;
    char tempE;
    char temp;
    puzzle.gotoBeginning();
    tempS = puzzle.getCursor();
    puzzle.gotoEnd();
    tempE = puzzle.getCursor();
    puzzle.replace_(tempS);
    puzzle.gotoBeginning();
    puzzle.replace_(tempE);
}

void Puzzle::display()
{
    puzzle.show_();
}

bool Puzzle::isSolved()
{
    puzzle.gotoBeginning();
    solution.gotoBeginning();
    for(int i = 0; i < puzzle.count() - 1; i++)
    {
        if(puzzle.getCursor() != solution.getCursor()) return false;
        puzzle.gotoNext();
        solution.gotoNext();
    }
    return true;
}

int main()
{
    char solution[7] = "Konrad";
    char rozsypanka[7] = "Kdonra";
    Puzzle ukladanka(solution, rozsypanka);
    int dziala = 1;
    char choice;
    while(dziala)
    {
        cout<<"D - display"<<endl
        <<"L - shift left"<<endl
        <<"S - swap ends"<<endl
        <<"C - check"<<endl
        <<"Q - quit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 'D':
            {
                ukladanka.display();
                break;
            }
        case 'L':
            {
                ukladanka.shiftLeft();
                break;
            }
        case 'S':
            {
                ukladanka.swapEnds();
                break;
            }
        case 'C':
            {
                if(ukladanka.isSolved()) 
                {
					cout<<"Correct!"<<endl;
					dziala = 0;
				}
                else cout<<"Incorrect!"<<endl;
                break;
            }
        case 'Q':
            {
                dziala = 0;
                break;
            }
        }
        cin.get();
        cout<<"Press enter to continue"<<endl;
        while((choice = getchar()) != '\n'){};
        system("clear");
    }


    /*double_clist<char> cdl;
    char choice;
    char element;
    int dziala = 1;
    while(dziala)
    {
        cin>>choice;
        switch(choice)
        {
            case '+':
            {
                cin>>element;
                cdl.insert_(element);
                break;
            }
            case '-':
            {
                cdl.remove_();
                break;
            }
            case '=':
            {
                cin>>element;
                cdl.replace_(element);
                break;
            }
            case '@':
            {
                cout<<cdl.getCursor()<<endl;
                break;
            }
            case 'N':
            {
                if(cdl.gotoNext()){};
                break;
            }
            case 'P':
            {
                if(cdl.gotoPrior()){};
                break;
            }
            case '<':
            {
                if(cdl.gotoBeginning()){};
                break;
            }
            case '>':
            {
                if(cdl.gotoEnd()){};
                break;
            }
            case 'E':
            {
                cout<<cdl.isEmpty()<<endl;
                break;
            }
            case 'C':
            {
                cdl.clear_();
                break;
            }
            case 'S':
            {
                cdl.show_();
                break;
            }
            case 'Q':
            {
                dziala = 0;
                break;
            }
        }
    }*/
    return 0;
}
