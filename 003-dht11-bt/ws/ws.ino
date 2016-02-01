
#include <SoftwareSerial.h>
#include <dht11.h>

SoftwareSerial Genotronex(10, 11); // RX, TX
#define dht_dpin 5
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  delay(300);
  
  Genotronex.println("Weather station");
  pinMode(ledpin,OUTPUT);
  delay(700); // 1000ms recommended DHT11 delay
}

void loop() {
   if (Genotronex.available()){
    BluetoothData=Genotronex.read();
    if(BluetoothData=='1'){   // if number 1 pressed ....
     digitalWrite(ledpin,1);
     Genotronex.println("LED  On D13 ON ! ");
    }
    if (BluetoothData=='0'){// if number 0 pressed ....
      digitalWrite(ledpin,0);
      Genotronex.println("LED  On D13 Off ! ");
    }

    
   }
   // DHT
   DHT11.read(dht_dpin);
   Genotronex.print("Humidity = ");
   Genotronex.print(DHT11.humidity);
   Genotronex.print("%  ");
   Genotronex.print("temperature = ");
   Genotronex.print(DHT11.temperature); 
   Genotronex.println("C  ");

   digitalWrite(ledpin,1);   
   delay(100);
   digitalWrite(ledpin,0);
   delay(4900);

}
