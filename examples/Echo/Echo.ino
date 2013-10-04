#include <TextInput.h>

TextInput  TXT;

void onTextInput(const char* txt) {
    Serial.println(txt);
}

void setup() {
    Serial.begin(115200);
    
    TXT.begin(Serial, 50);
    TXT.subscribe(onTextInput);
    
    Serial.println("Started");
}

void loop() {
    TXT.loop();
}
