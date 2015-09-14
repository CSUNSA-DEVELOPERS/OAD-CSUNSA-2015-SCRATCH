#include <iostream>
#include "Table.h"
#include "App.h"
using namespace std;

int main()
{
   /* Table<Record> table("data.dat");
    table.index();
    char elem[9];*/
    /*table.printKey();*/
   /* while(true){
        cin >> elem;
        table.GetRecord(elem);
    }*/
    //table.StartPrinting();

    /*Table<Record> pre("Prerequisitos.dat");
    pre.index();
    pre.StartPrinting();*/

    Aplicacion<int> nueva;
    nueva.start();

    /*int n, val;
    List<int> lista1, lista2, *lista3, *lista4;
    cin >> n;
    while(n--){
        cin >> val;
        lista1.add(val);
        lista1.print();
        cout << endl;
    }
    while(true){
        cin >> val;
        lista1.erase(val);
        lista1.print();
        cout << endl;
    }*/
    /*cout << endl;
    lista1.print();*/
    /*cin >> n;
    while(n--){
        cin >> val;
        lista2.insert(val);
    }*/
    /*for(int i = 0; i < n; ++i){
        string s(3, 'a'+i);
        lista.pushBack(s);
    }*/
    /*cout << endl;
    lista3 = lista1.unionListSort(lista2);
    lista3->print();
    cout << endl;
    lista1.print();
    cout << endl;
    lista2.print();
    cout << endl;
    lista4 = lista2.intersectionListSort(lista1);
    lista4->print();*/
    /*cout << lista.size() << endl;
    cout << lista.maxValue() << endl;
    cin >> n;
    cout << lista.find(n) << endl;*/
    return 0;
}
