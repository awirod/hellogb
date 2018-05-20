#include <gb/gb.h>
#include <gb/drawing.h>
#include "hello.h"
#include "tile.h"
#include "map.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 18

struct point {
  UINT8 x;
  UINT8 y;
};


// key status
static UINT8 keys;

struct point myposition;
UINT8 fall_speed = 0;

void main() {

  set_bkg_data(0, 3, tile);
  set_bkg_tiles(0, 0, mapWidth, mapHeight, map);

  // Initialize
  myposition.x = 24;
  myposition.y =24;

  // Main Loop
  for(;;) {

    keys = joypad();
    if (keys & J_LEFT) {
      myposition.x--;
    }
    if (keys & J_RIGHT) {
      myposition.x++;
    }

    if (keys & J_UP) {
      myposition.y--;
    }

    if (keys & J_DOWN) {
      myposition.y++;
    }
    
    SHOW_BKG;
    //circle(myposition.x, myposition.y, 4, M_NOFILL);
  }
}

