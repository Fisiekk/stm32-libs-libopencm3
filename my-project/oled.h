#ifndef OLED_H
#define OLED_H

void oled_start_write(void);
void oled_write(uint8_t data);

void oled_cmd_write(uint8_t cmd);
void oled_write8(uint8_t data);

void oled_init(void);

void oled_box(uint8_t row_start, uint8_t row_end, uint8_t col_start, uint8_t col_end);
void oled_zero(void);
void oled_fill(uint8_t fill);
void oled_sleep(uint8_t state);
void oled_printf(uint8_t *string, uint8_t len);


extern uint8_t font8x8[33][9];

#endif
