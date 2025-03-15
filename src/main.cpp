#include <Arduino.h>
int volup = 6;   //11 10
int vold = 5;    //21 20
int up = 8;      //31 30
int dow = 7;     //41 40
int mod = 9;     // 51
//int vklbt = 7;  //61 60 не используется в текущем проекте
int volup0 = 4; // 
int vold0 = 3;   //71 70 не используется в текущем проекте
int upv0 = 15;     //81 80
int dowv0 = 16;   //91 90
int set0 = 2;   //201 p/p
int set = 10; //disc up
//bool swmod = true;

void setup() {
Serial.begin(9600);
//pinMode(volup, OUTPUT);
//pinMode(vold, OUTPUT);
pinMode(up, OUTPUT);
pinMode(dow, OUTPUT);
pinMode(volup0, OUTPUT);
pinMode(vold0, OUTPUT);
pinMode(upv0, OUTPUT);
pinMode(dowv0, OUTPUT);
//pinMode(vklbt, OUTPUT);
//pinMode(mod, OUTPUT);
pinMode(set0, OUTPUT);
//pinMode(set, OUTPUT);
Serial.setTimeout(10);
}

void loop() {
//Serial.println("lightning");
  if (Serial.available()) {
    int val = Serial.parseInt();
    Serial.println(val);
    switch (val) {
          case 11:                     //disk
            pinMode(set, OUTPUT);
            delay(150);
            pinMode(set, INPUT);
            digitalWrite(set, LOW);
            break;
          case 12:                    //volup
            pinMode(volup, OUTPUT);
            delay(150);
            pinMode(volup, INPUT);
            digitalWrite(volup, LOW);
            break;
          case 13:                    //vold 3ch
            pinMode(vold, OUTPUT);
            delay(150);
            pinMode(vold, INPUT);
            digitalWrite(vold, LOW);
          break;
          case 15:                    // up 7ch
            pinMode(up, OUTPUT);
            delay(150);
            pinMode(up, INPUT);
            digitalWrite(up, LOW);
          break;
          case 14:                     //down 5ch
            pinMode(dow, OUTPUT);
            delay(150);
            pinMode(dow, INPUT);
            digitalWrite(dow, LOW);
          break;
          case 16:                    //mode 1ch
            pinMode(mod, OUTPUT);
            delay(150);
            pinMode(mod, INPUT);
            digitalWrite(mod, LOW);
          break;
                                              // лонги modeset = 1 штатная голова
          case 32:                    //volup long on 2ch
            pinMode(volup, OUTPUT);
            break;
          case 22:                    //volup long off 2ch
            pinMode(volup, INPUT);
            digitalWrite(volup, LOW);
            break;
          case 33:                    //vold long on 3ch
            pinMode(vold, OUTPUT);
            break;
          case 23:                    //vold long off 3ch
            pinMode(vold, INPUT);
            digitalWrite(vold, LOW);
            break;
          case 35:                    //up long on 4ch
            pinMode(up, OUTPUT);
            break;
          case 25:                    //up long off 4ch
            pinMode(up, INPUT);
            digitalWrite(up, LOW);
            break;
          case 34:                    //down long on 5ch
            pinMode(dow,OUTPUT);
            break;
          case 24:                    //down long off 5ch
            pinMode(dow,INPUT);
            digitalWrite(dow, LOW);
            break;
          case 36:                    //mod long on 1ch
            pinMode(mod, OUTPUT);
            break;
          case 26:                    //mod long on 1ch
            pinMode(mod, INPUT);
            digitalWrite(mod, LOW);
            break;        

//    }
//    case 0: {
//    digitalWrite(vklbt, HIGH);
//      switch (val) {
                                    // modeset =0 подключаемое говно
      case 45:
        digitalWrite(volup0, HIGH);
        delay(150);
        digitalWrite(volup0, LOW);
        break;
      case 46:
        digitalWrite(vold0, HIGH);
        delay(150);
        digitalWrite(vold0, LOW);
        break;
      case 48:
        digitalWrite(upv0, HIGH);
        delay(150);
        digitalWrite(upv0, LOW);
        break;
      case 47:
        digitalWrite(dowv0, HIGH);
        delay(150);
        digitalWrite(dowv0, LOW);
        break;                                                      
//      case 51:
//        digitalWrite(mod0, HIGH);
//        delay(150);
//        digitalWrite(mod0, LOW);
//        break;
      case 49:
        digitalWrite(set0, HIGH);
        delay(150);
        digitalWrite(set0, LOW);
        break;
                                    //лонги modeset =0 подключаемое говно
      case 65:
        digitalWrite(volup0, HIGH);
        break;
      case 55:
        digitalWrite(volup0, LOW);
        break;
      case 66:
        digitalWrite(vold0, HIGH);
        break;
      case 56:
        digitalWrite(vold0, LOW);
        break;
      case 68:
        digitalWrite(upv0, HIGH);
        break;
      case 58:
        digitalWrite(upv0, LOW);
        break;
      case 67:
        digitalWrite(dowv0, HIGH);
        break;
      case 57:
        digitalWrite(dowv0, LOW);
        break;
      case 69:
        digitalWrite(set0, HIGH);
        break;
      case 59:
        digitalWrite(set0, LOW);
        break;                                                  
        }
  }
}
