# Tic-Tac-Toe

## Contexto do projeto
Dentre os jogos clássicos que resistem ao teste do tempo, o Jogo da Velha continua a cativar mentes e estimular estratégias. Esta simples e elegante competição, também conhecida como jogo do "Galo" em algumas regiões, é um verdadeiro marco da lógica e da diversão. No entanto, o jogo da velha não ficou imune ao avanço tecnológico. Nos tempos atuais, encontramos versões digitais que ampliam ainda mais a acessibilidade e a experiência do jogo. Aplicativos para smartphones e versões online têm revitalizado este jogo clássico, trazendo-o para uma nova geração de jogadores

Diante disso, foi solicitado o desenvolvimento de um console que implemente uma versão do jogo da velha. O jogo deve ser executado em uma interface em modo texto, que possa ser visualizada via terminal. O jogo deve permitir a interação de dois jogadores, de forma que a escolha da posição de marcação no tabuleiro em cada jogada deve ser captada por um mouse conectado a uma das portas USB existentes no Kit de desenvolvimento DE1-SoC. Para acessar e controlar o jogo o usuário pode utilizar os botões e chaves disponíveis na placa. Os LEDs e displays 7-segmentos também podem ser utilizados para representação de outras informações, caso necessário.

## Requisitos

- O código deve ser escrito em linguagem C;

- O sistema só poderá utilizar os componentes disponíveis na placa.

## Arquitetura da placa DE1-SoC

### ARM CORTEX A9

A arquitetura utilizada por esse processador é a RISC – Reduced Instruction Set
Computer, suas operações lógicas e aritméticas são efetuadas em operadores dos registradores
de propósitos gerais. Os dados são movidos entre a memória e esses registradores por meio de
instruções de carga e armazenamento - Load and Store. 

### Registradores

O ARM possui 16 registradores de 32 bits, sendo 15 de uso geral, R0 a R14 e um
Program Counter R15. O registrador R15 tem o endereço da próxima instrução que será
executada. Os registradores R13 e R14, são usados convencionalmente como ponteiro de
pilha Stack Pointer, que contém o endereço atual do elemento superior da pilha e registrador
de link Link Register, que recebe o endereço de retorno em chamadas de procedimento,
respectivamente

### Diagrama de Blocos da DE1-SoC

![Texto Alternativo]()

A placa suporta 1GB de SDRAM DDR3, compreendendo dois dispositivos DDR3 de 16 bits cada no lado do HPS.
Os sinais estão conectados ao Controlador de Memória Dedicado para os bancos de I/O do HPS
e a velocidade alvo é de 400 MHz.

### Comunicação

