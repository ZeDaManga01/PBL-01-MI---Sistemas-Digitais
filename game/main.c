#include "tictactoe.h"

/**
 * @file mousev3.c
 * @brief Arquivo principal do jogo Tic Tac Toe com interação do mouse.
 * @author José Alberto, Kevin Borges, Pierre Machado Mendes Novaes
 */
int main(void)
{
    printf("\e[?25l"); // Esconde o cursor do terminal.

    /* Variáveis para ler as informações do mouse. */
    Mice mice = mice_iniciatilize();

    if (mice.fd == -1) {
        printf("Could not access mouse!\n");
        return -1;
    }
    
    bool running = true;

    main_menu(&mice, &running);
    while (running) {
        game(&mice);
        main_menu(&mice, &running);
    }
    
    system("clear");
    fflush(stdout);

    printf("See you next time!\n");
    printf("\e[?25h"); // Mostra o cursor do terminal.

    return 0;
}
