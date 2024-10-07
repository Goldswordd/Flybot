#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

// Định nghĩa chân điều khiển động cơ
#define MOTOR_LEFT_IN1  GPIO6   // PA6
#define MOTOR_LEFT_IN2  GPIO7   // PA7
#define MOTOR_RIGHT_IN3 GPIO0   // PB0
#define MOTOR_RIGHT_IN4 GPIO1   // PB1

void motor_setup(void) {
	// Bật clock cho các port liên quan
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);

	// Cấu hình các chân điều khiển động cơ làm output
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, MOTOR_LEFT_IN1 | MOTOR_LEFT_IN2);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, MOTOR_RIGHT_IN3 | MOTOR_RIGHT_IN4);
}

void motor_left_forward(void) {
	gpio_set(GPIOA, MOTOR_LEFT_IN1);   // IN1 = 1
	gpio_clear(GPIOA, MOTOR_LEFT_IN2); // IN2 = 0
}

void motor_right_forward(void) {
	gpio_set(GPIOB, MOTOR_RIGHT_IN3);  // IN3 = 1
	gpio_clear(GPIOB, MOTOR_RIGHT_IN4);// IN4 = 0
}

int main(void) {
	// Cấu hình các chân điều khiển động cơ
	motor_setup();

	// Chạy động cơ trái và phải tiến lên phía trước
	motor_left_forward();
	motor_right_forward();

	while (1) {
		// Bạn có thể thêm logic khác ở đây nếu cần
	}

	return 0;
}
