#include"AdminPesta�as.h"

int main() {
	Pesta�a* pes = new Pesta�a();
	PaginaWeb* pag1 = new PaginaWeb("https://store.steampowered.com", "Steam");
	PaginaWeb* pag2 = new PaginaWeb("https://onlyfans.com", "OnlyFans");
	PaginaWeb* pag3 = new PaginaWeb("https://www.playstation.com", "PlayStation");
	pes->insertarPrimero(pag1);
	pes->insertarPrimero(pag2);
	pes->insertarPrimero(pag3);
	pes->explorarHistorial();
	return 0;
}