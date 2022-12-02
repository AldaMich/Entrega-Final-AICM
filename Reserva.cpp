#include "Reserva.h"

// Constructor por defecto
Reserva::Reserva()
{
    id_reserva = "No definido";
    id_vuelo = "No definido";
    asiento = {"Ninguno"};
    precio = 0;
}

// Constructor con cobrecarga 1
Reserva::Reserva(string x){
    id_cliente = x;
}

// Constructor con cobrecarga 2
Reserva::Reserva(string x, string y, string z, vector<string> w){
    id_reserva = x;
    id_cliente = y;
    id_vuelo = z;
    asiento = w;
}

Reserva::~Reserva()
{
    //dtor
}

// Método set de el id de la reserva
void Reserva::setIdReserva(string x){
    id_reserva = x;
}

// Método get del id de la reserva
string Reserva::getIdReserva(){
    return id_reserva;
}

// Método set del id del cliente
void Reserva::setIdCliente(string x){
    id_cliente = x;
}

// Método get del id del cliente
string Reserva::getIdCliente(){
    return id_cliente;
}

// Método set del id del vuelo
void Reserva::setIdVuelo(string x){
    id_vuelo = x;
}

// Método get del id del vuelo
string Reserva::getIdVuelo(){
    return id_vuelo;
}

// Método set de los asientos
void Reserva::setAsiento(vector<string> x){
    asiento = x;
}

// Método get de los asientos
vector<string> Reserva::getAsiento(){
    return asiento;
}

// Método set del precio a pagar
void Reserva::setPrecio(float x){
    precio = x;
}

// Método get del precio a pagar
float Reserva::getPrecio(){
    return precio;
}

// Este método te ayuda a buscar vuelos dependiendo de los filtros dados
void Reserva::buscarVuelo(vector<Vuelo> v){ // Se va a ingresar desde main un vector con todos los vuelos que hay

    int cantidad_filtros;
    string aerolinea;
    string fecha;
    string destino;
    int disponibilidad = -1;
    float sup_precio = -1;  // Límite superior del precio
    vector<Vuelo> seleccion;
    int tamano = v.size();

    cout << "Bienvenido al menu para buscar vuelos :).\n ¿De acuerdo a que quieres buscar tu vuelo?" << endl
            << "1. Aerolinea" << endl
                << "2. Fecha" << endl
                    << "3. Disponibilidad" << endl
                        << "4. Precio" << endl
                            << "5. Destino" << endl
                            << "Ingresa la cantidad de filtros que vas a usar: " << endl;
    cin >> cantidad_filtros;

    for (int i = 0; i < cantidad_filtros; i++){
        int x;
        cout << "Ingresa el " << i + 1 << " filtro: ";
        cin >> x;
        cout << "\n";
        switch(x)
        {
            case 1:
                // Aerolinea
                cout << "Ingresa la aerolinea con las que deseas viajar: ";
                cin >> aerolinea;
                cout << endl;
                break;

            case 2:
                // Fecha
                cout << "Ingresa la fecha en la que deseas viajar en formato dd/mm/aaaa: ";
                cin >> fecha;
                cout << endl;
                break;

            case 3:
                // Disponibilidad
                cout << "Ingresa la cantidad de asientos que necesitas: ";
                cin >> disponibilidad;
                cout << endl;
                break;

            case 4:
                // Precio
                cout << "Ingresa el precio maximo del vuelo: ";
                cin >> sup_precio;
                cout << endl;
                break;

            case 5:
                // Destino
                cout << "Ingresa el destino del vuelo: ";
                cin >> destino;
                cout << endl;
                break;
        }
    }


    // Buscar y desplegar vuelos con esas características
    cout << "Estos son los algunas especificaciones de los vuelos con las especificaciones dadas: " << endl;

    cout << "Id del vuelo, "
                    << "Aerolinea, "
                        << "Fecha, "
                            << "Hora de salida, "
                                << "Numero de asientos disponibñes, "
                                    << "Precio, "
                                        << "Destino" << endl;

    for (int i = 0; i < tamano; i++){

        string aero = v[i].getAerolinea();
        string fe = v[i].getFecha();
        string desti = v[i].getDestino();
        int dispo = v[i].getDisponibilidad();
        float sup_pre = v[i].getPrecio();

        if ((aero == aerolinea || aerolinea.empty()) && (fe == fecha || fecha.empty()) && (desti == destino || destino.empty()) && (dispo >= disponibilidad || disponibilidad == -1) && (sup_pre <= sup_precio || sup_precio == -1)){
            cout << v[i].getIdVuelo() << ", "
                    << v[i].getAerolinea() << ", "
                        << v[i].getFecha() << ", "
                            << v[i].getHoraSalida() << ", "
                                << v[i].getDisponibilidad() << ", "
                                    << v[i].getPrecio() << ", "
                                        << v[i].getLugarSalida() << ", "
                                            << v[i].getDestino() << endl;
        }
    }
    cout << "Si ya escogiste el avion que quieres reservar, copia su id." << endl;
}

// Este método regresa todos los detalles del vuelo escogido
void Reserva::detallesVuelo(vector<Vuelo> v){
    string id_vuelo;
    int tamano = v.size();

    cout << "Dame el id del vuelo del que quieres ver los detalles: ";
    cin >> id_vuelo;

    for (int i = 0; i < tamano; i++){
        if(v[i].getIdVuelo() == id_vuelo){
            cout << "Id del vuelo: " << v[i].getIdVuelo() << endl
                    << "Numero de vuelo: " << v[i].getNumVuelo() << endl
                        << "Lugar de salida: " << v[i].getLugarSalida() << endl
                            << "Destino: " << v[i].getDestino() << endl
                                << "Aerolinea: " << v[i].getAerolinea() << endl
                                    << "Fecha: " << v[i].getFecha() << endl
                                        << "Hora de salida: " << v[i].getHoraSalida() << endl
                                            << "Precio: $" << v[i].getPrecio() << endl
                                                << "Duracion: " << v[i].getDuracion() << " minutos\n"
                                                    << "Kilometros a recorrer: " << v[i].getKilometros() << " km\n"
                                                        << "Cantidad de asientos disponibles: " << v[i].getDisponibilidad() << endl;
            v[i].verAsientosDisponibles();

        }
    }
}

// Este método reserva un vuelo, devuelve los km recorridos y el precio del viaje
vector<float> Reserva::reservarVuelo(vector<Vuelo> v, float km, float money){ // eliminar los asientos resrrvados con el método insert.
    vector<float> datos; // km, dinero
    string id_vuelo;
    int tamano = v.size();
    int cantidad_asientos;
    string asientos;
    string respuesta;
    int disponibilidad;

    cout << "Dame el id del vuelo que quieres reservar: ";
    cin >> id_vuelo;

    // Loop para  iterar vector de vuelos
    for (int i = 0; i < tamano; i++){
        // Escoger el vuelo
        if(v[i].getIdVuelo() == id_vuelo){
            disponibilidad = v[i].getDisponibilidad();
            if (disponibilidad == 0){
                cout << "Lo sentimos, no puedes reservar, el vuelo esta lleno.\n";
            }
            else{
                datos.push_back(v[i].getKilometros());

                cout << "¿Cuantos asientos quieres reservar? ";
                cin >> cantidad_asientos;

                precio = cantidad_asientos * v[i].getPrecio();
                if (km > 50000){
                    precio *= 0.6;
                    cout << "Felicidades, como haz recorrido " << km << " te daremos un 40% de descuento.";
                }

                cout << "La cantidad a pagar es de $" << precio << ".\n";
                cout << "Deseas comprar los asientos (si/no): ";
                cin >> respuesta;

                while (respuesta != "si" && respuesta != "no"){
                    cout << "Respuesta invalida.\nDeseas comprar los asientos (si/no): ";
                    cin >> respuesta;
                }

                if (respuesta == "si"){
                    if (money < precio){
                        cout << "No tienes fondos suficientes. Lo sentimos :(.\n";
                    }
                    else{
                        datos.push_back(money - precio);
                        for (int j = 0; j < cantidad_asientos; j++){
                            id_vuelo = v[i].getIdVuelo();
                            cout << "Dame el identificador del asiento " << j + 1 << " a reservar: ";
                            cin >> asientos;
                            v[i].cambiarDisponibilidad(asientos, false);
                            asiento.push_back(asientos);
                        }
                        v[i].verAsientosDisponibles();
                        cout << "Tu reserva fue un exito, gracias por confiar en nosotros. :)\n";
                    }
                }
                else{
                    cout << "Esperamos la proxima si puedas reservar con nosotros :)." << endl;
                }
            }
        }
    }
    if (respuesta.empty()){
        cout << "Lo sentimos, el id es invalido. Vuelve a intentarlo\n";
    }

    return datos;
}

// Este método cancela una reserva
vector<float> Reserva::cancelarReserva(vector<Vuelo> v){ // poner en true los asientos que se había reservado
    vector <float> datos;
    string id_vuelo;
    int tamano = v.size();
    int cantidad_asientos = asiento.size();

    cout << "Dame el id del vuelo del que quieres cancelar la reserva: ";
    cin >> id_vuelo;

    // Loop para iterar vector de vuelos
    for (int i = 0; i < tamano; i++){

        // Escoger el vuelo
        if(v[i].getIdVuelo() == id_vuelo){
            datos.push_back(v[i].getKilometros());

            for (int i = 0; i < cantidad_asientos; i++){
                v[i].cambiarDisponibilidad(asiento[i], true);
            }

            datos.push_back(precio);

            cout << "Ya hemos cancelado tu reserva." << endl;
        }
    }
    return datos;
}


