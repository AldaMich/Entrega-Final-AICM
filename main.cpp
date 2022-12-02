/**
Nombre:                 Evidencia 2 Entrega de proyecto integrador
Descripción:            Este código es el proyecto de la materia de Programación Orientada a Objetos.
                        Este es un sistema que es capaz de ingresar datos de clientes y vuelos, para después poder hacer reservas.
                        El cliente es capaz de buscar vuelos dependiendo de ciertos filtros y seleccionar uno de ellos para ver sus
                        detalles y reservar alguno de sus asientos.
Fecha de entrega:       Viernes 1 de diciembre del 2022.
Profesora:              Dra Yuridiana Alemán
Alumnos:                Alda Michelle Sandoval González A01750910
                        Loren Tapia Nieto A01749969
                        Daniel Aguilar Dario A01710975
                        Héctor Andrés Serranía Escamilla A01701740
**/
#include "Cliente.h"

// Esta función lee el archivo txt en donde se encuentra la información de los clientes, recibe un número entero y regresa un objeto de la clase cliente
Cliente leerArchivoCliente(int n){
    // Creación de los objetos de la clase Cliente
    Cliente x;
    string linea, nombre_personas, id_cliente, km_cliente, money_cliente;

    ifstream clientes("Clientes.txt"); // Lectura // Archivo como dato de entrada

    if(clientes.is_open()){ // si el archico esta abierto
        for (int i = 0; i < n; i++){
            getline(clientes,linea);
        }
        getline(clientes,linea); // obten una linea y asignalo a linea
    }
    clientes.close();

    // Asignaciónd e valores
    stringstream cambios(linea);
    getline(cambios, nombre_personas, '/');
    getline(cambios, id_cliente, '/');
    getline(cambios, km_cliente, '/');
    getline(cambios, money_cliente, '/');

    // Creación del objeto
    x.setDatos(nombre_personas, id_cliente, stof(km_cliente), stof(money_cliente));
    return x;
}

int main()
{
    // Bienvenida
    cout << "Bienvenido al sistema" << endl;

    // Creación de clientes desde archivos txt
    Cliente cliente1 = leerArchivoCliente(1);
    Cliente cliente2 = leerArchivoCliente(2);
    Cliente cliente3 = leerArchivoCliente(3);
    Cliente cliente4 = leerArchivoCliente(4);
    Cliente cliente5 = leerArchivoCliente(5);
    Cliente cliente6 = leerArchivoCliente(6);
    Cliente cliente7 = leerArchivoCliente(7);

    // Creación de objetos de la clase Vuelo desde archivos txt
    map <string, bool>mapa1;
    mapa1["A1"] = false;
    mapa1["A2"] = true;
    mapa1["A3"] = false;
    mapa1["A4"] = true;
    mapa1["A5"] = false;
    Vuelo vuelo1("IS55TF34", 1, "MimiAero", "Monterrey", "Ciudad de Mexico", "05/12/2022", "5:15 p.m", 2500.5, 120, mapa1, 1541521);

    map <string, bool>mapa2;
    mapa2["A1"] = true;
    mapa2["A2"] = true;
    mapa2["A3"] = false;
    mapa2["A4"] = false;
    mapa2["A5"] = false;
    Vuelo vuelo2("IT456F34", 2, "Interjet", "Ciudad de Mexico", "Washington D. C.", "24/12/2022", "10:15 a.m", 10700.25, 300, mapa2, 46545);

    map <string, bool>mapa3;
    mapa3["A1"] = false;
    mapa3["A2"] = false;
    mapa3["A3"] = false;
    mapa3["A4"] = false;
    mapa3["A5"] = true;
    Vuelo vuelo3("IVX45O56", 3,"Volaris","Ciudad de Mexico","Cancun","10/01/2023","6:45 p.m",4200.42,200, mapa3, 4125);

    map <string, bool>mapa4;
    mapa4["A1"] = true;
    mapa4["A2"] = true;
    mapa4["A3"] = true;
    mapa4["A4"] = true;
    mapa4["A5"] = true;
    Vuelo vuelo4("IVX45O75", 4,"Volaris","Ciudad de Mexico","Cancun","10/01/2023","12:05 p.m",2350,200, mapa4, 4125);

    map <string, bool>mapa5;
    mapa5["A1"] = false;
    mapa5["A2"] = false;
    mapa5["A3"] = false;
    mapa5["A4"] = false;
    mapa5["A5"] = false;
    Vuelo vuelo5("IVX45O15", 5,"Volaris","Ciudad de Mexico","Cancun","10/01/2023","11:15 a.m",3500.5,200, mapa5, 4125);

    map <string, bool>mapa6;
    mapa6["A1"] = true;
    mapa6["A2"] = false;
    mapa6["A3"] = true;
    mapa6["A4"] = false;
    mapa6["A5"] = false;
    Vuelo vuelo6("IQERXO72", 6,"Interjet","Cancun","Paris","02/02/2023","5:00 p.m",11700,500, mapa6, 541241);

    map <string, bool>mapa7;
    mapa7["A1"] = false;
    mapa7["A2"] = true;
    mapa7["A3"] = true;
    mapa7["A4"] = true;
    mapa7["A5"] = false;
    Vuelo vuelo7("IQEUGB672", 7,"MimiAero","Acapulco","Monterrey","18/12/2022","7:45 p.m",4000,160, mapa7, 3165);

    // Creación de un vector con todos los vuelos
    vector<Vuelo> vuelos_programados;
    vuelos_programados.push_back(vuelo1);
    vuelos_programados.push_back(vuelo2);
    vuelos_programados.push_back(vuelo3);
    vuelos_programados.push_back(vuelo4);
    vuelos_programados.push_back(vuelo5);
    vuelos_programados.push_back(vuelo6);
    vuelos_programados.push_back(vuelo7);


    // Inicio del programa
    cout << "Como eres nuevo usuario, danos tu nombre para registrarte: ";
    string nombre_cliente;
    getline(cin, nombre_cliente);
    string id = "AJPI52216";
    Reserva reserva1("AJPI52216"); // Creación de un objeto de la clase Reserva
    Cliente cliente_nuevo(nombre_cliente, id); // Creción de un nuevo objeto de la clase Cliente
    cliente_nuevo.setReserva(reserva1); // Registro de la reserva del nuevo cliente
    cout << "\nEste es tu id " << id << ". Guardalo." << endl;
    cout << "\nTiempo despues del registro de este usuario. Ahora tiene 75000 km recorridos y 10000 pesos en su cuenta.\n";
    cliente_nuevo.setKilometros(75000); // Cantidad de km recorridos
    cliente_nuevo.setDinero(10000); // Cantidad de dinero en su cuenta

    reserva1.buscarVuelo(vuelos_programados); // Buscar buelos por medio de filtros
    reserva1.detallesVuelo(vuelos_programados); // Ver detalles de 1 vuelo elegido
    vector<float> datos = reserva1.reservarVuelo(vuelos_programados, cliente_nuevo.getKilometros(), cliente_nuevo.getDinero()); // Reserva de los asientos

    reserva1.cancelarReserva(vuelos_programados);
    vuelo4.verAsientosDisponibles();

}
