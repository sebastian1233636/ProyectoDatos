#include"AdminPestañas.h"

int main() {
	Pestaña* pes = new Pestaña();
	PaginaWeb* pag1 = new PaginaWeb("https://store.steampowered.com", "Steam");
	PaginaWeb* pag2 = new PaginaWeb("https://onlyfans.com", "OnlyFans");
	PaginaWeb* pag3 = new PaginaWeb("https://www.playstation.com", "PlayStation");
	pes->InsertarPrimero(pag1);
	pes->InsertarPrimero(pag2);
	pes->InsertarPrimero(pag3);
	pes->ExplorarHistorial(pes->getTail());
	return 0;
}