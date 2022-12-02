#include "Cliente.h"

// Constructor por defecto
Cliente::Cliente()
{
    nombre = "Sin Nombre";
    id = "Sin Identificacion";
}

// Constructor con sobrecarga 1
Cliente::Cliente(string x, string y)
{
    nombre = x;
    id = y;
}

// Constructor con sobrecarga 2
Cliente::Cliente(string x, string w, float y, float p){
    nombre = x;
    id = w;
    kilometros_recorridos = y;
    dinero = p;
}

Cliente::~Cliente()
{
    //dtor
}

// M�todo set del nombre
void Cliente::setNombre(string x){
    nombre = x;
}

// M�todo get del nombre
string Cliente::getNombre(){
    return nombre;
}

// M�todo set del id
void Cliente::setId(string x){
    id = x;
}

// M�todo get del id
string Cliente::getId(){
    return id;
}

// M�todo set de la cantidad de kilometros recorridos
void Cliente::setKilometros(float x){
    kilometros_recorridos = x;
}

// M�todo get de la cantidad de kilometros recorridos
float Cliente::getKilometros(){
    return kilometros_recorridos;
}

// M�todo set de la cantidad de dinero disponible en la cuenta del cliente
void Cliente::setDinero(float x){
    dinero = x;
}

// M�todo get de la cantidad de dinero disponible en la cuenta del cliente
float Cliente::getDinero(){
    return dinero;
}

// M�todo set de la reserva
void Cliente::setReserva(Reserva x){
    reserva = x;
}

// M�todo get de la reserva
Reserva Cliente::getReserva(){
    return reserva;
}

void Cliente::setDatos(string x, string y, float z, float w){
    nombre = x;
    id = y;
    kilometros_recorridos = z;
    dinero = w;
}
