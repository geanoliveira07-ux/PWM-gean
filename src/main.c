#include <zephyr/kernel.h>          // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>          // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>    // API para controle de pinos de entrada/saída (GPIO)
#include <pwm_z42.h>                // Biblioteca personalizada com funções de controle do TPM (Timer/PWM Module)

// Define o valor do registrador MOD do TPM para configurar o período do PWM
#define TPM_MODULE 1000                 // Define a frequência do PWM fpwm = (TPM_CLK / (TPM_MODULE * PS))

// Valores de duty cycle correspondentes a diferentes larguras de pulso
uint16_t duty_100  = TPM_MODULE;         // 100% de duty cycle  (Apagado)
uint16_t duty_80   = TPM_MODULE * 0.8;   // 80% de duty cycle   (~20% de brilho)
uint16_t duty_0    = 0;                  // 0% de duty cycle    (Brilho máximo)

int main(void){
    // Inicializa o módulo TPM2 com:		 pwm_tpm_Init("1", "2", "3", "4", "5", "6");
    // 1. - base do TPMx
    // 2. - fonte de clock PLL/FLL (TPM_CLK)
    // 3. - valor do registrador MOD
    // 4. - tipo de clock (TPM_CLK)
    // 5. - prescaler de 1 a 128 (PS)
    // 6. - modo de operação EDGE_PWM
    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);

    // Inicializa o canal 0 do TPM2 para o LED vermelho (Porta GPIOB_18)
    // - modo TPM_PWM_H (nível alto durante o pulso)
    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18);

    // Inicializa o canal 1 do TPM1 para o LED verde (Porta GPIOB_19)
    pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19);

    // Loop infinito
    for (;;){
        pwm_tpm_CnV(TPM2, 0, duty_0);       
        pwm_tpm_CnV(TPM2, 1, duty_80);
        k_msleep(2000);

        pwm_tpm_CnV(TPM2, 0, duty_100);       
        pwm_tpm_CnV(TPM2, 1, duty_100);
        k_msleep(2000);
    }
    return 0;
}
