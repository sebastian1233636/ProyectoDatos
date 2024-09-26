#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	MarcadorPersonal = "";
	marcador = false;
	mostrada = false;
	tiempoIngreso = time(nullptr);
}

PaginaWeb::PaginaWeb() {
	URL = "Sin registro";
	Titulo = "Sin registro";
	MarcadorPersonal = "";
	marcador = false;
	mostrada = false;
	tiempoIngreso = time(nullptr);
}

string PaginaWeb::getURL(){return URL;}

string PaginaWeb::getTitulo(){return Titulo;}

string PaginaWeb::getMarcadorPersonal() { return MarcadorPersonal; }

void PaginaWeb::setUrl(string u) { URL = u; }

bool PaginaWeb::getMarcador() { return marcador; }

bool PaginaWeb::yaMostrada(){return mostrada;}

void PaginaWeb::setMarcadorPersonal(string marcador) { MarcadorPersonal = marcador; }

void PaginaWeb::marcarComoMostrada() {mostrada = true;}

void PaginaWeb::MostrarPaginaWeb() {
	cout << "----------------------------------------\n";
	if (!getMarcadorPersonal().empty()) { cout << "| " << getMarcadorPersonal() << endl; }
	cout << "| " << getURL() << "\n";
	if (marcador) { cout << "| Sitio Favorito \n"; }
	cout << "| " << getTitulo() << "\n";
	cout << "| " << mostrarTiempo() << "\n";
	cout << "----------------------------------------\n";
}

void PaginaWeb::PonerMarcador() { marcador = true; }

void PaginaWeb::QuitarMarcador() { marcador = false; }

time_t PaginaWeb::getTiempo() { return tiempoIngreso; }

string PaginaWeb::mostrarTiempo(){
	time_t now = std::time(nullptr);
	double seconds = difftime(now, tiempoIngreso);
	int minutos = static_cast<int>(seconds / 60);

	if (minutos == 0) { return "Hace unos segundos"; }
	else if (minutos == 1) { return std::to_string(minutos) + " minuto pasado desde ingreso"; }
	else { return std::to_string(minutos) + " minutos pasados desde ingreso"; }
}

void PaginaWeb::setTiempo(time_t t) { tiempoIngreso = t; }

void PaginaWeb::guardarPaginaWeb(ofstream& file){
	bool marcadores = getMarcador();
	string titulo = getTitulo();
	size_t longitudTitulo = titulo.size();
	file.write(reinterpret_cast<const char*>(&longitudTitulo), sizeof(longitudTitulo));
	file.write(titulo.c_str(), longitudTitulo);
	string url = getURL();
	size_t longitudURL = url.size();
	file.write(reinterpret_cast<const char*>(&longitudURL), sizeof(longitudURL));
	file.write(url.c_str(), longitudURL);
	file.write(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));
}

PaginaWeb* PaginaWeb::leerPaginaWeb(ifstream& file){
	string titulo;
	string url;
	bool marcadores;
	size_t LTitulo = 0;
	file.read(reinterpret_cast<char*>(&LTitulo), sizeof(LTitulo));
	titulo.resize(LTitulo);
	file.read(&titulo[0], LTitulo);
	size_t LUrl = 0;
	file.read(reinterpret_cast<char*>(&LUrl), sizeof(LUrl));
	url.resize(LUrl);
	file.read(&url[0], LUrl);
	file.read(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));
	PaginaWeb* paginaWeb = new PaginaWeb(url,titulo);
	if (marcadores) { paginaWeb->PonerMarcador(); }
	return paginaWeb;
}