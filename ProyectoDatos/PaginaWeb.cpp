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

void PaginaWeb::MostrarPaginaWeb(){
    stringstream s;
    cout << "----------------------------------------\n";
    cout << "| " + getURL() + "\n";
    if (marcador == true) {cout << "| Sitio Favorito \n";}
    cout << "| " + getTitulo() + "\n";
    cout << "----------------------------------------\n";
}

void PaginaWeb::PonerMarcador(){marcador = true;}
