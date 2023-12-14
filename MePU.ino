#include "cpu.h"
void setup(){
    Serial.begin(9600);
    open();
    Serial.println(exec());
}
void loop(){

}