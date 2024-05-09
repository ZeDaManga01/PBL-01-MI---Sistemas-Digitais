
<h1 align="center"> Tic-Tac-Toe </h1>



## Contexto do projeto
Dentre os jogos clássicos que resistem ao teste do tempo, o Jogo da Velha continua a cativar mentes e estimular estratégias. Esta simples e elegante competição, também conhecida como jogo do "Galo" em algumas regiões, é um verdadeiro marco da lógica e da diversão. No entanto, o jogo da velha não ficou imune ao avanço tecnológico. Nos tempos atuais, encontramos versões digitais que ampliam ainda mais a acessibilidade e a experiência do jogo. Aplicativos para smartphones e versões online têm revitalizado este jogo clássico, trazendo-o para uma nova geração de jogadores

Diante disso, foi solicitado o desenvolvimento de um console que implemente uma versão do jogo da velha. O jogo deve ser executado em uma interface em modo texto, que possa ser visualizada via terminal. O jogo deve permitir a interação de dois jogadores, de forma que a escolha da posição de marcação no tabuleiro em cada jogada deve ser captada por um mouse conectado a uma das portas USB existentes no Kit de desenvolvimento DE1-SoC. Para acessar e controlar o jogo o usuário pode utilizar os botões e chaves disponíveis na placa. Os LEDs e displays 7-segmentos também podem ser utilizados para representação de outras informações, caso necessário.

## Softwares Utilizados

### VS Code

O Visual Studio Code (VS Code) é uma ferramenta popular e altamente funcional utilizada em uma variedade de projetos de desenvolvimento de software. O uso dele foi necessário para agilizar o desenvolvimento, permitindo editar, depurar e gerenciar o código de maneira simplificada e eficaz.

### C

A linguagem C é amplamente utilizada em projetos devido à sua eficiência e versatilidade. Com sua sintaxe direta e controle próximo sobre o hardware, o C permite desenvolver programas robustos e rápidos, especialmente em sistemas embarcados, drivers de dispositivos e software de baixo nível. No contexto deste projeto, a utilização da linguagem C foi um dos requisitos necessarios a serem cumpridos.

## Requisitos

- O código deve ser escrito em linguagem C;

- O sistema só poderá utilizar os componentes disponíveis na placa.

## Kit de desenvolvimento DE1-SoC

O kit de desenvolvimento DE1-SoC apresenta uma plataforma robusta de design de hardware construída em torno do Altera
FPGA System-on-Chip (SoC), que combina os mais recentes núcleos incorporados Cortex-A9 dual-core
com lógica programável líder do setor para máxima flexibilidade de projeto.

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

### Memória

A placa suporta 1GB de SDRAM DDR3, compreendendo dois dispositivos DDR3 de 16 bits cada no lado do HPS.
Os sinais estão conectados ao Controlador de Memória Dedicado para os bancos de I/O do HPS
e a velocidade alvo é de 400 MHz.

### Diagrama de Blocos da DE1-SoC

Todas as conexões são estabelecidas através do
Dispositivo Cyclone V SoC FPGA para fornecer flexibilidade máxima aos usuários. Os usuários podem configurar o
FPGA para implementar qualquer projeto de sistema.

<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/Image.jpeg?raw=true" />
</p>

## Componentes utilizados

### Gigabit Ethernet
 
A placa suporta transferência Gigabit Ethernet por um chip externo Micrel KSZ9021RN PHY e
Função HPS Ethernet MAC. O chip KSZ9021RN com Gigabit 10/100/1000 Mbps integrado
O transceptor Ethernet também suporta interface RGMII MAC.

### Portas USB 2.0

A placa possui duas portas USB 2.0 tipo A com um controlador SMSC USB3300 e um hub de 2 portas
controlador. O dispositivo SMSC USB3300 em pacote QFN de 32 pinos faz interface com o SMSC
Controlador de hub USB2512B.

## Testes

  <h4 align="center"> Transição de Tela </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/Gif%20-%20Transi%C3%A7%C3%A3o%20de%20tela.gif" />
</p>

  <h4 align="center"> Encerramento </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/Gif%20-%20Encerramento.gif" />
</p>

  <h4 align="center"> Movimentação do Cursor </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/Gif%20-%20Movimenta%C3%A7%C3%A3o%20do%20%20Cursor.gif" />
</p>


  <h4 align="center"> Jogada em Quadrante Ocupado </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/Gif%20-%20Jogada%20em%20quadrante%20ocupado.gif" />
</p>

 <h4 align="center"> Vitória </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/Gif%20-%20Vit%C3%B3ria.gif" />
</p>

