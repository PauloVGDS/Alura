#pragma once
#include <string>

struct Sensor {
    std::string nome;
    int pino;
    float valor;
};

class SensorClasse {
    std::string nome;
    int pino;
    float valor;

public:
    SensorClasse(const std::string& nome_sensor, int pino_sensor) :
        nome(nome_sensor), pino(pino_sensor), valor(0.f) {
    }
    SensorClasse():
    nome("Sensor"), pino(-1), valor(0.f) {
    }

    void exibir() const;
    float getValor() const;
    void setValor(float val);

};

void exibirSensor(const Sensor& sensor);
