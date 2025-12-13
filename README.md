# 🐭 MAUS
Arduino-Based Mouse Jiggler

MAUS is a compact Arduino-based device that simulates mouse movements to prevent screensavers and keep your computer active. Small, fun, and fully programmable, it also adds a splash of RGB flair to your workspace! ✨

---

## 📸 Gallery

<p align="center">
  <img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/1678098086510a.jpg" width="600" />
</p>

<p align="center">
  <img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/1678098086495a.jpg" width="600" />
</p>

<p align="center">
  <img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/1678271177181.jpg" width="600" />
</p>

<!-- Example animated GIF placeholder -->
<p align="center">
  <img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/maus-demo.gif" width="600" alt="MAUS in action" />
</p>

---

## 🛒 Where to Buy

<p align="center">
  <a href="https://www.tindie.com/stores/makersun/?ref=offsite_badges&utm_source=sellers_MAKERSUN&utm_medium=badges&utm_campaign=badge_large">
    <img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-larges.png" alt="I sell on Tindie" width="200" height="104">
  </a>
</p>

<p align="center">
  <a href="https://www.ebay.it/itm/126484058631">
    <img src="https://ir.ebaystatic.com/pictures/aw/pics/announcements/new/logo/logo-inline.png" alt="I sell on eBay" width="200" height="104">
  </a>
</p>

---

## 🔹 Overview

MAUS generates small, fake mouse movements (1 pixel up and down) to keep your computer active and disable screensavers.  
Perfect for automation without interaction and a little ambient light fun! 💡

---

## ⚙️ Features

- **MCU:** ATtiny85  
- **LEDs:** Red LED on PB0, WS2812B RGB LED on PB1  
- **Free pins:** PB2, PB3, PB4 (programmable)  
- **Default Fuse Settings:**  
  - **Lfuse:** 0xE1 – PLL Clock + Startup 64 ms  
  - **Hfuse:** 0xDD – External Reset pin enabled (Pin5 not usable as I/O) + BOD 2.7V + Enable Serial Program/Data Downloading  
  - **Efuse:** 0xFE – Self programming enabled  
- **Plug & Play:** Arduino firmware pre-installed  
- **PlatformIO support** with a custom MAUS board  

<p align="center">
  <img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/maus-led.gif" width="400" alt="LED Animation Demo" />
</p>

---

## 💻 Software

- Fully open-source Arduino code and KiCad schematics  
- Adafruit Neopixel Library required for RGB functionality  
- Micronucleus bootloader info: [Micronucleus GitHub](https://github.com/micronucleus/micronucleus)  
- Modify and customize the software to your needs  

---

## 📦 Installation & Usage

1. Plug MAUS into a USB port  
2. Observe the LED lights and simulated mouse movements  
3. Optional: Modify Arduino code for custom behaviors or RGB animations  

---

## 🔗 Links & Resources

- [GitHub Repository](https://github.com/MAKERSUN99/MAUS) – source code, schematics, firmware  
- [Tindie Store](https://www.tindie.com/stores/makersun/) – purchase MAUS  

---

## 🌟 Tagline

No more sleepy screens. No more endless logins.  
Just movement… with light.  
**MAUS: your silent digital sidekick.** 🖱️✨
