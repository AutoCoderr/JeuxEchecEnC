#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main () {
	int C;
	int L;
	int winner;
	int formOK;
	int playerplaced = 0;
	int playernum = 0;
	int playerunselected[6] = {1,2,3,4,5,6};
	
	int listplayer[24];
	int *ReinePlayer1; 
	int *ChevalPlayer1;
	int *TourPlayer1;
	int *PionPlayer1;
	int *FouPlayer1;
	int *RoiPlayer1;
	
	int *ReinePlayer2; 
	int *ChevalPlayer2;
	int *TourPlayer2;
	int *PionPlayer2;
	int *FouPlayer2;
	int *RoiPlayer2;
	
	ReinePlayer1 = listplayer;
	ChevalPlayer1 = listplayer+2;
	TourPlayer1 = listplayer+4;
	PionPlayer1 = listplayer+6;
	FouPlayer1 = listplayer+8;
	RoiPlayer1 = listplayer+10;
	
	ReinePlayer2 = listplayer+12;
	ChevalPlayer2 = listplayer+14;
	TourPlayer2 = listplayer+16;
	PionPlayer2 = listplayer+18;
	FouPlayer2 = listplayer+20;
	RoiPlayer2 = listplayer+22;
	
	int *PlayertoMove;
	int tab[8][8] = {{0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0}};
	system("title Jeux d'echec");
	while(playerplaced<6) {
		system("cls");
		Color(10,0);
		printf("\n[PLAYER 1] : \n\n");
		Color(7,0);
		affiche(tab);
		//reine, cheval et tour (pion et fou en bonus)
		printf("quel perso veux tu mettre : \n");
		if (unselected(1,playerunselected,0) == 1) printf("1 : reine\n");
		if (unselected(2,playerunselected,0) == 1) printf("2 : cheval\n");
		if (unselected(3,playerunselected,0) == 1) printf("3 : tour\n");
		if (unselected(4,playerunselected,0) == 1) printf("4 : pion\n");
		if (unselected(5,playerunselected,0) == 1) printf("5 : fou\n");
		if (unselected(6,playerunselected,0) == 1) printf("6 : roi\n");
		printf("fait ton choix : ");
		scanf("%d", &playernum);
		if (playernum >= 1 & playernum <=6) {
			if (unselected(playernum,playerunselected,1) == 1) {
				playernum += 10;
				formOK = 0;
				while (formOK == 0) {
				
					printf("\nquelles cordonnees veux tu lui mettre ?\n");
					printf("Ligne (1-2)?  : ");
					scanf("%d", &L);
					while(L < 1 | L > 2) {
						printf("\nLigne (1-2)? : ");
						scanf("%d", &L);
					}
					printf("colonne (1-8) [Ligne %d]?  : ", L);
					scanf("%d", &C);
					while(C < 1 | C > 8) {
						printf("\ncolonne (1-8)? : ");
						scanf("%d", &C);
					}
					if (tab[L-1][C-1] == 0) {
						formOK = 1;
					} else {
						printf("\nL'emplacement %d:%d est deja utilise.\n", L, C);
					}
				}
				tab[L-1][C-1] = playernum;
				playerplaced ++;
				playernum -= 10;
				switch(playernum) {
					case 1 : {
						*ReinePlayer1 = L-1;
						*(ReinePlayer1+1) = C-1;
						break;
					}
					case 2 : {
						*ChevalPlayer1 = L-1;
						*(ChevalPlayer1+1) = C-1;
						break;
					}
					case 3 : {
						*TourPlayer1 = L-1;
						*(TourPlayer1+1) = C-1;
						break;
					}
					case 4 : {
						*PionPlayer1 = L-1;
						*(PionPlayer1+1) = C-1;
						break;
					}
					case 5 : {
						*FouPlayer1 = L-1;
						*(FouPlayer1+1) = C-1;
						break;
					}
					case 6 : {
						*RoiPlayer1 = L-1;
						*(RoiPlayer1+1) =  C-1;
						break;
					}
				}
			} else {
				printf("Le perso %d est deja positionne.\n", playernum);
				system("pause");
			}
		} else {
			printf("le perso %d n'est pas reconnu.\n", playernum);
			system("pause");
		}
	}
	playernum = 0;
	playerplaced = 0;
	playerunselected[0] = 1;
	playerunselected[1] = 2;
	playerunselected[2] = 3;
	playerunselected[3] = 4;
	playerunselected[4] = 5;
	playerunselected[5] = 6;
	printf("\n\n");
	while(playerplaced<6) {
		system("cls");
		Color(12,0);
		printf("\n[PLAYER 2] : \n\n");
		Color(7,0);
		affiche(tab);
		//reine, cheval et tour (pion et fou en bonus)
		printf("quel perso veux tu mettre : \n");
		if (unselected(1,playerunselected,0) == 1) printf("1 : reine\n");
		if (unselected(2,playerunselected,0) == 1) printf("2 : cheval\n");
		if (unselected(3,playerunselected,0) == 1) printf("3 : tour\n");
		if (unselected(4,playerunselected,0) == 1) printf("4 : pion\n");
		if (unselected(5,playerunselected,0) == 1) printf("5 : fou\n");
		if (unselected(6,playerunselected,0) == 1) printf("6 : roi\n");
		printf("fait ton choix : ");
		scanf("%d", &playernum);
		//verifplayer(choix,playerunselected,tab);
		if (playernum >= 1 & playernum <=6) {
			if (unselected(playernum,playerunselected,1) == 1) {
				playernum += 20;
				formOK = 0;
				while (formOK == 0) {
				
					printf("\nquelle cordonnee veut tu lui mettre ?\n");
				
					printf("Ligne (7-8)?  : ");
					scanf("%d", &L);
					while(L < 7 | L > 8) {
						printf("\nLigne (7-8)? : ");
						scanf("%d", &L);
					}
					printf("colonne (1-8) [Ligne %d]?  : ", L);
					scanf("%d", &C);
					while(C < 1 | C > 8) {
						printf("\ncolonne (1-8)? : ");
						scanf("%d", &C);
					}
					if (tab[L-1][C-1] == 0) {
						formOK = 1;
					} else {
						printf("\nL'emplacement %d:%d est deja utilise.\n", L, C);
					}
				}
				tab[L-1][C-1] = playernum;
				playerplaced ++;
				playernum -= 20;
				switch(playernum) {
					case 1 : {
						*ReinePlayer2 = L-1;
						*(ReinePlayer2+1) = C-1;
						break;
					}
					case 2 : {
						*ChevalPlayer2 = L-1;
						*(ChevalPlayer2+1) = C-1;
						break;
					}
					case 3 : {
						*TourPlayer2 = L-1;
						*(TourPlayer2+1) = C-1;
						break;
					}
					case 4 : {
						*PionPlayer2 = L-1;
						*(PionPlayer2+1) = C-1;
						break;
					}
					case 5 : {
						*FouPlayer2 = L-1;
						*(FouPlayer2+1) = C-1;
						break;
					}
					case 6 : {
						*RoiPlayer2 = L-1;
						*(RoiPlayer2+1) =  C-1;
						break;
					}
				}
			} else {
				printf("Le perso %d est deja positionne.\n", playernum);
				system("pause");
			}
		} else {
			printf("le perso %d n'est pas reconnu.\n", playernum);
			system("pause");
		}
	}
	
	

	printf("\n\n");
	winner = 0;
	while(winner == 0) {
		formOK = 0;
		while (formOK == 0) {
			system("cls");
			Color(10,0);
			printf("\n[PLAYER 1] : \n\n");
			Color(7,0);
			affiche(tab);
			printf("quel perso veux tu deplacer ? : \n");
			printf("0 : passer son tour\n\n");
			if (*ReinePlayer1 != 9 & *(ReinePlayer1+1) != 9) printf("1 : reine\n");
			if (*ChevalPlayer1 != 9 & *(ChevalPlayer1+1) != 9) printf("2 : cheval\n");
			if (*TourPlayer1 != 9 & *(TourPlayer1+1) != 9) printf("3 : tour\n");
			if (*PionPlayer1 != 9 & *(PionPlayer1+1) != 9) printf("4 : pion\n");
			if (*FouPlayer1 != 9 & *(FouPlayer1+1) != 9) printf("5 : fou\n");
			if (*RoiPlayer1 != 9 & *(RoiPlayer1+1) != 9) printf("6 : roi\n");
			printf("fait ton choix : ");
			scanf("%d", &playernum);
			if ((playernum == 1 & *ReinePlayer1 != 9 & *(ReinePlayer1+1) != 9) | 
			    (playernum == 2 & *ChevalPlayer1 != 9 & *(ChevalPlayer1+1) != 9) |
				(playernum == 3 & *TourPlayer1 != 9 & *(TourPlayer1+1) != 9) |
				(playernum == 4 & *PionPlayer1 != 9 & *(PionPlayer1+1) != 9) |
				(playernum == 5 & *FouPlayer1 != 9 & *(FouPlayer1+1) != 9) |
				(playernum == 6 & *RoiPlayer1 != 9 & *(RoiPlayer1+1) != 9)) {
				switch(playernum) {
					case 1 : {
						PlayertoMove = ReinePlayer1;
						break;
					}
					case 2 : {
						PlayertoMove = ChevalPlayer1;
						break;
					}
					case 3 : {
						PlayertoMove = TourPlayer1;
						break;
					}
					case 4 : {
						PlayertoMove = PionPlayer1;
						break;
					}
					case 5 : {
						PlayertoMove = FouPlayer1;
						break;
					}
					case 6 : {
						PlayertoMove = RoiPlayer1;
						break;
					}
				}
				formOK = moveplayer(tab, PlayertoMove, playernum+10, 1, listplayer);
				if (echecetmaths(RoiPlayer2,ReinePlayer1,ChevalPlayer1,TourPlayer1,PionPlayer1,FouPlayer1,RoiPlayer1) == 1) {
					winner = 1;
					formOK = 1;
				} else if (*RoiPlayer2 == 9 & *(RoiPlayer2+1) == 9) {
					winner = 1;
					formOK = 1;
				}
			} else if (playernum == 0) {
				printf("Le joueur 1 passe son tour\n");
				formOK = 1;
			} else {
				printf("le perso %d n'est pas reconnu ou il a ete mange.\n", playernum);
				system("pause");
				formOK = 0;
			}
		}
		if (winner == 0) {
			formOK = 0;
			while (formOK == 0) {
				system("cls");
				Color(12,0);
				printf("\n[PLAYER 2] : \n\n");
				Color(7,0);
				affiche(tab);
				printf("quel perso veux tu déplacer ? : \n");
				printf("0 : passer son tour\n\n");
				if (*ReinePlayer2 != 9 & *(ReinePlayer2+1) != 9) printf("1 : reine\n");
				if (*ChevalPlayer2 != 9 & *(ChevalPlayer2+1) != 9) printf("2 : cheval\n");
				if (*TourPlayer2 != 9 & *(TourPlayer2+1) != 9) printf("3 : tour\n");
				if (*PionPlayer2 != 9 & *(PionPlayer2+1) != 9) printf("4 : pion\n");
				if (*FouPlayer2 != 9 & *(FouPlayer2+1) != 9) printf("5 : fou\n");
				if (*RoiPlayer2 != 9 & *(RoiPlayer2+1) != 9) printf("6 : roi\n");
				printf("fait ton choix : ");
				scanf("%d", &playernum);
				if ((playernum == 1 & *ReinePlayer2 != 9 & *(ReinePlayer2+1) != 9) | 
			    	(playernum == 2 & *ChevalPlayer2 != 9 & *(ChevalPlayer2+1) != 9) |
					(playernum == 3 & *TourPlayer2 != 9 & *(TourPlayer2+1) != 9) |
					(playernum == 4 & *PionPlayer2 != 9 & *(PionPlayer2+1) != 9) |
					(playernum == 5 & *FouPlayer2 != 9 & *(FouPlayer2+1) != 9) |
					(playernum == 6 & *RoiPlayer2 != 9 & *(RoiPlayer2+1) != 9)) {
					switch(playernum) {
						case 1 : {
							PlayertoMove = ReinePlayer2;
							break;
						}
						case 2 : {
							PlayertoMove = ChevalPlayer2;
							break;
						}
						case 3 : {
							PlayertoMove = TourPlayer2;
							break;
						}
						case 4 : {
							PlayertoMove = PionPlayer2;
							break;
						}
						case 5 : {
							PlayertoMove = FouPlayer2;
							break;
						}
						case 6 : {
							PlayertoMove = RoiPlayer2;
							break;
						}
					}
					formOK = moveplayer(tab, PlayertoMove, playernum+20, 2,listplayer);
					if (echecetmaths(RoiPlayer1,ReinePlayer2,ChevalPlayer2,TourPlayer2,PionPlayer2,FouPlayer2,RoiPlayer2) == 1) {
						winner = 2;
						formOK = 1;
					} else if (*RoiPlayer1 == 9 & *(RoiPlayer1+1) == 9) {
						winner = 2;
						formOK = 1;
					}
				} else if (playernum == 0) {
					printf("Le joueur 2 passe son tour\n");
					formOK = 1;
				} else {
					printf("le perso %d n'est pas reconnu ou il a ete mange\n", playernum);
					system("pause");
					formOK = 0;
				}
			}
		}
	}
	system("cls");
	printf("\n\n\n");
	affiche(tab);
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\n\nLe joueurs %d a gagne!!!\nAppuyez sur une touche pour quitter\n", winner);
	system("pause > null");
	return 0;
}

int moveplayer(int *tab, int *perso, int playernum, int joueur, int *listplayer) {
	int i;
	int *L, *C;
	int nbcase;
	L = perso;
	C = perso+1;
	int choix = 0;
	switch(playernum-(10*joueur)) {
		case 1 : { // ------------------------------ DEPLACEMENT DE LA REINE ----------------------------------
			printf("Quel mouvement ? :\n");
			printf("1 : haut\n");
			printf("2 : bas\n");
			printf("3 : gauche\n");
			printf("4 : droite\n");
			printf("5 : diagonale haut/gauche\n");
			printf("6 : diagonale haut/droite\n");
			printf("7 : diagonale bas/gauche\n");
			printf("8 : diagonale bas/droite\n");
			printf("fais ton choix : ");
			scanf("%d", &choix);
			if (1 <= choix & choix <= 8) {
				printf("\nChoisis le nombre de case [1 - 8] : ");
				scanf("%d",&nbcase);
				if (nbcase >= 1 & nbcase <= 8) {
					moveplayerwhile(tab,L,C,choix,nbcase,playernum,listplayer);
					return 1;
				} else {
					return 0;
				}
			} else {
				printf("choix '%d' non reconnu.\n", choix);
				return 0;
			}
			break;
		}
		case 2 : { // ------------------------------ DEPLACEMENT DU CHEVAL ----------------------------------
			printf("Quel mouvement ? :\n");
			printf("1 : haut puis gauche\n");
			printf("2 : haut puis droite\n");
			printf("3 : bas puis gauche\n");
			printf("4 : bas puis droite\n");
			printf("5 : gauche puis haut\n");
			printf("6 : gauche puis bas\n");
			printf("7 : droite puis haut\n");
			printf("8 : droite puis bas\n");
			printf("fais ton choix : ");
			scanf("%d", &choix);
			if (1 <= choix & choix <= 8) {
				switch(choix) {
					case 1 : { // CHEVAL VERS HAUT PUIS GAUCHE
						moveplayerwhile(tab,L,C,1,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,3,1,playernum,listplayer);
						return 1;
						break;
					}
					case 2 : { // CHEVAL VERS HAUT PUIS DROITE
						moveplayerwhile(tab,L,C,1,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,4,1,playernum,listplayer);
						return 1;
						break;
					}
					case 3 : { // CHEVAL VERS BAS PUIS GAUCHE
						moveplayerwhile(tab,L,C,2,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,3,1,playernum,listplayer);
						return 1;
						break;
					}
					case 4 : { // CHEVAL VERS BAS PUIS DROITE
						moveplayerwhile(tab,L,C,2,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,4,1,playernum,listplayer);
						return 1;
						break;
					}
					case 5 : { // CHEVAL VERS GAUCHE PUIS HAUT
						moveplayerwhile(tab,L,C,3,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,1,1,playernum,listplayer);
						return 1;
						break;
					}
					case 6 : { // CHEVAL VERS GAUCHE PUIS BAS
						moveplayerwhile(tab,L,C,3,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,2,1,playernum,listplayer);
						return 1;
						break;
					}
					case 7 : { // CHEVAL VERS DROITE PUIS HAUT
						moveplayerwhile(tab,L,C,4,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,1,1,playernum,listplayer);
						return 1;
						break;
					}
					case 8 : { // CHEVAL VERS DROITE PUIS BAS
						moveplayerwhile(tab,L,C,4,2,playernum,listplayer);
						moveplayerwhile(tab,L,C,2,1,playernum,listplayer);
						return 1;
						break;
					}
				}
			} else {
				printf("choix '%d' non reconnu.\n", choix);
				return 0;
			}
			break;
		}
		case 3 : { // ------------------------------ DEPLACEMENT DE LA TOUR ----------------------------------
			printf("Quel mouvement ? :\n");
			printf("1 : haut\n");
			printf("2 : bas\n");
			printf("3 : gauche\n");
			printf("4 : droite\n");
			printf("fais ton choix : ");
			scanf("%d", &choix);
			if (1 <= choix & choix <= 4) {
				moveplayerwhile(tab,L,C,choix,2,playernum);
				return 1;
			} else {
				printf("choix '%d' non reconnu.\n", choix);
				return 0;
			}
			break;
		}
		case 4 : { // ------------------------------ DEPLACEMENT DU PION ----------------------------------
							// PION EN AVANT
			if (joueur == 1) {
				moveplayerwhile(tab,L,C,2,1,playernum,listplayer);
				return 1;
			} else if (joueur == 2) {
				moveplayerwhile(tab,L,C,1,1,playernum,listplayer);
				return 1;
			} else {
				printf("Le joueur '%d' n'existe pas.\n", joueur);
				return 0;
			}
			break;
		}
		case 5 : { // ------------------------------ DEPLACEMENT DU FOU ----------------------------------
			printf("Quel mouvement ? :\n");
			printf("1 : diagonale haut/gauche\n");
			printf("2 : diagonale haut/droite\n");
			printf("3 : diagonale bas/gauche\n");
			printf("4 : diagonale bas/droite\n");
			printf("fais ton choix : ");
			scanf("%d", &choix);
			if (1 <= choix & choix <= 4) {
				printf("\nChoisis le nombre de case [1 - 8] : ");
				scanf("%d",&nbcase);
				if (nbcase >= 1 & nbcase <= 8) {
					moveplayerwhile(tab,L,C,choix+4,nbcase,playernum,listplayer);
					return 1;
				} else {
					return 0;
				}
				return 1;
			} else {
				printf("Mouvement '%d' non reconnu.\n", choix);
				return 0;
			}
			break;
		}
		case 6 : { // ------------------------------ DEPLACEMENT DU ROI ----------------------------------
			printf("Quel mouvement ? :\n");
			printf("1 : haut\n");
			printf("2 : bas\n");
			printf("3 : gauche\n");
			printf("4 : droite\n");
			printf("5 : diagonale haut/gauche\n");
			printf("6 : diagonale haut/droite\n");
			printf("7 : diagonale bas/gauche\n");
			printf("8 : diagonale bas/droite\n");
			printf("fais ton choix : ");
			scanf("%d", &choix);
			if (1 <= choix & choix <= 8) {
				moveplayerwhile(tab,L,C,choix,1,playernum,listplayer);
				return 1;
			} else {
				printf("choix '%d' non reconnu.\n", choix);
				return 0;
			}
			break;
		}
	}
}

void moveplayerwhile(int *tab, int *L, int *C, int direction, int nbcase, int playernum, int *listplayer) {
	// 1 : haut ; 2: bas ; 3: gauche; 4: droite ; 5 : haut/gauche ; 6 : haut/droite ; 7 : bas/gauche ; 8 : bas/droite
	int i;
	int Lcoef,Ccoef,Llimit,Climit;
	switch(direction) {
		case 1 : {
			Lcoef = -1;
			Llimit = 0;
			break;
		}
		case 2 : {
			Lcoef = 1;
			Llimit = 7;
			break;
		}
		case 3 : {
			Ccoef = -1;
			Climit = 0;
			break;
		}
		case 4 : {
			Ccoef = 1;
			Climit = 7;
			break;
		}
		case 5 : {
			Lcoef = -1;
			Ccoef = -1;
			Llimit = 0;
			Climit = 0;
			break;
		}
		case 6 : {
			Lcoef = -1;
			Ccoef = 1;
			Llimit = 0;
			Climit = 7;
			break;
		}
		case 7 : {
			Lcoef = 1;
			Ccoef = -1;
			Llimit = 7;
			Climit = 0;
			break;
		}
		case 8 : {
			Lcoef = 1;
			Ccoef = 1;
			Llimit = 7;
			Climit = 7;
			break;
		}
	}
	i = 0;
	if (direction == 1 | direction == 2) {
		system("cls");
		printf("\n\n\n");
		affiche(tab);
		printf("\n\n\n\n\n\n\n\n\n\n");
		system("ping 127.0.0.1 -n 2 > nul");
		while (*L != Llimit & i<nbcase) {
			*(tab+(*L*8)+*C) = 0;
			if (*(tab+((*L+Lcoef)*8)+*C) != 0) {
				i = nbcase;
				deleteplayer(*L+Lcoef,*C,listplayer);
			} 
			*L += Lcoef;
			*(tab+(*L*8)+*C) = playernum;
			if (i < nbcase-1) {
				system("cls");
				printf("\n\n\n");
				affiche(tab);
				printf("\n\n\n\n\n\n\n\n\n\n");
				system("ping 127.0.0.1 -n 2 > nul");	
			}
			i += 1;
		}
	} else if (direction == 3 | direction == 4) {
		system("cls");
		printf("\n\n\n");
		affiche(tab);
		printf("\n\n\n\n\n\n\n\n\n\n");
		system("ping 127.0.0.1 -n 2 > nul");
		while (*C != Climit & i<nbcase) {
			*(tab+(*L*8)+*C) = 0;
			if (*(tab+(*L*8)+(*C+Ccoef)) != 0) {
				i = nbcase;
				deleteplayer(*L,*C+Ccoef,listplayer);
			}
			*C += Ccoef;
			*(tab+(*L*8)+*C) = playernum;
			if (i < nbcase-1) {
				system("cls");
				printf("\n\n\n");
				affiche(tab);
				printf("\n\n\n\n\n\n\n\n\n\n");
				system("ping 127.0.0.1 -n 2 > nul");	
			}
			i += 1;
		}
	} else if (direction >= 5 & direction <= 8) {
		system("cls");
		printf("\n\n\n");
		affiche(tab);
		printf("\n\n\n\n\n\n\n\n\n\n");
		system("ping 127.0.0.1 -n 2 > nul");
		while (*L != Llimit & *C != Climit & i<nbcase) {
			*(tab+(*L*8)+*C) = 0;
			if (*(tab+((*L+Lcoef)*8)+(*C+Ccoef)) != 0) {
				i = nbcase;
				deleteplayer(*L+Lcoef,*C+Ccoef,listplayer);
			}
			*L += Lcoef;
			*C += Ccoef;
			*(tab+(*L*8)+*C) = playernum;
			if (i < nbcase-1) {
				system("cls");
				printf("\n\n\n");
				affiche(tab);
				printf("\n\n\n\n\n\n\n\n\n\n");
				system("ping 127.0.0.1 -n 2 > nul");	
			}
			i += 1;
		}
	} else {
		printf("'%d' n'est pas une direction valide.\n", direction);
	}
}

void affiche(int *tab) {
	int *ptr;
	printf("  1 |2 |3 |4 |5 |6 |7 |8");
	for(ptr=tab;ptr<tab+64;ptr++) {
		if ((ptr-tab) % 8 == 0) {
			printf("\n%d|", ((ptr-tab)+8)/8);
		}
		switch(*ptr) {
			case 0: {
				printf("  |");
				break;
			}
			case 11 : {
				Color(10,0);
				printf("RN");
				Color(7,0);
				printf("|");
				break;
			}
			case 12 : {
				Color(10,0);
				printf("CH");
				Color(7,0);
				printf("|");
				break;
			}
			case 13 : {
				Color(10,0);
				printf("TO");
				Color(7,0);
				printf("|");
				break;
			}
			case 14 : {
				Color(10,0);
				printf("PI");
				Color(7,0);
				printf("|");
				break;
			}
			case 15 : {
				Color(10,0);
				printf("FO");
				Color(7,0);
				printf("|");
				break;
			}
			case 16 : {
				Color(10,0);
				printf("RO");
				Color(7,0);
				printf("|");
				break;
			}
			case 21 : {
				Color(12,0);
				printf("RN");
				Color(7,0);
				printf("|");
				break;
			}
			case 22 : {
				Color(12,0);
				printf("CH");
				Color(7,0);
				printf("|");
				break;
			}
			case 23 : {
				Color(12,0);
				printf("TO");
				Color(7,0);
				printf("|");
				break;
			}
			case 24 : {
				Color(12,0);
				printf("PI");
				Color(7,0);
				printf("|");
				break;
			}
			case 25 : {
				Color(12,0);
				printf("FO");
				Color(7,0);
				printf("|");
				break;
			}
			case 26 : {
				Color(12,0);
				printf("RO");
				Color(7,0);
				printf("|");
				break;
			}
		}
		if (((ptr-tab)+1) % 8 == 0) {
			printf("%d", ((ptr-tab)+1)/8 );
			switch (((ptr-tab)+1)/8) {
				case 1 : {
					Color(9,0);
					printf("    RN : Reine");
					Color(7,0);
					break;
				}
				case 2 : {
					Color(9,0);
					printf("    CH : Cheval");
					Color(7,0);
					break;
				}
				case 3 : {
					Color(9,0);
					printf("    TO : Tour");
					Color(7,0);
					break;
				}
				case 4 : {
					Color(9,0);
					printf("    PI : Pion");
					Color(7,0);
					break;
				}
				case 5 : {
					Color(9,0);
					printf("    FO : Fou");
					Color(7,0);
					break;
				}
				case 6 : {
					Color(9,0);
					printf("    RO : Roi");
					Color(7,0);
					break;
				}
			}
		}
	}
	printf("\n  1 |2 |3 |4 |5 |6 |7 |8\n");
}

int unselected(int playernum, int *playerunselected, int suppr) {
	int *ptr;
	for(ptr=playerunselected;ptr<playerunselected+6;ptr++) {
		if (playernum == *ptr) {
			if (suppr == 1) {
				*ptr = 0;
			}
			return 1;
		}
	}
	return 0;
}

int echecetmaths(int *Roi, int *AdvReine, int *AdvCheval, int *AdvTour, int *AdvPion, int *AdvFou, int *AdvRoi) {
	int *L, *C;
	L = Roi;
	C = Roi+1;
	
	if ((verifaroundRoi(*L+1,*C,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
		(verifaroundRoi(*L-1,*C,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
	    (verifaroundRoi(*L+1,*C+1,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
		(verifaroundRoi(*L+1,*C-1,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
		(verifaroundRoi(*L-1,*C+1,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
		(verifaroundRoi(*L-1,*C-1,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
		(verifaroundRoi(*L,*C+1,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1) &
		(verifaroundRoi(*L,*C-1,AdvReine,AdvCheval,AdvTour,AdvPion,AdvFou,AdvRoi) == 1)) {
			return 1;
		}
	return 0;
}
int verifaroundRoi(int L, int C, int *AdvReine, int *AdvCheval, int *AdvTour, int *AdvPion, int *AdvFou, int *AdvRoi) {
	if ((L == *AdvReine & C == *(AdvReine+1)) | 
	    (L == *AdvCheval & C == *(AdvCheval+1)) |
		(L == *AdvTour & C == *(AdvTour+1)) |
		(L == *AdvPion & C == *(AdvPion+1)) |
		(L == *AdvFou & C == *(AdvFou+1)) |
		(L == *AdvRoi & C == *(AdvRoi+1))) {
			return 1;
		}
		return 0;
}

void deleteplayer(int L, int C, int *listplayer) {
	int i = 0;
	while (i<24) {
		if (L == *(listplayer+i) & C == *(listplayer+i+1)) {
			*(listplayer+i) = 9;
			*(listplayer+i+1) = 9;
			i = 24;
		}
		i += 2;
	}
}

void Color(int couleurDuTexte,int couleurDeFond) {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
