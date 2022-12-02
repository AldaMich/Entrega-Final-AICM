#ifndef CLIENTE_H
#define CLIENTE_H

#include "Reserva.h"

class Cliente
{
    public:
        // 3 constructores
        Cliente();
        Cliente(string, string);
        Cliente(string, string, float, float);

        virtual ~Cliente();

        // Métodos sets y gets
        void setNombre(string);
        string getNombre();

        void setId(string);
        string getId();

        void setKilometros(float);
        float getKilometros();

        void setDinero(float);
        float getDinero();

        void setReserva(Reserva);
        Reserva getReserva();
        void setDatos(string, string, float, float);

    protected:

    private:
        // Atributos privados
        string nombre;
        string id;
        float kilometros_recorridos;
        float dinero;
        Reserva reserva;
};

#endif // CLIENTE_H
