# Sistem_Monitoring_IoT_Thingsboard
## Sistem Monitoring IoT dengan ESP32, INA219, DHT22, dan BH1750.
Proyek ini menggunakan mikrokontroler ESP32 untuk memantau berbagai parameter lingkungan dan karakteristik listrik, kemudian mengirimkan data yang dikumpulkan ke platform IoT ThingsBoard untuk visualisasi dan analisis. Sistem ini memanfaatkan konektivitas WiFi dan beberapa sensor untuk pengumpulan data, termasuk INA219 untuk pengukuran tegangan dan arus, DHT22 untuk suhu dan kelembaban, serta BH1750 untuk intensitas cahaya.

## Fitur
- **Konektivitas WiFi:** Menghubungkan ke jaringan WiFi untuk mengirim data ke cloud ThingsBoard.
- **Integrasi ThingsBoard:** Mengirim data telemetri ke ThingsBoard untuk pemantauan dan analisis secara real-time.
- **Pemantauan Multi-sensor:**
- **INA219:** Mengukur tegangan, arus, dan daya.
- **DHT22:** Mengukur suhu dan kelembaban.
- **BH1750:** Mengukur intensitas cahaya.
## Library yang Digunakan
- **Wire.h:** Untuk komunikasi I2C.
- **Adafruit_INA219.h:** Untuk interfacing dengan sensor INA219.
- **DHT.h:** Untuk interfacing dengan sensor DHT22.
- **BH1750.h:** Untuk interfacing dengan sensor BH1750.
- **ThingsBoard.h:** Untuk mengirim data ke platform ThingsBoard.
- **WiFi.h:** Untuk konektivitas WiFi.
Setup
## Koneksi Hardware:
- **INA219:** Terhubung melalui I2C.
- **DHT22:** Terhubung ke GPIO 2.
- **BH1750:** Terhubung melalui I2C.

![Monitoring Thingsboard](https://github.com/Achmad-Dimyati/Sistem_Monitoring_IoT_Thingsboard/assets/167073850/541a1e18-3409-4ebd-b090-36d7b8e86a85)
![1691681277525](https://github.com/Achmad-Dimyati/Sistem_Monitoring_IoT_Thingsboard/assets/167073850/1c539f62-943f-4bb0-a953-b49b0d96532b)
