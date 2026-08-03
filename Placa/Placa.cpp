#include "Placa.h"
#include <iostream>

void SensorClasse::exibir() const {
    std::cout << "Informações de " << nome << std::endl;
    std::cout << "Pino: " << pino << std::endl;
    std::cout << "Valor atual: " << valor << std::endl;
}

float SensorClasse::getValor() const {
    return valor;
}

void SensorClasse::setValor(float val) {
    if (val < -50 || val > 150) {
        std::cout << "Valor Inválido!" << std::endl;
        return;
    }
    valor = val;
}


void exibirSensor(const Sensor& sensor) {
    std::cout << "Informações de " << sensor.nome << std::endl;
    std::cout << "Pino: " << sensor.pino << std::endl;
    std::cout << "Valor atual: " << sensor.valor << std::endl;
}