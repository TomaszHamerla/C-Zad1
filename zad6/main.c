#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROUNDS 10
#define MAX_NAME_LENGTH 20

// Funkcja do wybierania losowego ruchu komputera (papier, kamień, nożyce)
int computerMove() {
    return rand() % 3; // 0 - papier, 1 - kamień, 2 - nożyce
}

// Funkcja do sprawdzania wyniku rundy
int checkRound(int playerMove, int computerMove) {
    if ((playerMove == 0 && computerMove == 1) || // papier pokonuje kamień
        (playerMove == 1 && computerMove == 2) || // kamień pokonuje nożyce
        (playerMove == 2 && computerMove == 0))   // nożyce pokonują papier
        return 1; // gracz wygrywa
    else if (playerMove == computerMove)
        return 0; // remis
    else
        return -1; // komputer wygrywa
}

int main() {
    int playerMove, computerMoveResult, roundCount = 0;
    int playerWins = 0, computerWins = 0, draws = 0;
    char command[10];

    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

    while (1) {
        printf("Podaj swój ruch (0 - papier, 1 - kamień, 2 - nożyce): ");
        scanf("%d", &playerMove);

        if (playerMove < 0 || playerMove > 2) {
            printf("Niepoprawny ruch. Podaj liczbę od 0 do 2.\n");
            continue;
        }

        computerMoveResult = computerMove();
        printf("Komputer wybrał: %d\n", computerMoveResult);

        int result = checkRound(playerMove, computerMoveResult);

        if (result == 1)
            playerWins++;
        else if (result == -1)
            computerWins++;
        else
            draws++;

        roundCount++;

        printf("Wynik rundy: %d\n", result);

        printf("Czy chcesz zakończyć grę? (tak/nie): ");
        scanf("%s", command);

        if (strcmp(command, "tak") == 0 || roundCount >= MAX_ROUNDS)
            break;
    }

    printf("Liczba zwycięstw gracza: %d\n", playerWins);
    printf("Liczba zwycięstw komputera: %d\n", computerWins);
    printf("Liczba remisów: %d\n", draws);

    return 0;
}
