/* Qduino RGB LED Rainbow Example
  
   This example controls the user RGB LED near the top
   of the board.
  
   created on 30 Jun 15
   made by Quin Etnyre
*/

#include "Qduino.h"
#include "Wire.h"

qduino q;  // initialize the library

void setup() {
  
  q.setup();

}

void loop() {
  
  // 1 = faster, 5 = slower
  
  q.rainbow(1);  // number between 1 & 5
  
}
