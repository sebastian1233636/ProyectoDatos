#include "Pesta�a.h"
#include <iostream>


Pesta�a::Pesta�a(string nom) {
	tail = nullptr;
	head = nullptr;
	nombre = nom;
	modoIcognito = false;
}

Pesta�a::Pesta�a() {
	nombre = "Sin registro";
	modoIcognito = false;
	tail = nullptr;
	head = nullptr;
}

Pesta�a::~Pesta�a() {
	NodoPag* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;// Libera la memoria del nodo actual.
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}
<<<<<<< HEAD

bool Pesta�a::getIcognito() { return modoIcognito; }

string Pesta�a::getNombre() { return nombre; }

NodoPag* Pesta�a::getTail() { return tail; }

NodoPag* Pesta�a::getHead() { return head; }

void Pesta�a::setNombre(string nom) { nombre = nom; }

void Pesta�a::insertarPrimero(PaginaWeb& pag) {
	NodoPag* nuevo = new NodoPag();
	nuevo->paginaWeb = &pag;
	if (tail == nullptr) {
=======
// M�todo que devuelve el estado del modo inc�gnito (false en este caso).
bool Pesta�a::getIcognito()
{
	return false;
}
// Retorna el puntero al nodo tail (�ltimo nodo de la lista).
NodoPag* Pesta�a::getTail() {return tail;}
// Retorna el puntero al nodo head (primer nodo de la lista).
NodoPag* Pesta�a::getHead() {return head;}
// Inserta una nueva p�gina web al principio de la lista.
void Pesta�a::insertarPrimero(PaginaWeb* pag){
	NodoPag* nuevo = new NodoPag(); // Crea un nuevo nodo.
	nuevo->paginaWeb = pag; // Asigna la p�gina web al nodo.
	if (tail == nullptr) { // Si la lista est� vac�a, inicializa head y tail.
>>>>>>> documentacion interna
		tail = head = nuevo;
		nuevo->siguiente;// Conecta el nuevo nodo al principio de la lista.
		nuevo->anterior;
	}
	else {
		nuevo->siguiente = tail;
		tail->anterior = nuevo; 
		tail = nuevo; // Actualiza el tail al nuevo nodo.
	}
}
// M�todo para explorar el historial. Navega hacia adelante o hacia atr�s usando teclas

void Pesta�a::explorarHistorial() {
	bool bandera = true;
	string marcador;
	NodoPag* nodoActual = tail;
	// Verifica si el historial est� vac�o.

	if (nodoActual == nullptr) { 
		cout << "El historial de paginas web esta vacio." << endl;
		system("pause");
	}
	else {
		while (bandera == true) {
			if (modoIcognito) {
				cout << "No guardar historial ni marcadores" << endl;
			}
			else {
				// Si se presiona la tecla izquierda, retrocede en el historial.
				if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
					if (nodoActual->anterior == nullptr) {
						nodoActual->paginaWeb->MostrarPaginaWeb();
						cout << "No se puede retroceder mas" << endl;

					}
					else {
						nodoActual->paginaWeb->MostrarPaginaWeb();
						nodoActual = nodoActual->anterior;

					}
					Sleep(300);
					// Si se presiona la tecla derecha, avanza en el historial.
				}
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					if (nodoActual->siguiente == nullptr) {
						nodoActual->paginaWeb->MostrarPaginaWeb();
						cout << "No se puede avanzar mas" << endl;
					}
					else {
						nodoActual->paginaWeb->MostrarPaginaWeb();
						nodoActual = nodoActual->siguiente;

					}
					Sleep(300);
				}
				// Si se presiona la tecla F, marca la p�gina actual como favorita.
				if (GetAsyncKeyState('F') & 0x8000) {
					nodoActual->paginaWeb->PonerMarcador();
					cout << "Ingrese el nombre del marcador (dejar en blanco para no asignar nombre): ";
					cin.ignore();
					getline(cin, marcador);
					if (!marcador.empty()) {
						nodoActual->paginaWeb->setMarcadorPersonal(marcador);
					}
					cout << "Pagina marcada como favorita" << endl;
					Sleep(300);
				}
				// Si se presiona la tecla Escape, sale del ciclo de exploraci�n.
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
			}
		}
	}
}
<<<<<<< HEAD

void Pesta�a::buscarFavorito() {
=======
// Busca y muestra las p�ginas que est�n marcadas como favoritas.
void Pesta�a::buscarFavorito(){
>>>>>>> documentacion interna
	NodoPag* nodoActual = tail;
	while (nodoActual != nullptr) {
		// Verifica si la p�gina est� marcada como favorita y a�n no ha sido mostrada.
		if (nodoActual->paginaWeb->getMarcador() == true && nodoActual->paginaWeb->yaMostrada() == false) {
			nodoActual->paginaWeb->marcarComoMostrada();
			nodoActual->paginaWeb->MostrarPaginaWeb();
			nodoActual = nodoActual->siguiente;
		}
		else(nodoActual = nodoActual->siguiente);// Avanza al siguiente nodo.
	}
}
// Activa el modo inc�gnito.

<<<<<<< HEAD
void Pesta�a::activarModoIncognito() { modoIcognito = true; }
=======
void Pesta�a::activarModoIcognito(){modoIcognito = true;}
// Desactiva el modo inc�gnito.
>>>>>>> documentacion interna

void Pesta�a::desactivarModoIncognito() { modoIcognito = false; }

<<<<<<< HEAD
string Pesta�a::mostrarPesta�a() {
=======
// Devuelve una cadena que representa el nombre de la pesta�a.

string Pesta�a::mostrarPesta�a()
{
>>>>>>> documentacion interna
	stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opci�n 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
	s << "|-------------------------" << nombre << "---------------------------|" << endl;
	return s.str();
}

string Pesta�a::mostrarPesta�aIncognito() {
	return "|-------------------------" + nombre + "---------------------------|\n"
		"-------------------------------\n"
		"|       MODO INCOGNITO         |\n"
		"|       _____________          |\n"
		"|      |             |         |\n"
		"|      |   PRIVADO   |         |\n"
		"|      |_____________|         |\n"
		"|       No se guarda           |\n"
		"|     el historial aqui        |\n"
		"-------------------------------\n";
}

PaginaWeb* Pesta�a::buscarPaginaWeb(string nomURL)
{
	NodoPag* actual = tail;
	while (actual != nullptr) {
		if (nomURL == actual->paginaWeb->getURL() || nomURL == actual->paginaWeb->getTitulo()) {
			return actual->paginaWeb;
		}
		else {
			actual = actual->siguiente;
		}
	}
	return nullptr;
}

void Pesta�a::buscarPorPalabraClave(string& palabraclave)
{
	NodoPag* actual = tail;
	bool bandera = false;

	while (actual != nullptr) {
		string url = actual->paginaWeb->getURL();
		string titulo = actual->paginaWeb->getTitulo();
		if (url.find(palabraclave) != string::npos || titulo.find(palabraclave) != string::npos) {
			actual->paginaWeb->MostrarPaginaWeb();
			bandera = true;
		}
		actual = actual->siguiente;
	}

	if (bandera == false) {
		cout << "No se encontraron paginas " << endl;
	}
}


void Pesta�a::timeFilter(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	NodoPag* actual = tail;

	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());
		if (segundosTranscurridos <= minutos * 60) { pagina->MostrarPaginaWeb(); }
		actual = actual->siguiente;
	}
}

void Pesta�a::eliminarCadaTiempo(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	NodoPag* aux = tail;

	while (aux != nullptr) {
		double segundosTranscurridos = difftime(tiempoActual, aux->paginaWeb->getTiempo());
		if (segundosTranscurridos > minutos * 60) {
			NodoPag* nodoAEliminar = aux;
			aux = aux->siguiente;

			if (nodoAEliminar == head && nodoAEliminar == tail) { head = tail = nullptr; }
			else if (nodoAEliminar == tail) {
				tail = tail->siguiente;
				if (tail != nullptr) {
					tail->anterior = nullptr;
				}
			}
			else if (nodoAEliminar == head) {
				head = head->anterior;
				if (head != nullptr) {
					head->siguiente = nullptr;
				}
			}
			else {
				NodoPag* prevNode = nodoAEliminar->anterior;
				NodoPag* nextNode = nodoAEliminar->siguiente;
				prevNode->siguiente = nextNode;
				nextNode->anterior = prevNode;
			}

			delete nodoAEliminar;
		}
		else {
			aux = aux->siguiente;
		}
	}
}

<<<<<<< HEAD
void Pesta�a::guardarPesta�a(ofstream& file) {
	string name = getNombre();
	bool incognito = getIcognito();
	size_t longitudname = name.size();
	file.write(reinterpret_cast<const char*>(&longitudname), sizeof(longitudname));
	file.write(name.c_str(), longitudname);
	file.write(reinterpret_cast<char*>(&incognito), sizeof(incognito));
}

Pesta�a* Pesta�a::leerPesta�a(ifstream& file) {
	string name;
	bool incognito;
	size_t Lname = 0;
	file.read(reinterpret_cast<char*>(&Lname), sizeof(Lname));
	name.resize(Lname);
	file.read(&name[0], Lname);
	file.read(reinterpret_cast<char*>(&incognito), sizeof(incognito));
	Pesta�a* pesta�a = new Pesta�a(name);
	if (incognito) { pesta�a->activarModoIncognito(); }
	return pesta�a;
}
=======

}
// Carga p�ginas web desde un archivo CSV binario.
void Pesta�a::cargarArchivoCSV(const string& archivoCVS)
{
	ifstream archivo(archivoCVS, ios::binary); // Abre el archivo en modo binario.
	if (!archivo) {
		cout << "No se pudo cargar el archivo binario" << endl;

	}
	int canPestanas = 0;
	archivo.read(reinterpret_cast<char*>(&canPestanas), sizeof(canPestanas));
	// Recorre cada pesta�a guardada en el archivo.
	for (int i = 0; i < canPestanas; i++) {
		bool incogito;
		archivo.read(reinterpret_cast<char*>(&incogito), sizeof(canPestanas));
		Pesta�a nuevaPestana("nombre");// Crea una nueva pesta�a.
		int canSitio = 0;
		archivo.read(reinterpret_cast<char*>(&canSitio), sizeof(canSitio));
		// Lee las p�ginas dentro de la pesta�a.
		for (int j = 0; j < canSitio; j++) {
			string titulo;
			string url;
			bool marcadores;
			size_t LTitulo = 0;
			archivo.read(reinterpret_cast<char*>(&LTitulo), sizeof(LTitulo));
			titulo.resize(LTitulo);
			archivo.read(&titulo[0], LTitulo);
			size_t LUrl = 0;
			archivo.read(reinterpret_cast<char*>(&LUrl), sizeof(LUrl));
			archivo.read(&url[0], LUrl);
			archivo.read(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));
			PaginaWeb* paginaWeb = new PaginaWeb(titulo, url);
			nuevaPestana.explorarHistorial();
>>>>>>> documentacion interna

void Pesta�a::guardarHistorialBinario(ofstream& file) {
	NodoPag* actual = tail;
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
	}
	else {
		while (actual != nullptr) {
			actual->paginaWeb->guardarPaginaWeb(file);
			actual = actual->siguiente;
		}
	}
	file.close();
}
<<<<<<< HEAD

void Pesta�a::leerHistorialBinario(ifstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return;
=======
// Guarda las pesta�as y p�ginas en un archivo CSV binario.
void Pesta�a::guardarArchivoCSV(const string& archivoCSV)
{

	ofstream archivo(archivoCSV, ios::binary);// Abre el archivo en modo binario para escritura.
	if (!archivo) {
		cout << "No se pudo abrir el archivo CSV Bianrio" << endl;
>>>>>>> documentacion interna
	}

	file.seekg(0, ios::end);
	std::streampos fileSize = file.tellg();
	file.seekg(0, ios::beg);

	while (file.tellg() < fileSize) {
		PaginaWeb* pagLeida = new PaginaWeb();
		PaginaWeb* pag = pagLeida->leerPaginaWeb(file);

		if (pag != nullptr) { insertarPrimero(*pag); }
		else {
			cout << "Error al leer una p�gina web del archivo." << endl;
			break;
		}
	}
	file.close();
	cout << "Lectura del historial completada." << endl;
}


void Pesta�a::explorarHistorialIncognito() {
	bool bandera = true;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl;
		return;
	}

	cout << "Modo incognito activado. No se guardara historial ni marcadores." << endl;

	while (bandera) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) { cout << "No se puede retroceder m�s." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) { cout << "No se puede avanzar m�s." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
	}
}