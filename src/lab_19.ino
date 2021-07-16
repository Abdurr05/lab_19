SYSTEM_MODE(MANUAL);
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"

WatchDog wd;
OledWingAdafruit display;

void setup() {
    pinMode(D5, INPUT);
    display.setup();

    display.clearDisplay();
    display.display();
    if (System.resetReason() == RESET_REASON_WATCHDOG){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("reset because of watch dog");
        display.display();
    }
    else{
        display.clearDisplay();
    }
    wd.initialize(5000);
    wd.pet();
}

void loop() {
    if (digitalRead(D5) == HIGH) {
        wd.pet();
    }
}
