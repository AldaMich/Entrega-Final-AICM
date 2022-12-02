#include "Vuelo.h"

// Constructor por defecto
Vuelo::Vuelo()
{
    id_vuelo = "Sin Id";
    num_vuelo = 0.0;
    aerolinea = "No definida";
    disponibilidad = true;
    destino = "Sin destino";
    fecha = "No definida";
    precio = 0.0;
    duracion = 0.0;
    asientos[0] = true;
    kilometros_recorridos = 0.0;
}

// Constructor con sobrecarga
Vuelo::Vuelo(string id_v, float num_v, string aero, string sal, string dest, string fec, string h, float prec, float dura, map<string, bool> asien, float km){
    id_vuelo = id_v;
    num_vuelo = num_v;
    aerolinea = aero;
    lugar_salida = sal;
    destino = dest;
    hora_salida = h;
    fecha = fec;
    precio = prec;
    duracion = dura;
    asientos = asien;
    kilometros_recorridos = km;
}

Vuelo::~Vuelo()
{
    //dtor
}

// Método set del id del vuelo
void Vuelo::setIdVuelo(string x){
    id_vuelo = x;
}

// Método get del id del vuelo
string Vuelo::getIdVuelo(){
    return id_vuelo;
}

// Método set del número de vuelo
void Vuelo::setNumVuelo(float x){
    num_vuelo = x;
}

// Método get del número de vuelo
float Vuelo::getNumVuelo(){
    return num_vuelo;
}

// Método set de la aerolinea
void Vuelo::setAerolinea(string x){
    aerolinea = x;
}

// Método get de la aerolinea
string Vuelo::getAerolinea(){
    return aerolinea;
}

// Método set de la fecha
void Vuelo::setFecha(string x){
    fecha = x;
}

// Método get de la fecha
void Vuelo::setHoraSalida(string x){
    hora_salida = x;
}

// Método set de la fecha
string Vuelo::getHoraSalida(){
    return hora_salida;
}

//Método get de la fecha
string Vuelo::getFecha(){
    return fecha;
}

// Obtiene la cantidad de asientos disponibles
int Vuelo::getDisponibilidad(){
    disponibilidad = false;
    int asientos_disponibles = 0;


    for (i = asientos.begin(); i != asientos.end(); i++){
        bool disponible = i -> second;
        if (disponible == true){
            disponibilidad = true;
            asientos_disponibles ++;
        }
        disponible = i -> second;
    }

    return asientos_disponibles;
}

// Método set del lugar de salida del vuelo
void Vuelo::setLugarSalida(string x){
    lugar_salida = x;
}

// Método get del lugar de salida del vuelo
string Vuelo::getLugarSalida(){
    return lugar_salida;
}

// Método set del destino del vuelo
void Vuelo::setDestino(string x){
    destino = x;
}

// Método get del destino del vuelo
string Vuelo::getDestino(){
    return destino;
}

// Método set del precio del vuelo
void Vuelo::setPrecio(float x){
    precio = x;
}

// Método get del precio del vuelo
float Vuelo::getPrecio(){
    return precio;
}

// Método set de la duración del vuelo en minutos
void Vuelo::setDuracion(float x){
    duracion = x;
}

// Método get de la duración del vuelo en minutos
float Vuelo::getDuracion(){
    return duracion;
}

// Método set de los asientos y su disponibilidad
void Vuelo::setAsientos(map<string, bool> x){
    asientos = x;
}

// Método get de los asientos y su disponibilidad
map<string, bool> Vuelo::getAsientos(){
    return asientos;
}

// Método set de los kilometros por recorrer
void Vuelo::setKilometros(float x){
    kilometros_recorridos = x;
}

// Método get de los kilometros por recorrer
float Vuelo::getKilometros(){
    return kilometros_recorridos;
}

//Despliega los asientos que estan disponibles
void Vuelo::verAsientosDisponibles(){
    vector<string> id_asientos; // Id de asientos diposnibles
    vector<string>::iterator y; // Iterador del vector id_asientos
    int asientos_disponibles = 0;
    disponibilidad = false;

    for (i = asientos.begin(); i != asientos.end(); i++){
        bool disponible = i -> second;

        if (disponible == true){ // ¿Esta disponible?
            disponibilidad = true;
            string x = i -> first;
            id_asientos.push_back(x);
            asientos_disponibles ++;
        }

        disponible = i -> second;
    }

    if (asientos_disponibles == 0){
        cout << "No hay asientos disponibles. Lo sentimos.\n";
    }
    else{

        cout << "Hay un total de " << asientos_disponibles << " asientos disponibles.\nEstos son: " << endl;

        int o = 0;

        for (y = id_asientos.begin(); y != id_asientos.end(); y++){
            cout << y[0] << endl;
            o++;
        }
    }
}

// Método que cambia a disponibilidad de un asiento en concreto
void Vuelo::cambiarDisponibilidad(string x, bool y){
    asientos[x] = y;
}

void Vuelo::setDatos(string id, float num, string aero, string lugar_sal, string desti, string fe, string h, float pre, float dura, float km, map<string, bool> as){
    id_vuelo = id;
    num_vuelo = num;
    aerolinea = aero;
    lugar_salida = lugar_sal;
    destino = desti;
    fecha = fe;
    hora_salida = h;
    precio = pre;
    duracion = dura;
    kilometros_recorridos = km;
    asientos = as;
}
