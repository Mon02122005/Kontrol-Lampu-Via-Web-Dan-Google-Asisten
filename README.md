# 💡 Kontrol Lampu Via Web dan Google Assistant

<p align="center">
  <img src="https://img.shields.io/badge/ESP8266-00979D?style=for-the-badge&logo=espressif&logoColor=white">
  <img src="https://img.shields.io/badge/Arduino-00878F?style=for-the-badge&logo=arduino&logoColor=white">
  <img src="https://img.shields.io/badge/Google_Assistant-4285F4?style=for-the-badge&logo=googleassistant&logoColor=white">
  <img src="https://img.shields.io/badge/Sinric_Pro-FF6B00?style=for-the-badge">
  <img src="https://img.shields.io/badge/IoT-Internet_of_Things-blue?style=for-the-badge">
</p>

---

# 📖 Deskripsi

Project Internet of Things (IoT) untuk mengendalikan lampu menggunakan:

* 🌐 Website
* 🎙️ Google Assistant
* 📶 ESP8266 (NodeMCU)
* ☁️ Sinric Pro

Lampu dapat dinyalakan dan dimatikan melalui perintah suara maupun melalui halaman web secara real-time.

---

# ✨ Fitur

✅ Kontrol lampu melalui Website

✅ Kontrol lampu menggunakan Google Assistant

✅ Monitoring status lampu

✅ Terhubung ke jaringan WiFi

✅ Integrasi Sinric Pro

✅ Respon real-time

---

# 🛠️ Komponen Yang Digunakan

| Komponen        | Jumlah     |
| --------------- | ---------- |
| ESP8266 NodeMCU | 1          |
| Relay Module    | 1          |
| Lampu           | 1          |
| Kabel Jumper    | Secukupnya |
| WiFi Router     | 1          |

---

# ⚙️ Teknologi

* ESP8266
* Arduino IDE
* Sinric Pro
* Google Assistant
* HTTP Client
* Web Server
* WiFi

---

# 🔄 Cara Kerja Sistem

```text
Google Assistant
        │
        ▼
    Sinric Pro
        │
        ▼
     ESP8266
        │
        ▼
      Relay
        │
        ▼
      Lampu

Website
   │
   ▼
Web Server
   │
   ▼
ESP8266
   │
   ▼
Relay → Lampu
```

---

# 📂 Struktur Program

### Library

```cpp
#include <SinricPro.h>
#include <SinricProSwitch.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
```

### Fungsi Utama

| Fungsi           | Keterangan                                             |
| ---------------- | ------------------------------------------------------ |
| onPowerState()   | Mengontrol lampu melalui Google Assistant              |
| checkWebServer() | Membaca perintah ON/OFF dari website                   |
| setup()          | Inisialisasi WiFi dan Sinric Pro                       |
| loop()           | Menjalankan kontrol suara dan web secara terus menerus |

---

# 🎙️ Perintah Google Assistant

Contoh:

```text
"Ok Google, turn on the light"
```

```text
"Ok Google, turn off the light"
```

---

# 🌐 Kontrol Melalui Website

Website mengirimkan status:

```text
ON
```

atau

```text
OFF
```

Kemudian ESP8266 membaca status tersebut menggunakan HTTP GET Request.

---

# 🚀 Cara Upload Program

1. Buka Arduino IDE
2. Install Board ESP8266
3. Install Library:

   * SinricPro
   * ESP8266WiFi
4. Masukkan:

   * WiFi SSID
   * WiFi Password
   * APP KEY Sinric Pro
   * APP SECRET Sinric Pro
   * DEVICE ID
5. Upload ke ESP8266

---

# 👨‍💻 Author

**Remon Pangkalangi & Fransisko Pangkalangi**


---

# ⭐ Project IoT

Smart Home Lighting Control menggunakan ESP8266, Website, dan Google Assistant.


# Kontrol-Lampu-Via-Web-Dan-Google-Asisten
