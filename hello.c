#include <gb/gb.h>
#include <time.h>
#include <gb/drawing.h>
#include "hello.h"
#include "tile.h"
#include "map.h"
#include "sprite.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 18

struct point {
  UINT8 x;
  UINT8 y;
};


// key status
static UINT8 prev_keys;
static UINT8 current_keys;
static UINT8 pushed_keys;

struct point myposition;
UINT8 fall_speed = 0;

void main() {

  set_bkg_data(0, 3, tile);
  set_bkg_tiles(0, 0, mapWidth, mapHeight, map);
  set_sprite_data(0, 1, sprite);

  SPRITES_8x8;

  set_sprite_tile(0, 0);

  // Initialize
  myposition.x = 8;
  myposition.y =16;

  // Main Loop
  for(;;) {

    current_keys = joypad();
    pushed_keys = (prev_keys ^ current_keys) & current_keys;

    if (pushed_keys & J_LEFT) {
      myposition.x -= 8;
    }
    if (pushed_keys & J_RIGHT) {
      myposition.x += 8;
    }

    if (pushed_keys & J_UP) {
      myposition.y -=8;
    }

    if (pushed_keys & J_DOWN) {
      myposition.y += 8;
    }
    
    prev_keys = current_keys;

    move_sprite(0, myposition.x, myposition.y);

    SHOW_BKG;
    SHOW_SPRITES;
  }
}

