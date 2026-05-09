(Os resultados registrados foram registrados e compartilhados pela dupla do projeto do carrinho seguidor de linha, Gean [eu] e Henrique)

Commit 2.2
Objetivo do teste: fazer com que o LED ficasse piscasse por 1 segundo na cor laranja.
Resultado: o LED ficou piscando na cor laranja por meio da regulação de intensidade dos LEDs vermelho e verde, sendo o verde um pouco mais fraco, e da alteração do duty cicle do PWM no looping a cada 1 segundo.

<img width="424" height="234" alt="20260509-0516-34 9325424" src="https://github.com/user-attachments/assets/0537ea7c-4ead-4620-b773-4e8c695f7a3c" />

Commit 3
Objetivo do teste: fazer os motores do carrinho girarem.
Resultado: os motores giraram ao ligar a bateria ao VCC, ENA e ENB.

<img width="424" height="238" alt="20260509-0518-11 3539322" src="https://github.com/user-attachments/assets/c6700fdb-c502-42ce-8807-8ff17da685a7" />

Commit 4.1
Objetivo do teste: fazer um dos motores variar velocidade.
Resultado: o motor A variou velocidade, alternando entre 100% de velocidade, 25% de velocidade e parados, por meio da mudança do duty cycle do PWM do TPM1 estabelecida no looping do código. Enquanto isso, o motor B manteve-se com velocidade constante.

<img width="312" height="552" alt="20260509-0522-34 6830955" src="https://github.com/user-attachments/assets/d6c762bf-b770-4300-a9e9-5dae4281e9a8" />

Commit 4.2
Objetivo do teste: fazer os dois motores variarem velocidade de forma sincronizada.
Resultado: os motores variaram suas velocidades de forma sincronizada, alternando entre 100% de velocidade, 25% de velocidade e parados, por meio da mudança do duty cycle do PWM estabelecida no looping do código.

<img width="310" height="552" alt="20260509-0524-26 8260925" src="https://github.com/user-attachments/assets/b5a20ad1-e9b3-4b0b-b33e-bf6347cf044d" />
 
