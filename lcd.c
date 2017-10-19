#include <wiringPi.h>
#include <pcf8574.h>
#include <lcd.h>
#include <stdio.h>
#define LCDOFS(x) (lcdofs + x)

const int lcdofs = 0x64;

void printText(int fd, char message[])
{
	lcdHome(fd);
    lcdClear(fd);
    lcdPrintf(fd, message);
	delay(500);
}

int main(void)
{
    int fd;
    char input;
    int a[20];
    int i=0;

    pcf8574Setup(lcdofs, 0x3f);
    wiringPiSetup();

    pinMode(LCDOFS(1), OUTPUT);
    pinMode(LCDOFS(3), OUTPUT);
    digitalWrite(LCDOFS(1), 0);
    digitalWrite(LCDOFS(3), 1);

    fd = lcdInit(4, 20, 4, LCDOFS(0), LCDOFS(2),LCDOFS(4), LCDOFS(5), LCDOFS(6), LCDOFS(7), 0, 0, 0, 0);
    for(;;)
	{
	printText(fd,"test1");
	}
}