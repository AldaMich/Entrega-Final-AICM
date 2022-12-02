#ifndef RESERVA_H
#define RESERVA_H

#include "Vuelo.h"

class Reserva
{
    public:
        // 3 constructores
        Reserva();
        Reserva(string);
        Reserva(string, string, string, vector<string>);

        virtual ~Reserva();

        // M�todos sets y gets
        void setIdReserva(string);
        string getIdReserva();

        void setIdCliente(string);
        string getIdCliente();

        void setIdVuelo(string);
        string getIdVuelo();

        void setAsiento(vector<string>);
        vector<string> getAsiento();

        void setPrecio(float);
        float getPrecio();

        void buscarVuelo(vector<Vuelo>); // M�todo para buscar vuelos
        void detallesVuelo(vector<Vuelo>); // M�todo para ver los detalles de un vuelo elegido
        vector<float> reservarVuelo(vector<Vuelo>, float, float); // M�todo para reservar un vuelo
        vector<float> cancelarReserva(vector<Vuelo>); // M�todo para cancelar el vuelo

    protected:

    private:
        // Atributos privados
        string id_reserva;
        string id_cliente;
        string id_vuelo;
        vector<string> asiento;
        float precio;
};

#endif // RESERVA_H
