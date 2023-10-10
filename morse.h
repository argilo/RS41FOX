//
//  Morse Code Playback Functions
//  Mark Jessop 2018-04
//
#ifndef RS41FOX_MORSE_H
#define RS41FOX_MORSE_H

#include "config.h"
#include "radio.h"
#include "delay.h"

// All morse characters
#define MORSE_DOT '.'
#define MORSE_DASH '-'

void sendDotOrDash (char unit, int wpm);
void sendMorseSequence (char* sequence, int wpm);
void sendMorse(char* message, int wpm);


#endif //RS41FOX_MORSE_H
