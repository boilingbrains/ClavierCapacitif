#include <CapacitiveSensor.h>
#include <Keyboard.h>

const int securityPin = 15;
const int threshold = 1000;

CapacitiveSensor cs1 = CapacitiveSensor(2, 3); //send and sense pins A
CapacitiveSensor cs2 = CapacitiveSensor(4, 5); //send and sense pins B
CapacitiveSensor cs3 = CapacitiveSensor(6, 7); //send and sense pins C
CapacitiveSensor cs4 = CapacitiveSensor(8, 9); //send and sense pins D

long cs1_read;
long cs2_read;
long cs3_read;
long cs4_read;

void setup() {
  pinMode(securityPin, INPUT_PULLUP); //On aura 0V sur la pin 15 quand le fil sera branché et 5V quand il sera débranché
  Keyboard.begin();
  //Serial.begin(9600);
}

void loop() {
  if (digitalRead(securityPin) == LOW)
  {
    cs1_read = cs1.capacitiveSensor(30);
    cs2_read = cs2.capacitiveSensor(30);
    cs3_read = cs3.capacitiveSensor(30);
    cs4_read = cs4.capacitiveSensor(30);

    if (cs1_read >= threshold)
    {
      Keyboard.press('a'); //A en QWERTY donne Q en AZERTY
      delayMicroseconds(1);
    }

    else {
      Keyboard.release('a');
      delayMicroseconds(1);
    }

    if (cs2_read >= threshold)
    {
      Keyboard.press('w'); //W en QWERTY donne Z en AZERTY
      delayMicroseconds(1);
    }

    else {
      Keyboard.release('w');
      delayMicroseconds(1);
    }

    if (cs3_read >= threshold)
    {
      Keyboard.press('s'); //S
      delayMicroseconds(1);
    }

    else {
      Keyboard.release('s');
      delayMicroseconds(1);
    }


    if (cs4_read >= threshold)
    {
      Keyboard.press('d'); //D
      delayMicroseconds(1);
    }

    else {
      Keyboard.release('d');
      delayMicroseconds(1);
    }

    delay(100);
  }
}

/*void loop() {
  if (digitalRead(securityPin) == LOW)
  {
    cs1_read = cs1.capacitiveSensor(30);
    cs2_read = cs2.capacitiveSensor(30);
    cs3_read = cs3.capacitiveSensor(30);
    cs4_read = cs4.capacitiveSensor(30);

    Serial.print("Valeur CS1: ");
    Serial.println(cs1_read);
    Serial.print("Valeur CS2: ");
    Serial.println(cs2_read);
    Serial.print("Valeur CS3: ");
    Serial.println(cs3_read);
    Serial.print("Valeur CS4: ");
    Serial.println(cs4_read);
    Serial.println("");

    delay(250);
  }
}*/
