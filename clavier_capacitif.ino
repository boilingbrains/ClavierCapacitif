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
  //Keyboard.begin();
  Serial.begin(9600);
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
      Keyboard.press(KEY_LEFT_LEFT);
      delay(50);
      Keyboard.release(KEY_LEFT_ARROW);

      //Keyboard.press('t'); //Si on veut appuyer sur une touche correspondant à une lettre
      //delay(50);
      //Keyboard.release('t');
    }

    if (cs2_read >= threshold)
    {
      Keyboard.press(KEY_UP_ARROW);
      delay(50);
      Keyboard.release(KEY_UP_ARROW);

      //Keyboard.press('y'); //Si on veut appuyer sur une touche correspondant à une lettre
      //delay(50);
      //Keyboard.release('y');
    }

    if (cs3_read >= threshold)
    {
      Keyboard.press(KEY_DOWN_ARROW);
      delay(50);
      Keyboard.release(KEY_DOWN_ARROW);

      //Keyboard.press('u'); //Si on veut appuyer sur une touche correspondant à une lettre
      //delay(50);
      //Keyboard.release('u');
    }

    if (cs4_read >= threshold)
    {
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(50);
      Keyboard.release(KEY_RIGHT_ARROW);

      //Keyboard.press('i'); //Si on veut appuyer sur une touche correspondant à une lettre
      //delay(50);
      //Keyboard.release('i');
    }

    delay(100);
  }
}

/*void loop() { //Loop pour afficher les valeurs dans le moniteur série
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
