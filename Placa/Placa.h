#pragma once
#include <string>

struct Sensor {
    std::string nome;
    int pino;
    float valor;
};

class Sensores {
    std::string nome;
    int pino;
    float valor;

public:
    Sensores(std::string nome_sensor, int pino_sensor, float valor_sensor) :
        nome(nome_sensor), pino(pino_sensor), valor(valor_sensor) {
    };
    // ~Sensores() {};
    void exibir() const;
    float getValor() const;
    void setValor(float val);

};

void exibirSensor(Sensor& sensor);
