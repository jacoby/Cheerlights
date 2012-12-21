const int amberPin = 13 ;
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

const int len_time = 1000 ;

void setup() {
    // Setup Serial
    Serial.begin(9600);
    delay(100);
 
    Serial.flush();
    delay(100);
 
    // PWM Pin Setup
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(redPin, OUTPUT);
    c_white() ;
    delay(300) ;
    c_dark() ;
    delay(300) ;
    }

void loop(){
     char charIn = 0;     
     byte i = 0 ;
     char stringIn[32] = ""; 
     while(Serial.available()) {
         charIn = Serial.read();
         stringIn[i] = charIn; 
         i += 1;
         }
    String input = String( stringIn ) ;
    
    if ( input.length() > 0 ) {
        if ( input == "red"       ) { c_red() ; }
        if ( input == "green"     ) { c_green() ; }
        if ( input == "blue"      ) { c_blue() ; }
        if ( input == "cyan"      ) { c_cyan() ; }
        if ( input == "white"     ) { c_white() ; }
        if ( input == "warmwhite" ) { c_warmwhite() ; }
        if ( input == "purple"    ) { c_purple() ; }
        if ( input == "magenta"   ) { c_magenta() ; }
        if ( input == "yellow"    ) { c_yellow() ; }
        if ( input == "orange"    ) { c_orange() ; }
        Serial.println( input ) ;
        }
    delay(100); 
    }
 
void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
    analogWrite( redPin   , red   ) ;
    analogWrite( greenPin , green ) ;
    analogWrite( bluePin  , blue  ) ;
    }

void c_red()       { setColourRgb(   0, 255, 255 ) ; }
void c_green()     { setColourRgb( 255,   0, 255 ) ; }
void c_blue()      { setColourRgb( 255, 255,   0 ) ; }
void c_cyan()      { setColourRgb( 255,   0,   0 ) ; }
void c_white()     { setColourRgb(   0,   0,   0 ) ; }
void c_warmwhite() { setColourRgb(   0,  32,  32 ) ; }
void c_purple()    { setColourRgb( 128, 255, 128 ) ; }
void c_magenta()   { setColourRgb(   0, 255,   0 ) ; }
void c_yellow()    { setColourRgb(   0,   0, 255 ) ; }
void c_orange()    { setColourRgb(   0, 165, 255 ) ; }
void c_dark()      { setColourRgb( 255, 255, 255 ) ; }



