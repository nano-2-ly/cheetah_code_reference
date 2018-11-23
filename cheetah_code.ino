/* Dynamixel Basic Position Control Example
 
 Turns left the dynamixel , then turn right for one second,
 repeatedly.
 
                   Compatibility
 CM900                  O
 OpenCM9.04             O
 
                  Dynamixel Compatibility
               AX    MX      RX    XL-320    Pro
 CM900          O      O      O        O      X
 OpenCM9.04     O      O      O        O      X
 **** OpenCM 485 EXP board is needed to use 4 pin Dynamixel and Pro Series ****
 
 created 16 Nov 2012
 by ROBOTIS CO,.LTD.
  */
/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define left_back_leg_1 35
#define left_back_leg_2 34
#define left_back_leg_3 33
#define left_back_leg_4 32
#define left_back_leg_5 31

#define right_back_leg_1 45
#define right_back_leg_2 44
#define right_back_leg_3 43
#define right_back_leg_4 42
#define right_back_leg_5 41

#define right_front_leg_1 25
#define right_front_leg_2 24
#define right_front_leg_3 23
#define right_front_leg_4 22
#define right_front_leg_5 21

#define left_front_leg_1 15
#define left_front_leg_2 14
#define left_front_leg_3 13
#define left_front_leg_4 12
#define left_front_leg_5 11

int left_front_leg[5] = {left_front_leg_1,left_front_leg_2,left_front_leg_3,left_front_leg_4,left_front_leg_5};
int right_front_leg[5] = {right_front_leg_1,right_front_leg_2,right_front_leg_3,right_front_leg_4,right_front_leg_5};
int left_back_leg[5] = {left_back_leg_1,left_back_leg_2,left_back_leg_3,left_back_leg_4,left_back_leg_5};
int right_back_leg[5] = {right_back_leg_1,right_back_leg_2,right_back_leg_3,right_back_leg_4,right_back_leg_5};


/* Control table defines */
#define GOAL_POSITION 30
#define GOAL_SPEED 32

Dynamixel Dxl(DXL_BUS_SERIAL3);

//Dxl.writeWord(motor id ,  GOAL_POSITION , angle);
//Dxl.writeWord(motor id ,  GOAL_SPEED , speed);


void change_motor_speed(int *arr, int *speed){
  //arr = leg , speed = leg`s speed
  
  Dxl.writeWord(arr[0], GOAL_SPEED, speed[0]);
  Dxl.writeWord(arr[1], GOAL_SPEED, speed[1]);
  Dxl.writeWord(arr[2], GOAL_SPEED, speed[2]);
  Dxl.writeWord(arr[3], GOAL_SPEED, speed[3]);
  Dxl.writeWord(arr[4], GOAL_SPEED, speed[4]);
}


void setup_one_leg(int *arr, int* position){
  Dxl.writeWord(arr[0], GOAL_POSITION, position[0]);
  Dxl.writeWord(arr[1], GOAL_POSITION, position[1]);
  Dxl.writeWord(arr[2], GOAL_POSITION, position[2]);
  Dxl.writeWord(arr[3], GOAL_POSITION, position[3]);
  Dxl.writeWord(arr[4], GOAL_POSITION, position[4]);
}

void stretch_one_leg(int *arr, int* position){
  Dxl.writeWord(arr[0], GOAL_POSITION, position[0]);
  Dxl.writeWord(arr[1], GOAL_POSITION, position[1]);
  Dxl.writeWord(arr[2], GOAL_POSITION, position[2]);
  Dxl.writeWord(arr[3], GOAL_POSITION, position[3]);
  Dxl.writeWord(arr[4], GOAL_POSITION, position[4]);
}

void fold_one_leg(int *arr, int* position){
  Dxl.writeWord(arr[0], GOAL_POSITION, position[0]);
  Dxl.writeWord(arr[1], GOAL_POSITION, position[1]);
  Dxl.writeWord(arr[2], GOAL_POSITION, position[2]);
  Dxl.writeWord(arr[3], GOAL_POSITION, position[3]);
  Dxl.writeWord(arr[4], GOAL_POSITION, position[4]);
}

/*
void setup_legs(){
  setup_one_leg(left_front_leg);
  setup_one_leg(right_front_leg);
  setup_one_leg(left_back_leg);
  setup_one_leg(left_back_leg);
}
*/

void setup() {
  
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  
  for(int i=1;i<5;i++){
    for(int j=1;j<6;j++){
      Dxl.jointMode(i*10+j);
    }
  }
  
}

void loop() {  
  
  
}
