#ifndef APP_H
#define APP_H
#include "Table.h"

template <class T>
class Aplicacion
{
    public:
        Aplicacion();
        virtual ~Aplicacion();
        void start();
        void startPrinting();
        void addPre_rqs();
        void print_for_code();
        void addSubject();
        void find_Subject();
    protected:
    private:
        Table<Record> *Cursos;
        Table<Record> *Requisitos;
        Nodo<Record>* Current;
};

template<class T>
Aplicacion<T>::Aplicacion()
{
    Cursos = new Table<Record>("data.dat");
    Requisitos = new Table<Record>("Prerequisitos.dat");
    Current = nullptr;
}

template <class T>
Aplicacion<T>::~Aplicacion()
{

}

template <class T>
void Aplicacion<T>::start()
{
    Cursos->index();
    Requisitos->index();
    startPrinting();
}

template <class T>
void Aplicacion<T>::startPrinting()
{
    Current = Cursos->m_record.head;
    Cursos->printFirst();
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
            Cursos->printFirst();
            Current = Current = Cursos->m_record.head;
            break;
        case 2:
            Cursos->printPrev(Current);
            break;
        case 3:
            Cursos->printNext(Current);
            break;
        case 4:
            Cursos->printLast();
            Current = Cursos->m_record.last;
            break;
    }
    cout << "salir? (0/1)" << endl;
    cin>>salir;
    }while(salir!= 1);
}
#endif // APP_H
