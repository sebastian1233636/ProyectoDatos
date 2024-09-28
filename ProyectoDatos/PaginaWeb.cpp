#include "PaginaWeb.h"


PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	MarcadorPersonal = "";  
	marcador = false;      
	mostrada = false;      
	mostrarFiltro = false;
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

// Getters y setters
string PaginaWeb::getURL() { return URL; }
string PaginaWeb::getTitulo() { return Titulo; }
string PaginaWeb::getMarcadorPersonal() { return MarcadorPersonal; }
void PaginaWeb::setUrl(string u) { URL = u; }
bool PaginaWeb::getMarcador() { return marcador; }
bool PaginaWeb::getMostrarFiltro() { return mostrarFiltro; }
bool PaginaWeb::yaMostrada() { return mostrada; }
void PaginaWeb::setTitulo(string tit) { Titulo = tit; }
void PaginaWeb::setMarcadorPersonal(string marcador) { MarcadorPersonal = marcador; }
void PaginaWeb::marcarComoMostrada() { mostrada = true; }

void PaginaWeb::MostrarPaginaWeb() {
	cout << "----------------------------------------\n";
	if (!getMarcadorPersonal().empty()) { cout << "| " << getMarcadorPersonal() << endl; }
	cout << "| " << getURL() << "\n";
	if (marcador) { cout << "| Sitio Favorito \n"; }
	cout << "| " << getTitulo() << "\n";
	cout << "| " << mostrarTiempo() << "\n";
	cout << "----------------------------------------\n";
}

// Marca la página web como favorita
void PaginaWeb::PonerMarcador() { marcador = true; }

// Elimina el marcador de la página web
void PaginaWeb::QuitarMarcador() { marcador = false; }

// Retorna el tiempo en el que la página fue ingresada
time_t PaginaWeb::getTiempo() { return tiempoIngreso; }

//Metodo usado para politicas del historial
string PaginaWeb::mostrarTiempo() {
	time_t now = std::time(nullptr);  // Obtiene el tiempo actual
	double seconds = difftime(now, tiempoIngreso);  // Diferencia en segundos
	int minutos = static_cast<int>(seconds / 60);  // Convierte a minutos

	if (minutos == 0) {
		return "Hace unos segundos";  // Si ha pasado menos de un minuto
	}
	else if (minutos == 1) {
		return std::to_string(minutos) + " minuto pasado desde ingreso";  // Exactamente 1 minuto
	}
	else {
		return std::to_string(minutos) + " minutos pasados desde ingreso";  // Más de 1 minuto
	}
}

// Activa el filtro para ocultar la página web en búsquedas
void PaginaWeb::activarFiltro() {
	mostrarFiltro = true;
}

// Desactiva el filtro para que la página sea visible en búsquedas
void PaginaWeb::desactivarFiltro() {
	mostrarFiltro = false;
}

// Cambia el tiempo de ingreso de la página
void PaginaWeb::setTiempo(time_t t) { tiempoIngreso = t; }

// ARCHIVOS
void PaginaWeb::guardarPaginaWeb(ofstream& file) {
	bool marcadores = getMarcador();
	string titulo = getTitulo();
	string marcadorPersonal = getMarcadorPersonal();

	// Escribe el tamaño y contenido del título
	size_t longitudTitulo = titulo.size();
	file.write(reinterpret_cast<const char*>(&longitudTitulo), sizeof(longitudTitulo));
	file.write(titulo.c_str(), longitudTitulo);

	// Escribe el tamaño y contenido de la URL
	string url = getURL();
	size_t longitudURL = url.size();
	file.write(reinterpret_cast<const char*>(&longitudURL), sizeof(longitudURL));
	file.write(url.c_str(), longitudURL);

	// Escribe si la página es un marcador
	file.write(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));

	// Escribe el tamaño y contenido del marcador personalizado
	size_t longitudMarcadorPersonal = marcadorPersonal.size();
	file.write(reinterpret_cast<const char*>(&longitudMarcadorPersonal), sizeof(longitudMarcadorPersonal));
	file.write(marcadorPersonal.c_str(), longitudMarcadorPersonal);
}

PaginaWeb* PaginaWeb::leerPaginaWeb(ifstream& file) {
	string titulo;
	string url;
	bool marcadores;

	// Lee el tamaño y contenido del título
	size_t LTitulo = 0;
	file.read(reinterpret_cast<char*>(&LTitulo), sizeof(LTitulo));
	titulo.resize(LTitulo);
	file.read(&titulo[0], LTitulo);

	// Lee el tamaño y contenido de la URL
	size_t LUrl = 0;
	file.read(reinterpret_cast<char*>(&LUrl), sizeof(LUrl));
	url.resize(LUrl);
	file.read(&url[0], LUrl);

	// Lee si la página es un marcador
	file.read(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));

	// Lee el tamaño y contenido del marcador personalizado
	string marcadorPersonal;
	size_t LMarcadorPersonal = 0;
	file.read(reinterpret_cast<char*>(&LMarcadorPersonal), sizeof(LMarcadorPersonal));
	marcadorPersonal.resize(LMarcadorPersonal);
	file.read(&marcadorPersonal[0], LMarcadorPersonal);

	// Crea un nuevo objeto PaginaWeb con los datos leídos
	PaginaWeb* paginaWeb = new PaginaWeb(url, titulo);
	paginaWeb->setMarcadorPersonal(marcadorPersonal);
	if (marcadores) {
		paginaWeb->PonerMarcador();  // Si es un marcador, lo marca como favorito
	}
	return paginaWeb;
}
