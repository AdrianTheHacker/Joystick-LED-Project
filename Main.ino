#define joyX = A0;
#define joyY = A1;

const float range = 1023;
const float num = range / 3;
const float num2 = num + num;
const float num3 = num2 + num;

int X(int numX) {
    int ledX;
    if(numX <= num) {
        ledX = 1;
    } else if(numX > num and numX <= num2) {
        ledX = 2;
    } else if(numX > num2 and numX <= num3) {
        ledX = 3;
    }
    return ledX;
}

int Y(int numY) {
    int ledY;
    if(numY <= num) {
        ledY = 1;
    } else if(numY > num and numY <= num2) {
        ledY = 2;
    } else if(numY > num2 and numY <= num3) {
        ledY = 3;
    }
    return ledY;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    int x = analogRead(A0);
    int y = analogRead(A1);

    //Serial.println(x + " " + y);
    Serial.println("Hello world");
    Serial.print(X(x));
    Serial.print(", ");
    Serial.println(Y(y));
}