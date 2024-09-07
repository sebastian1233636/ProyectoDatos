#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	marcador = false;
	mostrada = false;
}

PaginaWeb::PaginaWeb() {
	URL = "Sin registro";
	Titulo = "sin registro";
	marcador = false;
	mostrada = false;
}

string PaginaWeb::getURL(){return URL;}

string PaginaWeb::getTitulo(){return Titulo;}

bool PaginaWeb::getMarcador() { return marcador; }

bool PaginaWeb::yaMostrada(){return mostrada;}

void PaginaWeb::marcarComoMostrada() {mostrada = true;}

void PaginaWeb::MostrarPaginaWeb(){
    stringstream s;
    cout << "----------------------------------------\n";
    cout << "| " + getURL() + "\n";
    if (marcador == true) {cout << "| Sitio Favorito \n";}
    cout << "| " + getTitulo() + "\n";
    cout << "----------------------------------------\n";
}

void PaginaWeb::PonerMarcador() { marcador = true; }

void PaginaWeb::QuitarMarcador() { marcador = false; }

