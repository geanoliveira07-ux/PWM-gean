#include <zephyr/kernel.h>          
#include <zephyr/device.h>          
#include <zephyr/drivers/gpio.h>    
#include <pwm_z42.h>                

#define TPM_MODULE 1000         // Período máximo do PWM
uint16_t velocidade_100 = TPM_MODULE;
uint16_t velocidade_50  = TPM_MODULE * 0.5;
uint16_t velocidade_25  = TPM_MODULE * 0.25;
uint16_t velocidade_0   = 0;

int main(void){

    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);

    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 2);

    const struct device *gpioa_dev = DEVICE_DT_GET(DT_NODELABEL(gpioa));

    gpio_pin_configure(gpioa_dev, 1, GPIO_OUTPUT_ACTIVE); 
    gpio_pin_configure(gpioa_dev, 2, GPIO_OUTPUT_INACTIVE); 

    while (1){
        pwm_tpm_CnV(TPM2, 0, velocidade_100);
        k_msleep(2000); 

        pwm_tpm_CnV(TPM2, 0, velocidade_50);
        k_msleep(3000);
        
        pwm_tpm_CnV(TPM2, 0, velocidade_25);
        k_msleep(4000);
        
        pwm_tpm_CnV(TPM2, 0, velocidade_0);
        k_msleep(5000); 
    }
    return 0;
}
