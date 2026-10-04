#ifndef LORA_H_
#define LORA_H_

#include <RadioLib.h>
#define RADIO_BOARD_AUTO
#include <RadioBoards.h>

#define SYNC_WORD 0xB4

void lora_setup();

#endif