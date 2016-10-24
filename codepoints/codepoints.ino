// Codepoints.
//
// Copyright 2016 Henry Strickland (strickyak)
// Licensed under the MIT License.
//
// All it does is show you the glyphs in the
// builtin 5x7 character generator library.
// Use buttons to scroll up & down.
//
// Some of these are not available with the print()
// method, but all of them can be used with write().
//
// cf  https://en.wikipedia.org/wiki/Code_page_437

#include <Arduboy.h>
Arduboy A;

char hex[] = "0123456789ABCDEF";

int p;
void Draw() {
  for (int j = 0; j < 7; j++) {
    A.setCursor(5, j * 10);
    int cp = 255 & ((p + j) * 8);
    A.write(hex[(cp >> 4) & 15]);
    A.write(hex[(cp >> 0) & 15]);
    for (int i = 0; i < 8; i++) {
      A.setCursor(30 + i * 10, j * 10);
      A.write((8 * (p + j) + i) & 255);
    }
  }
}

void setup() {
  A.beginNoLogo();
  A.setFrameRate(30);
  A.setCursor(20, 20);
  A.clear();
  A.print("Codepoints.");
  A.display();
  delay(1000);
}

void loop() {
  int bs = A.buttonsState();
  if (bs & UP_BUTTON) p--;
  if (bs & DOWN_BUTTON) p++;
  if (bs & LEFT_BUTTON) p--;
  if (bs & RIGHT_BUTTON) p++;
  if (bs & A_BUTTON) p--;
  if (bs & B_BUTTON) p++;
  A.clear();
  Draw();
  A.display();
  delay(100);
}

