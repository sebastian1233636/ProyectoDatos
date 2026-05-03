#include "PaginaWeb.h"


PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	MarcadorPersonal = "";
	marcador = false;
	mostrada = false;
	mostrarFiltro = true;
	filtroTiempo = true;
	tiempoIngreso = time(nullptr);
}


PaginaWeb::PaginaWeb() {
	URL = "Sin registro";
	Titulo = "Sin registro";
	MarcadorPersonal = "";
	marcador = false;
	mostrada = false;
	mostrarFiltro = false;
	tiempoIngreso = time(nullptr);
}

string PaginaWeb::getURL() { return URL; }
string PaginaWeb::getTitulo() { return Titulo; }
string PaginaWeb::getMarcadorPersonal() { return MarcadorPersonal; }
void PaginaWeb::setUrl(string u) { URL = u; }
bool PaginaWeb::getMarcador() { return marcador; }
bool PaginaWeb::getMostrarFiltro() { return mostrarFiltro; }
bool PaginaWeb::getFiltroTiempo() { return filtroTiempo; }
bool PaginaWeb::yaMostrada() { return mostrada; }
void PaginaWeb::setTitulo(string tit) { Titulo = tit; }
void PaginaWeb::setMarcadorPersonal(string marcador) { MarcadorPersonal = marcador; }
void PaginaWeb::marcarComoMostrada() { mostrada = true; }
time_t PaginaWeb::getTiempo() { return tiempoIngreso; }
void PaginaWeb::setTiempo(time_t t) { tiempoIngreso = t; }

void PaginaWeb::MostrarPaginaWeb() {
	cout << "    \x1B[34m+-------------------------------------------+\x1B[0m\n";
	if (!getMarcadorPersonal().empty()) {
		cout << "    \x1B[34m|\x1B[0m \x1B[32m" << getMarcadorPersonal() << "\x1B[0m\n";
	}
	if (marcador) {
		cout << "    \x1B[34m|\x1B[0m [\x1B[33mSitio Favorito\x1B[0m]\n";
	}
	cout << "    \x1B[34m|\x1B[0m URL: " << getURL() << "\n";
	cout << "    \x1B[34m|\x1B[0m Titulo: " << getTitulo() << "\n";
	cout << "    \x1B[34m|\x1B[0m " << mostrarTiempo() << "\n";
	cout << "    \x1B[34m+-------------------------------------------+\x1B[0m\n";
}

void PaginaWeb::PonerMarcador() { marcador = true; }

void PaginaWeb::QuitarMarcador() { marcador = false; }

string PaginaWeb::mostrarTiempo() {
	time_t now = std::time(nullptr);
	double seconds = difftime(now, tiempoIngreso);
	int minutos = static_cast<int>(seconds / 60);

	if (minutos == 0) {
		return "Hace unos segundos";
	}
	else if (minutos == 1) {
		return std::to_string(minutos) + " minuto pasado desde ingreso";
	}
	else {
		return std::to_string(minutos) + " minutos pasados desde ingreso";
	}
}

void PaginaWeb::activarFiltro() { mostrarFiltro = true; }

void PaginaWeb::desactivarFiltro() { mostrarFiltro = false; }

void PaginaWeb::activarFiltroTiempo() { filtroTiempo = true; }

void PaginaWeb::desactivarFiltroTiempo() { filtroTiempo = false; }
void PaginaWeb::guardarPaginaWeb(ofstream& file) {
	file << getURL() << "|" << getTitulo() << "|" << getMarcador() << "|" << getMarcadorPersonal() << "\n";
}

PaginaWeb* PaginaWeb::leerPaginaWeb(ifstream& file) {
	string linea;
	if (!getline(file, linea)) {
		return nullptr;
	}

	size_t pos1 = linea.find('|');
	size_t pos2 = linea.find('|', pos1 + 1);
	size_t pos3 = linea.find('|', pos2 + 1);
	size_t pos4 = linea.find('|', pos3 + 1);

	if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
		return nullptr;
	}

	string url = linea.substr(0, pos1);
	string titulo = linea.substr(pos1 + 1, pos2 - pos1 - 1);
	bool marcadores = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1)) != 0;
	string marcadorPersonal = linea.substr(pos3 + 1, pos4 - pos3 - 1);

	PaginaWeb* paginaWeb = new PaginaWeb(url, titulo);
	paginaWeb->setMarcadorPersonal(marcadorPersonal);
	if (marcadores) {
		paginaWeb->PonerMarcador();
	}
	return paginaWeb;
}
