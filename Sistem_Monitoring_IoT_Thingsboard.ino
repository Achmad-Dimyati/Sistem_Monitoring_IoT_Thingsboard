//Liblary INA219
#include <Wire.h>  
#include <Adafruit_INA219.h>  
//Liblary DHT11
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22 
//Liblary BH1750
//#include <Wire.h>
#include <BH1750.h>
//Liblary Thingboard
#include <ThingsBoard.h>
#include <WiFi.h>

//****WIFI****
#define WIFI_AP "LAB. FISIKA"
#define WIFI_PASSWORD "00000004"

//++++TOKEN & THNGSBOARD++++
#define TOKEN "y3GhXJLGl5oMMGgyBkTG" 
char thingsboardServer[] = "thingsboard.cloud";
WiFiClient client1; // nama wifi client
ThingsBoard device1(client1);
int status = WL_IDLE_STATUS;
unsigned long lastSend;

//====INISIASI====
//Inisiasi INA219
Adafruit_INA219 ina219; //memberikan nama pada modul sensor dengan nama "ina219"
//membuat variabel yang akan dipakai untuk perhitungan, tipe datanya adalah bilangan desimal
float busvoltage = 0;
float current_mA = 0;
float power_mW = 0;
//Inisiasi DHT11
DHT dht(DHTPIN, DHTTYPE);
//Inisiasi BH1750
BH1750 lightMeter;

void setup() {
  Serial.begin(9600); //komunikasi dengan serial monitor
  ina219.begin(); // Menginisialisasi sensor INA219
  dht.begin(); // Menginisialisasi sensor DHT22
  Wire.begin(); // Menginisialisasi I2C
  lightMeter.begin(); // Menginisialisasi sensor BH1750
  InitWifi();
  lastSend = 0;  
  Serial.println("===START SYSTEM===");
}

void loop() {
  //mengambil data dan disimpan dalam variabel yang telah disediakan
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();

  //DHT11
  float temperature = dht.readTemperature(); // Membaca suhu dalam derajat Celsius
  float humidity = dht.readHumidity();       // Membaca kelembaban dalam persen
  int humInt = (int)humidity;

  //BH1750
  float lux = lightMeter.readLightLevel();
  int Intlux = (int)lux;

  //menampilkan hasil pengukuran
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");

  Serial.print("Suhu: "); Serial.print(temperature - 1.70); Serial.println(" C");
  Serial.print("Kelembaban: "); Serial.print(humInt + 2); Serial.println(" %");

  Serial.print("Light: "); Serial.print(Intlux + 34); Serial.println(" lx");
  
  Serial.println("");

  device1.sendTelemetryFloat("Voltage", busvoltage);
  device1.sendTelemetryFloat("Arus", current_mA);
  device1.sendTelemetryFloat("Daya", power_mW);
  device1.sendTelemetryFloat("suhu", temperature);
  device1.sendTelemetryFloat("kelembapan", humInt);
  device1.sendTelemetryFloat("Lux", Intlux);

  delay(2000);

}

void InitWifi() {
  Serial.println("Menghubungkan...");
  // mencoba koneksi ke wifi

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }   
  Serial.println("Berhasil Terhubung");
}

void reconnect() {
  // diulang sampai reconected
  while (!device1.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {        
        delay(500);
        Serial.print(".");
      }
      Serial.println("Berhasil Terhubung");
    }
    Serial.print("Menghubungkan ke thingsboard node ...");
    if ( device1.connect(thingsboardServer, TOKEN)) {
      Serial.println("[DONE]");      
    } else {
      Serial.print("[FAILED]");
      Serial.println(" : retrying in 5 seconds");
      // Wait 5 detik
      delay(5000);
    }
  }
}
