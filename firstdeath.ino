#include <Servo.h> // servo library

Servo myservo; 
int m=0;
int n=0;
int pos = 0; 
void setup()
 {
  // Kode disini hanya dijalankan sekali
pinMode(A0, INPUT_PULLUP);           // Soil Moisture Sensor 1 PIN A0
pinMode(A1, INPUT_PULLUP);           // Soil Moisture Sensor 1 PIN A1
pinMode(8,OUTPUT);                             // Relay Module PIN D8
Serial.begin(9600);                                  //  Sensor Buart Rate
myservo.attach(9);                                   //  Servo PIN D9

digitalWrite(8, HIGH);                           // Relay Normally Hight for OFF condition
}

void loop() 
{

  // Kode disini akan dijalankan secara berulang:

int m= analogRead(A0);                         // Soil Moisture Sensor 1 PIN A0
int n= analogRead(A1);                           // Soil Moisture Sensor 1 PIN A1
Serial.println(m);
delay(10);
Serial.println(n);
delay(200);
if (m>=980)
{
 myservo.write(0);              // Memerintahkan servo untuk ke posisi yang ditulis pada variabel 'pos'
        
  digitalWrite(8, LOW);       // Relay ON
  delay(700);
  }

else if(m<=970) 
{
 digitalWrite(8, HIGH);      // Relay ON
 }

 if (n>=980)
{

  myservo.write(90);              // Memerintahkan servo untuk ke posisi yang ditulis pada variabel 'pos'
        
  digitalWrite(8, LOW);       // Relay ON
  delay(700);
  
  }

else if(n<=970)
{

  digitalWrite(8, HIGH);    // Relay OFF
  }
  
else
{
  digitalWrite(8, HIGH);   // Relay OFF
  }
}