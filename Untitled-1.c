#include <wiringPi.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;
#define reset 16;
#define bot 7;
#define Lectura 6;
#define RGBverde 22 //pin verde patilla de RGB ANALOG OUTPUT
#define RGBrojo 23; //pin rojo patilla de RGB ANALOG OUTPUT
#define RGBazul 4;  //pin azul patilla de RGB ANALOG OUTPUT
#define piston 27;  //pin activa el piston para parar la botella
//#define piston_open  3;  //piston abierto DIG INPUT
//#define piston_closed  4;  //piston cerrado DIG INPUT
//#define sensor_pres_prod  5; // es uns ensor quie detecta cuando el producto esta en su posicion
//int sensorState = 0, lastState = 0;

int productos_bbdd = 0; //este valor lo vamos a coger de la base de datos.
int cont_prod_ope = 0;  //Este es el valor que el operario ha insertado
string texto_error = "has hecho muchos intentos de lectura fallidos, porfavor pulse el boton de reset para poder volver a intentar la lectura del qr";
string texto_okey = "OK";

int main()
{

    wiringPiSetupGpio();

    pinMode(RGBverde, OUTPUT);
    pinMode(RGBrojo, OUTPUT);
    pinMode(RGBazul, OUTPUT);
    pinMode(piston, OUTPUT);
    pinMode(reset, INPUT);
    pinMode(Lectura, INPUT);
    pinMode(bot, INPUT);

    digitaWrite(piston, LOW);
    analogWrite(RGBverde, 0);
    analogWrite(RGBazul, 0);
    analogWrite(RGBrojo, 0);
    digitaRead(reset, LOW);
    digitaRead(Lectura, LOW);
    digitaRead(bot, LOW);
if
    int i = 0;
    if (cont_prod_ope == productos_bbdd)
    {
        if (Lectura == HIGH)
        {
            digitalWrite(piston, HIGH); //cerramos piston
            analogWrite(RGBverde, 255); //encendemos la luz en verde
            analogWrite(RGBazul, 0);    // apagamos la luz roja
            analogWrite(RGBrojo, 0);    // apagamos la luz azul

            y = y + 1; //sumamos una unidad a la cantidad de productos.
        }
        else
        {

            digitalWrite(piston, LOW);
            analogWrite(RGBverde, 0);
            analogWrite(RGBazul, 0);
            analogWrite(RGBrojo, 255);

            i = i + 1;
            texto_error;
        }
    }
}