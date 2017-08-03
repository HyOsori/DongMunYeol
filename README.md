# DongMunYeol : Osori's private room checking system

## Overview
- This project is designed to solve how to check whether Osori's private room is open. By considering feature of room, we divide solution into 3 steps. Each step is being implemented, and we will decide which step is the most accurate and simplest solution.

## Specification
### Arduino & Board
- Arduino uno R3 & Wifi shield
### Sensor
- Switch sensor : AT1D-2M3
- Light sensor : Cds CELL(GL5537)
- Ultrasonic sensor : HC-SR04P

## Step 1 : Toggle Switch
- Decision is made by state of the switch. When the current state of the switch is different from the previous state, check the current status of the switch. If the switch's value is **on**, then sending a message **"toggle On"**. If the switch's value is **off**, then sending a message **"toggle Off"**.

- Sensor picture(connected to arduino)
![toggle_switch_sensor](/uploads/toggle_switch.jpg)

- Demo video
https://www.youtube.com/watch?v=7N-TJWVpftk

## Step 2 : Light Sensor
- Decision is made based on the brightness of the light (measured by cds values).
If the cds value is greater than 400, the light is turned off, sending a message “Opened!” on the screen.
If the cds value is less than or equal to 400, then the light is turned on, with a message “Closed!” displayed on the screen.


Thus, by using the light sensor and Arduino, it can be checked whether the Osori room is open or not.

Note:
Normally, when the light is bright, the resistance is lowered, resulting in higher voltage.
However, when a pull-up resistance is used, it gives out an opposite output, where there’s a lower voltage when the light is bright. (Connected to VCC)
In the case of a pull-down resistance, when the light is bright, the voltage is increased. (Connected to GND)

Images of the light sensor along with the Arduino is provided below.

![Light sensor 1](/uploads/Light_sensor_1.jpg)


![Light sensor 2](/uploads/Light_sensor_2.jpg)


![Light sensor 3](/uploads/Light_sensor_3.jpg)

-Demo video
https://www.youtube.com/watch?v=k8ZkReE8DSc

## Step 3 : Ultrasonic Sensor
- Decision is made by difference between long distance(over 10cm, Meaning close) and short distance(within 10cm, Meaning open). When room's card key is placed into key holder, distance calculated by ultrasonic sensor is shortened(within 10cm). Therefore arduino can decide whether room is open or not.

- Sensor picture(connected to arduino)
![ultrasonic_sensor](/uploads/ultrasonic.jpg)

- Demo video  
https://www.youtube.com/watch?v=QM-i1seSgpQ

## Design(For step 3)
- Design will be chosen by vote.  

**Nominee 1.**
![one](/uploads/Demo.PNG)  

**Nominee 2.**
![two](/uploads/Boxman.PNG)  

**Nominee 3.**
![three](/uploads/badgerlike.PNG)

## Network
### Connection to Server
### Using Chatbot
