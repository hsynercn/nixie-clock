# Tube Purchase
Several years ago I decided to build a 6-digit nixie clock from scratch. After some research I found a tube vendor which can deliver to Turkey/Istanbul. I purchased a dozen of of IN-12A nixie tubes and IN-12 / IN-15 / IV-22 sockets. If I remember correctly I paid 2.5 USD for one tube and 1.0 USD one socket. I bought them in March 2018, today (July 2021) tubes are 12.0 USD, sockets are 2.0 USD. If you have any intention to build a clock don't wait.

Nearly one month later I received the package with 4 extra tubes. They were covered in dirt, some of them had mud between their pins. Even today I am not sure if they are salvaged from some Soviet era contaminated scrapyard.

![IMG-20180319-WA0007](https://user-images.githubusercontent.com/28985966/126788682-389e18d5-115c-450b-9992-8a3984970a32.jpeg)

![IMG-20180319-WA0009](https://user-images.githubusercontent.com/28985966/126791696-fa4f2a50-22db-400e-a113-b326c6fac105.jpeg)


# Voltage Card

I soldered a [555 timer power supply](https://www.ledsales.com.au/pdf/555_kit.pdf) from basic parts. I couldn't find exact parts from local sources and bought 7 or 8 inductors, at some point I reached max 180V with a combination. This board worked for a long time until I shorted it accidently later resoldered it with replacement parts adn added a static cooler to MOSFET.

This is a design choice, you can make one from basic parts or purchase a PCB from some vendor. If you are concerned about high voltage or you don't have abundant time and patiance I recommend buying one.

First supply board with extra symbol tubes

![image](https://user-images.githubusercontent.com/28985966/126798058-14f500a7-ee8d-49b4-8724-e4e36494da7a.png)


![image](https://user-images.githubusercontent.com/28985966/126801428-0ff7941b-40e3-44da-b27a-6de26ce5b278.png)

Second board with cooler

![image](https://user-images.githubusercontent.com/28985966/126806871-d578747d-b1db-46e0-bb80-ee6bfbbf7bd5.png)



# Driver

After constructing a suffcient power supply I designed a redundant very redundant tube driver. I wanted to create some modular high voltage drivers for future projects.  

For every digit 4 bits are needed, I used a pair of CD74HC238E 3-to-8 line decoders for every digit and used high voltage transistors to enable nixie tube's specific pin-number. 

![image](https://user-images.githubusercontent.com/28985966/126802136-b6207000-11dc-4c02-a50a-a848098fd19b.png)




