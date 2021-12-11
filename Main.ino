#define joyX = A0;
#define joyY = A1;

const int rows = 3;
const int columns = 3;

int LEDs[rows][columns] = {{2, 3, 4},
                           {5, 6, 7},
                           {8, 9, 10}};

const float range = 1023;
const float xNum = range / rows;
const float xNum2 = xNum + xNum;
const float xNum3 = xNum2 + xNum;

const float yNum = range / rows;
const float yNum2 = yNum + yNum;
const float yNum3 = yNum2 + yNum;

/*
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;
const int LED9 = 10;

int Row1[] = {LED1, LED2, LED3};
int Row2[] = {LED4, LED5, LED6};
int Row3[] = {LED7, LED8, LED9};
*/

int X(int numX) {
    int ledX;
    if(numX <= xNum) {
        ledX = 1;
    } else if(numX > xNum and numX <= xNum2) {
        ledX = 2;
    } else if(numX > xNum2 and numX <= xNum3) {
        ledX = 3;
    }
    return ledX;
}

int Y(int numY) {
    int ledY;
    if(numY <= yNum) {
        ledY = 1;
    } else if(numY > yNum and numY <= yNum2) {
        ledY = 2;
    } else if(numY > yNum2 and numY <= yNum3) {
        ledY = 3;
    }
    return ledY;
}

void setup() {
    Serial.begin(9600);
    for(int i = 2; i <= 10; i++) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    int x = analogRead(A0);
    int y = analogRead(A1);

    Serial.print(X(x));
    Serial.print(", ");
    Serial.println(Y(y));

    Serial.println(LEDs[1][3]);
    
    digitalWrite(LEDs[X(x)][Y(y)], HIGH);
    
    for(int i = 2; i <= 10; i++) {
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
    }
}