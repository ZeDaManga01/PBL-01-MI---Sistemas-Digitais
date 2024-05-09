#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mice.h"

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define BLINK "\033[5m"
#define RESET "\x1b[m"

#define NO_COLOR 0
#define RED_X 1
#define BLUE_O 2
#define BLINKING_RED_X 3
#define BLINKING_BLUE_O 4

#define MAX_X 80
#define MAX_Y 24

#define MAX 10

    /**
     * @struct Cursor
     * @brief Representa as informações do cursor na tela.
     * 
     * Essa struct guarda informações do cursor: onde ele está posicionado na tela, 
     * onde ele estava da última vez e qual é o caractere que o representa graficamente.
     */
    typedef struct Cursor {
        char cursor;          /**< Caractere a ser impresso pelo cursor. */
        int x;                /**< Coordenada x atual do cursor. */
        int y;                /**< Coordenada y atual do cursor. */
        int previous_x;       /**< Coordenada x anterior do cursor. */
        int previous_y;       /**< Coordenada y anterior do cursor. */
    } Cursor;

    /**
     * @struct Button
     * @brief Estrutura que representa um botão na tela.
     *
     * Esta estrutura armazena as coordenadas x e y do canto superior esquerdo
     * do botão, bem como o tamanho em pixels do botão ao longo dos eixos x e y.
     * Além disso, cada botão possui um identificador único (id) para distinguir
     * entre diferentes botões, e uma variável que checa se o botão foi 
     * pressionado ou solto.
     */
    typedef struct Button {
        int x;        /**< Coordenada x do canto superior esquerdo do botão. */
        int y;        /**< Coordenada y do canto superior esquerdo do botão. */
        int size_x;   /**< Tamanho do botão ao longo do eixo x em pixels. */
        int size_y;   /**< Tamanho do botão ao longo do eixo y em pixels. */
        int pressed;  /**< Se o botão foi pressionado. Se 0: não foi pressionado. Se 1: foi pressionado. Se 2: foi solto. */
        int id;       /**< Identificador único do botão. */
    } Button;

    /**
     * @struct Screen
     * @brief Estrutura que representa uma tela de exibição.
     *
     * Esta estrutura contém informações sobre a tela de exibição, incluindo a matriz
     * de caracteres que representa a tela visível, uma matriz subjacente para rastrear
     * os caracteres originais da tela, o caractere anteriormente impresso, as informações
     * do cursor atual e uma matriz de botões presentes na tela.
     */
    typedef struct Screen {
        char screen[MAX_Y][MAX_X];
        short underscreen[MAX_Y][MAX_X];
        Cursor cursor;
    } Screen;

    void update_mice_pos(Screen *screen, Mice *mice);

    void print_at(int x, int y, char c);

    void print_screen(char screen[MAX_Y][MAX_X]);

    void print_cursor(Screen *screen);

    void create_button(Button *button, int x, int y, int size_x, int size_y, int id);

    void wipe_screen(Screen *screen);

    void print_x_o(Screen *screen, char x_o, int x, int y, bool blink);

    void print_vertical_separator(Screen *screen, int x, int y);

    void print_horizontal_separator(Screen *screen, int x, int y);

    void print_turn(Screen *screen, int x, int y, char x_o);

    bool check_button_collision(Cursor *cursor, Button *button);

    void verify_winner(char game[], char current_player, char *winner, signed char *f, signed char *s, signed char *t);

    void main_menu(Mice *mice, bool *running);

    void set_up_tictactoe(Screen *screen, Button buttons[]);

    void game(Mice *mice);

    void wait_for_mice_click(Mice *mice, bool condition);

#endif