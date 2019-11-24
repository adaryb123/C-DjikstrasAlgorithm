#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define INFINITY 99999999
//#include "halda.h"

/* UKAZKOVY TEST
5 5 30
PPHHH
HCHHC
CCHCC
CHCHC
HPCDC
*/

typedef struct vrchol {
	int x;
	int y;
	char znak;
	int dialka;
	short stav;
	struct vrchol* predosly;
}vrchol;

vrchol*** graf = NULL;

//___________________________________________________________________________________________________________________________________________
vrchol** halda = NULL;
int velkost_haldy = 0;

void inicializuj_haldu() {
	halda = calloc(100, sizeof(vrchol*));
}

void vymen(int prvy, int druhy) {
	vrchol* temp = halda[prvy];
	halda[prvy] = halda[druhy];
	halda[druhy] = temp;
}

void vypis_haldu() {
	int i = 0;
	for (i = 0; i <= velkost_haldy; i++)
		if (halda[i] != NULL)
			printf("index %d : %c %d\n", i, halda[i]->znak, halda[i]->dialka);
}

void heapify_zdola(int index) {
	if (index == 1)
		return;
	int index_rodica;
	if (index % 2 == 1)
		index_rodica = (index - 1) / 2;
	else
		index_rodica = index / 2;

	if (halda[index]->dialka < halda[index_rodica]->dialka) {
		vymen(index, index_rodica);
		heapify_zdola(index_rodica);
	}
}

void vloz(vrchol* novy_vrchol) {
	int novy_index = velkost_haldy + 1;
	if (halda[novy_index] == NULL)
		halda[novy_index] = malloc(sizeof(vrchol));
	halda[novy_index] = novy_vrchol;
	heapify_zdola(novy_index);
	velkost_haldy = novy_index;
}

void heapify_zhora(int index) {
	int index_laveho_decka = 2 * index, index_praveho_decka = 2 * index + 1, mensi = 0;
	if (halda[index_laveho_decka] == NULL && halda[index_praveho_decka] == NULL)
		return;
	else if (halda[index_laveho_decka] == NULL && halda[index_praveho_decka] != NULL)
		mensi = index_praveho_decka;
	else if (halda[index_laveho_decka] != NULL && halda[index_praveho_decka] == NULL)
		mensi = index_laveho_decka;
	else {
		if (halda[index_laveho_decka]->dialka < halda[index_praveho_decka]->dialka)
			mensi = index_laveho_decka;
		else
			mensi = index_praveho_decka;
	}

	if (halda[index]->dialka < halda[mensi]->dialka && mensi != 0) {
		vymen(index, mensi);
		heapify_zhora(mensi);
	}
}

vrchol* vyber_najmensi() {
	vrchol* najmensi = halda[1];
	free(halda[1]);
	halda[1] = NULL;
	if (velkost_haldy != 1) {
		vymen(1, velkost_haldy);
		heapify_zhora(1);
	}
	velkost_haldy--;
	return najmensi;
}
//_____________________________________________________________________________________________________________________________________________

void vypis_mapu(char** mapa, int vyska, int sirka) {
	printf("\n");
	for (int i = 0; i < vyska; i++) {
		for (int j = 0; j < sirka; j++) {
			printf("%c", mapa[i][j]);
		}
		printf("\n");
	}
}

void vytvor_graf(char** mapa, int vyska, int sirka) {
	int i = 0, j = 0;
	graf = calloc(vyska, sizeof(vrchol * *));
	for (i = 0; i < vyska; i++)
		graf[i] = calloc(sirka, sizeof(vrchol*));

	for (i = 0; i < vyska; i++) {
		for (j = 0; j < sirka; j++) {
			graf[i][j] = malloc(sizeof(vrchol));
			graf[i][j]->znak = mapa[i][j];
			graf[i][j]->x = i;
			graf[i][j]->y = j;
			graf[i][j]->dialka = INFINITY;
			graf[i][j]->stav = 0;
			graf[i][j]->predosly = calloc(1, sizeof(vrchol));
		}
	}
}

void pridaj_jedneho_suseda(vrchol* aktualny, vrchol* sused) {
	char znak = sused->znak;
	int dlzka_hrany = 0;
	if (znak == 'N')
		dlzka_hrany = INFINITY;
	else if (znak == 'H')
		dlzka_hrany = 2;
	else
		dlzka_hrany = 1;

	if (aktualny->dialka + dlzka_hrany < sused->dialka) {
		sused->dialka = aktualny->dialka + dlzka_hrany;
		sused->predosly = aktualny;
		vloz(sused);
	}
}

void pridaj_susedov_do_haldy(int vyska, int sirka, vrchol* aktualny) {
	int x = aktualny->x, y = aktualny->y;

	if (x - 1 >= 0 && graf[x - 1][y] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x - 1][y]);

	if (y - 1 >= 0 && graf[x][y - 1] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x][y - 1]);

	if (x + 1 < vyska && graf[x + 1][y] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x + 1][y]);

	if (y + 1 < sirka && graf[x][y + 1] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x][y + 1]);
}

int* zachran_princezne(char** mapa, int vyska, int sirka, int maximalny_cas, int* dlzka_cesty) {
	inicializuj_haldu();
	vytvor_graf(mapa, vyska, sirka);
	int x = 0, y = 0;
	graf[x][y]->dialka = 0;
	graf[x][y]->predosly = graf[x][y];
	pridaj_susedov_do_haldy(vyska, sirka, graf[x][y]);
	vypis_haldu();				//teraz budem prehladavat prvy prvok v halde, a susedov tam znova pridam. az kym nebudem na konci a prvy prvok v halde bude mat vacsu dialku ako aktualny

	//vypis_mapu(mapa,vyska,sirka);
}

int main() {
	int vyska, sirka, maximalny_cas, dlzka_cesty = 0, i = 0, j = 0, *cesta = NULL;
	char** mapa, znak;
	scanf("%d %d %d", &vyska, &sirka, &maximalny_cas);
	mapa = calloc(vyska, sizeof(char*));
	for (i = 0; i < vyska; i++)
		mapa[i] = calloc(sirka, sizeof(char));

	i = 0;
	j = 0;
	while (i < vyska) {
		scanf("%c", &znak);
		if (znak == '\n' || znak == ' ')
			continue;

		mapa[i][j] = znak;
		j++;
		if (j == sirka) {
			j = 0;
			i++;
		}
	}

	cesta = zachran_princezne(mapa, vyska, sirka, maximalny_cas, &dlzka_cesty);
	for (i = 0; i < dlzka_cesty; ++i)
		printf("%d %d\n", cesta[i * 2], cesta[i * 2 + 1]);
	return 0;
}
/*
int main() {
	inicializuj_haldu();
	vrchol* boi = malloc(sizeof(vrchol));
	boi->dialka = 5;
	boi->znak = 'Y';
	vloz(boi);
	vypis_haldu();
	return 0;
}*/