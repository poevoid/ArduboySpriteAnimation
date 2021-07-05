#pragma once

#include "vars.h"


void animate() { //just animates
  if (currentframe < lastframe) {
    ++currentframe;
  }
  else {
    currentframe = firstframe;
  }
}

void updateSprite() { //animates and allows player to move sprite
  if (arduboy.everyXFrames(9)) {
    animate();
  }
  if (arduboy.pressed(LEFT_BUTTON)) {
    --spritex;
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    ++spritex;
  }
  if (arduboy.pressed(UP_BUTTON)) {
    --spritey;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    ++spritey;
  }
}

void drawSprite(uint8_t* sprite) {
  Sprites::drawOverwrite(spritex, spritey, sprite, currentframe);
  Sprites::drawOverwrite(12, 0, sprite, 0);
  Sprites::drawOverwrite(24, 0, sprite, 1);
  Sprites::drawOverwrite(36, 0, sprite, 2);
  Sprites::drawOverwrite(48, 0, sprite, 3);
}


void gameloop() {
  switch (gamestate) {

    case 0:
      //title
      arduboy.setCursor(0, 0);
      arduboy.print("Animation demo");
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 1;
      }
      break;

    case 1:
      drawSprite(skeleton_guard);
      updateSprite();
      //animate(); //uncomment for plain animation demo
      break;

  }
}
