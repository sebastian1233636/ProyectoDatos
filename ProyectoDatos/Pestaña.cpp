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
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

bool Pestaña::getIcognito() { return modoIcognito; }
string Pestaña::getNombre() { return nombre; }
NodoPag* Pestaña::getTail() { return tail; }
NodoPag* Pestaña::getHead() { return head; }
void Pestaña::setNombre(string nom) { nombre = nom; }
void Pestaña::activarModoIncognito() { modoIcognito = true; }
void Pestaña::desactivarModoIncognito() { modoIcognito = false; }

void Pestaña::insertarPrimero(PaginaWeb& pag) {
	NodoPag* nuevo = new NodoPag();
	nuevo->paginaWeb = &pag;
	if (tail == nullptr) {
		tail = head = nuevo;
		nuevo->siguiente;
		nuevo->anterior;
	}
	else {
		nuevo->siguiente = tail;
		tail->anterior = nuevo;
		tail = nuevo;
	}
}

void Pestaña::explorarHistorial() {
	bool bandera = true;
	string marcador;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "\x1B[2J\x1B[H";
		cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
		cout << "\x1B[36m  ||              HISTORIAL DE PESTAÑA             ||\x1B[0m" << endl;
		cout << "\x1B[36m  ===================================================\x1B[0m\n" << endl;
		cout << "  \x1B[31m[!] El historial de paginas web esta vacio.\x1B[0m\n" << endl;
		system("pause");
		return;
	}

	cout << "\x1B[2J\x1B[H";
	cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
	cout << "\x1B[36m  ||              HISTORIAL DE PESTAÑA             ||\x1B[0m" << endl;
	cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
	cout << "  \x1B[33mCONTROLES:\x1B[0m" << endl;
	cout << "  [ <- ] Flecha Izquierda | Volver (Atras)" << endl;
	cout << "  [ -> ] Flecha Derecha   | Avanzar (Adelante)" << endl;
	cout << "  [ F ]  Tecla F          | Marcar pág. como Favorito" << endl;
	cout << "  [ESC]  Escape           | Salir del historial" << endl;
	cout << "\x1B[36m  ---------------------------------------------------\x1B[0m\n" << endl;

	if (modoIcognito) {
		cout << "  \x1B[35m> No guardar historial ni marcadores\x1B[0m" << endl;
	} else if (nodoActual->paginaWeb->getMostrarFiltro() && nodoActual->paginaWeb->getFiltroTiempo()) {
		nodoActual->paginaWeb->MostrarPaginaWeb();
	} else {
		cout << "  \x1B[31m[PAGINA OCULTA POR FILTRO]\x1B[0m" << endl;
	}

	while (bandera) {
		if (!modoIcognito) {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "\n  \x1B[31m[!] No se puede retroceder mas.\x1B[0m" << endl;
				} else {
					nodoActual = nodoActual->anterior;
					cout << "\x1B[2J\x1B[H";
					cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
					cout << "\x1B[36m  ||              HISTORIAL DE PESTAÑA             ||\x1B[0m" << endl;
					cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
					cout << "  \x1B[33mCONTROLES:\x1B[0m" << endl;
					cout << "  [ <- ] Flecha Izquierda | Volver (Atras)" << endl;
					cout << "  [ -> ] Flecha Derecha   | Avanzar (Adelante)" << endl;
					cout << "  [ F ]  Tecla F          | Marcar pág. como Favorito" << endl;
					cout << "  [ESC]  Escape           | Salir del historial" << endl;
					cout << "\x1B[36m  ---------------------------------------------------\x1B[0m\n" << endl;

					if (nodoActual->paginaWeb->getMostrarFiltro() && nodoActual->paginaWeb->getFiltroTiempo()) {
						nodoActual->paginaWeb->MostrarPaginaWeb();
					} else {
						cout << "  \x1B[31m[PAGINA OCULTA POR FILTRO]\x1B[0m" << endl;
					}
				}
				Sleep(300);
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "\n  \x1B[31m[!] No se puede avanzar mas.\x1B[0m" << endl;
				} else {
					nodoActual = nodoActual->siguiente;
					cout << "\x1B[2J\x1B[H";
					cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
					cout << "\x1B[36m  ||              HISTORIAL DE PESTAÑA             ||\x1B[0m" << endl;
					cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
					cout << "  \x1B[33mCONTROLES:\x1B[0m" << endl;
					cout << "  [ <- ] Flecha Izquierda | Volver (Atras)" << endl;
					cout << "  [ -> ] Flecha Derecha   | Avanzar (Adelante)" << endl;
					cout << "  [ F ]  Tecla F          | Marcar pág. como Favorito" << endl;
					cout << "  [ESC]  Escape           | Salir del historial" << endl;
					cout << "\x1B[36m  ---------------------------------------------------\x1B[0m\n" << endl;

					if (nodoActual->paginaWeb->getMostrarFiltro() && nodoActual->paginaWeb->getFiltroTiempo()) {
						nodoActual->paginaWeb->MostrarPaginaWeb();
					} else {
						cout << "  \x1B[31m[PAGINA OCULTA POR FILTRO]\x1B[0m" << endl;
					}
				}
				Sleep(300);
			}

			if (GetAsyncKeyState('F') & 0x8000) {
				nodoActual->paginaWeb->PonerMarcador();
				cout << "\n  \x1B[33mIngrese el nombre del marcador (dejar en blanco para no asignar):\x1B[0m ";
				cin.ignore();
				getline(cin, marcador);
				if (!marcador.empty()) {
					nodoActual->paginaWeb->setMarcadorPersonal(marcador);
				}
				cout << "  \x1B[32m[+] Pagina marcada como favorita\x1B[0m" << endl;
				Sleep(300);
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			bandera = false;
		}
	}
}


void Pestaña::buscarFavorito() {
	NodoPag* nodoActual = tail;
	bool bandera = false;

	while (nodoActual != nullptr) {
		if (nodoActual->paginaWeb->getMarcador() && !nodoActual->paginaWeb->yaMostrada()) {
			bandera = true;
			nodoActual->paginaWeb->marcarComoMostrada();
			nodoActual->paginaWeb->MostrarPaginaWeb();
		}
		nodoActual = nodoActual->siguiente;
	}

	if (!bandera) {
		cout << "No hay paginas marcadas como favoritas" << endl;
	}
}

string Pestaña::mostrarPestaña() {
	stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opción 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
	s << "|Para dejar de ver el historial y volver al menu de Pestaña presionar ESC." << endl;
	s << "|-------------------------" << nombre << "---------------------------|" << endl;
	return s.str();
}

string Pestaña::mostrarPestañaIncognito() {
	return "PESTAÑA: [Modo Incognito Activo]";
}

PaginaWeb* Pestaña::buscarPaginaWeb(string nomURL) {
	NodoPag* actual = tail;
	while (actual != nullptr) {
		if (nomURL == actual->paginaWeb->getURL() || nomURL == actual->paginaWeb->getTitulo()) {
			return actual->paginaWeb;
		}
		actual = actual->siguiente;
	}
	return nullptr;
}

void Pestaña::buscarPorPalabraClave(string palabraclave) {
	NodoPag* actual = tail;
	bool bandera = false;

	while (actual != nullptr) {
		string url = actual->paginaWeb->getURL();
		string titulo = actual->paginaWeb->getTitulo();

		if (url.find(palabraclave) == string::npos && titulo.find(palabraclave) == string::npos) {
			actual->paginaWeb->desactivarFiltro();
		} else {
			actual->paginaWeb->activarFiltro();
			bandera = true;
		}
		actual = actual->siguiente;
	}

	system("pause");

	if (!bandera) {
		cout << "No se ha encontrado una pagina que cumpla con el requisito." << endl;
		system("pause");
	}
}



void Pestaña::timeFilter(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	NodoPag* actual = tail;

	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());

		if (segundosTranscurridos > minutos * 60) {
			pagina->desactivarFiltroTiempo();
		} else {
			pagina->activarFiltroTiempo();
		}
		actual = actual->siguiente;
	}
}
void Pestaña::eliminarCadaTiempo(int minutos) {
	time_t tiempoActual = std::time(nullptr);//Obtiene  el tiempo actual
	NodoPag* aux = tail;

	while (aux != nullptr) {
		double segundosTranscurridos = difftime(tiempoActual, aux->paginaWeb->getTiempo());//cacula el timepo transcurrido desde que se ingresó la página
		if (segundosTranscurridos > minutos * 60) {//Si la pagina supera el limite inpuesto por el usuario se elimina
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

void Pestaña::desactivarFiltros() {
	NodoPag* actual = tail;
	while (actual != nullptr) {
		actual->paginaWeb->activarFiltro();
		actual = actual->siguiente;
	}
}

void Pestaña::desactivarFiltroTiempo() {
	NodoPag* actual = tail;
	while (actual != nullptr) {
		actual->paginaWeb->activarFiltroTiempo();
		actual = actual->siguiente;
	}
}

void Pestaña::guardarPestaña(ofstream& file) {
	string name = getNombre(); // Agarra el nombre de la pestaña
	bool incognito = getIcognito(); // Verifica si la pestaña está en modo incógnito
	size_t longitudname = name.size(); // Agarra la longitud del nombre de la pestaña

	// Escribe la longitud del nombre en el archivo
	file.write(reinterpret_cast<const char*>(&longitudname), sizeof(longitudname));

	// Escribe el nombre de la pestaña en el archivo
	file.write(name.c_str(), longitudname);

	// Escribe el estado de incógnito en el archivo
	file.write(reinterpret_cast<char*>(&incognito), sizeof(incognito));
}

Pestaña* Pestaña::leerPestaña(ifstream& file) {
	string name; 
	bool incognito; 
	size_t Lname = 0; // Variable para almacenar la longitud del nombre

	// Lee la longitud del nombre desde el archivo
	file.read(reinterpret_cast<char*>(&Lname), sizeof(Lname));

	// Redimensiona el string usado para el nombre
	name.resize(Lname);

	// Lee el nombre de la pestaña desde el archivo
	file.read(&name[0], Lname);

	// Lee el estado de incógnito desde el archivo
	file.read(reinterpret_cast<char*>(&incognito), sizeof(incognito));

	// Crea una nueva pestaña con el nombre leído
	Pestaña* pestaña = new Pestaña(name);

	// Si ña pestaña estaba en modo incógnito, lo activa
	if (incognito) {
		pestaña->activarModoIncognito();
	}

	return pestaña; // Devuelve el puntero a la nueva pestaña
}


void Pestaña::guardarHistorialBinario(ofstream& file) {
	NodoPag* actual = tail;

	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
		return;
	}

	while (actual != nullptr) {
		actual->paginaWeb->guardarPaginaWeb(file);
		actual = actual->siguiente;
	}
	file.close();
}

void Pestaña::leerHistorialBinario(ifstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return;
	}

	file.seekg(0, ios::end);
	std::streampos fileSize = file.tellg();
	file.seekg(0, ios::beg);

	while (file.tellg() < fileSize) {
		PaginaWeb* pagLeida = new PaginaWeb();
		PaginaWeb* pag = pagLeida->leerPaginaWeb(file);

		if (pag != nullptr) {
			insertarPrimero(*pag);
		} else {
			cout << "Error al leer una página web del archivo." << endl;
			break;
		}
	}
	file.close();
	cout << "Lectura del historial completada." << endl;
}



void Pestaña::explorarHistorialIncognito() {
	bool bandera = true;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl;
		return;
	}

	cout << "Modo incognito activado. No se guardara historial ni marcadores." << endl;

	while (bandera) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) {
				cout << "No se puede retroceder más." << endl;
			} else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) {
				cout << "No se puede avanzar más." << endl;
			} else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			bandera = false;
		}
	}
}