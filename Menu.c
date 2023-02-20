#include <stdlib.h>
#include "Menu.h"
#include "extra.h"
#include <stdio.h>
#include <string.h>

typedef struct MenuNode *MenuNodePtr; // Ο τύπος δείκτη σε κόμβο

struct InfoMenu {
	char* 	  Name; 	   // το όνομα του εστιατορίου
	MenuNodePtr Start;	   // Δείκτης στον πρώτο κόμβο του πρώτου επιπέδου
	MenuNodePtr Current;   // Δείκτης στον τρέχοντα κόμβο
	MenuNodePtr CutToPaste;// Δείκτης στον κόμβο προς μεταφορά σε άλλη θέση
};

struct MenuNode {
	MenuNodePtr Prev, Next, Up, Down;
	TStoixeiouMenu Data;
};

void Menu_Dimiourgia(MenuPlirof *p, char *onomaest){ //dimiourgei th synarthsh
	
	KomvosNenu *node;
	StrNode *stoixeia;
	
	(*p)=malloc(sizeof(struct InfoMenu)); //desmeyei mnhmes
	node=malloc(sizeof(KomvosNenu));
	stoixeia=malloc(sizeof(StrNode));
	
	stoixeia->Category=-1; //arxeikopoiei ton typo stoixeiou
	stoixeia->name=NULL;
	stoixeia->Price=0;
	
	node->Down=NULL;
	node->Next=NULL; //arxeikopoiei ton komvo
	node->Prev=NULL;
	node->Up=NULL;
	
	(*p)->CutToPaste=NULL;
	(*p)->Start=node;			//arxikopoiei to infomenu
	(*p)->Current=node;
	(*p)->Name=malloc(strlen(onomaest)+1);
	strcpy((*p)->Name, onomaest);
	node->Data=*stoixeia;
}

int Menu_Adeia_Kathgoria(MenuPlirof p){		//epistrefei 1 h 0 
	
	if((p)!=NULL){
	if(p->Current->Prev==NULL && p->Current->Next==NULL)
		return 1;
	else 
	 	return 0;
	}
	else{
		printf("Arxikopoihse to menu");
	}
}

void Menu_Eisagwgh_Komvou(MenuPlirof *p){  //eisagei neo kombo
	
	if((*p)!=NULL){
	KomvosNenu *node;
	StrNode *stoixeia;
	
	node=malloc(sizeof(KomvosNenu));  //desmeuei mnhmh
	stoixeia=malloc(sizeof(StrNode));
	
	int x;
	float y;
	char z[50]; //pinakas gia to onoma
	
	printf("1 gia kathgoria 0 gia piato\n");
	scanf("%d",&x);
	if(x==0){
		
		stoixeia->Category=0;
		
		printf("Pes timi\n");
		scanf("%f",&y);
		stoixeia->Price=y;
		
		printf("Pes onoma\n");
		scanf("%s",z);
		stoixeia->name=malloc(50*sizeof(char));
		strcpy(stoixeia->name,z);
	}
	else if(x==1){
			
	stoixeia->Category=1;
	
		printf("Pes onoma\n");
		scanf("%s",z);
		stoixeia->name=malloc(50*sizeof(char));
		strcpy(stoixeia->name,z);
	}
	
	node->Data=*stoixeia; //sundeei ton komvo
	node->Prev=(*p)->Current;
	node->Next=NULL;
	node->Up=(*p)->Current->Up;
	node->Down=NULL;
	(*p)->Current->Next=node;
	(*p)->Current=node;
	}
	else{
		printf("Arxikopoihse to menu");
	}
}

void Ektypwse_Periexomeno(MenuPlirof p){ //ektypvnei to periexomeno
	
	if(p!=NULL){
		if(p->Current->Prev!=NULL){
	
	if(p->Current->Data.Category==0)
		printf("%s	%f",p->Current->Data.name,p->Current->Data.Price);
	else if(p->Current->Data.Category==1)
		printf("%s",p->Current->Data.name);
	}
	else{
		printf("Einai Kefali");
		return;
	}
	}
	else{
		printf("Arxikopoihse to menu");
	}
}

void Allagh_Periexomeno(MenuPlirof *p){ //allazei to periexomeno enos kemvou
	
	if((*p)!=NULL){
		if((*p)->Current->Prev!=NULL){
	int y;
	char z[50];
	
	if((*p)->Current->Data.Category==0){
		printf("Pes timi\n");
		scanf("%f",&y);
		(*p)->Current->Data.Price=y;
		
		printf("Pes onoma\n");
		scanf("%s",z);
		(*p)->Current->Data.name=malloc(50*sizeof(char));
		strcpy((*p)->Current->Data.name,z);
	}
	else if((*p)->Current->Data.Category==1){
		
		printf("Pes onoma\n");
		scanf("%s",z);
		(*p)->Current->Data.name=malloc(50*sizeof(char));
		strcpy((*p)->Current->Data.name,z);
	}
		}
	else{
		printf("Einai Kefali");
	
	}
}
	else{
		printf("Arxikopoihse to menu");
	}
}
void Menu_Epomenos(MenuPlirof *p){ //deixnei ston epomeno komvo
	
	if((*p)!=NULL){
	if((*p)->Current->Next != NULL)
		(*p)->Current=(*p)->Current->Next;
	 else{
    	printf("teleytaios");
    	return;
    }
	}
	else{
		printf("Arxikopoihse to menu");
	}
}

void Menu_Prohgoumenos(MenuPlirof *p){ //deixnei ston prohgoymeno komvo
	
	if((*p)!=NULL){
	if((*p)->Current->Prev != NULL)
    	(*p)->Current=(*p)->Current->Prev;
    else{
    	printf("Kefali");
    	return;
    }
		}
	else{
		printf("Arxikopoihse to menu");
	}
}

void Menu_Metakinhsh_Meta(MenuPlirof *p){ //antallasei th thesi toy komvou me ton epomeno toy
	
	if((*p)!=NULL){
		
		if((*p)->Current==NULL)	{
			printf("Den yparxei deikths\n");
			return;
		}
		
		if((*p)->Current->Prev==NULL)	{
			printf("Kefali\n");
			return;
		}
		
		if((*p)->Current->Next==NULL)	{
			printf("Den exei epomeno\n");
			return;
		}
	KomvosNenu *tempa=(*p)->Current;
	KomvosNenu *tempb=tempa->Next;   			//orizei prosorinous kombous
	KomvosNenu *tempc=tempb->Next;
	KomvosNenu *tempd=tempa->Prev;
	
	tempd->Next=tempb;
	tempb->Prev=tempd;			//antalasei tis times
	tempb->Next=tempa;
	tempa->Prev=tempb;
	tempa->Next=tempc;
	if(tempc)
		tempc->Prev=tempa;
	}
		else{
		printf("Arxikopoihse to menu");
	}
	
}

void Menu_Metakinhsh_Prin(MenuPlirof *p){   //antallasei ton komvo me ton prohgoymeno toy
	
	if((*p)!=NULL){
		
		if((*p)->Current==NULL)	{
			printf("Den yparxei deikths\n");
			return;
		}
		
		if((*p)->Current->Prev==NULL)	{
			printf("Kefali\n");
			return;
		}
		
		if((*p)->Current->Prev->Prev==NULL)	{
			printf("O prohgoumenow einai kefali\n");
			return;
		}
		
	KomvosNenu *tempa=(*p)->Current;
	KomvosNenu *tempb=tempa->Prev;
	KomvosNenu *tempc=tempb->Prev;				
	KomvosNenu *tempd=tempa->Next;					//orizei prosorinous kombous
	
	tempc->Next=tempa;
	tempa->Prev=tempc;
	tempa->Next=tempb;					//antalasei tis times
	tempb->Prev=tempa;
	tempb->Next=tempd;
	if(tempd)
		tempd->Prev=tempb;
		}
		else{
		printf("Arxikopoihse to menu");
	}
	
}
void Menu_Eisagwgh_Kathgoria(MenuPlirof *p){ //eisagei nea upokathgoria sto down
	
	if((*p)!=NULL){	
	KomvosNenu *node;
	StrNode *stoixeia;
	
	node=malloc(sizeof(KomvosNenu));
	stoixeia=malloc(sizeof(StrNode));
	
	node->Prev=NULL;
	node->Next=NULL;
	node->Down=NULL;
	node->Up=(*p)->Current;
	
	stoixeia->Category=-1;
	stoixeia->name=NULL;
	stoixeia->Price=0;
	
	node->Data=*stoixeia;
	(*p)->Current->Down=node;
	}
		else{
		printf("Arxikopoihse to menu\n");
	}
}

void Menu_Metakinisi_Panw(MenuPlirof *p){  //deixnei ston pano komvo
	
	if((*p)!=NULL){
	if((*p)->Current->Up != NULL)
		(*p)->Current=(*p)->Current->Up;
	 else{
    	printf("teleytaios\n");
	}
}
		else{
		printf("Arxikopoihse to menu\n");
	}
}

void Menu_Metakinisi_Katw(MenuPlirof *p){  		//deixnei ston katw kombo		
	
	if((*p)!=NULL){
	if((*p)->Current->Down != NULL)
		(*p)->Current=(*p)->Current->Down;
	 else{
    	printf("teleytaios\n");
	}
	}
		else{
		printf("Arxikopoihse to menu\n");
	}
}

void Menu_Diagrafi(MenuPlirof *p){				//diagrafei ton epomeno kombo
	
	if((*p)!=NULL){
	
	if((*p)->Current==NULL)	{
			printf("Den yparxei deikths\n");
			return;
		}
		
	if((*p)->Current->Next==NULL)	{
			printf("Den yparxei epomenos\n");
			return;
		}	
		
	if((*p)->Current->Next->Down!=NULL)	{
			printf("Yparxei katw\n");
			return;
		}
		
	KomvosNenu *temp;
	temp=(*p)->Current->Next->Next;
	free((*p)->Current->Next);
	(*p)->Current->Next=temp;
	temp->Prev=(*p)->Current;
	}
		else{
		printf("Arxikopoihse to menu\n");
	}
	
}

void VoithitikiEktiposh(KomvosNenu *node){ //kanei thn anadromh gia tis epomenes
	
	do{
		
	if(node->Data.Category==0)
		printf("%s	%f \n",node->Data.name,node->Data.Price);
	else if(node->Data.Category==1)
		printf("%s\n",node->Data.name);
	if(node->Down !=NULL)
		VoithitikiEktiposh(node->Down);  //anadromh
	node=node->Next;
	}	while(node != NULL);
	


}

void Menu_Ektypwse_Kathgoria(MenuPlirof p){		//ektypvnei kathe kathgoria katw apo ton kombo
	
	if((p)!=NULL){
		if(p->Current->Prev==NULL){
	VoithitikiEktiposh(p->Current);
}
	else{
		printf("Den einai kefali\n");
		return;
	}
	}
		else{
		printf("Arxikopoihse to menu\n");
	}
}

void VoithitikiDiagrafi(KomvosNenu **node){		//kanei thn anadromh gia tis epomenes
	
	while((*node)->Next != NULL){
		
	KomvosNenu *next=(*node)->Next;
		if((*node)->Down !=NULL)
			VoithitikiDiagrafi(&next->Down);		//anadromh
		free((*node));
		(*node)=next;	
	}	
	free((*node));
	(*node)=NULL;
}

void Diagrafi_Katw(MenuPlirof *p){		//diagrafei kathe katw kombo
	
	if((*p)!=NULL){
	
	if((*p)->Current==NULL)	{
			printf("Den yparxei deikths\n");
			return;
		}	
		
	if((*p)->Current->Down==NULL)	{
			printf("Den Yparxei katw\n");
			return;
		}
			
	VoithitikiDiagrafi (&(*p)->Current->Down);
	}
	else{
		printf("Arxikopoihse to menu");
	}
}

void Oliki_Katastrofi(MenuPlirof *p){  //diagrafei ta panta
	
	if((*p)!=NULL){			
		VoithitikiDiagrafi(&(*p)->Start);
	}
	
	else{
		printf("Arxikopoihse to menu");
	}
}
