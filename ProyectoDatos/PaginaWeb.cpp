#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	marcador = false;
	mostrada = false;
	tiempoIngreso = time(nullptr);
}

PaginaWeb::PaginaWeb() {
	URL = "Sin registro";
	Titulo = "sin registro";
	marcador = false;
	mostrada = false;
	tiempoIngreso = time(nullptr);
}

string PaginaWeb::getURL(){return URL;}

string PaginaWeb::getTitulo(){return Titulo;}

bool PaginaWeb::getMarcador() { return marcador; }

bool PaginaWeb::yaMostrada(){return mostrada;}

void PaginaWeb::marcarComoMostrada() {mostrada = true;}

void PaginaWeb::MostrarPaginaWeb(){
    cout << "----------------------------------------\n";
    cout << "| " + getURL() + "\n";
    if (marcador == true) {cout << "| Sitio Favorito \n";}
    cout << "| " + getTitulo() + "\n";
	cout << "| " + mostrarTiempo();
    cout << "----------------------------------------\n";
}

void PaginaWeb::PonerMarcador() { marcador = true; }

void PaginaWeb::QuitarMarcador() { marcador = false; }

time_t PaginaWeb::getTiempo()
{
	return tiempoIngreso;
}

string PaginaWeb::mostrarTiempo()
{
	time_t now = std::time(nullptr);
	double seconds = difftime(now, tiempoIngreso);

	// Convertir a minutos, por ejemplo
	int minutos = static_cast<int>(seconds / 60);
	return std::to_string(minutos) + " pasados desde ingreso";
}

void PaginaWeb::setTiempo(time_t t)
{
	tiempoIngreso = t;
}

