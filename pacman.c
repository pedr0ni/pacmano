#include <stdio.h>
#include <stdlib.h>

char mapa[20][20];
int pacX, pacY;

int score = 0;
int maxScore = 0;

void readMap() {

    FILE *file;

    file = fopen("mapa.txt", "r");

    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            fscanf(file, "%c", &mapa[i][j]);
            if (mapa[i][j] == '@') {
                pacX = i;
                pacY = j;
            }
            if (mapa[i][j] == '.') maxScore++;
        }
    }

}

void printMap() {
    printf("\nSCORE = %d\n", score);
    printf("\n");
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%c", mapa[i][j]);
        }
    }
    fflush(stdout);
}

int isParede(char position) {
    if (position == '|' || position == '-' || position == '_') {
        return 1;
    }
    return 0;
}

void checkScore(char position) {
    if (!isParede(position) && position == '.') score++;
}

void readJogada() {

    char jogada;

    while (scanf("%c", &jogada) != EOF) {

        if (jogada == 'd' && !isParede(mapa[pacY][pacX + 1])) {
            mapa[pacY][pacX] = '\0';
            pacX++;
            mapa[pacY][pacX] = '@';
            checkScore(mapa[pacY][pacX + 1]);

        } else if (jogada == 'a' && !isParede(mapa[pacY][pacX - 1])) {
            mapa[pacY][pacX] = '\0';
            pacX--;
            mapa[pacY][pacX] = '@';
            checkScore(mapa[pacY][pacX - 1]);

        } else if (jogada == 'w' && !isParede(mapa[pacY - 1][pacX])) {
            mapa[pacY][pacX] = '\0';
            pacY--;
            mapa[pacY][pacX] = '@';
            checkScore(mapa[pacY - 1][pacX]);

        } else if (jogada == 's' && !isParede(mapa[pacY + 1][pacX])) {
            mapa[pacY][pacX] = '\0';
            pacY++;
            mapa[pacY][pacX] = '@';
            checkScore(mapa[pacY + 1][pacX]);

        }
        if (score == maxScore) {
            int xd;
            for (xd = 0; xd < 25; xd++) {
                printf("\n");
            }
            printf("VOCE VENCEU O PACMANO DO PEDRONI GOD!");
            break;
        }
        printMap();
    }


}

int main() {
    readMap();
    printMap();
    readJogada();
    return 0;
}
