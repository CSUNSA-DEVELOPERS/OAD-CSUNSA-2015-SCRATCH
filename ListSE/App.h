#ifndef APP_H
#define APP_H
#include "Table.h"
#include <string>
#include <vector>

template <class T>
class Aplicacion
{
    public:
        Aplicacion();
        virtual ~Aplicacion();
        void start();
        void startPrinting();
        void addPre_rqs(char *key);
        vector<string>* find_prerqs(char *key);
        void print_for_code();
        void addSubject();
        void find_Subject();
        char* year_key(char *key);
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
    char temp[9]= "CS3CB111";
    addPre_rqs(temp);
}

template <class T>
void Aplicacion<T>::addPre_rqs(char *key)
{
    std::string temp;
    cout << "Ingrese codigo prerequisito: ";
    cin>>temp;
    temp.insert(0,"\n,");
    Requisitos->write_in_file(key,temp);
}

template <class t>
vector<string>* Aplicacion<t>::find_prerqs(char *key)
{
    std::vector<string> *prerequisitos_V = new vector<string> ;
    prerequisitos_V->push_back(Requisitos->GetRecord(key)); // Encuentra el prerequisito y le da al vector
    return prerequisitos_V;
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
    std::cout << "1) FIRST\n2) PREV\n3)NEXT\n4)LAST\n5)FIND\n6)VER ORDENADO\n";
    cin>>opcion;
    switch(opcion)
    {
        case 1:
            Cursos->printFirst();
            Current = Cursos->m_record.head;
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
        case 5:
            find_Subject();
            break;
        case 6:
            print_for_code();
            break;
    }
    cout << "salir? (0/1)" << endl;
    cin>>salir;
    }while(salir!= 1);
}

template <class T>
void Aplicacion<T>::find_Subject()
{
    char elem[9];
    cout << "Ingrese el codigo del curso: "<< endl;
    cin >> elem;
    Cursos->GetRecord(elem);
    find_prerqs(elem);  // imprime requisitos
}

template <class T>
char* Aplicacion<T>::year_key(char *key)
{
    char  nuevo;
    for(int i = 0; i< 3 ; i++ )
    {
        nuevo = key[i];
    }
    return &nuevo;
}

template <class T>
void Aplicacion<T>::print_for_code()
{
    Nodo<Record> * temp = Cursos->m_record.head;
    //years
    std::vector<char*> first_year;
    std::vector<char*> second_year;
    std::vector<char*> third_year;
    std::vector<char*> forth_year;
    std::vector<char*> fifth_year;
    char *year;
    while(temp!=nullptr)
    {
        year = year_key((temp->dato).key);
        switch(*year)
        {
        case '1':
            first_year.push_back((temp->dato).key);
            break;
        case '2':
            second_year.push_back((temp->dato).key);
            break;
        case '3':
            third_year.push_back((temp->dato).key);
            break;
        case '4':
            forth_year.push_back((temp->dato).key);
            break;
        case '5':
            fifth_year.push_back((temp->dato).key);
            break;
        }
        temp = temp->sig;
    }
    cout << "IMPRIMIENDO POR AÑOS: " << endl;
    cout << "--------------------First Year ------------------- " <<endl;
    for(std::vector<char*>::iterator tem = first_year.begin(); tem != first_year.end();tem++)
    {
        Cursos->GetRecord(*tem);
    }
    cout << "--------------------Second year ------------------" <<endl;
    for(std::vector<char*>::iterator tem = second_year.begin(); tem != second_year.end();tem++)
    {
        Cursos->GetRecord(*tem);
    }
    cout << "--------------------third year ------------------" <<endl;
    for(std::vector<char*>::iterator tem = third_year.begin(); tem != third_year.end();tem++)
    {
        Cursos->GetRecord(*tem);
    }
    cout << "--------------------fourth year ------------------" <<endl;
    for(std::vector<char*>::iterator tem = forth_year.begin(); tem != forth_year.end();tem++)
    {
        Cursos->GetRecord(*tem);
    }
    cout << "--------------------fifth year ------------------" <<endl;
    for(std::vector<char*>::iterator tem = fifth_year.begin(); tem != fifth_year.end();tem++)
    {
        Cursos->GetRecord(*tem);
    }


}
#endif // APP_H
