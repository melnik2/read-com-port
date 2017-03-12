
//SDA - A4 SKL - A5 

#include <Wire.h>
#include <string.h>
  
#define DEVICE (0x53)    //ADXL345 device address
#define TO_READ (6)        //num of bytes we are going to read each time (two bytes for each axis)
  
byte buff[TO_READ];    //6 bytes buffer for saving data read from the device
  
void setup()
{
  Serial.begin(9600);  // start serial for output

  Wire.begin();        // join i2c bus (address optional for master)
  
  writeTo(DEVICE, 0x2D, 0);      
  writeTo(DEVICE, 0x2D, 16);
  writeTo(DEVICE, 0x2D, 8);
  writeTo(DEVICE, 0x2C, 15);
  writeTo(DEVICE, 0x31, 0);

//  Serial.println("	x		y		z");
}

int regAddress = 0x32;
unsigned long t;
int x,y,z;
int n;
char *str1 = new char[4];
char *str2 = new char[4];
char *str3 = new char[4];
char *str4 = "\t";
char *s3 = new char[16];
  
void loop()
{
  readFrom(DEVICE, regAddress, TO_READ, buff); 
  
 // t=micros();
 x = (((int)buff[1]) << 8) | buff[0];   
 y = (((int)buff[3])<< 8) | buff[2];
 z = (((int)buff[5]) << 8) | buff[4];

 itoa(x, str1, 10);
 itoa(y, str2, 10);
 itoa(z, str3, 10);

strcpy(s3, str1);
strcat(s3, str4);
strcat(s3, str2);
strcat(s3, str4);
strcat(s3, str3);
 
  Serial.println(s3);

  for (int i=0; i<4; i++){
str1[i]=0;
str2[i]=0;
str3[i]=0;
 }
for (int i=0; i<16; i++){
s3[i]=0;
 }
delay (100);
}
//---------------- Functions

//Writes val to address register on device
void writeTo(int device, byte address, byte val) {
  Wire.beginTransmission(device); //start transmission to device 
  Wire.write(address);        // send register address
  Wire.write(val);        // send value to write
  Wire.endTransmission(); //end transmission
}
  
//reads num bytes starting from address register on device in to buff array
void readFrom(int device, byte address, int num, byte buff[]) {
  Wire.beginTransmission(device); //start transmission to device 
  Wire.write(address);        //nds address to read from
  Wire.endTransmission(); //end transmission
  Wire.beginTransmission(device); //start transmission to device
  Wire.requestFrom(device, num);    // request 6 bytes from device
  
  int i = 0;
  while(Wire.available())    //device may send less than requested (abnormal)
  { 
    buff[i] = Wire.read(); // receive a byte
    i++;
  }
  Wire.endTransmission(); //end transmission
}
