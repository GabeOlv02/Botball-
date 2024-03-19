#include <kipr/wombat.h>

void motors(l,r,t){
    motor(1,l);
    motor(2,r);
    msleep(t);
    ao();
}

void move_to_objects(l,r,d){
    /*claw lifts and opens*/
    set_servo_position(1,0);
    set_servo_position(3,1000);
    msleep(500);
    /* ohaiyo */
    while (analog(0) <= d)
    {
        motor(1,l);
    	motor(2,r);
    }
	
    if (analog(0) >= d)
    {
     	ao();
    }
}




void collect_objects(){
    set_servo_position(1,750);
    msleep(500);
    set_servo_position(3,2047);
    msleep(500);
}



void deliver_objects(){
    set_servo_position(1,200);
    msleep(500);
    motors(-90, -90, 100);
    motors(100, -100, 1300);
}

int main(){
    
    enable_servos();
    
    
    move_to_objects(100,100,2800);
	collect_objects();
    deliver_objects();
   


    enable_servos();
    camera_open();
    
    while (a_button() == 0)
    {
        camera_update();
        
        if (get_object_count(0) > 0)
        {
            if (get_object_center_column(0,0) <79)
            {
                motor(0, -50);
                motor(3,50);
            }
            
            if (get_object_center_column(0,0) > 79)
            {
                motor(0, 50);
                motor(3, -50);
            }
            
            if (get_object_center_column(0,0) == 79)
            {
                motor(0, 50);
                motor(3, 50);
            }
        }
        else
        {
            ao();
        }
    }
    ao();
    camera_close();
    return 0;
}
