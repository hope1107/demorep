#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include<clocale>
using namespace std;

void Vvod(int n, int* list, int* next, int* prev) ///функция заполнения
{
  cout<<"Введите элементы: \n";


    int i;
    for (i=0; i<n; i++)

    {
    cin>>list[i];
    next[i]=i+1;
    prev[i]=i-1;

    }
 next[n-1] = -1;

}

void VyvodNazad(int n, int* list, int* next, int* prev) ///функция вывода назад
{
    cout<<"\nВывод элементов от конца к началу: \n";

    int temp = n - 1;

    do { cout<<list[temp]<<"\n";

    temp=prev[temp];

    } while (temp != -1 && prev[temp]!= -1);

    cout<<list[temp];

}

void VyvodVpered(int n, int* list, int* next, int* prev) ///функция вывода вперед
{
    cout<<"\nВывод элементов от начала к концу: \n";
    int temp = 0;
    do { cout<<list[temp]<<"\n";

    temp=next[temp];

    } while (temp != -1 && next[temp] != -1);//(prev[temp]!= n - 2);

    cout<<list[temp];
}

void VyvodMassiv(int n, int* list, int* next, int* prev)  ///вывод вспомогательных массивов
{
    cout<<"\nВывод вспомогательного массива:\n";
    for (int i=0; i<n; i++)
    {
        cout<<next[i]<<", ";
        cout<<prev[i]<<"\n";
    }
}

bool Udalenie(int &n, int* list, int* next, int* prev)    ///удаление элемента
{
    int nom;
   cout << "Укажите номер элемента массива, который необходимо удалить: ";
   cin >> nom;
    if ( nom > /*sizeof(list)*/ n || nom < 1)
    {
        cout << "Ошибка удаления" << endl;
        return false;
    }

    for(int i = nom - 1; i < /*sizeof(list) - 1*/ n; i++)
    {
        list[i] = list[i + 1];

    }
    next[n-2]=-1;

    n-- ;
    return true;
}

void Dobavlenie(int &d, int &n, int* list, int* next, int* prev)   ///добавление элемента в конец
{
    
    n++;
    cout<<"\nКакое число вы хотите добавить?";
    cin>>d;
    list[n-1]=d;

    next[n-1] = -1;
    prev[n-1] = n-2;
    next[n-2] = n-1;
}

int main ()

{
    setlocale (LC_ALL, "RUS");
int n;
cout<<"Введите количество элементов:  ";
cin>>n;

int list[100];   ///задаем массивы

int next[100];

int prev[100];


next[n] = 0;
prev[0] = 0;

int d;
int h;

for (int i=0; i<n; i++)

{ list[i]=next[i]=prev[i]=0; }


Vvod(n, list, next, prev);
VyvodNazad(n, list, next, prev);
VyvodVpered(n, list, next, prev);
VyvodMassiv(n, list, next, prev);

while(true)
{
    cout<<"\nВыберите действие с массивом. 1 - удаление элемента; 2 - добавление элемента; 3 - конец работы : ";
    cin>>h;
    if(h==1)
    {
        Udalenie(n, list, next, prev);
        
    }
    else if(h==2)
    {
        Dobavlenie(d, n, list, next, prev);
    }
    else if(h==3)
    {
        break;
    }
    else
    {
        cout<<"\nОшибка...";

    }
    VyvodMassiv(n, list, next, prev);
    VyvodVpered(n, list, next, prev);
    VyvodNazad(n, list, next, prev);
       

}



return 0;
}
