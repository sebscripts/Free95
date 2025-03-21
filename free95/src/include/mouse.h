#ifndef MOUSE_H
#define MOUSE_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MOUSE_COMMAND_PORT 0x64
#define MOUSE_DATA_PORT 0x60

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOUSE_CMD_RESET 0xFF
#define MOUSE_CMD_RESEND 0xFE
#define MOUSE_CMD_SET_DEFAULTS 0xF6
#define MOUSE_CMD_DISABLE_PACKET_STREAMING 0xF5
#define MOUSE_CMD_ENABLE_PACKET_STREAMING 0xF4
#define MOUSE_CMD_SAMPLE_RATE 0xF3
#define MOUSE_CMD_MOUSE_ID 0xF2
#define MOUSE_CMD_REQUEST_SINGLE_PACKET 0xEB
#define MOUSE_CMD_STATUS 0xE9
#define MOUSE_CMD_RESOLUTION 0xE8

#define MOUSE_ACKNOWLEDGE 0xFA

#define PS2_CMD_PORT 0x64    // read/write PS/2 command register
#define MOUSE_DATA_PORT 0x60 // PS/2 data port register see https://wiki.osdev.org/%228042%22_PS/2_Controller

typedef struct
{
    uint8_t left_button : 1;
    uint8_t right_button : 1;
    uint8_t middle_button : 1;
    uint8_t always_1 : 1;
    uint8_t x_sign : 1;
    uint8_t y_sign : 1;
    uint8_t x_overflow : 1;
    uint8_t y_overflow : 1;
} MOUSE_STATUS;

typedef struct
{
    int x, y;         // Mouse coordinates
    bool left, right; // Mouse button states
    bool middle;
} MouseState;

void mouse_initialize();
void mouse_poll();
uint8_t mouse_read();
void mouse_write(uint8_t data);

void mousedrv();

int mouse_getx();
int mouse_gety();
bool mouse_button_left();
bool mouse_button_right();
bool mouse_button_middle();

void mouse_init();
int mouse_getlc();
int mouse_getrc();
int mGetX();
int mGetY();

#endif
