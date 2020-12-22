#include <Servo.h>

//11
#define Tthr 1600
#define newPWM1 11
#define newPWM2 10
#define newPWM3 9
#define newPWM4 6

Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;

volatile int pwm_start_time[4];

void setup()
{

    Serial.begin(9600);
    Serial.println("OG!");
    motor0.attach(newPWM1);
    motor1.attach(newPWM2);
    motor2.attach(newPWM3);
    motor3.attach(newPWM4);

    mot_init(motor0, 1000, Tthr);
    mot_init(motor1, 1000, Tthr);
    mot_init(motor2, 1000, Tthr);
    mot_init(motor3, 1000, Tthr);
}

void loop()
{

    motor0.writeMicroseconds(Tthr);
    motor1.writeMicroseconds(Tthr);
    motor2.writeMicroseconds(Tthr);
    motor3.writeMicroseconds(Tthr);
}

void mot_init(Servo sv_tar, int sv_min, int sv_max)
{

    for (int i = sv_min; i < sv_max; i++)
    {
        sv_tar.writeMicroseconds(i);
    }
    for (int i = sv_max; i > sv_min; i--)
    {
        sv_tar.writeMicroseconds(i);
    }
}
