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
<<<<<<< HEAD

string PaginaWeb::getURL() { return URL; }

string PaginaWeb::getTitulo() { return Titulo; }

string PaginaWeb::getMarcadorPersonal() { return MarcadorPersonal; }

void PaginaWeb::setUrl(string u) { URL = u; }
=======
// Retorna la URL de la p�gina web.
string PaginaWeb::getURL(){return URL;}
// Retorna el t�tulo de la p�gina web.
string PaginaWeb::getTitulo(){return Titulo;}
// Retorna el estado del marcador (true si la p�gina est� marcada como favorita).
>>>>>>> documentacion interna

bool PaginaWeb::getMarcador() { return marcador; }
// Retorna si la p�gina ya ha sido mostrada.

<<<<<<< HEAD
bool PaginaWeb::yaMostrada() { return mostrada; }

void PaginaWeb::setTitulo(string tit) {	Titulo = tit;}

void PaginaWeb::setMarcadorPersonal(string marcador) { MarcadorPersonal = marcador; }

void PaginaWeb::marcarComoMostrada() { mostrada = true; }
=======
bool PaginaWeb::yaMostrada(){return mostrada;}
// Marca la p�gina como "mostrada" para indicar que ya ha sido visualizada.

void PaginaWeb::marcarComoMostrada() {mostrada = true;}
// Si la p�gina est� marcada como favorita, muestra "Sitio Favorito".
>>>>>>> documentacion interna

void PaginaWeb::MostrarPaginaWeb() {
	cout << "----------------------------------------\n";
	if (!getMarcadorPersonal().empty()) { cout << "| " << getMarcadorPersonal() << endl; }
	cout << "| " << getURL() << "\n";
	if (marcador) { cout << "| Sitio Favorito \n"; }
	cout << "| " << getTitulo() << "\n";
	cout << "| " << mostrarTiempo() << "\n";
	cout << "----------------------------------------\n";
}
// Marca la p�gina como favorita estableciendo el marcador en verdadero.
void PaginaWeb::PonerMarcador() { marcador = true; }

// Quita el marcador de la p�gina, estableciendo el marcador en falso

void PaginaWeb::QuitarMarcador() { marcador = false; }
// Retorna el tiempo de ingreso de la p�gina web en formato `time_t`.

<<<<<<< HEAD
time_t PaginaWeb::getTiempo() { return tiempoIngreso; }
=======
time_t PaginaWeb::getTiempo()
{
	return tiempoIngreso;
}
// Devuelve una cadena que muestra el tiempo transcurrido desde que se registr� el ingreso a la p�gina.
// El tiempo se muestra en minutos.
>>>>>>> documentacion interna

string PaginaWeb::mostrarTiempo() {
	time_t now = std::time(nullptr);
	double seconds = difftime(now, tiempoIngreso);
	int minutos = static_cast<int>(seconds / 60);

	if (minutos == 0) { return "Hace unos segundos"; }
	else if (minutos == 1) { return std::to_string(minutos) + " minuto pasado desde ingreso"; }
	else { return std::to_string(minutos) + " minutos pasados desde ingreso"; }
}
// Establece un nuevo valor para el tiempo de ingreso de la p�gina.

void PaginaWeb::setTiempo(time_t t) { tiempoIngreso = t; }
// Guarda la informaci�n de la p�gina web en un archivo binario.
void PaginaWeb::guardarPaginaWeb(ofstream& file) {
	// Obtiene el estado del marcador, el t�tulo y el marcador personal de la p�gina.
	bool marcadores = getMarcador();
	string titulo = getTitulo();
	string marcadorPersonal = getMarcadorPersonal();
	// Guarda la longitud del t�tulo y el t�tulo en el archivo.

	size_t longitudTitulo = titulo.size();
	file.write(reinterpret_cast<const char*>(&longitudTitulo), sizeof(longitudTitulo));// Escribe la longitud de la titulo
	file.write(titulo.c_str(), longitudTitulo); // Escribe el t�tulo.
	// Guarda la URL de la p�gina.

	string url = getURL();
	size_t longitudURL = url.size();
	file.write(reinterpret_cast<const char*>(&longitudURL), sizeof(longitudURL));// Escribe la longitud del url
	file.write(url.c_str(), longitudURL);
	// Guarda el estado del marcador en el archivo.
	file.write(reinterpret_cast<char*>(&marcadores), sizeof(marcadores)); // Escribe el estado del marcador.
	// Guarda el marcador personal de la p�gina.

	size_t longitudMarcadorPersonal = marcadorPersonal.size();
	file.write(reinterpret_cast<const char*>(&longitudMarcadorPersonal), sizeof(longitudMarcadorPersonal));// Escribe la longitud del marcador personal.
	file.write(marcadorPersonal.c_str(), longitudMarcadorPersonal);// Escribe el marcador personal.

}

PaginaWeb* PaginaWeb::leerPaginaWeb(ifstream& file) {
	// Declara variables para almacenar la informaci�n le�da.
	string titulo;
	string url;
	bool marcadores;
	size_t LTitulo = 0;
	// Lee la longitud del t�tulo y el t�tulo desde el archivo.
	file.read(reinterpret_cast<char*>(&LTitulo), sizeof(LTitulo));// Lee la longitud del t�tulo.
	titulo.resize(LTitulo);
	file.read(&titulo[0], LTitulo);// Lee el t�tulo.
	// Lee la longitud de la URL y la URL desde el archivo.
	size_t LUrl = 0;
	file.read(reinterpret_cast<char*>(&LUrl), sizeof(LUrl));// Lee la longitud de la URL.
	url.resize(LUrl);// Lee la URL.
	// Lee el estado del marcador desde el archivo.
	file.read(&url[0], LUrl);
	file.read(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));// Lee el estado del marcador.
	// Lee el marcador personal de la p�gina.
	string marcadorPersonal;
	size_t LMarcadorPersonal = 0;
	file.read(reinterpret_cast<char*>(&LMarcadorPersonal), sizeof(LMarcadorPersonal));// Lee la longitud del marcador personal.
	marcadorPersonal.resize(LMarcadorPersonal);
	file.read(&marcadorPersonal[0], LMarcadorPersonal);
	// Crea un nuevo objeto PaginaWeb con la URL y el t�tulo le�dos.

	PaginaWeb* paginaWeb = new PaginaWeb(url, titulo);
	// Configura el marcador personal y el estado del marcador.
	paginaWeb->setMarcadorPersonal(marcadorPersonal);
	if (marcadores) { paginaWeb->PonerMarcador(); }// Activa el marcador si corresponde.
	return paginaWeb;// Retorna el puntero al objeto PaginaWeb reconstruido
}