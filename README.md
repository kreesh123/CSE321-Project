Automated Light Swtich - README

Overiview
We will be implementing a design for an automated light switch. This switch is meant to help a person financially by automatically turning the lights on if it senses motion and turning the lights off by checking after a certain amount of time. The sensor will check after some time is there is still motion in the room, if there is, then the room will stay lit for the allotted amount of time, if there is no movement, the lights will turn off themselves.  

 

Motion can be any movement the sensor recognizes. The user can manually turn off the lights and turn them on if they want to override the sensor. This is meant to help save money by not having the lights left on when no one is in the room, assisting the user financially. 

Hardware Components 

Our project consists of an Arduino Uno, and several other components. These include: A motion sensor, an LED that responds to the motion detected, and a manual override switch/button to override the input from the sensor. 

The exact components are: 

Arduino Uno Rev 3 

HC-SR501 PIR Motion Sensor 

Chanon SPDT Mini Slide Switch 

LED Light Diodes 



Software Components 

Motion-based control 

The Manual Override Handling part of the code detects the moment the switch is pressed and toggles the light state. When the switch is pressed, it enters override mode and temporarily ignores the motion sensor, so it doesn’t immediately turn the light back on or off. So, each button presses cleanly toggles the light and temporarily disables automatic control. 


The Override Timer makes sure the manual override only lasts for a limited amount of time. Once the override is activated, it keeps track of how long it’s been active. After the delay has passed, the system automatically ends the override and gives the control back to the motion sensor. 


The Motion-based Control section controls the light based on motion when the system is not in manual override mode. When the motion is detected, the light turns on, and a timer is reset, so the system knows when the movement occurred. If no movement happens for the full duration of the time, the system will decide if there is no movement and turns the light off automatically. 
