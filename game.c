#include "game.h"

void reset_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) { //Resetando as posições do tabuleiro para um char vazio
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }    
    }
}

void draw_board(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}
void check_win_or_tie(char board[3][3], int* moves, int* score1, int* score2) {
    //checagem para o jogador 1 e jogador 2
    int plrwin = 0; // Variavel responsavel por definir qual jogador ganhou
    for (int i = 0; i < 3; i++) {//checagem em relação as linhas                //Checagem em relação as colunas
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')) {
            plrwin = 1; 
            break;    
        }
        if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') || (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')) {
            plrwin = 2;
            break;    
        }
    }   //checagem em relação a diagonal esquerda                           //checagem em relação a diagonal da direita
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
        plrwin = 1;
    }
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
        plrwin = 2;
    }
    if (plrwin != 0) { //checagem de qual jogador ganhou
        printf("\nJOGADOR %d GANHOU", plrwin);
        Sleep(1500);
        system("cls");
        reset_board(board);
        *moves = 0;
        plrwin = plrwin == 1 ? (*score1)++ : (*score2)++;
    }
    if (plrwin == 0 && (*moves) == 9) { //Verificação se houve empate
        printf("\nEMPATE");
        Sleep(1500);
        system("cls");
        reset_board(board);
        *moves = 0;
    }
}

void players_input(char board[3][3], int* currentplr, int* plrtime, int* moves,int row, int col) {
    *currentplr = *plrtime ? 1 : 2; // Trocando de jogador a cada jogada válida
    printf("JOGADOR %d: ", *currentplr);
    scanf("%d%d", &row, &col);
    if (board[row-1][col-1] == ' ' && ((row >= 1 && row <= 3) && (col >= 1 && col <= 3))) { //Verificação para saber se a jogada está disponível
        *plrtime = *currentplr == 1 ? 0 : 1; // Verificando qual é jogador que vai jogar
        board[row-1][col-1] = *currentplr == 1 ? 'X' : 'O'; // Se o jogador atual for 1 então será X caso contrário será O
        (*moves)++; //Cada jogada válida, o número de movimentos será incrementado
    }    
}

void start_game() {
    char board[3][3]; // Criando tabuleiro
    int currentplr = 1, plrtime = 1, moves = 0, plr1score = 0, plr2score = 0;
    reset_board(board);
    while (1) {
       system("cls");
       draw_board(board);     
       printf("\nPLACAR: %d X %d\n\n", plr1score, plr2score);
       players_input(board, &currentplr, &plrtime, &moves, 0, 0);
       check_win_or_tie(board, &moves, &plr1score, &plr2score);
    }   
}