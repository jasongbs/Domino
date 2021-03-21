#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct peca{
	int id;
	int numeroEsq;
	int numeroDir;
}Peca;

typedef struct Peca peca;

typedef struct jogador{
	char jogador[20];
	Peca pack[28];
	int qtdPecas;
}Jogador;

typedef struct Jogador jogador;

typedef struct game{
	int id;
	Peca *pecas;
	Peca pecasEmJogo[28];
	Jogador *jogadores; 
	int NJogadores;
	int NPecas;
	int NPecasEmJogo;
	int JogadorJogando;
}Game;

typedef struct Game game;

void criarPecas(Peca pecas[28]){
	int aux=7,i=0,j=0;
	
	int x,y,cont=0;

	for(x=0; x<=6; x++)
	{
		for(y=x;y<=6;y++)
		{
			pecas[cont].id = cont;
			pecas[cont].numeroEsq = x;
			pecas[cont].numeroDir = y;
			cont++;
		}		
	}	
}

int selecionaJogadorInicial(Game *game){
	int njg=0,i,IdMelhorPeca;
	int max[game->NJogadores];
	int maxId[game->NJogadores];
	bool stop;

	for(i=0; i<=game->NJogadores;i++){//inicializando vetor auxiliar
		max[i]=-1;
	}
	
	do{
		stop=false;
		for(i=game->jogadores[njg].qtdPecas-1;  i>=0;i--){

			if( game->jogadores[njg].pack[i].id == 0 || game->jogadores[njg].pack[i].id == 7 || game->jogadores[njg].pack[i].id == 13 ||	game->jogadores[njg].pack[i].id == 18 ||
			game->jogadores[njg].pack[i].id == 22 ||	game->jogadores[njg].pack[i].id == 25 ||	game->jogadores[njg].pack[i].id == 27){
			if(max[njg]<game->jogadores[njg].pack[i].id){
			max[njg]=game->jogadores[njg].pack[i].id;
			maxId[njg]=i;
		}
		}
	}
	njg++;
	}while(njg!=game->NJogadores);
	
	int maiorPontos=-1,maiorCod=-1,somaTemp=-1;

	for(i=0;i<game->NJogadores;i++){
	
		if(max[i]>maiorPontos){
			
			maiorPontos=max[i];
			maiorCod = i;
			IdMelhorPeca=maxId[i];
			
		}
	}
	

	njg=0;
	
	if(maiorCod==-1){

		maiorPontos=0;
		maiorCod=0;
		
	do{
		for(i=game->jogadores[njg].qtdPecas; i<=0;i--){
		somaTemp=game->jogadores[njg].pack[i].numeroDir+game->jogadores[njg].pack[i].numeroEsq;
	if(somaTemp > somaTemp ){
			maiorPontos=game->jogadores[njg].pack[i].id;
			maiorCod=njg;
			IdMelhorPeca=i;
		}
	}
	
	}while(njg!=game->NJogadores && njg++);	
	

}

	game->JogadorJogando=maiorCod;
	printf("Melhor peca para iniciar: %d",IdMelhorPeca);
return IdMelhorPeca;
}

void mostrarPecas(Peca pecas[], int quantidadePecas){

	int cont=0;
	//printf("\nQuantidade de Pecas: %d\n",quantidadePecas);
	for(cont=0;cont<quantidadePecas && cont<20;cont++)
		{
			//printf("%d (%d ,%d )",pecas[cont].id,pecas[cont].numeroEsq,pecas[cont].numeroDir);
			//printf("%d = (%d ,%d )",cont+1,pecas[cont].numeroEsq,pecas[cont].numeroDir);
			//desenharNumeros(pecas[cont].numeroEsq,pecas[cont].numeroDir);
			desenharPeca(pecas[cont].numeroEsq,pecas[cont].numeroDir);
			printf("\n");
		}	
}

void desenharNumeros(int numeroEsquerda, int numeroDireita){
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,187);
	
	printf("%c",186);
	
	//Primeira Linha Esquerda
	if(numeroEsquerda==6 || numeroEsquerda==2 || numeroEsquerda==0 || numeroEsquerda==1 || numeroEsquerda==4){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==3){
	printf(" %c %c %c",32,32,254);
	}

	printf(" %c",186);
	
	//Primeira Linha Direita
	if(numeroDireita==6 || numeroDireita==4 || numeroDireita==2 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita==3){
	printf(" %c %c %c",32,32,254);
	}
	printf(" %c\n%c",186,186);
	
	//Segunda Linha Esquerda
	if(numeroEsquerda==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroEsquerda==5 || numeroEsquerda==3 || numeroEsquerda==1 || numeroEsquerda==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==2){
	printf(" %c %c %c",32,32,254);
	}
	printf(" %c",186);
	
	//Segunda Linha Direita
	if(numeroDireita==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroDireita==5 || numeroDireita==3 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita==2){
	printf(" %c %c %c",32,32,254);
	}
	
	printf(" %c\n%c",186,186);
	
	//Terceira Linha Esquerda
	if(numeroEsquerda==6 || numeroEsquerda==4 || numeroEsquerda==2){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==5 || numeroEsquerda==1 || numeroEsquerda==3) {
	printf(" %c %c %c",32,254,32);
	}else if(numeroEsquerda==0){
	printf(" %c %c %c",32,45,32);
	}
	printf(" %c",186);
	
	//Terceira Linha Direita
	if(numeroDireita==6 || numeroDireita==4 || numeroEsquerda==2){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==5 || numeroDireita==1 || numeroDireita==3){
	printf(" %c %c %c",32,254,32);
	}else if(numeroDireita==0){
	printf(" %c %c %c",32,45,32);
	}
	printf(" %c\n%c",186,186);
	
	//Quarta Linha Esquerda
	if(numeroEsquerda==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroEsquerda==5 || numeroEsquerda==3 || numeroEsquerda==1 || numeroEsquerda==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==2){
	printf(" %c %c %c",254,32,32);
	}
	printf(" %c",186);
	
	//Quarta Linha Direita
	if(numeroDireita==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroDireita==5 || numeroDireita==3 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita==2){
	printf(" %c %c %c",254,32,32);
	}
	printf(" %c\n%c",186,186);
	
	//Quinta Linha Esquerda
	if(numeroEsquerda==6 || numeroEsquerda==4 || numeroEsquerda==2 || numeroEsquerda==1 || numeroEsquerda==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==3){
	printf(" %c %c %c",254,32,32);
	}
	
	printf(" %c",186);
	
	//Quinta Linha Direita
	if(numeroDireita==6 || numeroDireita==4 || numeroDireita==2 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita == 3){
	printf(" %c %c %c",254,32,32);
	}
	
	printf(" %c",186);
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,188);
}

int desenharPeca(int numeroCima, int numeroBaixo){
	
		if(numeroCima!=numeroBaixo){
		printf("\n    %c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,187);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		desenharPecasVericais( numeroCima);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		printf("\n    %c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,185);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		desenharPecasVericais( numeroBaixo);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		printf("\n    %c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,188);
	}else{
		desenharNumeros(numeroCima,numeroBaixo);
	}
	
}

int desenharPecasVericais(int numero){

	printf("\n    %c",186);
	//Primeira Linha 
	if(numero==0 || numero==1)
	printf(" %c %c %c",32,32,32);
	if(numero==2)
	printf(" %c %c %c",254,32,32);
	if(numero==3)
	printf(" %c %c %c",32,32,254);
	if(numero==4 || numero==5 || numero==6)
	printf(" %c %c %c",254,32,254);
	
	printf("%c%c\n    %c",32,186,186);
	
	//Segunda Linha 
	if(numero==0 )
	printf(" %c %c %c",32,196,32);
	if(numero==2 || numero==4 )
	printf(" %c %c %c",32,32,32);
	if(numero==1 || numero==3 || numero==5)
	printf(" %c %c %c",32,254,32);
	if(numero==6)
	printf(" %c %c %c",254,32,254);
	
	printf("%c%c\n    %c",32,186,186);	
	
	//Terceira Linha 
	if(numero==0 || numero==1)
	printf(" %c %c %c",32,32,32);
	if(numero==2)
	printf(" %c %c %c",32,32,254);
	if(numero==3)
	printf(" %c %c %c",254,32,32);
	if(numero==4 || numero==5 || numero==6)
	printf(" %c %c %c",254,32,254);
	
	printf("%c%c",32,186);
	
}

int sortear(Peca pecas[28], int tamanhoVetor, Jogador *jogador){

	int sorteados[28];
	int sorteado;
	int nSorteados=0;
	int i,j;
	
	
	if(tamanhoVetor<=7){		
		for( i=0; i<7; i++){
			jogador->pack[i].id = pecas[i].id;	
			jogador->pack[i].numeroDir=pecas[i].numeroDir;
			jogador->pack[i].numeroEsq=pecas[i].numeroEsq;
			jogador->qtdPecas=i+1;
			tamanhoVetor--;
		}
		return tamanhoVetor;
		pecas = NULL;
	}
	
	for(i=0;i<28 ;i++){
		sorteados[i]=-1;
	}

	srand(time(NULL));
	for( i=0; nSorteados<7 && tamanhoVetor!= 0; i++){
		sorteado = rand() % tamanhoVetor;
		if(indexof(sorteados, sorteado)==0){
			if(pecas[sorteado].id!=-1){
			jogador->pack[nSorteados].id = pecas[sorteado].id;	
			jogador->pack[nSorteados].numeroDir=pecas[sorteado].numeroDir;
			jogador->pack[nSorteados].numeroEsq=pecas[sorteado].numeroEsq;
			nSorteados++;
			jogador->qtdPecas=nSorteados;
			sorteados[nSorteados]=sorteado;
			removePeca(pecas,sorteado,tamanhoVetor);
			tamanhoVetor--;
		}
		}
		mostrarPecas(jogador->pack,jogador->qtdPecas);
		
	}			
	return tamanhoVetor;
}

int indexof( int sorteados[28], int sorteado){
	int status=0,i;
	for(i=0;i<28 && status == 0;i++){
		if(sorteados[i]==sorteado){
			status=1;
		}
	}
	return status;
}

int removePeca( Peca vetor[28], int posicao, int tamanhoAtual){
	int i;
	for(i=posicao;i<tamanhoAtual;i++){
		vetor[i]=vetor[i+1];
		}
	} 
 
int inserePeca(Peca vetor[28], int tamanhoAtual){
		int i,x;
		Peca temp;
		
		//0 - 3
	for(i=0;i<=tamanhoAtual;i++){
	
		if(i==0){
			temp=vetor[i];
			vetor[i]=vetor[tamanhoAtual];
		}else{
			temp=vetor[i+1];
			vetor[i+1]=vetor[i];
		}
		
		
	}
	

} 



void jogarPeca(Game *game, Jogador *jogador, int PosicaoPeca, int sentido){
	printf("\nEsquerda: %d - Direita: %d -- \n",game->pecasEmJogo[0].numeroEsq,game->pecasEmJogo[0].numeroDir);
	
	if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroDir ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroEsq || 
	 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroEsq ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroDir || 
	 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir || 
	 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq || 
	 game->NPecasEmJogo == 0){
	
	int NPecasEmJogo = game->NPecasEmJogo;
	
	if(game->NPecasEmJogo==0){
		game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroEsq;
		game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroDir;
		game->pecasEmJogo[NPecasEmJogo].id = jogador->pack[PosicaoPeca].id;
	}
	
	if(sentido==0){
		if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroDir ||
	 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroEsq ||
			 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroEsq ||
	 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroDir){
	 			if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroEsq){
	 				printf("\n!Invertendoooo! (%d,%d)",jogador->pack[PosicaoPeca].numeroEsq,jogador->pack[PosicaoPeca].numeroDir);
	 				
					game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroEsq;
					game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroDir;
						printf("\n!Invertido! (%d,%d)",jogador->pack[PosicaoPeca].numeroDir,jogador->pack[PosicaoPeca].numeroEsq);
				}else if(jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroEsq){
					printf("\n!Nao sera invertido! (%d,%d)",jogador->pack[PosicaoPeca].numeroEsq,jogador->pack[PosicaoPeca].numeroDir);
					game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroDir;
					game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroEsq;	
			}
		game->pecasEmJogo[NPecasEmJogo].id = jogador->pack[PosicaoPeca].id;
		}
	}else{
			if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir ||
	 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq ||
			 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq ||
	 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir){
	 			
	 			if(jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir){
	 				printf("\n!Invertendoooo! (%d,%d)",jogador->pack[PosicaoPeca].numeroEsq,jogador->pack[PosicaoPeca].numeroDir);
					game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroEsq;
					game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroDir;
						printf("\n!Invertido! (%d,%d)",jogador->pack[PosicaoPeca].numeroDir,jogador->pack[PosicaoPeca].numeroDir);
				}else if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir){
					printf("\n!Nao sera invertido! (%d,%d)",jogador->pack[PosicaoPeca].numeroEsq,jogador->pack[PosicaoPeca].numeroDir);
					game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroDir;
					game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroEsq;	
			}
		game->pecasEmJogo[NPecasEmJogo].id = jogador->pack[PosicaoPeca].id;//mesa 6/1  peca 1/4
	}
}


	
	if(sentido==0){
	inserePeca(game->pecasEmJogo,NPecasEmJogo);
	}
	removePeca(jogador->pack,PosicaoPeca,jogador->qtdPecas-1);
	jogador->qtdPecas--;
	game->NPecasEmJogo++;
	}else{
		printf("\nAVISO! Essa peca nao pode ser utilizada ai!\n");
	}
}

void ComprarPeca(Game *game, Peca pecas[28], Jogador *jogador){
	int sorteado;
	if(game->NPecas>0){
	srand(time(NULL));
	sorteado = rand() % game->NPecas;
	jogador->pack[jogador->qtdPecas].id = pecas[sorteado].id;	
	jogador->pack[jogador->qtdPecas].numeroDir = pecas[sorteado].numeroDir;
	jogador->pack[jogador->qtdPecas].numeroEsq = pecas[sorteado].numeroEsq;
	removePeca(pecas,sorteado,game->NPecas);
	jogador->qtdPecas++;
	game->NPecas++; 
	}else{
		printf("\nAVISO! Não possui mais pecas para serem compradas!");
	}
}

int mudarJogador(Game *game){
	if(game->JogadorJogando!=game->NJogadores-1){
		return ++game->JogadorJogando;
	}else{
		return game->JogadorJogando=0;
	}
}

void controladorPartida(){
	
}
	
int main(int argc, char *argv[]) {
	
	Game game;
	game.NPecas = 28;
	
	Peca pecas[28];
	
	game.pecas = &pecas;
	game.id = 1;
	game.NPecasEmJogo = 0;
	int QTDJogadores, i;
		
	/** Criando as Peças**/
	criarPecas(pecas);
	
	/** Criando a interface **/
	printf("\n     DOMINO \n");
	
	printf("Quantos Jogadores? ");
	scanf("%d",&QTDJogadores);
	Jogador jogador[QTDJogadores];
	game.NJogadores =QTDJogadores;
	
	do{
		printf("Nome do Jogador %d: ",i+1);
		scanf("%s",jogador[i].jogador);
		i++;	
	}while(i<game.NJogadores);
	
	game.jogadores = &jogador;
	system("cls");	
	
	
	i=0;
	printf("\n===================================================");
	do{
	
	printf("\nSorteando as pecas do Jogador %d",i+1);	
	game.NPecas=sortear(pecas,game.NPecas,&jogador[i]);	
	Sleep(700);
	printf("\nSorteio concluida... \n",i+1);	
	printf("\n===================================================");
	Sleep(300);
	i++;
	
	}while(i<game.NJogadores);
	
	system("cls");
	int inicio=1;
	/*i=0;
	do{
	printf("\nPecas do Jogador %d",i+1);	
	mostrarPecas(jogador[i].pack,jogador[i].qtdPecas);
	i++;
	}while(i<game.NJogadores);*/

	/*printf("\n==========================");
	printf("\nPecas restantes na pilha");
	mostrarPecas(pecas,game.NPecas);
		*/
		
		/** Início de jogo **/
	int SelecionadaComecar = selecionaJogadorInicial(&game);	
	mostrarPecas(jogador[game.JogadorJogando].pack,jogador[game.JogadorJogando].qtdPecas);
	jogarPeca(&game,&jogador[game.JogadorJogando],SelecionadaComecar,1);//0 = cima 1 = baixo


//	mostrarPecas(&game.jogadores[game.JogadorJogando], &game.jogadores[game.JogadorJogando].qtdPecas);
	
	printf("\n Quem comecou foi Jogador %d\n",game.JogadorJogando);	
	mostrarPecas(game.pecasEmJogo, game.NPecasEmJogo);
	
	int selecao,local;
	do{
		
		int  vezJogador = mudarJogador(&game);
		
		printf("\n Vez do Jogador  %d\n",vezJogador);	
		mostrarPecas(jogador[vezJogador].pack,jogador[vezJogador].qtdPecas);
		printf("Peca: ");
		scanf("%d",&selecao);
		printf(" Local? 0=Cima 1=Baixo: ");
		scanf("%d",&local);
		jogarPeca(&game,&jogador[vezJogador],selecao-1,local);
		//Sleep(1000);
		getch();
		system("cls");
		mostrarPecas(game.pecasEmJogo, game.NPecasEmJogo);
	}while(inicio!=0);
	/*printf("\n==========================");
	printf("\nEm jogo");*/
	//jogarPeca(&game,&jogador[0],2,0);//0 = cima 1 = baixo
	//jogarPeca(&game,&jogador[0],1,0);
	//jogarPeca(&game,&jogador[0],1,1);
	
	/*
	printf("\n========= Game ============");
	mostrarPecas(game.pecasEmJogo, game.NPecasEmJogo);
	printf("\n========== Jogador ============");
	mostrarPecas(jogador[0].pack,jogador[0].qtdPecas);
	
	printf("\n========= Comprar ============");
	ComprarPeca(&game, pecas, &jogador[0]);
	printf("\n========== Jogador ============");
	mostrarPecas(jogador[0].pack,jogador[0].qtdPecas);
	*/
	return 0;
	

}


