/*
Autor:Wojciech Kosierkiewicz
Grupa: Wt/P 11:15 (Wtorek parzysty godz 9:15)
Temat: laboratoria 3
Data: 18 pazdziernika 2022 r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "string.h"

#define ROZMIAR 20
#define SZER_MENU 60

float tab[ROZMIAR];

void wyczysc_ekran() {
    system("cls");
}

void czekaj_na_symbol_i_wyczysc() {
    printf("\nNacisnij dowolny klawisz, aby kontynuowac...");
    getch();
    wyczysc_ekran();
}

void opcja_menu(int nmr_opcji, char *nazwa_opcji) {
    printf("# %d. %s", nmr_opcji, nazwa_opcji);

    for (int i = 0; i < SZER_MENU - 6 - strlen(nazwa_opcji); ++i)
        printf(" ");

    printf("#\n");
}

void pokaz_menu() {
    printf("Wojciech Kosierkiewicz (Wt/P 11:15)\n");
    for (int i = 0; i < SZER_MENU; ++i)
        printf("#");

    printf("\n");

    opcja_menu(1, "wpisz dane do tablicy");
    opcja_menu(2, "losowo wypelnij tablice");
    opcja_menu(3, "wypisz zawartosc tablicy");
    opcja_menu(4, "srednie i sumy tablicy");
    opcja_menu(5, "sprawdz uporzadkowanie tablicy");
    opcja_menu(6, "posortuj tablice rosnoca");
    opcja_menu(7, "zliczanie wystapien znakow w podanym teskcie");
    opcja_menu(0, "wyjdz z programu");

    for (int i = 0; i < SZER_MENU; ++i)
        printf("#");
}


void wypelnij_tablice_losowo() {
    srand(time(NULL));
    float zakres_min, zakres_max;

    printf("podaj zakres losowania :");
    printf("\nmin: ");
    scanf("%f", &zakres_min);
    printf("\nmax: ");
    scanf("%f", &zakres_max);

    for (int i = 0; i < ROZMIAR; ++i)
        tab[i] = zakres_min + (zakres_max - zakres_min) * rand() / ((double) RAND_MAX);
}

void wpisz_dane_do_tablicy() {
    for (int i = 0; i < ROZMIAR; ++i) {
        printf("Tab[%d] = ", i);
        scanf("%f", &tab[i]);
    }
}

void uporzadkowanie_tablicy() {
    int zdane = 1;
    for (int i = 1; i < ROZMIAR; ++i)
        if (tab[i - 1] != tab[i])
            zdane = 0;

    if (zdane) {
        printf("wszystkie elementy maja jednakowa wartosc");
        return;
    }
    zdane = 1;
    for (int i = 1; i < ROZMIAR; ++i) {
        if (tab[i - 1] <= tab[i]) {
            zdane = 0;
        }
    }
    if (zdane) {
        printf("wszystkie elementy tablicy sa uporzadkowane malejaco");
        return;
    }
    zdane = 1;
    for (int i = 1; i < ROZMIAR; ++i) {
        if (tab[i - 1] >= tab[i]) {
            zdane = 0;
        }
    }
    if (zdane) {
        printf("wszystkie elementy tablicy sa uporzadkowane rosnaco");
        return;
    }
    zdane = 1;
    for (int i = 1; i < ROZMIAR; ++i) {
        if (tab[i - 1] < tab[i]) {
            zdane = 0;
        }
    }
    if (zdane) {
        printf("wszystkie elementy tablicy sa uporzadkowane nierosnoca");
        return;
    }
    zdane = 1;
    for (int i = 1; i < ROZMIAR; ++i) {
        if (tab[i - 1] > tab[i]) {
            zdane = 0;
        }
    }
    if (zdane) {
        printf("wszystkie elementy tablicy sa uporzadkowane niemalejaco");
        return;
    }
    printf("tablica nie jest uporzadkowana");
}

void wypisz_dane_z_tablicy() {
    printf("Tab = [  ");
    for (int i = 0; i < ROZMIAR; ++i) {
        printf("%0.1f", tab[i]);
        if (i < ROZMIAR - 1) {
            printf("  ");
        }
    }
    printf("  ]\n");
}

void zamien(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void posortuj() {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            if (tab[i] < tab[j]) {
                zamien(&tab[i], &tab[j]);
            }
        }
    }
}

void sprawdz_informacje_o_tablicy() {
    int liczba_dodatnich = 0, liczba_ujemnych = 0;
    float suma_dodatnich = 0, suma_ujemnych = 0;
    for (int i = 0; i < ROZMIAR; ++i) {
        if (tab[i] > 0) {
            liczba_dodatnich++;
            suma_dodatnich += tab[i];
        } else if (tab[i] < 0) {
            liczba_ujemnych++;
            suma_ujemnych += tab[i];
        }
    }
    if (liczba_dodatnich > 0) {
        printf("liczba dodatnich elementow: %d\n", liczba_dodatnich);
        printf("Suma dodatnich elementow: %0.2f\n", suma_dodatnich);
        printf("Srednia dodatnich: %0.2f\n", suma_dodatnich / liczba_dodatnich);
    } else {
        printf("Brak dodatnich elementow\n");
    }
    if (liczba_ujemnych > 0) {
        printf("Liczba ujemnych elementow: %d\n", liczba_ujemnych);
        printf("Suma ujemnych elementow: %0.2f\n", suma_ujemnych);
        printf("srednia ujemnych elementow: %0.2f\n", suma_ujemnych / (liczba_ujemnych * 1.0));
    } else {
        printf("Brak ujemnych elementow\n");
    }
}

void zliczanieznakow() {
    int tab_znakow[26];
    int ilosc_znakow = 0;

    for (int i = 0; i < 26; ++i)
        tab_znakow[i] = 0;

    printf("wpisuj litery: ");

    while (1) {
        char znak = getch();

        if (znak == 27)
            break;

        printf("%c", znak);

        ilosc_znakow++;

        if (znak >= 'a' && znak <= 'z')
            znak -= 32;
        if (znak >= 'A' && znak <= 'Z')
            tab_znakow[znak - 'A']++;
    }

    wyczysc_ekran();

    printf("Ilosc znakow: %d\n", ilosc_znakow);

    for (int i = 0; i < 26; ++i) {
        printf("litera %c %d ", i + 'A', tab_znakow[i]);
        for (int j = 0; j < tab_znakow[i]; ++j)
            printf("#");
        printf("\n");
    }
}

int main() {
    while (1) {
        pokaz_menu();
        switch (getch() - '0') {
            case 1:
                wyczysc_ekran();
                wpisz_dane_do_tablicy();
                czekaj_na_symbol_i_wyczysc();
                break;
            case 2:
                wyczysc_ekran();
                wypelnij_tablice_losowo();
                wyczysc_ekran();
                break;
            case 3:
                wyczysc_ekran();
                wypisz_dane_z_tablicy();
                czekaj_na_symbol_i_wyczysc();
                break;
            case 4:
                wyczysc_ekran();
                sprawdz_informacje_o_tablicy();
                czekaj_na_symbol_i_wyczysc();
                break;
            case 5:
                wyczysc_ekran();
                uporzadkowanie_tablicy();
                czekaj_na_symbol_i_wyczysc();
                break;
            case 6:
                wyczysc_ekran();
                posortuj();
                printf("Tablica zostala posortowana\n");
                czekaj_na_symbol_i_wyczysc();
                break;
            case 7:
                wyczysc_ekran();
                zliczanieznakow();
                czekaj_na_symbol_i_wyczysc();
                break;
            case 0:
                printf("\nKoncze dzialanie programu...\n");
                return 0;
            default:
                printf("\nNieznana opcja menu!\n");
                czekaj_na_symbol_i_wyczysc();
                break;
        }
    }
}