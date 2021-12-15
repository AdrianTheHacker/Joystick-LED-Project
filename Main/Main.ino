// Where the VSX and VSY are wired to
#define joyX = A0;
#define joyY = A1;

// Number of rows and columns of LEDs
const int rows = 3;
const int columns = 3;

// Grid of LEDs
int LEDs[rows][columns] = {{2, 3, 4},
                           {5, 6, 7},
                           {8, 9, 10}};

// Range of motion of joystick
const float range = 1023;

// divides the range of motion into three variables
const float xNum = range / rows;
const float xNum2 = xNum + xNum;
const float xNum3 = xNum2 + xNum;

const float yNum = range / rows;
const float yNum2 = yNum + yNum;
const float yNum3 = yNum2 + yNum;

// Debugging variables used to reference specific LEDs
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

// Determines where on a 3x3 grid the horizontal axis of the joystick position is
int X(int numX) {
    int ledX;
    // Box ones X
    if(numX <= xNum) {
        ledX = 1;
    // Box twos X
    } else if(numX > xNum and numX <= xNum2) {
        ledX = 2;
    // Box threes X
    } else if(numX > xNum2 and numX <= xNum3) {
        ledX = 3;
    }
    return ledX;
}

// Determines where on a 3x3 grid the vertical axis of the joystick position is
int Y(int numY) {
    int ledY;
    // Box ones Y
    if(numY <= yNum) {
        ledY = 1;
    // Box twos Y
    } else if(numY > yNum and numY <= yNum2) {
        ledY = 2;
    // Box threes Y
    } else if(numY > yNum2 and numY <= yNum3) {
        ledY = 3;
    }
    return ledY;
}

void setup() {
    // Enables serial monitor for debugging
    Serial.begin(9600);

    // Sets all LEDs to OUTPUT
    for(int i = 2; i <= 10; i++) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    // Reads the joystick X and Y
    int x = analogRead(A0);
    int y = analogRead(A1);
       
    // Turns on the LEDs corrisponding with the grid
    digitalWrite(LEDs[X(x) - 1][Y(y) - 1], HIGH); 
    delay(10);
    digitalWrite(LEDs[X(x) - 1][Y(y) - 1], LOW); 
    delay(10);

    // Debugging tool used to print the cords of the joystick on a 3x3 grid
    //Serial.print(X(x)); Serial.print(", "); Serial.println(Y(y));
    
    // Debugging tool used to check if all LEDs are on
    /*
    for(int i = 2; i <= 10; i++) {
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
    }
    */ 
}
