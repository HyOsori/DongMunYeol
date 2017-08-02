# DongMunYeol : Osori's private room checking system

## Overview
- This project is designed to solve how to check whether Osori's private room is open. By considering feature of room, we divide soulution into 3 steps. Each step is being implemented, and we will decide which step is the most accurate and simplest solution.

## Specification
### Arduino & Board
- Arduino uno R3 & Wifi shield
### Sensor
- Switch sensor : AT1D-2M3
- Light sensor : Cds CELL(GL5537)
- Ultrasonic sensor : HC-SR04P

## Step 1

## Step 2

## Step 3 : Ultrasonic Sensor
- Decision is done by difference between long distance(over 10cm, Meaning close) and short distance(within 10cm, Meaning open). When room's card key is placed into key holder, distance calculated by ultrasonic sensor is shortened(within 10cm). Therefore arduino can decide whether room is open or not.

- Sensor picture(connected to arduino)
![ultrasonic_sensor](/uploads/ultrasonic.jpg)

- Demmo video  
https://www.youtube.com/watch?v=QM-i1seSgpQ

## Design(For step 3)
- Design will be chosen by vote.  

**Nominee 1.**
![one](/uploads/Demo.PNG)  

**Nominee 2.**
![two](/uploads/Boxman.PNG)  

**Nominee 3.**
![three](/uploads/badgerlike.PNG)
