#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"
#include "TyposStoixeiouMenu.h"
#include "extra.h"


int main(int argc, char *argv[]) {
	InfoMenuPtr 	FoodMenu=NULL,
					CafeMenu=NULL;
	int x,i,j;	
	
	if(argc==1){
		printf("Den dwthike onoma magazioy");
		return 0;
	}
	
	printf("gapse 1 gia faghto h 2 gia kafe"); //katalogos gai kafe h estiatorio
	scanf("%d",&j);
	
	if(j==1){ //an epilexthei estiatorio
	
	printf("Estiatorio %s ",argv[1]);
	do{
	
		PrintEpiloges();
		scanf("%d",&x);
	
	switch(x){
		case 1: Menu_Dimiourgia(&FoodMenu,argv[1]);
				break;
		
				
		case 2: i=Menu_Adeia_Kathgoria(FoodMenu);
			if(i==1)
				printf("den exei epomeno");
			else
				printf("Adeios");
				break;
		
		case 3:	Menu_Eisagwgh_Komvou(&FoodMenu);
				break;
				
		case 4: Ektypwse_Periexomeno(FoodMenu);
				break;
				
		case 5: Allagh_Periexomeno(&FoodMenu);
				break;
		
		case 6:Menu_Epomenos(&FoodMenu);
				break;
		
		case 7:Menu_Prohgoumenos(&FoodMenu);
				break;
				
		case 8: Menu_Metakinhsh_Meta(&FoodMenu);
				break;
				
		case 9: Menu_Metakinhsh_Prin(&FoodMenu);
				break;
				
		case 10:	Menu_Eisagwgh_Kathgoria(&FoodMenu);
				break;
				
		case 11:	Menu_Metakinisi_Panw(&FoodMenu);
				break;
				
		case 12:	Menu_Metakinisi_Katw(&FoodMenu);
				break;
		
		case 13:	Menu_Ektypwse_Kathgoria(FoodMenu);
				break;
				
		case 14:	Menu_Diagrafi(&FoodMenu);
				break;
				
		case 15: Diagrafi_Katw(&FoodMenu);
				break;

		case 16: Oliki_Katastrofi(&FoodMenu);
				break;
	}
}while(x!=101);
}

if(j==2){ //an epilexthei kafes
	
	printf("kafetereia %s ",argv[1]);
	do{
	
		PrintEpiloges();
		scanf("%d",&x);
	
	switch(x){
		case 1: Menu_Dimiourgia(&CafeMenu,argv[1]);
				break;
		
				
		case 2: i=Menu_Adeia_Kathgoria(CafeMenu);
			if(i==1)
				printf("den exei epomeno");
			else
				printf("mh Adeia");
				break;
		
		case 3:	Menu_Eisagwgh_Komvou(&CafeMenu);
				break;
				
		case 4: Ektypwse_Periexomeno(CafeMenu);
				break;
				
		case 5: Allagh_Periexomeno(&CafeMenu);
				break;
		
		case 6:Menu_Epomenos(&CafeMenu);
				break;
		
		case 7:Menu_Prohgoumenos(&CafeMenu);
				break;
				
		case 8: Menu_Metakinhsh_Meta(&CafeMenu);
				break;
				
		case 9: Menu_Metakinhsh_Prin(&CafeMenu);
				break;
				
		case 10:	Menu_Eisagwgh_Kathgoria(&CafeMenu);
				break;
				
		case 11:	Menu_Metakinisi_Panw(&CafeMenu);
				break;
				
		case 12:	Menu_Metakinisi_Katw(&CafeMenu);
				break;
		
		case 13:	Menu_Ektypwse_Kathgoria(CafeMenu);
				break;
				
		case 14:	Menu_Diagrafi(&CafeMenu);
				break;
				
		case 15: Diagrafi_Katw(&CafeMenu);
				break;
				
		case 16:
				break;
				
		case 17:
				break;
				
		case 18:Oliki_Katastrofi(&CafeMenu);
				break;
	}
}while(x!=101);
}
	else
	return 0;
}
