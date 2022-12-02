#ifndef VUELO_H
#define VUELO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

class Vuelo
{
    public:

        // 2 constructores
        Vuelo();
        Vuelo(string, float, string, string, string, string, string, float, float, map<string, bool>, float);

        virtual ~Vuelo();

        // métodos sets y gets
        void setIdVuelo(string);
        string getIdVuelo();

        void setNumVuelo(float);
        float getNumVuelo();

        void setAerolinea(string);
        string getAerolinea();

        void setFecha(string);
        string getFecha();

        void setHoraSalida(string);
        string getHoraSalida();

        int getDisponibilidad();

        void setLugarSalida(string);
        string getLugarSalida();

        void setDestino(string);
        string getDestino();

        void setPrecio(float);
        float getPrecio();

        void setDuracion(float);
        float getDuracion();

        void setAsientos(map<string, bool>);
        map<string, bool> getAsientos();

        void setKilometros(float);
        float getKilometros();

        void verAsientosDisponibles(); // Permite ver cuántos y cuáles asientos estan libres en un avión
        void cambiarDisponibilidad(string, bool); // Permite cambiar la disponibilidad de los asientos
        void setDatos(string, float, string, string, string, string, string, float, float, float, map<string, bool>);

    protected:

    private:

        // Atributos privados
        string id_vuelo;
        float num_vuelo;
        string aerolinea;
        string fecha;
        string hora_salida;
        float kilometros_recorridos;
        bool disponibilidad; // Indica si hay almenos 1 asiento disponible
        string lugar_salida;
        string destino;
        float precio; // Por asiento
        float duracion;
        map<string, bool> asientos; // Mapa que indica el id del asiento y si esta disponible o no
        map<string, bool>::iterator i; // Iterador del mapa asientos
};

#endif // VUELO_H
