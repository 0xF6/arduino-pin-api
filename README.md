<!-- Logo -->
<p align="center">
  <a href="#">
    <img height="128" width="128" src="https://user-images.githubusercontent.com/13326808/73615952-62df8380-461e-11ea-8cbe-92122cb6ce7b.png">
  </a>
</p>
<!-- Name -->
<h1 align="center">
  Arduino PIN API
</h1>
<!-- desc -->
<h4 align="center">
    A concise api for using pin management with fast mode
</h4>

<!-- popup badges -->
<p align="center">
  <a href="https://t.me/ivysola">
    <img src="https://img.shields.io/badge/Ask%20Me-Anything-1f425f.svg?style=popout-square&logo=telegram">
  </a>
</p>

<!-- big badges -->
<p align="center">
  <a href="#">
    <img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg">
    <img src="https://forthebadge.com/images/badges/oooo-kill-em.svg">
    <img src="https://forthebadge.com/images/badges/ages-18.svg">
    <img src="https://forthebadge.com/images/badges/powered-by-electricity.svg">
  </a>
</p>


### API

##### Pin Mode
```cpp
#define LED_PIN 13

// new
pin<LED_PIN>().mode(OUTPUT);

// vs

// default
pinMode(LED_PIN, OUTPUT);
```
##### Digital write
```cpp
#define LED_PIN 13

// new
pin<LED_PIN>().digital().write(255);

// vs

// default
digitalWrite(LED_PIN, 255);
```
##### Digital read
```cpp
#define TARGET_PIN 13

// new
const int value = pin<TARGET_PIN>().digital().read();

// vs

// default
const int value = digitalRead(TARGET_PIN);
```
##### Analog read\write
```cpp
#define TARGET_PIN 13

// new
pin<TARGET_PIN>().analog().write(LOW);
const int value = pin<TARGET_PIN>().digital().read();

// vs

// default
const int value = analogRead(TARGET_PIN);
analogWrite(TARGET_PIN, LOW);
```


### remarks

```
fast-mode work only in ATmega328* chips, in future planned more goto-go-fast
```



<p align="center">
   <a href="https://ko-fi.com/P5P7YFY5">
    <img src="https://www.ko-fi.com/img/githubbutton_sm.svg">
  </a>
</p>