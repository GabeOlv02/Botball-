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
    camera_open();
    camera_update();
    msleep(3000);
    /*int offset, x, y;
    enable_servos();
    camera_update(); // get most recent image and process it
    while(a_button() == 0) {
        x = track_x(0,0);
        y = track_y(0,0);
        if (get_object_count(0) > 0) {// there is a blob
            printf("Blob is at (%d,%d)\n", x, y);
            offset=5*(x-80); // amount to deviate servo from center
            set_servo_position(0,2014+offset);
        }
        else {
            printf("No object in sight\n");
        }
        msleep(500);// dont rush print statement update
        camera_update();// get new image data before repeating
    }*/
    ao();
    return 0;
}
