#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 99999999
#define TAKTO_VELKA_BUDE_HALDA 20000
#pragma warning(disable:4996)

/* UKAZKOVY TEST
5 5 30
PPHHH
HCHHC
CCHCC
CHCHC
HPCDC

40 50 272

C C C C C C C C H G C C C H C C C C C C H C C C C C C C H C C C H H H C H C C C C C C C C C C C C C
C C C C C C C H C 2 C H C C C H C H C C C C C H H H C H C C H H H C C C 0 C C C C H C C H C C C C C
C C C H C C C C 0 C C C 2 C C C C H C C C C H C C C C C C C C C H C C C C C C H C C C C C H H C H C
C H C C C C C C C C C C C C C C C C C H H H C C C C H C H C H C H C C 3 C C H C C C C H C C C H C C
C C C H C C C H C H H C C H C C C C C H H C C H C C H C C C C C C H H C C H C C H H C H C C C C C H
H C C C C H C C H C C C 0 C C C C C C C C H C H C C C C C H C C C C H C C C C C C H H C C H C C C C
C C C H C H C C C C C H H C C C C C C H C C C C C H C C P C C C C C C C H C C C C C C C C H C H C C
C C C H C H C C H C H C C C C H H C C C C C C C C C C C H C C H C C C C C C C C C C C H C C C H H C
C C C C C C C C C C C C C H C C C C C H C H H C C H C C C C C C H H C C C 3 C H C H H C C C C C C H
C C C C C C H C C H C 0 H C C H C C H H C C C H C C C C C C C C H C C C C C C C C C C H H C 3 H C C
C C C H C C C C C C H C C H C C C C H H C H C C C C C C C C C H C C H C C C C C H C C C C C C C C C
H C C C C H H C C C C C C C C C C C C C H C C C C H H C C C C C C H C C H C C C C C C H C C C H C C
C C C H C C C C C C H C C C C C H H C C C 0 C C C H C H H 1 C C C C C C H C C C C C H C C H C C C C
H H C C C C C C H H C C C H H C H C C C C C C C C C C C C C C C C C C C H C H C C H C C C C H C C C
C C C C H C H C C H H C H H C C C H H C C H H C C C H C C C C C C C H H C C C C C C C C H C C C H C
C C C H C C H H C H C C H H C C C C C H C C C C C C C C C H C C C C C C C C C C C C C C C C C C C C
C C C C C C C 2 C H C C H C C C C C H C C C H C C C H H C C H C C H H C C C C C C C H C C 0 H H H C
H H C C C P C C C H C H H 1 C C C H C H C C C H C C C H C H H C C C C C C C C C C C C H C C C C C C
C C C C C C C H C H C C C H H C H C C H C H C C C C C C C C C C H C C C C C C C C C C C C H C C C C
C C C H C C C C C C C H H C H 0 C C C C C C C H C H C C C C H H H C C C C H C H C C C C C C C 2 C C
C C H H C C H C C C C C C C C C C C C C C C H C C C C C C C C H C C C C C C H C C C C C H C H C H H
H H C H C C C C C C C C C C C C C C C H C H C C C C C C H C C H C C C C C C C C C C C C C C C H C C
C C H C C 0 C H C C C C C H C C C C C C C C C C C H C H C C C C 3 H H C C C C C C C 2 C C C C C C C
H H C C C C H C C H C C C C C C C H C C C C C C C C C C C H C C H H C C H C C C H C H C H C H H C C
C C H C C C C H C C C C C C C C H C C C C C C C C C C C C H H H H H C H C C C C C C C C H C C C C C
C C C C C C C C H H C C C C C C C C C C C C H C C C H H C C C C C C H D C C C C C H C H C C H C C C
H C C C C C C C H H C C H C H C C C C H C H C C C C C C C C C C C C C H C C C 2 C C C C C C C C C C
H C H C H C H H H C C C C H H C C C C C H C C 1 C H C C H H C H H C C H C C C C C C C C C C C C C C
C C C C C C C C C C C H C C C C C C H C C C H C C H H H C C C C C H C C C C C H C C C C C C C C H C
C C H C H C C C C C C C C H C C C C H C H C 2 H H C C P H C 0 H C H H H C C 2 H C C H H H H C C C C
C C C C C C C C C C C H C C C C H C H C C C C C C C C H C C C C C C C C H H H C C H C C H C C C C H
C C H C C C C C C C C C C C C C H C C C C C C C C C C C C C H C C C C C C C H C C C C H C C H H H C
C H C H C C C C C C C H C C H H H C C H C C C C C H C H C C C C C H C H C C H C C C C C C C H C C C
H C C H C C H H C C C C C C C H H H C H H H C H H C C H C H C C C C C C C H C C C C C H C C C C C C
C C C C C C C C C C C C C C C C H C C C C C C H C H C C C H C C H H H C C H C H C C H H C C C C C H
C H C C H C C C H C C C C H C C C C C H H H C H C C C H H C C C C C C C H H C C C H C H C C H C C C
C C H C C C H C C C C C C C C C C C 2 C C C C C C H C C C C C C H C C C C C C C H C C C H C C C C C
H C C C C H H H C C C C C C H C C C H C H C C C C H C C C H C C C C C H C C C C C C C C C C C H C H
C H H H H H H H C C H C C C C C H C C C H C C C C C C C C H C H C C C C C C C H H C C C C H C C C 0
C C C C H H C C C H H C H C C C C C H H C C C H C C C C C C H H C C C C C C C H C C C H C C C C C C
*/

typedef struct vrchol {
	short x;
	short y;
	char znak;
	int dialka;
	short stav;
	struct vrchol* predosly;
}vrchol;

vrchol**** graf = NULL;
int* teleporty[10];
vrchol* halda[TAKTO_VELKA_BUDE_HALDA];
int velkost_haldy = 0;
//___________________________________________________________________________________________________________________________________________
													//FUNKCIE NA VYPIS

void vypis_mapu(char** mapa, int vyska, int sirka) {
	printf("\n");
	for (int i = 0; i < vyska; i++) {
		for (int j = 0; j < sirka; j++) {
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
}

void vypis_haldu() {
	int i = 0;
	for (i = 0; i <= velkost_haldy; i++)
		if (halda[i] != NULL)
			printf("index %d : %c %d\n", i, halda[i]->znak, halda[i]->dialka);
}

void vypis_pole_teleportov() {
	for (int i = 0; i < 10; i++) {
		printf("pocet teleportov s cislom %d je %d\n", i, teleporty[i][0]);
		for (int j = 1; j < teleporty[i][0]; j += 2) {
			printf(" %d,%d\n", teleporty[i][j], teleporty[i][j + 1]);
		}
	}
}
//___________________________________________________________________________________________________________________________________________
														//FUNKCIE NA INICIALIZACIU PAMATE

void vytvor_graf(char** mapa, int vyska, int sirka, int pocet_stavov) {
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
			}
		}
	}
}

void vytvor_pole_teleportov() {
	for (int i = 0; i < 10; i++)
		teleporty[i] = calloc(1, sizeof(int));
}

int zrataj_stavy(int pocet_princezien) {
	int pocet_stavov = 1;
	for (int i = 0; i < pocet_princezien + 2; i++)
		pocet_stavov = pocet_stavov * 2;
	return pocet_stavov;
}

//___________________________________________________________________________________________________________________________________________
															//FUNKCIE NA UVOLNENIE PAMATE

void uvolni_pole_teleportov() {
	for (int i = 0; i < 10; i++) 
		free(teleporty[i]);
}

void uvolni_pamat(int vyska, int sirka, int pocet_stavov) {
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
	uvolni_pole_teleportov();
}

//___________________________________________________________________________________________________________________________________________
															//FUNKCIE NA PRACU S HALDOU

void vymen(int prvy, int druhy) {
	vrchol* temp = halda[prvy];
	halda[prvy] = halda[druhy];
	halda[druhy] = temp;
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
																//FUNKCIE NA BITOVE POSUNY

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

void vloz_ak_vyhovuje(vrchol* aktualny, vrchol* sused, int dlzka_hrany) {
	if (aktualny->dialka + dlzka_hrany < sused->dialka) {
		sused->dialka = aktualny->dialka + dlzka_hrany;
		sused->predosly = aktualny;
		vloz(sused);
	}
}

void pridaj_jedneho_suseda(vrchol* aktualny, vrchol* sused) {
	char znak = sused->znak;
	int dlzka_hrany = 0;
	if (znak == 'N')
		return;
	else if (znak == 'H') {
		dlzka_hrany = 2;
		vloz_ak_vyhovuje(aktualny, sused, dlzka_hrany);
	}
	else {
		dlzka_hrany = 1;
		if (znak == 'D' && (zisti_stav(aktualny->stav, 'D') == 0)) {		//ak je drak zivy , zabijeme ho
			sused->stav = prepni_stav(sused->stav, 'D');
			vloz_ak_vyhovuje(aktualny, sused, dlzka_hrany);
		}
		else if ((znak == 'Z' || znak == 'Y' || znak == 'X' || znak == 'W' || znak == 'V') && (zisti_stav(aktualny->stav, 'D') == 1)) {		//ak je drak mrtvy, zachranime princeznu
			sused->stav = prepni_stav(sused->stav, znak);
			vloz_ak_vyhovuje(aktualny, sused, dlzka_hrany);
		}
		else if (znak == 'G' && (zisti_stav(aktualny->stav, 'G') == 0)) {		//ak je generator vypnuty, zapneme ho
			sused->stav = prepni_stav(sused->stav, 'G');
			vloz_ak_vyhovuje(aktualny, sused, dlzka_hrany);
		}
		else if (znak >= '0' && znak <= '9' && (zisti_stav(aktualny->stav, 'G') == 1)) {	//ak je generator zapnuty, preskumame vsetky miesta, kam sa mozme teleportovat
			vloz_ak_vyhovuje(aktualny, sused, dlzka_hrany);
			int cislo = znak - '0';
			dlzka_hrany = 0;
			for (int i = 1; i < teleporty[cislo][0]; i += 2) {
				vrchol* teleportovy_sused = graf[teleporty[cislo][i]][teleporty[cislo][i + 1]][aktualny->stav];
				vloz_ak_vyhovuje(sused, teleportovy_sused, dlzka_hrany);
			}
		}
		else 
			vloz_ak_vyhovuje(aktualny, sused, dlzka_hrany);
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

char** objav_princezne_a_teleporty(char** mapa, int vyska, int sirka,int *pocet_princezien) { 
	vytvor_pole_teleportov();
	for (int i = 0; i < vyska; i++) {
		for (int j = 0; j < sirka; j++) {
			if (mapa[i][j] == 'P') {
				if (*pocet_princezien == 0)
					mapa[i][j] = 'Z';
				else if (*pocet_princezien == 1) 
					mapa[i][j] = 'Y';		
				else if (*pocet_princezien == 2) 
					mapa[i][j] = 'X';
				else if (*pocet_princezien == 3) 
					mapa[i][j] = 'W';
				else if (*pocet_princezien == 4) 
					mapa[i][j] = 'V';
				
				*pocet_princezien = *pocet_princezien + 1;
			}
			else if (mapa[i][j] >= '0' && mapa[i][j] <= '9') {
				int cislo = mapa[i][j] - '0';
				int index = teleporty[cislo][0];
				teleporty[cislo] = realloc(teleporty[cislo], (3 + index) * sizeof(int));
				teleporty[cislo][index + 1] = i;
				teleporty[cislo][index + 2] = j;
				teleporty[cislo][0] += 2;
			}
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

int* zachran_princezne(char** mapa, int vyska, int sirka, int maximalny_cas, int* dlzka_cesty) {
	int pocet_princezien = 0;
	mapa = objav_princezne_a_teleporty(mapa, vyska, sirka,&pocet_princezien); //zistime kolko princezien je , a zapiseme si suradnice teleportov
	int pocet_stavov = zrataj_stavy(pocet_princezien);			//podla poctu prncezien vyratame kolko stavov moze nastat
	vytvor_graf(mapa, vyska, sirka,pocet_stavov);		//graf bude trojrozmerne pole s rozermi VYSKA x SIRKA x POCET STAVOV

	vrchol* aktualny = graf[0][0][0];				//zacneme z laveho horneho rohu
	aktualny->dialka = 1;
	
	while (nasli_sme_vsetky_princezne(pocet_princezien, aktualny->stav) != 1) {		//kym nie sme v stave , v ktorom su najdene vsetky princezne:
		pridaj_susedov_do_haldy(vyska, sirka, aktualny->stav, aktualny);		//pridame do haldy vsetky vyhovujuce susedne vrcholy akutalneho vrcholu
		aktualny = vyber_najmensi();						//pokracujeme na najlacnejsi vrchol v halde
	}

	int* vysledok = urob_cestu(aktualny, dlzka_cesty);		//vratime sa po vlastnych stopach, tak vznikne cesta
	uvolni_pamat(vyska, sirka,pocet_stavov);
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
