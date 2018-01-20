

// include the DHT11 Library...
#include <DHT.h>


#define DHTTYPE DHT11 //Type of DHT sensor we're using
DHT dht(DHTPIN, DHTTYPE); //initializes the DHT sensor
int LDR_Pin = A0;
int ledPin = 13;
int state = 0;
int flag = 0;

void setup() {
 // pinMode(ledPin, OUTPUT);
 // digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  // standard serial 

  Serial.println("DHTxx test!");
  dht.begin();
}

void loop(){

  //DHT loop...
  // Wait 3 seconds between measurements.
  delay(3000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int LDRReading = analogRead(LDR_Pin); 
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Light: ");
  Serial.print(LDRReading);
  Serial.print(" Lux ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("*C ");
  Serial.print(f);
  Serial.print("*F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print("*C ");
  Serial.print(hif);
  Serial.println("*F");
}

