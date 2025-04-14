#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void draw_board(char board[SIZE][SIZE]) {
    clear();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mvprintw(i * 2, j * 4, "%c", board[i][j]);
            if (j < SIZE - 1) mvprintw(i * 2, j * 4 + 1, "|");
        }
        if (i < SIZE - 1) {
            mvprintw(i * 2 + 1, 0, "---------");
        }
    }
    refresh();
}

int check_winner(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

void ai_move(char board[SIZE][SIZE]) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (board[row][col] != ' ');
    
    board[row][col] = 'O';
}

int main(void) {
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, 
                               {' ', ' ', ' '}, 
                               {' ', ' ', ' '}};
    int row, col, moves = 0;
    char player = 'X'; 
    char mode;

    srand(time(NULL)); 

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    mvprintw(0, 0, "Choisissez votre mode de jeu : (1) Joueur vs Joueur (2) Joueur vs IA");
    mode = getch();
    clear();

    while (1) {
        draw_board(board);
        
        mvprintw(SIZE * 2, 0, "Joueur %c, entrez votre coup (1-9) ou 'q' pour quitter : ", player);
        refresh();
        
        int input = getch();
        if (input == 'q') break; 

        if (input >= '1' && input <= '9') {
            int pos = input - '1';
            row = pos / SIZE;
            col = pos % SIZE;

            if (row < SIZE && col < SIZE && board[row][col] == ' ') {
                board[row][col] = player;
                moves++;

                if (check_winner(board, player)) {
                    draw_board(board);
                    mvprintw(SIZE * 2 + 1, 0, "Le joueur %c gagne ! Appuyez sur une touche pour quitter.", player);
                    getch();
                    break;
                }
                
                if (moves == SIZE * SIZE) {
                    draw_board(board);
                    mvprintw(SIZE * 2 + 1, 0, "Match nul ! Appuyez sur une touche pour quitter.");
                    getch();
                    break;
                }

                if (mode == '2' && player == 'X') {
                    player = 'O';
                    ai_move(board);
                    moves++;

                    if (check_winner(board, player)) {
                        draw_board(board);
                        mvprintw(SIZE * 2 + 1, 0, "Le joueur %c gagne ! Appuyez sur une touche pour quitter.", player);
                        getch();
                        break;
                    }

                    if (moves == SIZE * SIZE) {
                        draw_board(board);
                        mvprintw(SIZE * 2 + 1, 0, "Match nul ! Appuyez sur une touche pour quitter.");
                        getch();
                        break;
                    }
                }

                player = (player == 'X') ? 'O' : 'X';
            }
        }
    }

    endwin();
    return 0;
}
