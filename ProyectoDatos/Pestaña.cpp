#include "Pestaña.h"
#include <iostream>


Pestaña::Pestaña(string nom) {
	tail = nullptr;
	head = nullptr;
	nombre = nom;
	modoIcognito = false;
}

Pestaña::Pestaña() {
	nombre = "Sin registro";
	modoIcognito = false;
	tail = nullptr;
	head = nullptr;
}

Pestaña::~Pestaña() {
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

bool Pestaña::getIcognito() { return modoIcognito; }

string Pestaña::getNombre() { return nombre; }

NodoPag* Pestaña::getTail() { return tail; }

NodoPag* Pestaña::getHead() { return head; }

void Pestaña::setNombre(string nom) { nombre = nom; }

void Pestaña::insertarPrimero(PaginaWeb& pag) {
	NodoPag* nuevo = new NodoPag();
	nuevo->paginaWeb = &pag;
	if (tail == nullptr) {
=======
// Método que devuelve el estado del modo incógnito (false en este caso).
bool Pestaña::getIcognito()
{
	return false;
}
// Retorna el puntero al nodo tail (último nodo de la lista).
NodoPag* Pestaña::getTail() {return tail;}
// Retorna el puntero al nodo head (primer nodo de la lista).
NodoPag* Pestaña::getHead() {return head;}
// Inserta una nueva página web al principio de la lista.
void Pestaña::insertarPrimero(PaginaWeb* pag){
	NodoPag* nuevo = new NodoPag(); // Crea un nuevo nodo.
	nuevo->paginaWeb = pag; // Asigna la página web al nodo.
	if (tail == nullptr) { // Si la lista está vacía, inicializa head y tail.
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
// Método para explorar el historial. Navega hacia adelante o hacia atrás usando teclas

void Pestaña::explorarHistorial() {
	bool bandera = true;
	string marcador;
	NodoPag* nodoActual = tail;
	// Verifica si el historial está vacío.

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
				// Si se presiona la tecla F, marca la página actual como favorita.
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
				// Si se presiona la tecla Escape, sale del ciclo de exploración.
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
			}
		}
	}
}
<<<<<<< HEAD

void Pestaña::buscarFavorito() {
=======
// Busca y muestra las páginas que están marcadas como favoritas.
void Pestaña::buscarFavorito(){
>>>>>>> documentacion interna
	NodoPag* nodoActual = tail;
	while (nodoActual != nullptr) {
		// Verifica si la página está marcada como favorita y aún no ha sido mostrada.
		if (nodoActual->paginaWeb->getMarcador() == true && nodoActual->paginaWeb->yaMostrada() == false) {
			nodoActual->paginaWeb->marcarComoMostrada();
			nodoActual->paginaWeb->MostrarPaginaWeb();
			nodoActual = nodoActual->siguiente;
		}
		else(nodoActual = nodoActual->siguiente);// Avanza al siguiente nodo.
	}
}
// Activa el modo incógnito.

<<<<<<< HEAD
void Pestaña::activarModoIncognito() { modoIcognito = true; }
=======
void Pestaña::activarModoIcognito(){modoIcognito = true;}
// Desactiva el modo incógnito.
>>>>>>> documentacion interna

void Pestaña::desactivarModoIncognito() { modoIcognito = false; }

<<<<<<< HEAD
string Pestaña::mostrarPestaña() {
=======
// Devuelve una cadena que representa el nombre de la pestaña.

string Pestaña::mostrarPestaña()
{
>>>>>>> documentacion interna
	stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opción 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
	s << "|-------------------------" << nombre << "---------------------------|" << endl;
	return s.str();
}
// La función muestra el mensaje de modo incógnito activado.
// Retorna un string con el diseño de la pestaña en modo incógnito.
string Pestaña::mostrarPestañaIncognito() {
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
// Busca una página web en la lista a partir del nombre o URL.
// Retorna un puntero a la página web encontrada o nullptr si no la encuentra.

PaginaWeb* Pestaña::buscarPaginaWeb(string nomURL)
{
	NodoPag* actual = tail;// Se inicia desde el nodo tail (último).
	while (actual != nullptr) {
		// Compara el nombre o URL con el de las páginas.
		if (nomURL == actual->paginaWeb->getURL() || nomURL == actual->paginaWeb->getTitulo()) {
			return actual->paginaWeb;
		}
		else {
			actual = actual->siguiente;// Avanza al siguiente nodo.
		}
	}
	return nullptr;// Si no se encuentra la página, retorna nullptr.
}
// Busca páginas web en la lista que contengan una palabra clave.
// Imprime las páginas que coincidan con la palabra clave. Si no hay coincidencias, informa al usuario.

void Pestaña::buscarPorPalabraClave(string& palabraclave)
{
	NodoPag* actual = tail; // Comienza desde el final de la lista.
	bool bandera = false;// Bandera para saber si se encontró una coincidencia.

	while (actual != nullptr) {
		// Busca la palabra clave en el título o URL de la página web.
		string url = actual->paginaWeb->getURL();
		string titulo = actual->paginaWeb->getTitulo();
		if (url.find(palabraclave) != string::npos || titulo.find(palabraclave) != string::npos) {
			actual->paginaWeb->MostrarPaginaWeb(); // Muestra la página si hay coincidencia.
			bandera = true;
		}
		actual = actual->siguiente;// Avanza al siguiente nodo.
	}
	// Si no se encontraron coincidencias, informa al usuario.
	if (bandera == false) {
		cout << "No se encontraron paginas " << endl;
	}
}

// Filtra y muestra las páginas web cuya antigüedad sea menor al tiempo especificado en minutos.
void Pestaña::timeFilter(int minutos) {
	time_t tiempoActual = std::time(nullptr);// Obtiene el tiempo actual.
	NodoPag* actual = tail;// Comienza desde el nodo tail.

	while (actual != nullptr) {
		// Calcula el tiempo transcurrido desde que se accedió a la página.
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());
		// Si la página fue visitada dentro del rango de tiempo dado, se muestra.
		if (segundosTranscurridos <= minutos * 60) { pagina->MostrarPaginaWeb(); }
		actual = actual->siguiente;// Avanza al siguiente nodo.
	}
}
// Elimina de la lista las páginas que superen un tiempo determinado (en minutos) desde que fueron visitadas.
void Pestaña::eliminarCadaTiempo(int minutos) {
	time_t tiempoActual = std::time(nullptr);/// Obtiene el tiempo actual.
	NodoPag* aux = tail; // Comienza desde el nodo tail.

	while (aux != nullptr) {
		// Calcula el tiempo transcurrido desde que se accedió a la página.
		double segundosTranscurridos = difftime(tiempoActual, aux->paginaWeb->getTiempo());
		// Si el tiempo transcurrido es mayor al límite, se elimina el nodo correspondiente.
		if (segundosTranscurridos > minutos * 60) {
			NodoPag* nodoAEliminar = aux;
			aux = aux->siguiente;// Avanza al siguiente nodo.
			// Actualiza las referencias entre nodos o la lista si es necesario.

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

			delete nodoAEliminar;// Libera la memoria del nodo eliminado.
		}
		else {
			aux = aux->siguiente;// Avanza al siguiente nodo si no se eliminó.
		}
	}
}

<<<<<<< HEAD
	// Guarda información básica de la pestaña (nombre y modo incógnito) en un archivo binario.
void Pestaña::guardarPestaña(ofstream& file) {
	string name = getNombre();
	bool incognito = getIcognito();
	size_t longitudname = name.size();
	file.write(reinterpret_cast<const char*>(&longitudname), sizeof(longitudname)); // Escribe la longitud del nombre.
	file.write(name.c_str(), longitudname);
	file.write(reinterpret_cast<char*>(&incognito), sizeof(incognito));// Escribe el estado del modo incógnito.
}
// Lee la información de una pestaña desde un archivo binario y la reconstruye.
Pestaña* Pestaña::leerPestaña(ifstream& file) {
	string name;
	bool incognito;
	size_t Lname = 0;
	file.read(reinterpret_cast<char*>(&Lname), sizeof(Lname));// Lee la longitud del nombre.
	name.resize(Lname);
	file.read(&name[0], Lname);
	file.read(reinterpret_cast<char*>(&incognito), sizeof(incognito));// Lee el estado del modo incógnito.
	Pestaña* pestaña = new Pestaña(name);
	if (incognito) { pestaña->activarModoIncognito(); }
	return pestaña;// Retorna la pestaña leída desde el archivo.
}
=======

}
// Carga páginas web desde un archivo CSV binario.
void Pestaña::cargarArchivoCSV(const string& archivoCVS)
{
	ifstream archivo(archivoCVS, ios::binary); // Abre el archivo en modo binario.
	if (!archivo) {
		cout << "No se pudo cargar el archivo binario" << endl;

	}
	int canPestanas = 0;
	archivo.read(reinterpret_cast<char*>(&canPestanas), sizeof(canPestanas));
	// Recorre cada pestaña guardada en el archivo.
	for (int i = 0; i < canPestanas; i++) {
		bool incogito;
		archivo.read(reinterpret_cast<char*>(&incogito), sizeof(canPestanas));
		Pestaña nuevaPestana("nombre");// Crea una nueva pestaña.
		int canSitio = 0;
		archivo.read(reinterpret_cast<char*>(&canSitio), sizeof(canSitio));
		// Lee las páginas dentro de la pestaña.
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

void Pestaña::guardarHistorialBinario(ofstream& file) {
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
	// Lee el historial de la pestaña (las páginas web) desde un archivo binario

void Pestaña::leerHistorialBinario(ifstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return;
=======
// Guarda las pestañas y páginas en un archivo CSV binario.
void Pestaña::guardarArchivoCSV(const string& archivoCSV)
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
		PaginaWeb* pag = pagLeida->leerPaginaWeb(file);// Lee cada página web.


		if (pag != nullptr) { insertarPrimero(*pag); }// Inserta la página en la lista.
		else {
			cout << "Error al leer una página web del archivo." << endl;
			break;
		}
	}
	file.close();
	cout << "Lectura del historial completada." << endl;
}
// Función para explorar el historial de navegación en modo incógnito.

void Pestaña::explorarHistorialIncognito() {
	bool bandera = true;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl;
		return;
	}

	cout << "Modo incognito activado. No se guardara historial ni marcadores." << endl;
	// Navegación del historial usando las teclas de dirección.
	while (bandera) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) { cout << "No se puede retroceder más." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);// Retardo para evitar múltiples capturas de la tecla.
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) { cout << "No se puede avanzar más." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; } // Finaliza la exploración del historial al presionar Escape.
	}
}