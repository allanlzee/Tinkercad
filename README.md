# Tinkercad
Tinkercad project for TER3M1. 

6.1 Assignment: Projects by Arduino - Keyboard Instrument

Write a one to two page summary of the project - the idea behind it, the components that it uses (you don't need to include things like wires, resistors, the arduino and breadboards). Include a picture of the tinkercad and real-life version of each component and a brief description of its purpose and how it's wired.

The assigned document is clear and without errors. Students effectively present their circuit and description to their classmates. 

Initial Project: 
https://www.tinkercad.com/things/5NYtwprJezS-writing-the-code/editel?lessonid=E213TJWISCBWUP0&projectid=OP98ET3ISCC2EQ5&collectionid=OMOZACHJ9IR8LRE&sharecode=nVgdHW605VSGMDvsP_mcSew8ChEJmTerB2-1wDLuiuw

Revision: 
https://www.tinkercad.com/things/i1iwXiKr0TL-copy-of-arduino-piano/editel?sharecode=bTn0CUC7eu6BwOPTvBxSFN8it1z5pb9ZBsT68ZKwQZ8

Final:
https://www.tinkercad.com/things/c4fJSDnGFMy-surprising-jofo/editel?sharecode=GI25iU2pwszmin0OSFRaI-gm8PspU24TYE3AOTIv0Qo
 
Electrical Components:
2 Piezo Buzzers
Purpose: To output a sound of a certain frequency that correlates with a “musical” note.
Wiring: Negative pin connected to ground, positive pin connected to digital port of Arduino.
Arduino:	    Real Life:

 
4 Pushbuttons (Initial Project), 13 Pushbuttons (Final Project)
Purpose: To act as an input that signals the performance of a certain function.
Wiring: Terminal 1a connected to power, Terminal 2a connected to digital port of arduino, and also to ground using a resistor (to prevent voltage leak)
Arduino:	    Real Life:

 
2 Potentiometers
Purpose: To control different levels of a certain variable using the analog function.
Wiring: Terminal 1 connected to power, terminal 3 connected to ground, wiper connected to analog port of Arduino.
Arduino:	      Real Life:

 
2 10 k-ohm resistors,  1 220 ohm resistor, 1 M-ohm resistor (Initial Project)    
13 690 ohm resistors, 2 6900 ohm resistors (Final Project)









Summary:

The purpose of this project is to create a remake of a keyboard on TinkerCad.

The first keyboard instrument used one piezo buzzer, four push buttons, and other basic Arduino components. Initially, the piezo's tone was determined by the resistance of the resistors connected to the push buttons to the Arduino. While this was somewhat accurate, we found the method to be unnecessarily complicated and inconsistent. 

The keyboard works by setting buttons to send a specific frequency to the Piezo buzzer. The buzzer will end up buzzing the frequency requested. There are a few problems with the project. First of all, there are only four notes in the base project. The limited range leaves no satisfaction for the user and the lack of notes defeats the purpose of using a keyboard instrument. We try to increase the number of keys available in our improved version. Furthermore, a significant problem is sound. The buzzer makes an irritating sound when playing a frequency. The “music”, if you can call it that, is a loud annoying buzz that rings painfully throughout the room. Unfortunately, this is a more difficult problem to fix than just adding a few notes. This problem is very difficult to change due to its technicality, and we decided we are going to keep it like that. 

In the initial model, the project relied on varying resistances to control the pitch of a note, using a concept known as a “Resistor Ladder”, where pushing a certain button essentially produces a different voltage divider. However, we found that relying on the hardware limits the capabilities of the musical instrument. Since further resistance values are unknown, we would not be able to incorporate the full extent of notes in a scale. Also, being able to manipulate frequencies within the code would even allow for the fabrication of semitones (sharps and flats), and multiple octaves in addition to more accurate tones. 

The revisions we have made from the initial project are going to tackle some of the problems we have faced while making the base project. We are changing the number of notes on the keyboard and removing the resistor ladder to simplify how we make the new notes. It would make implementing new notes too tedious if we were to test resistor values for each new note. The issue of sound quality was slightly improved on through the addi a delay. 

Coding our proposed revisions and additional implementations required push-button interaction and digital reading for Piezo frequency. We have 12 buttons for each of the notes in an octave, each of which has a pin mode setup. The Arduino will read whether the button is being pressed using digital read in a conditional statement, which will trigger the tone function for its corresponding note if true. Note that our project incorporates two Arduinos--one for the notes in the C Major scale, and one for the sharps and flats. The code also supports octave changing, using custom functionality (octaveMultiplier = pow(2, state)). The value of this will multiply the frequency of each function accordingly. See https://github.com/allanlzee/Tinkercad for the original code. 

Extension and how we are doing it
More resistance, the lower the sound, the better for our ears
More notes, full scale including sharp, resulting in additional arduino because of the lack of digital squares
Changing octaves 
We made different potential meters for the sharps and whole notes because there were glitches in Tinkercad that we wanted to avoid. (Wires got stuck, and pieces got stuck) 


Conclusion 











Build Process Images:















Resistor Ladder:
In the initial model, the project relied on varying resistances to control the pitch of a note, using a concept known as a “Resistor Ladder”, where pushing a certain button essentially produces a different voltage divider. However, we found that relying on the hardware limits the capabilities of the musical instrument. Since further resistance values are unknown, we would not be able to incorporate the full extent of notes in a scale. Also, being able to manipulate frequencies within the code would even allow for the fabrication of semitones, and multiple octaves in addition to more accurate tones. 

Let's take a closer look at the resistor ladder, which connects the 4-button keyboard to a single analog pin.

All of the buttons share one terminal connection at pin A0. The other terminals are connected to the 5 volt pin through resistors of different values., resulting in a different voltage at A0.

For example:

If no buttons are pressed, A0 sees 0 volts or ground.

Pressing the first button results in 5V input.

Pressing the 3rd button results in 2.5V input.
