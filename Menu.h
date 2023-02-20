#ifndef __MENU__
#define __MENU__
#include "extra.h"
#include "TyposStoixeiouMenu.h"

typedef struct InfoMenu *InfoMenuPtr; // Ο Τύπος δείκτη σε Πληροφοριακό Κόμβο Μενού
typedef struct MenuNode *MenuNodePtr;

void Menu_Dimiourgia(MenuPlirof *p, char *onomaest);
int Menu_Adeia_Kathgoria(MenuPlirof p);
void Menu_Eisagwgh_Komvou(MenuPlirof *p);
void Ektypwse_Periexomeno(MenuPlirof p);
void Allagh_Periexomeno(MenuPlirof *p);
void Menu_Epomenos(MenuPlirof *p);
void Menu_Prohgoumenos(MenuPlirof *p);
void Menu_Eisagwgh_Kathgoria(MenuPlirof *p);
void Menu_Metakinisi_Panw(MenuPlirof *p);
void Menu_Metakinisi_Katw(MenuPlirof *p);
void Menu_Diagrafi(MenuPlirof *p);
void Diagrafi_Katw(MenuPlirof *p);
void Voithitiki(KomvosNenu **node);
void Menu_Metakinhsh_Meta(MenuPlirof *p);
void Menu_Metakinhsh_Prin(MenuPlirof *p);
void Menu_Ektypwse_Kathgoria(MenuPlirof p);
void VoithitikiEktiposh(KomvosNenu *node);
void Oliki_Katastrofi(MenuPlirof *p);

#endif
