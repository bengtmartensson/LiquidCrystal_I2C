#pragma once

#include <Wire.h>

class LiquidCrystal_I2C : public Print {
    // commands
    static const unsigned int LCD_CLEARDISPLAY = 0x01;
    static const unsigned int LCD_RETURNHOME = 0x02;
    static const unsigned int LCD_ENTRYMODESET = 0x04;
    static const unsigned int LCD_DISPLAYCONTROL = 0x08;
    static const unsigned int LCD_CURSORSHIFT = 0x10;
    static const unsigned int LCD_FUNCTIONSET = 0x20;
    static const unsigned int LCD_SETCGRAMADDR = 0x40;
    static const unsigned int LCD_SETDDRAMADDR = 0x80;

    // flags for display entry mode
    static const unsigned int LCD_ENTRYRIGHT = 0x00;
    static const unsigned int LCD_ENTRYLEFT = 0x02;
    static const unsigned int LCD_ENTRYSHIFTINCREMENT = 0x01;
    static const unsigned int LCD_ENTRYSHIFTDECREMENT = 0x00;

    // flags for display on/off control
    static const unsigned int LCD_DISPLAYON = 0x04;
    static const unsigned int LCD_DISPLAYOFF = 0x00;
    static const unsigned int LCD_CURSORON = 0x02;
    static const unsigned int LCD_CURSOROFF = 0x00;
    static const unsigned int LCD_BLINKON = 0x01;
    static const unsigned int LCD_BLINKOFF = 0x00;

    // flags for display/cursor shift
    static const unsigned int LCD_DISPLAYMOVE = 0x08;
    static const unsigned int LCD_CURSORMOVE = 0x00;
    static const unsigned int LCD_MOVERIGHT = 0x04;
    static const unsigned int LCD_MOVELEFT = 0x00;

    // flags for function set
    static const unsigned int LCD_8BITMODE = 0x10;
    static const unsigned int LCD_4BITMODE = 0x00;
    static const unsigned int LCD_2LINE = 0x08;
    static const unsigned int LCD_1LINE = 0x00;
    static const unsigned int LCD_5x10DOTS = 0x04;
    static const unsigned int LCD_5x8DOTS = 0x00;

    // flags for backlight control
    static const unsigned int LCD_BACKLIGHT = 0x08;
    static const unsigned int LCD_NOBACKLIGHT = 0x00;

    static const unsigned int En = 0b00000100; // Enable bit
    static const unsigned int Rw = 0b00000010; // Read/Write bit
    static const unsigned int Rs = 0b00000001; // Register select bit

public:
  LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows);
  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS );
  void clear();
  void home();
  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void printLeft();
  void printRight();
  void leftToRight();
  void rightToLeft();
  void shiftIncrement();
  void shiftDecrement();
  void noBacklight();
  void backlight();
  void autoscroll();
  void noAutoscroll(); 
  void createChar(uint8_t, uint8_t[]);
  void createChar(uint8_t location, const char *charmap);
  // Example: 	const char bell[8] PROGMEM = {B00100,B01110,B01110,B01110,B11111,B00000,B00100,B00000};
  
  void setCursor(uint8_t, uint8_t); 
  virtual size_t write(uint8_t);
  void command(uint8_t);
  void init();
  void oled_init();

////compatibility API function aliases
void blink_on();						// alias for blink()
void blink_off();       					// alias for noBlink()
void cursor_on();      	 					// alias for cursor()
void cursor_off();      					// alias for noCursor()
void setBacklight(uint8_t new_val);				// alias for backlight() and nobacklight()
void load_custom_character(uint8_t char_num, uint8_t *rows);	// alias for createChar()
void printstr(const char[]);

////Unsupported API functions (not implemented in this library)
//uint8_t status();
//void setContrast(uint8_t new_val);
//uint8_t keypad();
//void setDelay(int,int);
//void on();
//void off();
//uint8_t init_bargraph(uint8_t graphtype);
//void draw_horizontal_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
//void draw_vertical_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
	 

private:
  void init_priv();
  void send(uint8_t, uint8_t);
  void write4bits(uint8_t);
  void expanderWrite(uint8_t);
  void pulseEnable(uint8_t);
  uint8_t _Addr;
  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;
  uint8_t _numlines;
  bool _oled = false;
  uint8_t _cols;
  uint8_t _rows;
  uint8_t _backlightval;
};
