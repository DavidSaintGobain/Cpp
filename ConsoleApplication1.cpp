#include <wiringPi.h>
#include <unistd.h>

#define RGBverde  0;  //pin verde patilla de RGB ANALOG OUTPUT
#define RGBrojo  1;  //pin rojo patilla de RGB ANALOG OUTPUT
#define RGBazul  2;  //pin azul patilla de RGB ANALOG OUTPUT
#define piston_open  3;  //piston abierto DIG INPUT 
#define piston_closed  4;  //piston cerrado DIG INPUT
#define sensor_pres_prod  5; // es uns ensor quie detecta cuando el producto esta en su posicion
int sensorState = 0, lastState = 0;

int cont_prod_prog = 0; //Este lo define el programa base 
int cont_prod_ope = 0; //Este es el valor que el operario ha insertado 



int main() {
    wiringPiSetupGpio();
    PinMode();
    Proceso();
}

void PinMode() {

    pinMode(RGBverde, OUTPUT);
    pinMode(RGBrojo, OUTPUT);
    pinMode(RGBazul, OUTPUT);
    pinMode(piston_open, INPUT);
    pinMode(piston_closed, INPUT);
    pinMode(sensor_pres_prod, INPUT);
    digitalWrite(piston_open, HIGH);
    digitalWrite(piston_closed, LOW);
    digitalWrite(sensor_pres_prod, HIGH);
}

void Proceso() {
    if (sensor_pres_prod == LOW){

        tirgger;

    else {
        !trigger;
    }

}
}