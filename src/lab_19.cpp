/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Abdurrahman/Documents/labs/lab_19/src/lab_19.ino"
// SYSTEM_MODE(MANUAL);
// #include "WatchDog_WCL.h"
// #include "oled-wing-adafruit.h"

// WatchDog wd;
// OledWingAdafruit display;

// void setup() {
//     pinMode(D5, INPUT);
//     display.setup();

//     display.clearDisplay();
//     display.display();
//     if (System.resetReason() == RESET_REASON_WATCHDOG){
//         display.clearDisplay();
//         display.setTextSize(1);
//         display.setTextColor(WHITE);
//         display.setCursor(0, 0);
//         display.println("reset because of watch dog");
//         display.display();
//     }
//     else{
//         display.clearDisplay();
//     }
//     wd.initialize(5000);
//     wd.pet();
// }

// void loop() {
//     if (digitalRead(D5) == HIGH) {
//         wd.pet();
//     }
// }
void setup();
void loop();
#line 34 "c:/Users/Abdurrahman/Documents/labs/lab_19/src/lab_19.ino"
SYSTEM_MODE(MANUAL);
#include "WatchDog_WCL.h"

WatchDog wd;

void setup() {
    pinMode(D6, INPUT_PULLUP);
    RGB.control(true);
    if  (System.resetReason() == RESET_REASON_WATCHDOG) {
        RGB.color(255,0,0);
        delay(CONCURRENT_WAIT_FOREVER);
    }  else {
        RGB.color(0,0,255);
    }
    wd.initialize(5000);
    wd.pet();
}

void loop() {
    if (digitalRead(D6) == LOW) {
        wd.pet();
    }
}
