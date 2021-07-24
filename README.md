# Nixie Clock From Scratch
Several years ago I decided to build a 6-digit nixie clock. As a hobby project it took quite some time for me. I hope this guide will provide some helpful information at key points if you have limited access to PCB printing or component markets. 


Before beginning:
* Find a reliable tube supplier for your location.
* Select a tube model and find it's datasheet, check voltage range.
* Choose a suitable high voltage power supply design or board. Generally 170V is enough for most of the tubes.
 


## Tube Purchase
After some research I found a tube vendor which can deliver to Turkey. I purchased a dozen IN-12A nixie tubes and IN-12 / IN-15 / IV-22 sockets. If I remember correctly I paid 2.5 USD for one tube and 1.0 USD for one socket. I bought them in March 2018, today (July 2021) tubes are 12.0 USD, sockets are 2.0 USD.

Nearly one month later I received the package with 4 extra tubes. They were covered in dirt, some of them had mud between their pins. Even today I am not sure if they are salvaged from some Soviet era contaminated scrapyard.

![IMG-20180319-WA0007](https://user-images.githubusercontent.com/28985966/126788682-389e18d5-115c-450b-9992-8a3984970a32.jpeg)

![IMG-20180319-WA0009](https://user-images.githubusercontent.com/28985966/126791696-fa4f2a50-22db-400e-a113-b326c6fac105.jpeg)


## Voltage Card

I soldered a [555 timer power supply](https://www.ledsales.com.au/pdf/555_kit.pdf) from basic components. I couldn't find exact parts from local sources and bought 2-3 different inductors, at some point the circuit reached max 180V. First supply board worked for a long time until I shorted it accidently, made a second board with spare parts and added a static cooler to the MOSFET.

This is a design choice, you can make one from basic parts or purchase a card from some vendor. If you are concerned about voltage range or you don't have abundant time and patience I recommend buying one.

First supply board with extra symbol tubes

![image](https://user-images.githubusercontent.com/28985966/126798058-14f500a7-ee8d-49b4-8724-e4e36494da7a.png)


![image](https://user-images.githubusercontent.com/28985966/126801428-0ff7941b-40e3-44da-b27a-6de26ce5b278.png)

Second board with cooler

![image](https://user-images.githubusercontent.com/28985966/126806871-d578747d-b1db-46e0-bb80-ee6bfbbf7bd5.png)


## Driver

After constructing a sufficient power supply I designed a very redundant tube driver. I wanted to create some modular high voltage drivers for future projects.  

For every digit 4 bits are needed, I used a pair of CD74HC238E 3-to-8 line decoders for every tube and used high voltage transistors to enable the nixie tube's specific pin/number. 

![image](https://user-images.githubusercontent.com/28985966/126802136-b6207000-11dc-4c02-a50a-a848098fd19b.png)

Wired up an Arduino Uno

[![Second video](https://img.youtube.com/vi/qUaKFGdwrgs/0.jpg)](https://www.youtube.com/watch?v=qUaKFGdwrgs)

All 6 boards

![image](https://user-images.githubusercontent.com/28985966/126812323-0b6f56cc-1902-4d49-902f-fc64c002466a.png)

## Main Board
I completed the digit drivers and started to implement the main board for MCU. I decided to use an Arduino Mega with an external clock. Simply distributed the pins to cable connections. Until this point I used jumpers or crocodile cables to connect boards together and used breadboards for Arduino IO connections, after completing the main board I pressed flat ribbon cables for every connection. 

Normally specialized IDC crimp tools are used for cable connectors, but I used a cheap bench clamp.

I strongly recommend using properly insulated connections while working with high voltage!  

![image](https://user-images.githubusercontent.com/28985966/126817051-ff466bec-cbae-478d-8d72-c545ab555c05.png)

## Assembly

Connected tubes to driver boards with these isolated socket/connectors. Original tube sockets are the best option for maintainability.

![image](https://user-images.githubusercontent.com/28985966/126826947-dad2f21c-a53d-4282-b63c-497df5c775f2.png)

Fully assembled. March 2018 to October 2018.

![image](https://user-images.githubusercontent.com/28985966/126828447-6382e6bd-ea40-4106-a66f-5c6e51df6fba.png)

Desk for scale

![image](https://user-images.githubusercontent.com/28985966/126834625-3ebe124a-7c2f-4d89-baaf-41c744d922fb.png)


## Programming
This is the easy part, at least you can't electrocute yourself. 

Arduino Mega just simply applies voltage to each digit. Refreshing all tubes with a proper frame rate creates a solid view. Additionally I used a sound sensor for clock display activation. 

Final result

![dark_theme](https://user-images.githubusercontent.com/28985966/126835887-5a8c6e0a-f48e-4b84-ac48-84d94cca40b7.gif)







