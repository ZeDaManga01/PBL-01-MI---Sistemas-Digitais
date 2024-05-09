#include "tictactoe.h"

/**
 * @brief Atualiza a posição do mouse na tela.
 * 
 * Essa função atualiza a posição do mouse na tela com base no movimento do mouse.
 * Ela também garante que o mouse permaneça dentro dos limites da tela.
 *
 * @param *screen Um ponteiro para a estrutura Screen em que a posição do mouse será atualizada.
 * @param *mice Um ponteiro para a estrutura Mice que contém as informações sobre o movimento do mouse.
 * @return Não retorna nada.
 * @note A função usa a posição anterior do cursor para restaurar o caractere abaixo dele antes de atualizar a posição do cursor.
 * @note A função atualiza as coordenadas x e y do cursor na estrutura Screen.
 * @note A função garante que o cursor permaneça dentro dos limites da tela verificando as coordenadas x e y em relação às constantes MAX_X e MAX_Y.
 */
void update_mice_pos(Screen *screen, Mice *mice)
{
    Cursor *cursor = &screen->cursor;

    cursor->previous_x = cursor->x;
    cursor->previous_y = cursor->y;

    /* atualiza a posição do mouse */
    cursor->x += mice->dx;
    cursor->y -= mice->dy;

    /* condicionais para manter o cursor dentro da tela
    sem ele, o cursor iria "fugir", andando infinitamente para os cantos */
    if (cursor->x < 0) {
        cursor->x = 0;
    } 
    else if (cursor->x >= MAX_X) {
        cursor->x = MAX_X-1;
    }

    if (cursor->y < 0) {
        cursor->y = 0;
    }
    else if (cursor->y >= MAX_Y) {
        cursor->y = MAX_Y-1;
    }

    return;
}

/**
 * @brief Imprime um caractere no terminal com coordenadas.
 * 
 * Esta função imprime o caractere designado na posição especificada (x, y) na tela do terminal.
 *
 * @param x A coordenada x (horizontal) do terminal.
 * @param y A coordenada y (vertical) do terminal.
 * @param c O caractere a ser impresso.
 * @return Não retorna nada.
 */
void print_at(int x, int y, char c)
{
    printf("\033[%d;%dH%c", y+1, x+1, c);

    return;
}

/**
 * @brief Imprime o cursor na tela.
 * 
 * Essa função imprime o cursor na tela, substituindo o caractere que estava sob ele 
 * pelo caractere do cursor e então imprimindo o cursor na nova posição.
 *
 * @param *screen Ponteiro para a estrutura de tela onde o cursor será impresso.
 * @return Não retorna nada.
 * @note A função utiliza a função print_at() para imprimir o cursor na tela.
 * @note A função atualiza a variável previous da estrutura de tela com o caractere que estava sob o cursor antes de imprimi-lo.
 * @note A função utiliza as coordenadas x e y do cursor na estrutura de tela para imprimir o cursor na tela.
 */
void print_cursor(struct Screen *screen)
{
    Cursor *cursor = &screen->cursor;

    short color = screen->underscreen[cursor->previous_y][cursor->previous_x];

    if (color == RED_X) {
        printf("\033[%d;%dH%s%c%s", cursor->previous_y + 1, cursor->previous_x + 1, RED, screen->screen[cursor->previous_y][cursor->previous_x], RESET);
    } else if (color == BLUE_O) {
        printf("\033[%d;%dH%s%c%s", cursor->previous_y + 1, cursor->previous_x + 1, BLUE, screen->screen[cursor->previous_y][cursor->previous_x], RESET);
    } else {
        printf("\033[%d;%dH%c", cursor->previous_y + 1, cursor->previous_x + 1, screen->screen[cursor->previous_y][cursor->previous_x]);
    }

    print_at(cursor->x, cursor->y, cursor->cursor); // printa o cursor por cima do caractere que está no lugar atual do cursor

    return;
}

/**
 * @brief Cria um botão na tela.
 * 
 * Essa função cria um botão na tela, que é representado por uma área retangular da tela.
 * O botão é identificado por um ID, que pode ser usado para distinguir entre botões diferentes.
 * O botão é criado preenchendo a matriz subjacente da tela com o valor de ID especificado.
 * 
 * @param *screen Um ponteiro para a estrutura da tela em que o botão será criado.
 * @param x A coordenada x do canto superior esquerdo do botão.
 * @param y A coordenada y do canto superior esquerdo do botão.
 * @param size_x A largura do botão.
 * @param size_y A altura do botão.
 * @param id O ID do botão.
 * @return Retorna uma estrutura do tipo Button.
 */
void create_button(Button *button, int x, int y, int size_x, int size_y, int id)
{
    button->x = x;
    button->y = y;
    button->size_x = size_x;
    button->size_y = size_y;
    button->id = id;
}

/**
 * @brief Limpa a tela.
 * 
 * Essa função itera sobre toda a tela,
 * definindo cada caractere como um espaço (' ').
 *
 * @param *screen Um ponteiro para a estrutura Screen onde a tela está localizada.
 * @return void Essa função não retorna nenhum valor.
 * @note Essa função é usada para preparar a tela para um novo jogo ou para redefinir a tela após o término de um jogo.
 * @note A matriz abaixo da tela é uma matriz 2D de inteiros curtos, com dimensões MAX_Y x MAX_X.
 * MAX_Y e MAX_X são constantes representando a altura e largura da tela do jogo, respectivamente.
 */
void wipe_screen(Screen *screen)
{
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            screen->screen[y][x] = ' ';
        }
    }
    
    return;
}

/**
 * @brief Limpa a matriz abaixo da tela da tela do jogo.
 *
 * Esta função itera sobre toda a matriz abaixo da tela da tela do jogo,
 * definindo cada célula como 0. A matriz abaixo da tela é usada para armazenar informações adicionais
 * sobre a tela do jogo, como a cor de cada caractere.
 *
 * @param *screen Um ponteiro para a estrutura de Tela onde a tela do jogo está localizada.
 * @return void Esta função não retorna nenhum valor.
 * @note Esta função é usada para redefinir a matriz abaixo da tela antes de começar um novo jogo,
 * ou para limpar a matriz após o fim de um jogo.
 * @note A matriz abaixo da tela é uma matriz 2D de inteiros curtos, com dimensões MAX_Y x MAX_X.
 * MAX_Y e MAX_X são constantes representando a altura e largura da tela do jogo, respectivamente.
 */
void wipe_underscreen(Screen *screen)
{
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            screen->underscreen[y][x] = 0;
        }
    }
    
    return;
}

/**
 * @brief Imprime um caractere 'X' ou 'O' na posição especificada na tela.
 *
 * Esta função imprime um caractere 'X' ou 'O' na posição especificada na tela.
 * Ela usa sequências de escape ANSI para posicionar o cursor e imprimir o caractere.
 * A sequência de caracteres para “X” e “O” é armazenada no vetor “sequence”.
 * O caractere é impresso na tela e também armazenado na posição correspondente na matriz “screen”.
 *
 * @param *screen Um ponteiro para a estrutura Screen em que o caractere será impresso.
 * @param x_o O caractere a ser impresso, seja 'x' ou 'o'.
 * @param x A coordenada x do canto superior esquerdo do caractere.
 * @param y A coordenada y do canto superior esquerdo do caractere.
 * @return void Essa função não retorna nenhum valor.
 * @note A função não fará nada se x_o não for nem 'x' e nem 'o'.
 */
void print_x_o(Screen *screen, char x_o, int x, int y, bool blink)
{
    char sequence[50];
    short color;

    if (x_o == 'X') {
        strcpy(sequence, " _    _ \\ \\  / / \\ \\/ /   )  (   / /\\ \\ /_/  \\_\\");
        color = RED_X;
    } else if (x_o == 'O') {
        strcpy(sequence, "  ____   / __ \\ | |  | || |  | || |__| | \\____/ ");
        color = BLUE_O;
    } else {
        return;
    }

    int k = 0; 
    for (int i = y; i < y + 6; i++) {
        for (int j = x; j < x + 8; j++) {
            if (x_o == 'X') {
                if (blink) {
                    printf("\033[%d;%dH%s%s%c%s", i + 1, j + 1, BLINK, RED, sequence[k], RESET);
                } else {
                    printf("\033[%d;%dH%s%c%s", i + 1, j + 1, RED, sequence[k], RESET);
                }
                
            } else if (x_o == 'O') {
                if (blink) {
                    printf("\033[%d;%dH%s%s%c%s", i + 1, j + 1, BLINK, BLUE, sequence[k], RESET);
                } else {
                    printf("\033[%d;%dH%s%c%s", i + 1, j + 1, BLUE, sequence[k], RESET);
                }
            }

            screen->screen[i][j] = sequence[k];
            screen->underscreen[i][j] = color;
            k++;
        }
    }
}

/**
 * @brief Imprime um separador vertical na tela.
 *
 * Essa função imprime um separador vertical na tela na posição especificada.
 * O separador é representado por uma cadeia de caracteres armazenada no vetor 'vertical_separator'.
 * Os caracteres são impressos na tela e também armazenados nas posições correspondentes na matriz 'screen'.
 *
 * @param *screen Um ponteiro para a estrutura Screen em que o separador será impresso.
 * @param x A coordenada x do canto superior esquerdo do separador.
 * @param y A coordenada y do canto superior esquerdo do separador.
 * @return void Essa função não retorna nenhum valor.
 */
void print_vertical_separator(Screen *screen, int x, int y) {
    char vertical_separator[] = " _ | || || || ||_|";

    int k = 0; 
    for (int i = y; i < y + 6; i++) {
        for (int j = x; j < x + 3; j++) {
            print_at(j, i, vertical_separator[k]);
            screen->screen[i][j] = vertical_separator[k];
            k++;
        }
    }
}

/**
 * @brief Imprime um separador horizontal na tela.
 *
 * Essa função imprime um separador horizontal na tela na posição especificada.
 * O separador é representado por uma cadeia de caracteres armazenada no vetor 'horizontal_separator'.
 * Os caracteres são impressos na tela e também armazenados nas posições correspondentes na matriz 'screen'.
 *
 * @param *screen Um ponteiro para a estrutura Screen em que o separador será impresso.
 * @param x A coordenada x do canto superior esquerdo do separador.
 * @param y A coordenada y do canto superior esquerdo do separador.
 * @return void Essa função não retorna nenhum valor.
 */
void print_horizontal_separator(Screen *screen, int x, int y) {
    char horizontal_separator[] = " _________________________________ (_________________________________)";

    int k = 0;
    for (int i = y; i < y + 2; i++) {
        for (int j = x; j < x + 35; j++) {
            print_at(j, i, horizontal_separator[k]);
            screen->screen[i][j] = horizontal_separator[k];
            k++;
        }
    }
}

/**
 * @brief Imprime a vez do jogador atual na tela.
 *
 * Esta função imprime a vez do jogador atual na tela nas coordenadas especificadas.
 * Ela altera a cor do texto com base no jogador atual.
 *
 * @param screen Um ponteiro para a estrutura Screen que representa a tela do jogo.
 * @param x A coordenada x onde a mensagem de vez do jogador deve ser impressa.
 * @param y A coordenada y onde a mensagem de vez do jogador deve ser impressa.
 * @param x_o O caractere que representa o jogador atual ('X' ou 'O').
 *
 * @return void Esta função não retorna nenhum valor.
 */
void print_turn(Screen *screen, int x, int y, char x_o) {
    char turn[] = "-'s turn";
    turn[0] = x_o;

    short color;

    int k = 0;

    for (int j = x; j < x + (int) strlen(turn); j++) {
        if (x_o == 'X') {
            printf("\033[%d;%dH%s%c%s", y + 1, j + 1, RED, turn[k], RESET);
            color = RED_X;
        } else if (x_o == 'O') {
            printf("\033[%d;%dH%s%c%s", y + 1, j + 1, BLUE, turn[k], RESET);
            color = BLUE_O;
        }
        screen->screen[y][j] = turn[k];
        screen->underscreen[y][j] = color;
        k++;
    }
}

/**
 * @brief Verifica se há um vencedor no jogo.
 *
 * Essa função verifica o tabuleiro do jogo para ver se há um vencedor.
 * Ela verifica as linhas, as colunas e as diagonais em busca de uma correspondência.
 * Se for encontrado um vencedor, a função define a variável vencedor como o jogador atual.
 *
 * @param game Uma matriz que representa o tabuleiro do jogo.
 * @param current_player O caractere que representa o jogador atual.
 * @param *vencedor Um ponteiro para uma variável de caractere em que o vencedor será armazenado.
 * @return void A função não retorna um valor.
 * @note O tabuleiro do jogo é representado por um vetor de tamanho MAX (10, neste caso).
 * A função verifica se há um vencedor comparando os caracteres na matriz do jogo.
 * Se for encontrado um vencedor, a função define a variável vencedor como o jogador atual.
 */
void verify_winner(char game[], char current_player, char *winner, signed char *f, signed char *s, signed char *t){
    int win_conditions[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, /* Horizontais */
                                {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, /* Verticais */
                                {0, 4, 8}, {2, 4, 6}}; /* Diagonais */

    for (int i = 0; i < 8; i++) {
        if (game[win_conditions[i][0]] != ' ' && 
            game[win_conditions[i][0]] == game[win_conditions[i][1]] && 
            game[win_conditions[i][1]] == game[win_conditions[i][2]]) {
            
            *f = win_conditions[i][0];
            *s = win_conditions[i][1];
            *t = win_conditions[i][2];

            *winner = current_player;
            return;
        }
    }
}

/**
 * @brief Verifica a colisão entre o cursor e um botão.
 * 
 * Esta função verifica se a posição do cursor está dentro dos limites de um determinado botão.
 * Isso é feito comparando as coordenadas x e y do cursor com as coordenadas x, y, size_x e size_y do botão.
 *
 * @param cursor Um ponteiro para a estrutura Cursor que representa a posição do cursor.
 * @param button Um ponteiro para a estrutura Button que representa o botão a ser verificado.
 * @return Um valor booleano indicando se houve colisão.
 */
bool check_button_collision(Cursor *cursor, Button *button)
{
    bool x_collision = (cursor->x >= button->x) && (cursor->x < (button->x + button->size_x));
    bool y_collision = (cursor->y >= button->y) && (cursor->y < (button->y + button->size_y));

    return x_collision && y_collision; 
}

/**
 * @brief Exibe o menu principal do jogo.
 *
 * Esta função limpa a tela, imprime o título do jogo e aguarda a entrada do mouse.
 * Se o botão esquerdo for pressionado, a função retorna, iniciando o jogo.
 * Se o botão direito for pressionado, a função define a flag de execução como false, encerrando o programa.
 *
 * @param *mice Um ponteiro para a estrutura Mice que contém dados de entrada do mouse.
 * @param *running Um ponteiro para uma flag booleana indicando se o jogo está em execução.
 *
 * @return void Esta função não retorna nenhum valor.
 */
void main_menu(Mice *mice, bool *running)
{   
    char title1[] = "████████ ██  ██████ ████████  █████   ██████ ████████  ██████  ███████";
    char title2[] = "   ██    ██ ██         ██    ██   ██ ██         ██    ██    ██ ██     ";
    char title3[] = "   ██    ██ ██         ██    ███████ ██         ██    ██    ██ █████  ";
    char title4[] = "   ██    ██ ██         ██    ██   ██ ██         ██    ██    ██ ██     ";
    char title5[] = "   ██    ██  ██████    ██    ██   ██  ██████    ██     ██████  ███████";

    system("clear");
    fflush(stdout);

    int y = (MAX_Y - 5) / 2;
    int x = (MAX_X - 70) / 2 + 1;

    printf("\033[%d;%dH%s", y + 1, x, title1);
    fflush(stdout);
    printf("\033[%d;%dH%s", y + 2, x, title2);
    fflush(stdout);
    printf("\033[%d;%dH%s", y + 3, x, title3);
    fflush(stdout);
    printf("\033[%d;%dH%s", y + 4, x, title4);
    fflush(stdout);
    printf("\033[%d;%dH%s", y + 5, x, title5);
    fflush(stdout);

    char play[] = "LEFT BUTTON to play | RIGHT BUTTON to quit";

    printf("\033[%d;%dH%s%s%s", MAX_Y/2+6, (int) (MAX_X - strlen(play)) / 2, BLINK, play, RESET);
    fflush(stdout);

    while (true) {
        mice_read(mice);

        if (mice->left_release) {
            return;
        }  else if (mice->right_release) {
            *running = false;
            return;
        }
    }
}

/**
 * @brief Configura o Jogo da Velha na tela.
 * 
 * Esta função configura o Jogo da Velha na tela criando os botões e desenhando os separadores.
 * Ela cria nove botões para o jogo, cada um com um ID exclusivo. Em seguida, desenha os separadores 
 * verticais e horizontais na tela, usando as funções print_vertical_separator() e print_horizontal_separator().
 * 
 * @param *screen Um ponteiro para a estrutura Screen que representa a tela do jogo.
 * @param *buttons Um array de estruturas Button que representam os nove botões na tela do jogo.
 */
void set_up_tictactoe(Screen *screen, Button buttons[])
{
    int x = (MAX_X - 34) / 2;
    int y = (MAX_Y - 22) / 2;

    print_vertical_separator(screen, x + 9, y);
    print_vertical_separator(screen, x + 22, y);

    print_horizontal_separator(screen, x, y + 6);

    print_vertical_separator(screen, x + 9, y + 8);
    print_vertical_separator(screen, x + 22, y + 8);

    print_horizontal_separator(screen, x, y + 14);

    print_vertical_separator(screen, x + 9, y + 16);
    print_vertical_separator(screen, x + 22, y + 16);

    create_button(&buttons[0], x, y, 8, 6, 1);
    create_button(&buttons[1], x + 13, y, 8, 6, 2);
    create_button(&buttons[2], x + 26, y, 8, 6, 3);

    create_button(&buttons[3], x, y + 8, 8, 6, 4);
    create_button(&buttons[4], x + 13, y + 8, 8, 6, 5);
    create_button(&buttons[5], x + 26, y + 8, 8, 6, 6);

    create_button(&buttons[6], x, y + 16, 8, 6, 7);
    create_button(&buttons[7], x + 13, y + 16, 8, 6, 8);
    create_button(&buttons[8], x + 26, y + 16, 8, 6, 9);
}

/**
 * @brief Laço principal do jogo.
 * 
 * Esta função lida com o laço principal do jogo, incluindo a inicialização do jogo, 
 * o processamento de entradas de mouse, a atualização do estado do jogo e a renderização do jogo.
 *
 * @param *mice Um ponteiro para a estrutura Mice que contém dados de entrada de mouse.
 * @return void Esta função não retorna nenhum valor.
 * @note Esta função utiliza as funções mice_read(), correct_mice_sensitivity(), 
 * update_mice_pos(), print_cursor(), set_up_tictactoe(), print_x_o(), 
 * verify_winner(), check_button_collision(), printf(), e wait_for_mice_click() 
 * para implementar a lógica do jogo.
 */
void game(Mice *mice)
{
    system("clear");
    fflush(stdout);

    /* Atribuição da tela. */
    Screen screen;
    wipe_screen(&screen);
    wipe_underscreen(&screen);

    Button buttons[MAX];
    for (int i = 0; i < MAX; i++) {
        create_button(&buttons[i], -1, -1, -1, -1, -1);
    }

    /* Inicialização da posição do mouse e símbolo do cursor. */
    Cursor *cursor = &screen.cursor;

    cursor->x = (int) MAX_X/2; // Colocando a posição do mouse no centro horizontal da tela.
    cursor->y = (int) MAX_Y/2; // Colocando a posição do mouse no centro vertical da tela.
    cursor->previous_x = cursor->x;
    cursor->previous_y = cursor->y;
    cursor->cursor = '<';

    print_cursor(&screen);
    set_up_tictactoe(&screen, buttons);

    char game[MAX];
    signed char winning_squares[3] = {-1, -1, -1};

    char current_player = 'X';
    char winner = ' ';

    for(int i = 0; i < MAX-1; i++){
        game[i] = ' ';
    }

    int plays = MAX-1;

    print_turn(&screen, ((MAX_X) - strlen("-'s turn"))/2, 0, current_player);

    /* Loop infinito do programa. */
    while (winner == ' ' && plays) {
        mice_read(mice); /* Recebe os inputs do mouse */

        if (mice->event) /* an event has occurred */ {
            correct_mice_sensitivity(mice, 8, 8); /* correct the mice sensitivity */
            update_mice_pos(&screen, mice);
            print_cursor(&screen);

            if (mice->left_release) {
                for (int i = 0; i < MAX - 1; i++) {
                    Button *button = &buttons[i];

                    if (check_button_collision(cursor, button) && game[button->id - 1] == ' ') {
                        print_x_o(&screen, current_player, button->x, button->y, false);
                        game[button->id - 1] = current_player;
                        
                        verify_winner(game, current_player, &winner, &winning_squares[0], &winning_squares[1], &winning_squares[2]);

                        if (winner != ' ') {
                            break;
                        }

                        plays--;

                        if (current_player == 'X') {
                            current_player = 'O';
                        } else {
                            current_player = 'X';
                        }
                        break;
                    }
                }
                print_turn(&screen, ((MAX_X) - strlen("-'s turn"))/2, 0, current_player);
            } else if (mice->right_release) /* current player has forfeited */ {
                switch (current_player) {
                    case 'X':
                        winner = 'O';
                        break;
                    case 'O':
                        winner = 'X';
                        break;
                }
            }
        }

        fflush(stdout); /* limpa o buffer */
    }

    if (winning_squares[0] != -1) {
        for (int i = 0; i < 3; i++) {
            print_x_o(&screen, winner, buttons[winning_squares[i]].x, buttons[winning_squares[i]].y, true);
        }
    }

    switch (winner) {
        case 'X':
            printf("\033[%d;%dH%s%sCongratulations, X!%s", 1, (int) (MAX_X-strlen("Congratulations, X!"))/2, BLINK, RED, RESET);
            break;
        case 'O':
            printf("\033[%d;%dH%s%sCongratulations, O!%s", 1, (int) (MAX_X-strlen("Congratulations, O!"))/2, BLINK, BLUE, RESET);
            break;
        default:
            printf("\033[%d;%dH%s%sIt's a draw!%s", 1, (int) (MAX_X-strlen("It's a draw!"))/2, BLINK, GREEN, RESET);
            break;
    }
    
    printf("\033[%d;%dH%sPress LEFT BUTTON to continue%s", MAX_Y, (int) (MAX_X - strlen("Press LEFT BUTTON to continue")) / 2, BLINK, RESET);
    fflush(stdout);

    while (true)
    {
        mice_read(mice);

        if (mice->left_release)
        {
            return;
        }
    }

    return;
}