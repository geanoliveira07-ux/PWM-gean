#include <zephyr/kernel.h>          
#include <zephyr/device.h>          
#include <zephyr/drivers/gpio.h>                 

// CONFIGURAÇÃO PRÉ-MAIN VIA DEVICE TREE
#define LED_VERDE_NODE 	    DT_ALIAS(led0)	// Define em utilizar o LED verde

// Extrai as especificações completas de cada pino (porta, número, flags) direto do DT
static const struct gpio_dt_spec led_verde = GPIO_DT_SPEC_GET(LED_VERDE_NODE, gpios);

int main(void){
    int ret;

    // INICIALIZAÇÃO DE HARDWARE
    // Confirma se os controladores GPIO estão prontos antes de usá-los
    if (!gpio_is_ready_dt(&led_verde)) { return 0; }

    // Configura os pinos como SAÍDA em nível 0
    
    ret = gpio_pin_configure_dt(&led_verde, GPIO_OUTPUT_INACTIVE);
    if (ret < 0){ return 0; }

    while (1){
        gpio_pin_set_dt(&led_verde, 1);		// Estabelece o estado de cada pino para reproduzir a cor desejada
		k_msleep(3000);	

        gpio_pin_set_dt(&led_verde, 0);		// Estabelece o estado de cada pino para reproduzir a cor desejada
		k_msleep(3000);	
    }
    return 0;
}