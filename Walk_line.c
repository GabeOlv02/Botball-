#include <kipr/wombat.h>
void arm_down(){
    enable_servos();
    set_servo_position(3,600);
    set_servo_position(2,1120);
    set_servo_position(1,940);
}

void track(){
    while (digital(0) == 0)
    {
        if (analog(3) >= 3900)
        {
            motor(1,100);
            motor(2,-10);
        }
        else
        {
            motor(1,-10);
            motor(2,100);
        }
        /*if (analog(1) >= 2100)
        {
            break;
            motor(1,-100);
            motor(2,100);
            msleep(500);
        }*/
            
    }
}

int main()
{
    /*arm_down();*/
   /* motor(1,100);
    motor(2,100);
    msleep(2300);
    
    motor(1,40);
    motor(2,100);
    msleep(1100);*/
	
    track();
    
    
    motor(1,100);
    motor(2,100);
    msleep(5000);
    ao();
    return 0;
}
