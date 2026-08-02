#include "Placa.h"
#include <iostream>

void Sensores::exibir() const {
    std::cout << "Informações de " << nome << std::endl;
    std::cout << "Pino: " << pino << std::endl;
    std::cout << "Temperatura atual: " << valor << std::endl;
}

float Sensores::getValor() const {
    return valor;
}

void Sensores::setValor(float val) {
    if (!(val > -50 && val < 150)) {
        std::cout << "Valor Inválido!" << std::endl;
        return;
    }
    valor = val;
}


void exibirSensor(Sensor& sensor) {
    std::cout << "Informações de " << sensor.nome << std::endl;
    std::cout << "Pino: " << sensor.pino << std::endl;
    std::cout << "Temperatura atual: " << sensor.valor << std::endl;
}