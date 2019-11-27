#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 99999999
#pragma warning(disable:4996)
#define TAKTO_VELKA_BUDE_HALDA 10000

/* UKAZKOVY TEST
5 5 30
PPHHH
HCHHC
CCHCC
CHCHC
HPCDC

11 11 66

H H H H C H H C C C H
H C H H C C C C C H C
H P H C C C H H H H C
C H H C H H C H C C C
H C H C C C C C H H C
H C H C C C H H H C H
H H H H C H H H C C H
H H C H C P H H C C P
H H H C H C H C C C C
C C D C C H C H C C C
C C C C C H C C C H H
*/

typedef struct vrchol {
	short x;
	short y;
	char znak;
	int dialka;
	short stav;
	struct vrchol* predosly;
	char preskumany;		//toto asi netreba
}vrchol;

vrchol**** graf = NULL;

//___________________________________________________________________________________________________________________________________________
vrchol** halda = NULL;
int velkost_haldy = 0;

void inicializuj_haldu() {
	halda = calloc(TAKTO_VELKA_BUDE_HALDA, sizeof(vrchol*));
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
	if ((mensi != 0) && (halda[index]->dialka > halda[mensi]->dialka)) {
		vymen(index, mensi);
		heapify_zhora(mensi);
	}
}

vrchol* vyber_najmensi() {
	vrchol* najmensi = halda[1];
	najmensi = halda[1];
	halda[1] = NULL;
	if (velkost_haldy != 1) {
		vymen(1, velkost_haldy);
		heapify_zhora(1);
	}
	velkost_haldy--;
	return najmensi;
}
//_____________________________________________________________________________________________________________________________________________

char zisti_hodnotu_bajtu(short stav, int pozicia) {
	return (stav >> (pozicia - 1)) & 1;
}

short nastav_hodnotu_bajtu(short stav, int pozicia, char hodnota) {
	if (hodnota == 1)
		return (1 << (pozicia - 1)) | stav;
	else if (hodnota == 0)
		return ~(1 << (pozicia - 1)) & stav;
	else
		printf("Hodnota musi byt 0 alebo 1!\n");
	return -1;
}

short prepni_stav(short stav, char nazov_stavu) {
	if (nazov_stavu == 'D')
		return nastav_hodnotu_bajtu(stav, 1, 1);
	else if (nazov_stavu == 'G')
		return nastav_hodnotu_bajtu(stav, 2, 1);
	else if (nazov_stavu == 'Z')
		return nastav_hodnotu_bajtu(stav, 3, 1);
	else if (nazov_stavu == 'Y')
		return nastav_hodnotu_bajtu(stav, 4, 1);
	else if (nazov_stavu == 'X')
		return nastav_hodnotu_bajtu(stav, 5, 1);
	else if (nazov_stavu == 'W')
		return nastav_hodnotu_bajtu(stav, 6, 1);
	else if (nazov_stavu == 'V')
		return nastav_hodnotu_bajtu(stav, 7, 1);
	else
		printf("NEEXISTUJUCI STAV\n");
	return stav;
}

char zisti_stav(short stav, char nazov_stavu) {
	if (nazov_stavu == 'D')
		return zisti_hodnotu_bajtu(stav, 1);
	else if (nazov_stavu == 'G')
		return zisti_hodnotu_bajtu(stav, 2);
	else if (nazov_stavu == 'Z')
		return zisti_hodnotu_bajtu(stav, 3);
	else if (nazov_stavu == 'Y')
		return zisti_hodnotu_bajtu(stav, 4);
	else if (nazov_stavu == 'X')
		return zisti_hodnotu_bajtu(stav, 5);
	else if (nazov_stavu == 'W')
		return zisti_hodnotu_bajtu(stav, 6);
	else if (nazov_stavu == 'V')
		return zisti_hodnotu_bajtu(stav, 7);
	else
		printf("NEEXISTUJUCI STAV\n");
	return 0;
}

char nasli_sme_vsetky_princezne(int pocet_princezien, short stav) {
	char vysledok = 1;
	if (pocet_princezien > 0)
		vysledok = vysledok & zisti_stav(stav, 'Z');
	if (pocet_princezien > 1)
		vysledok = vysledok & zisti_stav(stav, 'Y');
	if (pocet_princezien > 2)
		vysledok = vysledok & zisti_stav(stav, 'X');
	if (pocet_princezien > 3)
		vysledok = vysledok & zisti_stav(stav, 'W');
	if (pocet_princezien > 4)
		vysledok = vysledok & zisti_stav(stav, 'V');
	return vysledok;
}

//_____________________________________________________________________________________________________________________________________________

void vypis_mapu(char** mapa, int vyska, int sirka) {
	printf("\n");
	for (int i = 0; i < vyska; i++) {
		for (int j = 0; j < sirka; j++) {
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
}

void vytvor_graf(char** mapa, int vyska, int sirka,int pocet_stavov) {
	int i = 0, j = 0, k = 0;
	graf = calloc(vyska, sizeof(vrchol * **));
	for (i = 0; i < vyska; i++) {
		graf[i] = calloc(sirka, sizeof(vrchol * *));
		for (j = 0; j < sirka; j++) {
			graf[i][j] = calloc(pocet_stavov, sizeof(vrchol*));
			for (k = 0; k < pocet_stavov; k++) {
				graf[i][j][k] = malloc(sizeof(vrchol));
				graf[i][j][k]->znak = mapa[i][j];
				graf[i][j][k]->x = i;
				graf[i][j][k]->y = j;
				graf[i][j][k]->dialka = INFINITY;
				graf[i][j][k]->stav = k;
				graf[i][j][k]->predosly = NULL;
				graf[i][j][k]->preskumany = 0;
			}
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
	else if (znak == 'D') {
		dlzka_hrany = 1;
		if (zisti_stav(aktualny->stav, 'D') == 0) {
			if (aktualny->dialka + dlzka_hrany < sused->dialka) {
				sused->dialka = aktualny->dialka + dlzka_hrany;
				sused->predosly = aktualny;
				sused->preskumany = 1;
				sused->stav = prepni_stav(sused->stav, 'D');
				vloz(sused);
			}
		}
	}
	else if (znak == 'Z' || znak == 'Y' || znak == 'X' || znak == 'W' || znak == 'V') {
		dlzka_hrany = 1;
		if (zisti_stav(aktualny->stav, 'D') == 1) {
			if (aktualny->dialka + dlzka_hrany < sused->dialka) {
				sused->dialka = aktualny->dialka + dlzka_hrany;
				sused->predosly = aktualny;
				sused->preskumany = 1;
				sused->stav = prepni_stav(sused->stav, znak);
				vloz(sused);
			}
		}
	}
	else
		dlzka_hrany = 1;

	if (aktualny->dialka + dlzka_hrany < sused->dialka) {
		sused->dialka = aktualny->dialka + dlzka_hrany;
		sused->predosly = aktualny;
		sused->preskumany = 1;
		vloz(sused);
	}
}

void pridaj_susedov_do_haldy(int vyska, int sirka, int stav, vrchol* aktualny) {
	int x = aktualny->x, y = aktualny->y;

	if (x - 1 >= 0 && graf[x - 1][y][stav] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x - 1][y][stav]);

	if (y - 1 >= 0 && graf[x][y - 1][stav] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x][y - 1][stav]);

	if (x + 1 < vyska && graf[x + 1][y][stav] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x + 1][y][stav]);

	if (y + 1 < sirka && graf[x][y + 1][stav] != aktualny->predosly)
		pridaj_jedneho_suseda(aktualny, graf[x][y + 1][stav]);
}

char** objav_princezne(char** mapa, int vyska, int sirka,int *pocet_princezien) { // tato funkcia moze neskor objavit aj teleporty
	for (int i = 0; i < vyska; i++)
		for (int j = 0; j < sirka; j++) {
			if (mapa[i][j] == 'P') {
				if (*pocet_princezien == 0)
					mapa[i][j] = 'Z';
				else if (*pocet_princezien == 1) {
					mapa[i][j] = 'Y';
				}
				else if (*pocet_princezien == 2) {
					mapa[i][j] = 'X';
				}
				else if (*pocet_princezien == 3) {
					mapa[i][j] = 'W';
				}
				else if (*pocet_princezien == 4) {
					mapa[i][j] = 'V';
				}
				*pocet_princezien = *pocet_princezien + 1;
			}
		}
	return mapa;
}

int* urob_cestu(vrchol* posledny, int* pocet_suradnic) {
	vrchol* aktualny = posledny;
	int dlzka_pola = 2;
	int* cesta = malloc(dlzka_pola * sizeof(int));
	while (1) {
		cesta[0] = aktualny->x;	//som vymenil
		cesta[1] = aktualny->y;	// som vymenil

		if (aktualny->x == 0 && aktualny->y == 0 && aktualny->stav == 0)
			break;
		dlzka_pola += 2;
		cesta = realloc(cesta, dlzka_pola * sizeof(int));

		for (int i = dlzka_pola - 1; i >= 2; i--)
			cesta[i] = cesta[i - 2];

		aktualny = aktualny->predosly;
	}
	*pocet_suradnic = dlzka_pola / 2;
	return cesta;
}

void uvolni_pamat(int vyska, int sirka,int pocet_stavov) {
	int i, j, k;
	for (i = 0; i < vyska; i++) {
		for (j = 0; j < sirka; j++) {
			for (k = 0; k < pocet_stavov; k++) {
				free(graf[i][j][k]);
			}
			free(graf[i][j]);
		}
		free(graf[i]);
	}
	free(graf);
}

int zrataj_stavy(int pocet_princezien) {
	int pocet_stavov = 1;
	for (int i = 0; i < pocet_princezien + 2; i++)
		pocet_stavov = pocet_stavov * 2;
	return pocet_stavov;
}

int* zachran_princezne(char** mapa, int vyska, int sirka, int maximalny_cas, int* dlzka_cesty) {
	inicializuj_haldu();
	int pocet_princezien = 0;
	mapa = objav_princezne(mapa, vyska, sirka,&pocet_princezien);
	int pocet_stavov = zrataj_stavy(pocet_princezien);
	vypis_mapu(mapa, vyska, sirka);
	vytvor_graf(mapa, vyska, sirka,pocet_stavov);
	vrchol* aktualny = graf[0][0][0];
	aktualny->dialka = 1;
	aktualny->predosly = aktualny;
	//teraz budem prehladavat prvy prvok v halde, a susedov tam znova pridam. az kym nebudem na konci a prvy prvok v halde bude mat vacsu dialku ako aktualny
	while (nasli_sme_vsetky_princezne(pocet_princezien, aktualny->stav) != 1) {
		pridaj_susedov_do_haldy(vyska, sirka, aktualny->stav, aktualny);
		aktualny = vyber_najmensi();
	}
	int* vysledok = urob_cestu(aktualny, dlzka_cesty);
	uvolni_pamat(vyska, sirka,pocet_stavov);
	free(halda);
	return vysledok;
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
