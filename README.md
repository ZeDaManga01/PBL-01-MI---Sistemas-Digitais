
<h1 align="center"> Tic-Tac-Toe </h1>



## Contexto do Projeto
Dentre os jogos clássicos que resistem ao teste do tempo, o Jogo da Velha continua a cativar mentes e estimular estratégias. Esta simples e elegante competição, também conhecida como jogo do "Galo" em algumas regiões, é um verdadeiro marco da lógica e da diversão. No entanto, o jogo da velha não ficou imune ao avanço tecnológico. Nos tempos atuais, encontramos versões digitais que ampliam ainda mais a acessibilidade e a experiência do jogo. Aplicativos para smartphones e versões online têm revitalizado este jogo clássico, trazendo-o para uma nova geração de jogadores

Diante disso, foi solicitado o desenvolvimento de um console que implemente uma versão do jogo da velha. O jogo deve ser executado em uma interface em modo texto, que possa ser visualizada via terminal. O jogo deve permitir a interação de dois jogadores, de forma que a escolha da posição de marcação no tabuleiro em cada jogada deve ser captada por um mouse conectado a uma das portas USB existentes no Kit de desenvolvimento DE1-SoC. Para acessar e controlar o jogo o usuário pode utilizar os botões e chaves disponíveis na placa. Os LEDs e displays 7-segmentos também podem ser utilizados para representação de outras informações, caso necessário.


## Requisitos

- É necessário que o problema seja implementado no Kit de desenvolvimento DE1-SoC.

- O jogo deve permitir a interação de dois jogadores, de forma que a escolha da posição de marcação no tabuleiro em cada jogada (assim como a confirmação da jogada) deve ser capturada por um mouse conectado a uma das portas USB existentes no Kit de desenvolvimento DE1-SoC.

- O código deve ser escrito em linguagem C.

- O sistema só poderá utilizar os componentes disponíveis na placa.

## Equipe

<uL>
  <li><a href="https://github.com/pierremachado">Pierre Machado</a></li>
  <li><a href="https://github.com/kevincorges">Kevin Borges</a></li>
  <li><a href="https://github.com/ZeDaManga01">José Alberto</a></li>
</ul>

<h1 align="center"> Sumário </h1>
<div id="sumario">
        <ul>
        <li><a href="#sft_ut"> Softwares Utilizados </a></li>
        <li><a href="#kit_placa"> Kit de Desenvolvimento DE1-SoC</a></li>
        <li><a href="#comp_u">  Componentes Utilizados</a></li>
        <li><a href="#movemouse"> Captura de Movimentos do Mouse</a></li>
        <li><a href="#gamerules"> Funcionamento do jogo</a></li>
        <li><a href="#test"> Testes</a></li>
        <li><a href="#resultado"> Resultados alcançados</a></li>
        <li><a href="#conclusion"> Conclusão</a></li>
        <li><a href="#makefile"> Instruções de execução</a></li>
        <li><a href="#ref"> Referências</a></li>
        </ul>
</div>

<div id="sft_ut"> 
<h2> Softwares Utilizados</h2>
<div align="justify">

### GNU/Linux

Por fim, o kit de desenvolvimento DE1-SoC possui uma distribuição do Linux embarcado instalada, possibilitando a comunicação com a placa com o kit bem como a execução dos códigos criados através de conexão remota. Isso oferece uma gama de possibilidades para a elaboração do problema: a disposição dos diretórios do sistema e a possibilidade de compilar e códigos na linguagem de programação requisitada de forma fácil com o compilador gcc embarcado no kit de desenvolvimento foram fundamentais.

### VS Code

O Visual Studio Code (VS Code) é uma ferramenta popular e altamente funcional utilizada em uma variedade de projetos de desenvolvimento de software. O uso dele foi necessário para agilizar o desenvolvimento, permitindo editar, depurar e gerenciar o código de maneira simplificada e eficaz.

### C

A linguagem C é amplamente utilizada em projetos devido à sua eficiência e versatilidade. Com sua sintaxe direta e controle próximo sobre o hardware, o C permite desenvolver programas robustos e rápidos, especialmente em sistemas embarcados, drivers de dispositivos e software de baixo nível. No contexto deste projeto, a utilização da linguagem C foi um dos requisitos necessarios a serem cumpridos.

<div id="kit_placa"> 
<h2> Kit de Desenvolvimento DE1-SoC</h2>
<div align="justify">

O kit de desenvolvimento DE1-SoC apresenta uma plataforma robusta de design de hardware construída em torno do Altera
FPGA System-on-Chip (SoC), que combina os mais recentes núcleos incorporados Cortex-A9 dual-core
com lógica programável líder do setor para máxima flexibilidade de projeto.

<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/image%20-%20De1-SoC.jpeg" />
</p>

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
respectivamente.

### Memória

A placa suporta 1GB de SDRAM DDR3, compreendendo dois dispositivos DDR3 de 16 bits cada no lado do HPS.
Os sinais estão conectados ao Controlador de Memória Dedicado para os bancos de I/O do HPS
e a velocidade alvo é de 400 MHz.

### Diagrama de Blocos da DE1-SoC

Todas as conexões são estabelecidas através do
Dispositivo Cyclone V SoC FPGA para fornecer flexibilidade máxima aos usuários. Os usuários podem configurar o
FPGA para implementar qualquer projeto de sistema.

<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Image.jpeg" />
</p>

<div id="comp_u"> 
<h2> Componentes Utilizados</h2>
<div align="justify">

### Gigabit Ethernet
 
A placa suporta transferência Gigabit Ethernet por um chip externo Micrel KSZ9021RN PHY e
Função HPS Ethernet MAC. O chip KSZ9021RN com Gigabit 10/100/1000 Mbps integrado
O transceptor Ethernet também suporta interface RGMII MAC.

### Portas USB 2.0

A placa possui duas portas USB 2.0 tipo A com um controlador SMSC USB3300 e um hub de 2 portas
controlador. O dispositivo SMSC USB3300 em pacote QFN de 32 pinos faz interface com o SMSC
Controlador de hub USB2512B.

<div id="movemouse"> 
<h2> Captura de Movimentos do Mouse </h2>
<div align="justify">
A implementação de código que utilize os movimentos de um mouse conectado a uma das portas USB 2.0 presentes na DE1-SoC foi, também, um dos requisitos propostos do problema. Assim, a captura dos eventos do mouse se deu por ler as informações armazenadas pelo arquivo mice no diretório /dev/input/, onde cada evento relacionado ao dispositivo é armazenado em uma FIFO (First In, First Out). As informações dos eventos do mouse no arquivo são lidas de forma não bloqueante, ou seja, o fluxo do jogo não é interrompido quando nenhum movimento do mouse é detectado.

De acordo com a documentação do GNU/Linux, cada evento é registrado em uma struct contendo variáveis que guardam informações como a data e hora do evento, tipo, código e valor. A struct de data/hora ocupa 16 bytes no espaço de memória, e as variáveis de tipo, código e valor ocupam 8 bytes juntas. Como apenas os três últimos dados foram relevantes para a implementação do mouse, apenas estes foram lidos.

A struct guarda o valor do deslocamento horizontal ou vertical em um espaço de tempo específico, e quais dos botões foram pressionados. Entretanto, os eventos não são simultâneos, sendo armazenados um de cada vez. Logo, em cada leitura do arquivo, algumas informações podem ser perdidas se não manuseadas de forma correta. Além disso, a posição atual do mouse também não é calculada, sendo apenas guardados o deslocamento dos eixos:

<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/mouse_usb.png" />
</p>

- Caso o mouse se mova para cima, o deslocamento é positivo do eixo y.
- Por outro lado, caso se mova para baixo, o deslocamento é negativo do eixo y.
- Similarmente, o deslocamento é positivo do eixo x para a direita e negativo para a esquerda.

Portanto, a implementação se deu da seguinte forma:

- Para salvar as informações do mouse, uma struct dedicada foi implementada para registrar as informações do file descriptor do /dev/input/mice, um vetor auxiliar usado como buffer, deslocamento para o eixo x, deslocamento para o eixo y e pressionamento dos botões (quais dos botões foram pressionados, quais foram soltos e os seus estados anteriores, a fim de comparação). Os bytes são lidos com o auxílio das bibliotecas unistd e fcntl, e são manipulados dentro do próprio código.
- Também foi criada uma struct para armazenar as informações do cursor, como a posição x e y e o caractere usado para representar o cursor. É importante salientar que o mouse e o cursor são elementos distintos – o mouse é o dispositivo físico, enquanto o cursor é a sua representação gráfica na tela.
- Primeiro, o cursor é inicializado no centro da tela. Em seguida, o seu movimento é calculado somando a posição horizontal do mouse com o seu deslocamento horizontal e subtraindo a posição vertical pelo deslocamento vertical, porque o eixo vertical do terminal é invertido em relação ao eixo do deslocamento y do mouse.
- Foram criadas duas matrizes: uma para guardar o caractere que o cursor estaria sobrepondo e outra para sua cor, para que fosse possível colocar o caractere na sua posição antiga onde o cursor estava sobrepondo. Após isso, o cursor é posto em sua posição atualizada, eliminando assim a necessidade de imprimir o tabuleiro inteiro a cada movimento do mouse. Sem essas matrizes, o rastro do cursor permaneceria na tela, dificultando a visualização dos itens na tela.

<div id="gamerules"> 
<h2> Funcionamento do jogo </h2>
<div align="justify">

Funcionamento


<div id="test"> 
<h2> Testes</h2>
<div align="justify">


Esta sessão é reservada para demonstração dos testes feitos no projeto.


  <h4 align="center"> Transição de Tela </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Gif%20-%20Transi%C3%A7%C3%A3o%20de%20tela.gif" />
</p>

  <h4 align="center"> Encerramento </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Gif%20-%20Encerramento.gif" />
</p>

  <h4 align="center"> Movimentação do Cursor </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Gif%20-%20Movimenta%C3%A7%C3%A3o%20do%20%20Cursor.gif" />
</p>

</p>
 <h4 align="center"> Jogada em Quadrante Livre </h4>

<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Gif%20-%20Jogada%20em%20Quadrante%20Livre.gif" />
</p>


  <h4 align="center"> Jogada em Quadrante Ocupado </h4>



<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Gif%20-%20Vit%C3%B3ria.gif" />


 <h4 align="center"> Vitória </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/Gif%20-%20Vit%C3%B3ria.gif" />
</p>
 <h4 align="center"> Empate(Velha) </h4>


<p align="center">
  <img src="https://github.com/ZeDaManga01/PBL-01-MI---Sistemas-Digitais/blob/main/docs/GIf%20-%20Empate(Velha).gif" />
</p>

<div id="resultado"> 
<h2> Resultados alcançados</h2>
<div align="justify">

Resultados

<div id="conclusion"> 
<h2> Conclusão</h2>
<div align="justify">

Conclusão

<div id="makefile"> 
<h2> Instruções para executar o programa</h2>
<div align="justify">

Abrindo o diretório /game no terminal em um ambiente GNU/Linux, preferencialmente no kit de desenvolvimento DE1-SoC, execute as instruções:

```
make
sudo ./ttt
```

Os arquivos gerados serão automaticamente removidos após a execução do comando `make`. Apenas o executável será mantido.

<div id="ref"> 
<h2> Referências </h2>
<div align="justify">
  
DE1-SoC Board. Disponível em: https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&No=836&PartNo=4. Acessado em: 7 de maio de 2024.

Introduction to the ARM Cortex-A9 Processor. Disponível em: https://github.com/fpgacademy/Tutorials/releases/download/v21.1/ARM_intro_intelfpga.pdf. Acessado em: 5 de maio de 2024.

Linux Input drivers v1.0. Disponível em: https://www.kernel.org/doc/Documentation/input/input.txt.

WEISSTEIN, Eric W. Tic-tac-toe. https://mathworld. wolfram. com/, 2002.


