// LCD Screen, Switch & LED подесувања
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LCDswitchPin = 7; // Дефинирање на кој пин е switch-от за мени за песни
int LCDswitchState = 0; // Дефинирање на состојба switch-от за мени за песни
int prevLCDswitchState = 0; //Предходна состојба на switch-ot за мени за песни
int blueLED = 6; //Пин на сината лед диода
int LCDswitchCounter = 0;   //Бројач кој брои колку пати е притиснато копче(switch) за мени за песни, 
    // според тоа колку пати е кликнато копчето се листа низ менито,
	// односно бројачот почнува од нула, кога прв пат ќе го притиснеме копчето за мени се вклучува LCD дсисплејот,
	// кога прв пат ќе го претиснеме копчето за мени ОДКАКО се вклучил дисплејот бројачот се зголемува на 1
	// и се прикажува насловот на првата песна,кога ќе го притиснеме копчето за мени втор пат се прикажува насловот
	// на втората песна итн. Кога ќе стигне борјачот до последната песна и го притиснеме копчето пак, бројачот се
	// ресетира и LCD дисплејот ќе се исклучи. Кога е исклучен дисплејот тогаш можеме да ги користиме копчињата
	// на пијано односно седумте копчиња кои се користат за свирење на пијано односно на седумте ноти.



//******************************************************************
//**  Дефинирање на музички ноти, односно доделување на фреквенција 
//******************************************************************
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
//***************** SONG 5 НОТИ **************************
void Song5()  {
  
  lcd.clear();


// Ноти во мелодијата:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Времетраење на нотите: 4 = четврт нота, 8 = осмина нота, итн.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

	//Принтање на дисплејот
  
      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("  SONG 5 TITLE");
     
      

      int thisNote = 0;

        // За да се пресмета реалното времетраење на нотите,
        // треба една секунда да ја поделиме со времетраењето на нотата.
  		// (дефинирани погоре во низата noteDurations)
        // четврт нота = 1000 / 4, осмина нота = 1000/8, итн.
      for (int thisNote = 0; thisNote < 8; thisNote++) { 
        
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
      	//За да можеме да ја чуеме нотата односно да не се мешаат ноти туку да се свират една по една,
        // ќе треба да дефинириаме време помеѓу нотите и да почекаме да се одсвири нотата 
        // пред да започне друга нота. Затоа тоа време ќе биде 30% плус од времетраењето на една нота
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(8); //Со оваа функција се стопира свирењето на нота од звучникот:
        } 


Song5title();

  
  } // end Song5 loop

//***************** SONG 4 NOTES HERE **************************
void Song4()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("  SONG 4 TITLE");
     
      

      int thisNote = 0;

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      for (int thisNote = 0; thisNote < 8; thisNote++) { 
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
      
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(8); // stop the tone playing:
        } // end for


Song4title();

  
  } // end Song4 loop

//***************** SONG 3 NOTES HERE **************************
void Song3()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
	NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2,
	NOTE_C3, NOTE_F3, NOTE_C3,
	NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
	NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
	NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2, // repeat line 1 and 2
	NOTE_C3, NOTE_F3, NOTE_C3,
	NOTE_AS3, 0, NOTE_G3, NOTE_F3,
	NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
	4,    4,    4,    8,   8,
	4,    4,          2,
	4,    4,    4,    4,
	3,    8,    8,    8,    8,   8,
	4,    4,    4,    8,    8, // repeat line 1 and 2
	4,    4,          2,
	4,    8,    8,    4,    4,
	4,    4,    4,    4,
	0};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("    JEOPARDY");
     
      

  for (int thisNote = 0; noteDurations[thisNote] != 0; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration * 0.9);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
	delay(noteDuration);
  }


Song3title();

  
  } // end Song3 loop
//***************** SONG 2 NOTES HERE **************************

///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////  FULL TUTORIAL ON HOW TO CREATE THE MARIO SONGS CAN BE FOUND HERE:  /////////////////////////
/////////  http://www.linuxcircle.com/2013/03/31/playing-mario-bros-tune-with-arduino-and-piezo-buzzer/  
///////////////////////////////////////////////////////////////////////////////////////////////////////

void Song2()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("MARIO UNDERWORLD");
     
      


    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(8, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(8, 0, noteDuration);
 
    }


Song2title();

  
  } // end Song2 loop
//***************** SONG 1 NOTES HERE **************************

///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////  FULL TUTORIAL ON HOW TO CREATE THE MARIO SONGS CAN BE FOUND HERE:  /////////////////////////
/////////  http://www.linuxcircle.com/2013/03/31/playing-mario-bros-tune-with-arduino-and-piezo-buzzer/  
///////////////////////////////////////////////////////////////////////////////////////////////////////

void Song1()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("MARIO THEME SONG");
     
      


    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(8, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(8, 0, noteDuration);
 
    }


Song1title();

  
  } // end Song1 loop
int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Set notes C, D, E, F, G, A, B



//////////////////////////////////////////////
void setup() {
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  pinMode(LCDswitchPin, INPUT);
  pinMode(blueLED, OUTPUT);
  digitalWrite(blueLED, LOW); // LED stays off while piano keys are on
  

} // end setup


//////////////////////////////////////////////
void loop() {
  
  LCDswitchState = digitalRead(LCDswitchPin);
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  lcd.noDisplay();
  digitalWrite(blueLED, LOW); // Turn LED back off every time main loop starts
  


// ************** START "LCDstart" WHEN MENU BUTTON IS PUSHED ***********

    if (LCDswitchState == HIGH)  {
      digitalWrite(blueLED, HIGH); // Turn LED on to show piano keys are disabled and device is in "menu mode"
      lcd.display();
      lcd.clear();
      LCDstart();
      }
   
   
// ***********************************************************************
  
  

////// KEYBOARD NOTES & FREQUENCY STATEMENTS //////
// Use the resistor ladder you created to change the voltage of each piano key button
// 220 ohm = C5 // 560 ohm = D5 // 1K ohm = E5 // etc...
  if(keyVal == 1023)  {
    tone(8, notes[0]); // C
    } // end if
    
        else if(keyVal >= 990 & keyVal <=1010)  {
          tone(8, notes[1]); // D
          } // end else if
    
        else if(keyVal >= 960 && keyVal <= 980)  {
          tone(8, notes[2]); // E
          } // end else if
        
        else if(keyVal >= 900 && keyVal <= 945)  {
          tone(8, notes[3]); // F
          } // end else if
        
        else if(keyVal >= 650 && keyVal <= 710)  {
          tone(8, notes[4]); // G
          } // end else if
        
        else if(keyVal >= 500 && keyVal <= 550)  {
          tone(8, notes[5]); // A
          } // end else if
        
        else if(keyVal >= 5 && keyVal <= 10)  {
          tone(8, notes[6]); // B
          } // end else if
        
        else if(keyVal <= 1)  { // if no switch is pressed, do not play tone
          noTone(8);
          } // end else if

} //end frequency tone loop





/////////////////////////////////////////////////////
void LCDstart()  {
  int keyVal = analogRead(A0);  
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button

    while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed
      LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button every time loop starts
      
      //************* START SONG 1 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 1
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song1title();
        lcd.clear();
        break;
        }

      //************* ELSE SHOW MENU ****************
      else   {  // if menu button is not pressed, then...
        LCDswitchCounter=0; // set menu button count to 0
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WHICH SONG WOULD");
        lcd.setCursor(0, 1);
        lcd.print("YOU LIKE TO PLAY");
        delay(50); // return to main 
        }
     
      } // end while
  } // end LCDstart loop
  
  
  

// ************* SONG 1 LOOP STARTS HERE **************  
void Song1title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 2 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 2
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song2title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed   
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song1();
           break;
           } // end if
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SUPER MARIO BROS");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
    } // end while song 1 -> 2
        
} // end Song1title loop




// ************* SONG 2 LOOP STARTS HERE **************  
void Song2title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 3 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 3
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song3title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song2();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SUPER MARIO BROS");
          lcd.setCursor(0, 1);
          lcd.print("   UNDERWORLD");
          delay(50);
          }
        
        } // end while song 2 -> 3
        
} // end Song2title loop




// ************* SONG 3 LOOP STARTS HERE **************  
void Song3title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 4
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song4title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song3();
           break;
           } // end if
           
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    JEOPARDY");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
        
        } // end while song 3 -> 4
        
} // end Song3title loop





// ************* SONG 4 LOOP STARTS HERE **************  
void Song4title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 5 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 5
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song5title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song4();
           break;
           } // end if
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     SONG 4");
          lcd.setCursor(0, 1);
          lcd.print("   TITLE HERE");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song4title loop




// ************* SONG 5 LOOP STARTS HERE **************  
void Song5title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter=0; // set button count to 0
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more
        lcd.clear();
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song5();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     SONG 5");
          lcd.setCursor(0, 1);
          lcd.print("   TITLE HERE");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song5title loop