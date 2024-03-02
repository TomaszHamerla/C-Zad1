#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROUNDS 10

// Funkcja do generowania losowego ruchu komputera
int generateComputerMove() {
    return rand() % 3; // 0 - kamień, 1 - papier, 2 - nożyce
}

// Funkcja do zwracania nazwy ruchu
const char* moveToString(int move) {
    switch(move) {
        case 0:
            return "Kamień";
        case 1:
            return "Papier";
        case 2:
            return "Nożyce";
        default:
            return "Nieznany ruch";
    }
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych
    int playerMove, computerMove;
    int round = 0;
    int playerScore = 0, computerScore = 0;
    int moves[MAX_ROUNDS][2]; // Tablica do przechowywania ruchów w poszczególnych rundach (0 - gracz, 1 - komputer)

    printf("Witaj w grze Papier, Kamień, Nożyce!\n");

    while (round < MAX_ROUNDS) {
        printf("\nRunda %d:\n", round + 1);
        printf("Twój ruch (0 - Kamień, 1 - Papier, 2 - Nożyce): ");
        if (scanf("%d", &playerMove) != 1) {
            printf("Błąd podczas wczytywania ruchu. Koniec gry.\n");
            break;
        }

        if (playerMove < 0 || playerMove > 2) {
            printf("Niepoprawny ruch! Spróbuj jeszcze raz.\n");
            continue;
        }

        computerMove = generateComputerMove();
        printf("Komputer wybrał: %s\n", moveToString(computerMove));

        // Zapisanie ruchów w tablicy
        moves[round][0] = playerMove;
        moves[round][1] = computerMove;

        // Sprawdzenie wyniku rundy
        if ((playerMove == 0 && computerMove == 2) ||
            (playerMove == 1 && computerMove == 0) ||
            (playerMove == 2 && computerMove == 1)) {
            printf("Wygrałeś rundę!\n");
            playerScore++;
        } else if (playerMove == computerMove) {
            printf("Remis!\n");
        } else {
            printf("Przegrałeś rundę!\n");
            computerScore++;
        }

        round++;
    }

    printf("\nWyniki:\n");
    printf("Gracz: %d\n", playerScore);
    printf("Komputer: %d\n", computerScore);

    // Wyświetlenie wszystkich ruchów
    char command[10];
    printf("\nWpisz 'scores', aby zobaczyć wszystkie ruchy: ");
    scanf("%s", command);
    if (strcmp(command, "scores") == 0) {
        printf("\nWszystkie ruchy:\n");
        for (int i = 0; i < round; i++) {
            printf("Runda %d: Gracz - %s, Komputer - %s\n", i + 1, moveToString(moves[i][0]), moveToString(moves[i][1]));
        }
    } else {
        printf("Niepoprawna komenda.\n");
    }

    return 0;
}

