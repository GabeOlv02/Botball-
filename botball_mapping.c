#include <kipr/wombat.h>

void arm_down(){
    enable_servos();
    set_servo_position(3,600);//1600 to open
    set_servo_position(2,1120);
    set_servo_position(1,940);
    ao();
}
    

int main()
{
    arm_down();
    
    motor(1,100);
    motor(2,100);
    msleep(2000);
    
    motor(1,10);
    motor(2,100);
    msleep(500);
    
    if (analog(1) >= 1100)
    {
      motor(0,100);
      motor(3,-10);
    }
    else
    {
      motor(0,-10);
      motor(3,100);
    }
    	
    return 0;
}
