/* Released into the public domain */
/* Earle F. Philhower, III <earlephilhower@yahoo.com> */

#include <Keyboard.h>

void setup() {
  Serial.begin(115200);
  //Keyboard.begin();
  Keyboard.begin(KeyboardLayout_fr_FR);
  //Keyboard.begin(KeyboardLayout_de_DE);
  //Keyboard.begin(KeyboardLayout_en_US);
  //Keyboard.begin(KeyboardLayout_es_ES);
  //Keyboard.begin(KeyboardLayout_it_IT);
 delay(5000);
  Serial.printf("Arduino USB Password Typer\n");
  Serial.printf("Press BOOTSEL to enter your super-secure(not!) password\n\n");
}

void loop() {
  if (BOOTSEL) {
    Serial.println("Typing password for you...shhhh....");
    Keyboard.print("ThisPasswordIsWeakLikeABaby");
    while (BOOTSEL);
  }
}
