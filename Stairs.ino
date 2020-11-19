#include <FastLED.h>

#define COLOUR        Yellow
#define BUTTON_PIN    2
#define LED_PIN       7
#define NUM_LEDS      60
#define BRIGHTNESS    50
#define LED_TYPE      WS2812B
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];

// how fast the motion should be
#define UPDATES_PER_SECOND 20

// variable for reading the pushbutton status
int buttonState = 0;                          

void setup() {
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN, INPUT);             
  
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);        

  // if the button is pressed
  if (buttonState == HIGH) {
    
    for(int i = 0; i < NUM_LEDS; i++){

      // displays the color you've selected in the start of the code
      leds[i] = CRGB::COLOUR;
      
      FastLED.show();
      FastLED.delay(1000 / UPDATES_PER_SECOND);
          
    }

    // delay for the leds to stay lit (depending on your speed going up the stairs :P )
    delay(9000);
    
  } else {

    // turn off the led strip
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
        
    }
  
}
