#include <FastLED.h>

#define COLOUR        SkyBlue
#define BUTTON_PIN1    2
#define BUTTON_PIN2    6
#define LED_PIN       7
#define NUM_LEDS      60
#define BRIGHTNESS    50
#define LED_TYPE      WS2812B
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];

// how fast the motion should be
#define UPDATES_PER_SECOND 15

// variable for reading the pushbutton status
int buttonState1 = 0;
int buttonState2 = 0;                            

void setup() {
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN1, INPUT);
  pinMode(BUTTON_PIN2, INPUT);             
  
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(BUTTON_PIN1); 
  buttonState2 = digitalRead(BUTTON_PIN2);       

  // if the button 1 is pressed
  if (buttonState1 == HIGH) {
    
    for(int i = 0; i < NUM_LEDS; i++){

      // displays the color you've selected in the start of the code
      leds[i] = CRGB::COLOUR;
      
      FastLED.show();
      FastLED.delay(1000 / UPDATES_PER_SECOND);
          
    }

    // delay for the leds to stay lit (depending on your speed going up the stairs :P )
    delay(9000);

  } 

  // if the button 2 is pressed
  else if (buttonState2 == HIGH) {
    
    for(int j = 1; j < NUM_LEDS; j++){

      // displays the color you've selected in the start of the code
      leds[NUM_LEDS - j] = CRGB::COLOUR;
      
      FastLED.show();
      FastLED.delay(1000 / UPDATES_PER_SECOND);
          
    }

    // delay for the leds to stay lit (depending on your speed going down the stairs :P )
    delay(9000);

  } 
  

  else {

    // turn off the led strip
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
        
    }

  
}
