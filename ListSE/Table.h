#ifndef TABLE_H
#define TABLE_H
#include "List.h"
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;
/*void   strcpy(char * p, char *q)
{
      while(*p++=*q++);
}*/

/*int strlen(char * p)
{
   register int i =0;
   for(;*p;p++,i++);
   return i;

}*/
struct Record{
    char key[9];
    long start;
    long end;
};

template<class T>
class Table{
    //private:
    public:
        List<Record> m_record;
        char *file;
        Nodo<Record>* Current;
    //public:
        Table(char *file);
        void index();
        T GetRecord(char *key);
        void printKey();
        void StartPrinting();
        void printNext(Nodo<T>* &temp);
        void printPrev(Nodo<T>* &temp);
        void printFirst();
        void printLast();
};

template<class T>
Table<T> :: Table(char *file){
    this->file = file;
    Current = nullptr;
}

template<class T>
void Table<T> :: index(){
    /** variables para guardar el key y la data temporalmente **/
    char key[10];
    char buffer[1000];

    std::ifstream in(file); /** abrimos el archivo para manipularlo **/
    long offset = 0; /** variable para determinar el inicio de cada registro **/
    while(!in.eof())/** recorrecmos hasta que encuentre el final del archivo **/
    {
        /*std::cout << in.tellg() << " ";*/

        in.getline(key, 11, ','); /** capturamos los 11 primeros caracteres o hasta encontrar una coma **/
        in.getline(buffer, 1000); /** capturamos los siguientes 1000 caracteres **/

        std::cout << key << buffer << std::endl;


        Record R;
        strcpy(R.key , key); /** copiamos el contenido de key en el key de Record **/
        R.start = offset; /** guardamos el inicio del registro **/
        m_record.pushBack(R); /** ingresamos el registro a lista **/
        offset += strlen(key) + strlen(buffer) + 2; /** actualizamos la variable para el inicio de la siguiente linea **/
    }

    in.close();
}

template<class T>
T Table<T> :: GetRecord(char * key)
{
       char data[1000];
       Record *r = m_record.findElem(key, new Record); /** funcion especial que devuelve el puntero de el Record buscado **/
       //std::cout << r->start << std::endl;
       int pos;
       if(r){
           std::ifstream file(this->file,ios::in | ios::binary); /** abrimos el archivo para manipularlo **/
           file.seekg(r->start, std::ios_base::beg); /** Nos posicionamos en el archivo segun la posicion guardada del registro **/
           file.getline(data, 1000); /** capturamos los la linea **/
           pos = file.tellg();
           std::cout<<":::"<< data <<"posicion"<< pos << std::endl;
       }
       else
       {
           cout << r->key << "not found" <<endl;
       }
}

template<class T>
void Table<T> :: printKey(){
    m_record.printStruct();
}

template <class T>
void Table<T>::StartPrinting()
{
    Current = m_record.head;
    GetRecord((Current->dato).key);
    int opcion;
    bool salir;
    do
    {
    std::cout << "INGRESE LA OPCION: "<<std::endl;
    std::cout << "1) FIRST\n2) PREV\n3)NEXT\n4)LAST \n";
    cin>>opcion;
    switch(opcion)
    {
        case 1:
            printFirst();
            Current = m_record.head;
            break;
        case 2:
            printPrev(Current);
            break;
        case 3:
            printNext(Current);
            break;
        case 4:
            printLast();
            Current = m_record.last;
            break;
    }
    cout << "salir? (0/1)" << endl;
    cin>>salir;
    }while(salir!= 1);
}

template <class T>
void Table<T>::printFirst()
{
    GetRecord((m_record.head->dato).key);
}

template <class T>
void Table<T>::printPrev(Nodo<T>* &temp)
{
    if(temp!=m_record.head)
    {

      temp = temp->prev;
        GetRecord((temp->dato).key);
    }
    else{
        cout << "Prev doesn't exist" << endl;
    }
}

template <class T>
void Table<T>::printNext(Nodo<T>* &temp)
{
    if(temp!=m_record.last)
    {
        temp= temp->sig;
        GetRecord((temp->dato).key);
    }
    else{
        cout << "Next doesn't exist" << endl;
    }
}

template <class T>
void Table<T>::printLast()
{
    GetRecord((m_record.last->dato).key);
}

#endif // TABLE_H
