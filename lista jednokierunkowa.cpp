#include <iostream>
#include <random>
#include <time.h>
using namespace std;

struct element
{
    int number;
    element* next;
};


struct single_list
{
    element* head;
    element* tail;
    int counter;
};


void add_tail(single_list &, int  );
void add_head(single_list &, int  );
void add_position(single_list &, int ,int );
void delete_tail(single_list &);
void delete_head(single_list &);
void delete_position(single_list &,int );
void show(single_list );
float srednia(single_list);
int max_el(single_list , int *);
int sum_of_elements(single_list);

int main()
{
    single_list l ;
    l.counter = 1 ;
    l.tail = nullptr;
    l.head = nullptr;
    cout << endl;
    int choice = 1;
    while(choice != 15)
    {

        cout << " \n\n MENU \n1.sprawdzenie czy lista jest pusta\n2.dodanie elementu na koniec listy\n3.dodanie elementu na poczatek listy"<<
                "\n4.dodanie elementu na okreslona pozycje\n5.usuniecie elementu z kocca listy\n6.usuniecie elementu z poczatku listy," <<
                "\n7.usuniecie elementu znajdujacego sie na okreslonej pozycji\n8.wyswietlenie calej listy" <<
                "\n9.srednia arytmetyczna wszystkich elementow\n10.znalezienie elementu maksymalnego w liscie\n11.usuwanie calej listy";
             //   cout << "\n aktualna ilosc elementow to : " << l.counter << endl<<endl;
        cin >> choice;
        system("cls");
        srand(time(NULL));
        switch(choice)
        {
            case 1:
            {
                if(l.tail == nullptr)
                {
                    cout << " lista  jest pusta ";
                }
                else cout << " lista nie jest pusta ";

                break;
            }
            case 2 :
            {
                srand(time(NULL));
                int number = rand()%(50)+1;
                add_tail(l, number);
                cout << "na koniec listy dodano liczbe " << number;
                break;
            }
            case 3 :
            {
                srand(time(NULL));
                int number = rand()%(50)+1;
                add_head(l, number);
                cout << "na poczatek list dodano liczbe " << number;
                break;
            }
            case 4:
            {
                int pos;
                cout << "Podaj pozycje na ktora ma zostac dodana liczba \n jesli podana liczba bedzie wieksza niz aktualny rozmiar listy liczba zostanie dodana na koniec ";
                cin >> pos;
                srand(time(NULL));
                int number = rand()%(50)+1;
                if(pos > l.counter)
                {
                    add_tail(l, number);

                }
                else if (pos < 0 )
                {
                    cout << "nie ma takiej pozycji !! " ;break;
                }
                else if(pos == 0 || l.tail == nullptr)
                {
                    add_head(l, number);

                }
                else add_position(l,number , pos);
                cout << " pomyslanie dodano liczbe " << number;
                break;
            }
            case 5:
            {
                if(l.counter == 1)
                {
                    cout << "lista jest juz pusta " ;break;
                }
                else delete_tail(l);
                cout << "pomyslnie usunieto";
                break;
            }
            case 6:
            {
                if(l.counter == 1)
                {
                    cout << "lista jest juz pusta " ;break;
                }
                else delete_head(l);

                cout << "pomyslnie usunieto";

                break;
            }
            case 7:
            {
                int pos;
                cout << "Podaj pozycje z ktorej ma zostac usunieta liczba\nW przypadku podania liczby wiekszej niz ilosc elementow zostanie usuniety ostatni element\n";
                cin >> pos;
                if(l.counter == 1)
                {
                    cout << "lista jest juz pusta " ;break;
                }
                else if(pos > l.counter)
                {
                    delete_tail(l);

                }
                else if(pos < 0 )
                {
                    cout << "nie ma takiej pozycji !! " ;break;
                }
                else if(pos == 0)
                {
                    delete_head(l);

                }
                else delete_position(l , pos);
                cout << "pomyslnie usunieto";

                break;
            }
            case 8:
                {
                    cout << "\nlista \n ";
                    show(l);
                    break;
                }
            case 9:
                {
                    float res = srednia(l);
                    cout << "srednia arytmetyczna to " << res ;

                    break;
                }
            case 10:
                {
                    int pos = 0 ;
                    int  res = max_el(l, & pos);

                    cout << "maksymalny element  to " << res <<  "i jego pozycja to " << pos ;

                    break;
                }
            case 11:
                {
                    if(l.counter == 1)
                    {cout << " lista jest pusta "; break ;
                    }
                    else
                    {
                       while(l.counter != 1)
                        {
                            delete_tail(l);
                          //  l.counter--;
                        }
                        delete_head(l);
                        l.counter = 1;

                    }
                    break;

                }
            case 12:
            {
                cout << "\n suma elementow to " << sum_of_elements(l);
            }

        }



    }

    return 0 ;
}


void add_tail(single_list &l, int value )
{
    element *el = new element ;
    el->number = value ;
    el->next = nullptr;

    if(l.tail != nullptr)
    {
        l.tail->next = el;
    }
    else
    {
        l.head = el ;
    }
    l.counter++;
    l.tail = el;

}


void add_head(single_list &l, int  value)
{
    element *el = new element ;
    el->number = value ;
    el->next = l.head;
    l.head = el ;
    if(l.tail == nullptr)
    {
        l.tail = el;

    }
    l.counter++;
}

void add_position(single_list &l, int value ,int position)
{
    element *el = new element ;
    el->number = value ;
    element *temp  = l.head;
    int i = 1;
    while(i < position - 1)
    {
        temp = temp->next;
        i++;

    }
    el->next = temp->next;
    temp->next = el;
    l.counter++;

}
void delete_tail(single_list &l)
{
    element *temp = l.tail;
    if(l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        element * bef_temp = l.head;
        int i = 1;
        while ( i < l.counter - 1)
        {
            bef_temp = bef_temp->next;
            i++;
        }
        l.tail = bef_temp;
        l.tail->next = nullptr;

    }
    delete temp ;
    l.counter-- ;


}
void delete_head(single_list &l)
{
    element *temp = l.head;
    l.head = l.head->next;
    if(l.counter == 1)
    {
        l.tail = nullptr;


    }
    delete temp;
    l.counter--;
}
void delete_position(single_list &l,int position)
{
    element *prev= l.head;
    int i = 1;
    while ( i < position - 1)
    {
        prev = prev->next;
        i++;

    }
    element *temp = prev->next;
    prev->next = temp->next;
    delete temp;
    l.counter--;


}
void show(single_list l)
{
    int i = 1 ;
    element *temp = l.head;
    while(i < l.counter)
    {

    cout << temp->number << " ";
    temp = temp->next;
    i++;
    }

}
float srednia(single_list l )
{
    int i = 1 ;
    float result = 0;

    element *temp = l.head;
    while(i < l.counter)
    {

    result += temp->number;
    temp = temp->next;
    i++;
    }
    return result/(l.counter-1);
}
int max_el(single_list l, int *pos )
{
    int i = 1 ;
    int max_el;

    element *temp = l.head;
    max_el =temp->number;
    while(i < l.counter )
    {
        if(max_el < temp->number )
        {
            max_el = temp->number ;
            *pos = i;
        }
        temp = temp->next;
        i++;
    }
    return max_el;

}
int sum_of_elements(single_list  L)
{

    if(L.head == nullptr) return 0;
    else
    {
        int counter = 1;
        element *temp = L.head;
        while(temp != L.tail)
        {

            temp = temp->next;
            counter++;

        }
        return counter;
    }

}
