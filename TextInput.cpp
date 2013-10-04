/**
 ** This is Public Domain Software.
 ** 
 ** The author disclaims copyright to this source code.  
 ** In place of a legal notice, here is a blessing:
 **
 **    May you do good and not evil.
 **    May you find forgiveness for yourself and forgive others.
 **    May you share freely, never taking more than you give.
 **/
 
#include <Arduino.h>
#include "TextInput.h"

TextInput::TextInput() :
	onReceive(NULL),
	input(NULL),
	buffer(NULL),
	pos(0),
	length(0) {
}

void TextInput::begin(Stream& anInput, byte len) {
	input = &anInput;
	if (buffer != NULL)
		free(buffer);
		
	buffer = (char*)malloc(length);
	length = len;
	pos = 0;
}

void TextInput::loop() {
	if (input == NULL || buffer == NULL)
		return;
	
	while(input->available()) {
		byte ch = input->read();
		if (ch == '\n') {
			buffer[pos] = 0;
			if (onReceive != NULL)
				onReceive(buffer);
			pos = 0;
		} else if (pos + 1 < length) {
			buffer[pos++] = ch;
		}
	}
}
