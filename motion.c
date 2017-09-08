#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <softTone.h>
 
#define MOTION_PIN 7
#define BUZZER_PIN 0
 
int scale [8] = { 262, 294, 330, 349, 392, 440, 494, 525 } ;
 
int main(int argc, char** argv) {
    //int i = 0;
 
    // set up motion pin
    wiringPiSetup();
    pinMode(MOTION_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
 
    softToneCreate (BUZZER_PIN) ;
   
    for(;;)
    {
        if (digitalRead(MOTION_PIN)==HIGH) // motion detected
        {
	    printf ("motion detected \n") ;
            // get the current time
            for (int i = 0 ; i < 8 ; ++i)
            {
              softToneWrite (BUZZER_PIN, scale [i]) ;
              delay (500) ;
            }
        }
        else
        {
            printf ("motion not detected \n") ;
            softToneWrite (BUZZER_PIN,0);
        }

	delay(500);
    }
}
