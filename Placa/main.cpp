#include <iostream>
#include "Placa.h"


int main()
{
    std::cout << std::endl << "Utilizando STRUCTS" << std::endl;
    Sensor sensor1;
    sensor1.nome = "Temperatura";
    sensor1.pino = 18;
    sensor1.valor = 38.8;

    Sensor sensor2;
    sensor2.nome = "Humidade";
    sensor2.pino = 19;
    sensor2.valor = 57.4;

    exibirSensor(sensor1);
    exibirSensor(sensor2);

    std::cout << std::endl << "Utilizando Classes" << std::endl;

    Sensores sensor3("Luminosidade", 20, 78.0);
    Sensores sensor4("Pressão", 21, 19.3);

    sensor3.exibir();
    sensor4.exibir();

    sensor3.setValor(44);
    std::cout << std::endl << "Valor do Sensor 3: " << sensor3.getValor() << std::endl;


}

