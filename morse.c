//
//  Morse Code Playback Functions
//  Mark Jessop 2018-04
//
//  Based on code from https://github.com/Paradoxis/Arduino-morse-code-translator/blob/master/main.ino
//
#include "morse.h"

// Letters
char* MORSE_LETTERS[] = {
  ".-",     // A
  "-...",   // B
  "-.-.",   // C
  "-..",    // D
  ".",      // E
  "..-.",   // F
  "--.",    // G
  "....",   // H
  "..",     // I
  ".---",   // J
  "-.-",    // K
  ".-..",   // L
  "--",     // M
  "-.",     // N
  "---",    // O
  ".--.",   // P
  "--.-",   // Q
  ".-.",    // R
  "...",    // S
  "-",      // T
  "..-",    // U
  "...-",   // V
  ".--",    // W
  "-..-",   // X
  "-.--",   // Y
  "--.."    // Z
};



// Numerals.
char* MORSE_NUMBERS[] = {
  "-----",   // 0
  ".----",   // 1
  "..---",   // 2
  "...--",   // 3
  "....-",   // 4
  ".....",   // 5
  "-....",   // 6
  "--...",   // 7
  "---..",   // 8
  "----."    // 9
};

// Symbols (though we handle this in a bit of a hacky way.)
char* MORSE_SYMBOLS[] = {
  ".-.-.-", // .
  "-..-."   // /
};


// Send a single character
void sendDotOrDash (char unit, int wpm) {

  radio_enable_tx();

  // Unit is a dot (500 ms)
  if (unit == MORSE_DOT) {
    _delay_ms(1200 / wpm);
  }

  // Unit is a dash (1500 ms)
  if (unit == MORSE_DASH) {
    _delay_ms((1200 / wpm) * 3);
  }

  // Inter-element gap
  radio_inhibit_tx();
  _delay_ms(1200 / wpm);
}


void sendMorseSequence (char* sequence, int wpm) {

  // Counter
  int i = 0;

  // Loop through every character until an 'end-of-line' (null) character is found
  while (sequence[i] != '\0') {
    sendDotOrDash(sequence[i], wpm);
    i++;
  }

  // Delay between every letter
  _delay_ms((1200 / wpm) * 3);
}



void sendMorse(char* message, int wpm) {

  int i = 0;
  while (message[i] != '\0') {
    char current = message[i];

      // Lower case letters
      if (current >= 'a' && current <= 'z') {
        sendMorseSequence(MORSE_LETTERS[current - 'a'], wpm);
      }

      // Capital case letters
      else if (current >= 'A' && current <= 'Z') {
        sendMorseSequence(MORSE_LETTERS[current - 'A'], wpm);
      }

      // Numbers
      else if (current >= '0' && current <= '9') {
        sendMorseSequence(MORSE_NUMBERS[current - '0'], wpm);
      }

      else if (current == '.') {
        sendMorseSequence(MORSE_SYMBOLS[0], wpm);
      }

      else if (current == '/') {
        sendMorseSequence(MORSE_SYMBOLS[1], wpm);
      }

      // Space character (3500  ms)
      else if (current == ' ') {
        _delay_ms((1200 / wpm) * 7);
      }

      // Treat all other characters as a space.
      else {
        _delay_ms((1200 / wpm) * 7);
      }

    i++;
  }

  radio_disable_tx();
}


