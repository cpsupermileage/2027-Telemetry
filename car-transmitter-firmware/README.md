# car-transmitter-firmware

This package contains the firmware for the on-car [Xiao esp32s3 w/ Wio-SX1262](https://www.seeedstudio.com/Wio-SX1262-with-XIAO-ESP32S3-p-5982.html) with [2.6dbi antenna](https://www.seeedstudio.com/External-Antenna-915MHZ-2-6dBi-SMA-L195mm-p-5047.html).

It connects data from:
- Vesc Motor Controller
- Hall effect sensor
- Joulemeter
- 6 axis IMU
and sends it via LoRa to tbe base station device.
