#include <wiringPi.h>
#include <unistd.h>
#include <string.h>
#include <iostream> 
#include <cstring>
using namespace std;

#define RGBverde 22  //pin verde patilla de RGB ANALOG OUTPUT
#define RGBrojo  23; //pin rojo patilla de RGB ANALOG OUTPUT
#define RGBazul  4;  //pin azul patilla de RGB ANALOG OUTPUT
#define piston 27;   //pin activa el piston para parar la botella 
//#define piston_open  3;  //piston abierto DIG INPUT 
//#define piston_closed  4;  //piston cerrado DIG INPUT
//#define sensor_pres_prod  5; // es uns ensor quie detecta cuando el producto esta en su posicion
//int sensorState = 0, lastState = 0;

int productos_bbdd = 0;//este valor lo vamos a coger de la base de datos.
int cont_prod_ope = 0; //Este es el valor que el operario ha insertado 
string texto_error;
string texto_info;
string texto_name;
string texto_type;
string texto_id;


int main() {
    
    wiringPiSetupGpio();
    PinMode();
    Proceso(productos_bbdd);
}

void PinMode() {

    pinMode(RGBverde, OUTPUT);
    pinMode(RGBrojo, OUTPUT);
    pinMode(RGBazul, OUTPUT);
  //  pinMode(piston_open, INPUT);
  //  pinMode(piston_closed, INPUT);
    pinMode(piston, OUTPUT);
  // pinMode(sensor_pres_prod, INPUT);


    //digitalRead(piston_open, HIGH);
   // digitalRead(piston_closed, LOW);
    //digitalRead(sensor_pres_prod, HIGH);
    digitaWrite(piston, LOW);
    analogWrite(RGBverde, 0);
    analogWrite(RGBazul, 0);
    analogWrite(RGBrojo, 0);

}

void Proceso(int productos_bbdd) {
    if (sensor_pres_prod == LOW) {

        tirgger;
        Comprobar_lectura(productos_bbdd);

    else {
        !trigger;
    }

    }

    void Comprobar_lectura(int productos_bbdd)
    {
        int i = 0;
        if (cont_prod_ope == productos_bbdd)
        {
            if (Lectura)
            {
                digitalWrite(piston, HIGH);//cerramos piston
                analogWrite(RGBverde, 255);//encendemos la luz en verde
                analogWrite(RGBazul, 0);// apagamos la luz roja
                analogWrite(RGBrojo, 0);// apagamos la luz azul
                !trigger;//paramos de hacer trigger
                         //texto de okey
                y = y + 1;//sumamos una unidad a la cantidad de productos.

            }
            else
            {

                if (i = 3)
                {
                    //mensaje de error y de comprobacion del estado de la maquina
                    //hay que pulsar el boton reset para entrar de nuevo a la lectura del producto.
                    if (boton_reset) {
                        Comprobar_lectura();
                    }
                }
                else
                {
                    digitalWrite(piston, LOW);
                    analogWrite(RGBverde, 0);
                    analogWrite(RGBazul, 0);
                    analogWrite(RGBrojo, 255);
                    trigger;
                    i = i + 1;
                    //texto de nok
                }
            }
        }

    }


}