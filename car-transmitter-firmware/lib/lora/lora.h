// include RadioLib
#include <RadioLib.h>

// automatically detect which board is being used
#define RADIO_BOARD_AUTO

// now include RadioBoards
// this must be included AFTER RadioLib!
#include <RadioBoards.h>

#define SMV_SYNC_WORD 0xB4

void radio_setup();
