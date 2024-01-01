#include <libopencm3/stm32/i2c.h>
#include <stdint.h>

#include "./oled.h"

uint8_t font8x8[33][9] =
    {
      {
	0b00011100,
	0b00110110,
	0b01100011,
	0b01100011,
	0b01111111,
	0b01100011,
	0b01100011,
	0b00000000
      },
      {
	0b00111111,
	0b01100011,
	0b01100011,
	0b00111111,
	0b01100011,
	0b01100011,
	0b00111111,
	0b00000000
      },
      {
	0b00111110,
	0b01111111,
	0b01100011,
	0b00000011,
	0b01100011,
	0b01111111,
	0b00111110,
	0b00000000
      },
      {
	0b00111111,
	0b01111111,
	0b01100011,
	0b01100011,
	0b01100011,
	0b01111111,
	0b00111111,
	0b00000000
      },
      {
	0b01111111,
	0b01111111,
	0b00000011,
	0b01111111,
	0b00000011,
	0b01111111,
	0b01111111,
	0b00000000
      },
      {
	0b01111111,
	0b01111111,
	0b00000011,
	0b01111111,
	0b01111111,
	0b00000011,
	0b00000011,
	0b00000000
      },
      {
	0b00111110,
	0b01111111,
	0b00000011,
	0b01111011,
	0b01100011,
	0b01111111,
	0b00111110,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b01100011,
	0b01111111,
	0b01100011,
	0b01100011,
	0b01100011,
	0b00000000
      },
      {
	0b01111111,
	0b00011100,
	0b00011100,
	0b00011100,
	0b00011100,
	0b00011100,
	0b01111111,
	0b00000000
      },
      {
	0b01111000,
	0b01100000,
	0b01100000,
	0b01100000,
	0b01100011,
	0b01100011,
	0b00111110,
	0b00000000
      },
      {
	0b01100011,
	0b00110011,
	0b00011011,
	0b00011111,
	0b00110011,
	0b01100011,
	0b01100011,
	0b00000000
      },
      {
	0b00000011,
	0b00000011,
	0b00000011,
	0b00000011,
	0b00000011,
	0b01100011,
	0b01111111,
	0b00000000
      },
      {
	0b01100011,
	0b01110111,
	0b01111111,
	0b01101011,
	0b01100011,
	0b01100011,
	0b01100011,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b01100111,
	0b01101111,
	0b01111011,
	0b01110011,
	0b01100011,
	0b00000000
      },
      {
	0b00111110,
	0b01100011,
	0b01100011,
	0b01100011,
	0b01100011,
	0b01100011,
	0b00111110,
	0b00000000
      },
      {
	0b00111111,
	0b01100011,
	0b01100011,
	0b00111111,
	0b00000011,
	0b00000011,
	0b00000011,
	0b00000000
      },
      {
	0b00111110,
	0b01100011,
	0b01100011,
	0b01100011,
	0b01101011,
	0b01100111,
	0b00111111,
	0b00000000
      },
      {
	0b00111111,
	0b01100011,
	0b01100011,
	0b00111111,
	0b01100011,
	0b01100011,
	0b01100011,
	0b00000000
      },
      {
	0b00111110,
	0b01100011,
	0b00000110,
	0b00011100,
	0b00110000,
	0b01100011,
	0b00111110,
	0b00000000
      },
      {
	0b01111111,
	0b01111111,
	0b00011100,
	0b00011100,
	0b00011100,
	0b00011100,
	0b00011100,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b01100011,
	0b01100011,
	0b01100011,
	0b01111111,
	0b00111110,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b00110110,
	0b00110110,
	0b00011100,
	0b00011100,
	0b00001000,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b01101011,
	0b01101011,
	0b00111110,
	0b00110110,
	0b00110110,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b00110110,
	0b00011100,
	0b00110110,
	0b01100011,
	0b01100011,
	0b00000000
      },
      {
	0b01100011,
	0b01100011,
	0b01100011,
	0b00111110,
	0b00011100,
	0b00011100,
	0b00011100,
	0b00000000
      },
      {
	0b01111111,
	0b00100000,
	0b00010000,
	0b00001000,
	0b00000100,
	0b00000010,
	0b01111111,
	0b00000000
      },
      
      {/*end of upper letters*/
  	0b00000000,
	0b00000000,
	0b00000000,
	0b01100011,
	0b01101011,
	0b01111111,
	0b00110110,
	0b00000000
      },
      {
	0b00000000,
	0b00011000,
	0b00011000,
	0b00000000,
	0b00000000,
	0b00011000,
	0b00011000,
	0b00000000
      },
      {
	0b00111110,
	0b01100011,
	0b01100000,
	0b00111110,
	0b01100000,
	0b01100011,
	0b00111110,
	0b00000000
      },
      {
	0b0000000,
	0b0000000,
	0b0000000,
	0b0000000,
	0b0000000,
	0b0000000,
	0b0111111,
	0b00000000
      },
      {
	0b00000000,
	0b00000000,
	0b00000000,
	0b01111111,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000
      },
      {
	0b00000000,
	0b00011000,
	0b01111110,
	0b01111110,
	0b00011000,
	0b00000000,
	0b01111110,
	0b00000000
      },
      {
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111
      }
    };

/*
    template
    {
	0b0,
	0b0,
	0b0,
	0b0,
	0b0,
	0b0,
	0b0,
	0b00000000
      },
   */

/*bus things*/
void oled_start_write(void)
{
  while ((I2C_SR2(I2C1) & I2C_SR2_BUSY)) {
  }
 
  i2c_send_start(I2C1);
 
  /* Wait for the end of the start condition, master mode selected, and BUSY bit set */
  while ( !( (I2C_SR1(I2C1) & I2C_SR1_SB)
	     && (I2C_SR2(I2C1) & I2C_SR2_MSL)
	     && (I2C_SR2(I2C1) & I2C_SR2_BUSY) ));
 
  i2c_send_7bit_address(I2C1, 0x3C, I2C_WRITE);
 
  /* Waiting for address is transferred. */
  while (!(I2C_SR1(I2C1) & I2C_SR1_ADDR));
 
  /* Clearing ADDR condition sequence. */
  (void)I2C_SR2(I2C1);
}
void oled_write(uint8_t data)
{
  i2c_send_data(I2C1, data);
  while (!(I2C_SR1(I2C1) & (I2C_SR1_BTF)));
} /*i2c_send_stop(I2C1); after writing*/



void oled_cmd_write(uint8_t cmd)
{
  uint8_t buffer[2];

  buffer[0] = 0x00;
  buffer[1] = cmd;
  
  i2c_transfer7(I2C1, 0x3c, buffer, 2, 0, 0);
}

void oled_write8(uint8_t data)
{
  oled_start_write();

  oled_write(0x40);
  oled_write(data);
  
  i2c_send_stop(I2C1);
}



/*display controll*/

void oled_init(void)
{
  oled_cmd_write(0xA8);
  oled_cmd_write(0x3F);

  oled_cmd_write(0xD3);
  oled_cmd_write(0x01); /*I think offset is the same for every display?*/

  oled_cmd_write(0x7F);

  oled_cmd_write(0xA1);
  
  oled_cmd_write(0xC8);

  oled_cmd_write(0xDA);
  oled_cmd_write(0x12);

  oled_cmd_write(0x81);
  oled_cmd_write(0x7F);

  oled_cmd_write(0xA4);

  oled_cmd_write(0xA6);

  oled_cmd_write(0xD5);
  oled_cmd_write(0x80);

  oled_cmd_write(0x8D);
  oled_cmd_write(0x14);

  oled_cmd_write(0x20);

  oled_cmd_write(0xA4);
  oled_cmd_write(0xA6);
  oled_cmd_write(0xAF);
}

/*misc functions*/
void oled_box(uint8_t row_start, uint8_t row_end, uint8_t col_start, uint8_t col_end)
{
  oled_cmd_write(0x21);
  oled_cmd_write(col_start);
  oled_cmd_write(col_end);

  oled_cmd_write(0x22);
  oled_cmd_write(row_start);
  oled_cmd_write(row_end);
}

void oled_zero(void)
{
  oled_cmd_write(0x21);
  oled_cmd_write(0);
  oled_cmd_write(15);

  oled_cmd_write(0x22);
  oled_cmd_write(0);
  oled_cmd_write(64);
}

void oled_fill(uint8_t fill)
{
  oled_start_write();
  oled_write(0x40);
  for(uint16_t k = 0; k <= 1023; k++)
    {
      oled_write(fill);     
    }
  i2c_send_stop(I2C1);
}

void oled_sleep(uint8_t state)
{
  if(!state)
    {
      oled_cmd_write(0xAF);
      return;
    }
  oled_cmd_write(0xAE);
}

/* TODO: fucking kill this thing */
void oled_printf(uint8_t *string, uint8_t len)
{
  uint8_t lines = 0;
  
  if(len <= 15)
    {
      lines = 0;
    }
  else if((len <= 32) && (len >= 16))
    {
      lines = 1;
    }

  uint8_t q = 0;
  
  for(uint8_t k = 0; k <= lines; k++)
    {
      
      for(uint8_t i = 0+k*10; i <= 10+k*10; i++)
	{
	  
	  oled_box(k*8, 8+k*8, i, i);

	  for(uint8_t j = 0; j <= 8; j++)
	    {
	      oled_write8(font8x8[string[q]-65][j]);
	    }
	  q++;
	}
    }
}

