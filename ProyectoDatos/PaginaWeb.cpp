#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	marcador = false;
}

PaginaWeb::PaginaWeb() {
	URL = "Sin registro";
	Titulo = "sin registro";
	marcador = false;
}

string PaginaWeb::getURL(){return URL;}

string PaginaWeb::getTitulo(){return Titulo;}

bool PaginaWeb::getFavorito(){return marcador;}

void PaginaWeb::MostrarPaginaWeb(){
	cout << "------------------------------------" << getURL() << "----------------------------------------" << endl;
	if (getFavorito() == true) {
		cout << "FAVORITO" << endl;
	}
}

void PaginaWeb::PonerMarcador(){marcador = true;}
