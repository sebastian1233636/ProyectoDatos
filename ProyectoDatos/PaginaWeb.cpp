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

void PaginaWeb::guardarPaginaWeb(ofstream& file)
{
	// Guardar longitud y contenido de URL
	size_t longitudURL = URL.size();
	file.write(reinterpret_cast<const char*>(&longitudURL), sizeof(longitudURL));
	file.write(URL.c_str(), longitudURL);

	// Guardar longitud y contenido de Titulo
	size_t longitudTitulo = Titulo.size();
	file.write(reinterpret_cast<const char*>(&longitudTitulo), sizeof(longitudTitulo));
	file.write(Titulo.c_str(), longitudTitulo);

	// Guardar longitud y contenido de MarcadorPersonal
	size_t longitudMarcador = MarcadorPersonal.size();
	file.write(reinterpret_cast<const char*>(&longitudMarcador), sizeof(longitudMarcador));
	file.write(MarcadorPersonal.c_str(), longitudMarcador);

	// Guardar el atributo booleano 'marcador'
	file.write(reinterpret_cast<const char*>(&marcador), sizeof(marcador));

}

PaginaWeb* PaginaWeb::leerPaginaWeb(ifstream& file)
{
	
	// Leer URL
	size_t longitudURL;
	file.read(reinterpret_cast<char*>(&longitudURL), sizeof(longitudURL));
	string url(longitudURL, '\0');
	file.read(&url[0], longitudURL);

	// Leer Titulo
	size_t longitudTitulo;
	file.read(reinterpret_cast<char*>(&longitudTitulo), sizeof(longitudTitulo));
	string titulo(longitudTitulo, '\0');
	file.read(&titulo[0], longitudTitulo);

	// Crear objeto con URL y Titulo
	PaginaWeb* pagina = new PaginaWeb(url, titulo);

	// Leer MarcadorPersonal
	size_t longitudMarcadorPersonal;
	file.read(reinterpret_cast<char*>(&longitudMarcadorPersonal), sizeof(longitudMarcadorPersonal));
	string marcadorPersonal(longitudMarcadorPersonal, '\0');
	file.read(&marcadorPersonal[0], longitudMarcadorPersonal);
	pagina->setMarcadorPersonal(marcadorPersonal);

	// Leer el booleano marcador
	bool marcador;
	file.read(reinterpret_cast<char*>(&marcador), sizeof(marcador));
	if (marcador == true) {
		pagina->PonerMarcador();
	}
	else {
		pagina->QuitarMarcador();
	}
	
	return pagina;
}
