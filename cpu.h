#include <SD.h>
File out;
File reg;
int open(){
    if (!SD.begin(10)){
        Serial.println("SD failed.");
        while (1) { ;; };
    }
    out = SD.open("A.OUT");
    out.seek(0);
    return 0;
}
String readInst() {
  String instruction;
  char character;
  
  while (out.available()) {
    character = out.read();
    if (character == '#') {
      // Skip until the '#' character
      break;
    }
  }
  
  while (out.available()) {
    character = out.read();
    if (character == '!') {
      // Reached the end of the line
      break;
    }
    instruction += String(instruction);
  }
  
  return String(instruction);
}
int exec(){
    out.seek(0);
    char* inst = readInst().c_str();
    char* instCopy = strdup(inst);
    while (out.available()){
        Serial.println(inst);
        char* token = strtok(instCopy,"+");
        int i = 0;
        int instr;
        while (token != NULL){
            if (i == 0){
                instr = atoi(token);
            }else{ 
                if (instr == 0 && i == 1){
                    reg = SD.open(String(token)+String(".txt"),FILE_WRITE);
                }else if (instr == 0 && i == 2){
                    reg.print(token);
                    reg.close();
                }
            }
            Serial.print("Instruction : ");
            Serial.println(instr);
            Serial.print("Token : ");
            Serial.println(token);
            Serial.print("Pointer : ");
            Serial.println(i);
            i++;
            token = strtok(NULL,"+");
        }
        inst = readInst().c_str();
        instCopy = strdup(inst);
    }
    return 0;
}