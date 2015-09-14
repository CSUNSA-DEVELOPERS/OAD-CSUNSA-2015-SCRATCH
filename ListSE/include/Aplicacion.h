#ifndef APLICACION_H
#define APLICACION_H
#include "Table.h"

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
};

Aplicacion::Aplicacion()
{
    Cursos = new Table<Record>("data.dat");
    Requisitos = new Table<Record>("Prerequisitos.dat");
}


#endif // APLICACION_H
