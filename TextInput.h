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
 
#ifndef __TEXT_INPUT_H__
#define __TEXT_INPUT_H__

#include <Arduino.h>
#include <Stream.h>

typedef void (*OnLineReceiveFuncton)(const char*);

class TextInput {
protected:
	OnLineReceiveFuncton onReceive;

	Stream*  			 input;
	char* 				 buffer;
	
	byte 				 pos;
	byte			     length;
	
	
public:
			  TextInput();

	void	  begin(Stream& anInput, byte length);
	void 	  loop();

	void      subscribe(OnLineReceiveFuncton callback);
};

inline void TextInput::subscribe(OnLineReceiveFuncton callback) {
	onReceive = callback;
}


#endif //__TEXT_INPUT_H__
