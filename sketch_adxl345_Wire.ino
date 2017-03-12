
//SDA - A4 SKL - A5 

#include <Wire.h>
#include <string.h>
  
#define DEVICE (0x53)
#define TO_READ (6)
  
byte buff[TO_READ];
  
void setup()
{
  Serial.begin(9600);

  Wire.begin();
  
  writeTo(DEVICE, 0x2D, 0);      
  writeTo(DEVICE, 0x2D, 16);
  writeTo(DEVICE, 0x2D, 8);
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

void writeTo(int device, byte address, byte val) {
  Wire.beginTransmission(device);
  Wire.write(address); 
  Wire.write(val);  
  Wire.endTransmission(); 
}
  
void readFrom(int device, byte address, int num, byte buff[]) {
  Wire.beginTransmission(device); 
  Wire.write(address);
  Wire.endTransmission();
  Wire.beginTransmission(device);
  Wire.requestFrom(device, num);
  
  int i = 0;
  while(Wire.available())
  { 
    buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
}
