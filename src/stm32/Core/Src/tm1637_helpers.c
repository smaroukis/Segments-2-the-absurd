
#include "tm1637.h"


// Functions to write

// Example from README

// Requires initialized tm1637_t struct
void display_LOAD(tm1637_t *tm1637) {
    const uint8_t segment_data[4]  = {0x38, 0x5c, 0x77, 0x5e}; 
    tm1637_write_segment(tm1637, segment_data, 4, 0);
}

// EXAMPLES
void display_ex1(tm1637_t *tm1637) {
    tm1637_write_float(tm1637, -1.23, 2, 0);
}

void display_ex2(tm1637_t *tm1637) {
    tm1637_write_int(tm1637, 42, 0);
}

void display_ex3(tm1637_t *tm1637) {
    static int pos = 0;
    static int dir = 1;
    tm1637_write_int(tm1637, 42, pos);
    pos += dir;
    
    if (pos ==0 || pos == 2) {
        dir = -dir;
    }
    // delay
}

void display_test_segs(tm1637_t *tm1637) {
    // const uint8_t data[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    // loop through each digit
    for (int pos=0; pos < 4; pos++) {
        uint8_t data = 0x01;
        for (int seg=0; seg < 8; seg++) {
            // write out segment to digit
            const uint8_t * pData =  &data;
            // create mask with bit data 
            tm1637_write_segment(tm1637, pData, 1, pos);
            data = data << 1;
            // delay
            HAL_Delay(200);
        }
    }
}

// FADING 
// fade in / out
void display_fade_all(tm1637_t *tm1637) {
    for (int k = 0; k < 8; k++){
        // Incrase brightness memmber value
        tm1637_brightness(tm1637, k);

        tm1637_fill(tm1637, 1);
        HAL_Delay(200);
    }
}

void display_fade_one(tm1637_t *tm1637) {
    for (int k = 0; k < 8; k++){
        // Get the register contents
        // Mask the new content in


        // Increase brightness memmber value

        // How only affect one segment? probably need a rewrite
        tm1637_brightness(tm1637, k);


        tm1637_fill(tm1637, 1);
        HAL_Delay(200);
    }
}


// fade out and in a single segment while keeping others constant

