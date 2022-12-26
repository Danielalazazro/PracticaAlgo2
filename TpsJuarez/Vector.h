
//
#ifndef TPSJUAREZ_VECTOR_H
#define TPSJUAREZ_VECTOR_H
#include <string>
template<class T> class Vector {
private:
    T * datos;
    int longitud;

public:

    /**
     * pre: la longitud es mayor o igual a 1. Y el dato inicial puede ser NULL si es un puntero
     * pos: deja un vector con las posiciones solicitadas
     */
    Vector(int longitud, T datoInicial) {
        if (longitud < 1) {
            throw "La longitud debe ser mayor o igual a 1";
        }
        this->datos = new T[longitud];
        this->longitud = longitud;
        for(int i = 0; i < this->longitud; i++){
            this->datos[i] = datoInicial;
        }
    }

    /**
     * pre:
     * post: libera la memoria
     */
    virtual ~Vector() {
        delete [] this->datos;
    }

    /**
     * pre:
     * post: devuelve la longitud actual del vector
     */
    int getLongitud() {
        return this->longitud;
    }

    /**
     * pre: la posicion esta entre 1 y n (inclusive)
     * pos: guarda el dato en la posicion indicada, sino devuelve error
     */
    void agregar(int posicion, T dato) {
        //std::string posicion1= std::to_string(posicion);
        //std::string longitud1 = std::to_string(this->longitud);
        if ((posicion < 1) || (posicion > this->longitud)) {
            throw "La " +  std::to_string(posicion)  + " no esta en el rango 1 y " + std::to_string(this->longitud) + " inclusive";
        }
        this->datos[posicion - 1] = dato;
    }

    /**
     * pre: la posicion esta entre 1 y n (inclusive)
     * pos: guarda el dato en la posicion indicada, sino devuelve error
     */
    T& obtener(int posicion) {
        if ((posicion < 1) ||
            (posicion > this->longitud)) {

            throw "La " + std::to_string(posicion) + " no esta en el rango 1 y " + std::to_string(this->longitud) + " inclusive";
        }
        return this->datos[posicion - 1];
    }
};

#endif //TPSJUAREZ_VECTOR_H
