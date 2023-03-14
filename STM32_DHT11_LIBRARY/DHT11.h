#ifndef INC_DHT11_H_
#define INC_DHT11_H_

void set_gpio_output (void);
void set_gpio_input (void);
void DHT11_start (void);
void DHT11_check_response (void);
uint8_t DHT11_read_data (void);
void DHT11_Init(void);

#endif
