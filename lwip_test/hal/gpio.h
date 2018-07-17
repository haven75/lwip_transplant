#ifndef GPIO_H_
#define GPIO_H_



void initGpio (void);


#define DEBUG_PIN_LED 1
#define DEBUG_PIN_OUT1 2
#define DEBUG_PIN_OUT2 3
#define DEBUG_LEN_ON debug_pin_ext(DEBUG_PIN_LED, 0)
#define DEBUG_LEN_OFF debug_pin_ext(DEBUG_PIN_LED, 1)
// debug pins for board
void debug_pin_ext (int index, int op);
int debug_buttom_press (void);
#endif /* BSP_H_ */
