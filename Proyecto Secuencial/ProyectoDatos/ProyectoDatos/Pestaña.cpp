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

void Pestaña::mostrarFavoritos() {
	NodoPag* nodoActual = tail;
	int contador = 0;

	while (nodoActual != nullptr) {
		if (nodoActual->paginaWeb->getMarcador()) {
			contador++;
		}
		nodoActual = nodoActual->siguiente;
	}

	cout << "\x1B[2J\x1B[H";
	cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
	cout << "\x1B[36m  ||              PAGINAS FAVORITAS               ||\x1B[0m" << endl;
	cout << "\x1B[36m  ===================================================\x1B[0m\n" << endl;

	if (contador > 0) {
		cout << "  \x1B[32m[+] Total de paginas favoritas: " << contador << "\x1B[0m" << endl;
	} else {
		cout << "  \x1B[31m[!] No hay paginas marcadas como favoritas\x1B[0m" << endl;
	}
	cout << endl;
	system("pause");
}

void Pestaña::mostrarPorPalabraClave(string palabraclave) {
	NodoPag* actual = tail;
	int contador = 0;

	while (actual != nullptr) {
		string url = actual->paginaWeb->getURL();
		string titulo = actual->paginaWeb->getTitulo();

		if (url.find(palabraclave) != string::npos || titulo.find(palabraclave) != string::npos) {
			contador++;
		}
		actual = actual->siguiente;
	}

	cout << "\x1B[2J\x1B[H";
	cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
	cout << "\x1B[36m  ||          RESULTADOS DE BUSQUEDA              ||\x1B[0m" << endl;
	cout << "\x1B[36m  ||  Palabra clave: \x1B[32m" << palabraclave << "\x1B[36m" << "                      ||\x1B[0m" << endl;
	cout << "\x1B[36m  ===================================================\x1B[0m\n" << endl;

	if (contador > 0) {
		cout << "  \x1B[32m[+] Se encontraron " << contador << " pagina(s) que cumplen con el requisito.\x1B[0m" << endl;
	} else {
		cout << "  \x1B[31m[!] No se ha encontrado ninguna pagina que cumpla con el requisito.\x1B[0m" << endl;
	}
	cout << endl;
	system("pause");
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
	file << getNombre() << "|" << getIcognito() << "\n";
}

Pestaña* Pestaña::leerPestaña(ifstream& file) {
	string linea;
	if (!getline(file, linea)) {
		return nullptr;
	}

	size_t pos = linea.find('|');
	if (pos == string::npos) {
		return nullptr;
	}

	string name = linea.substr(0, pos);
	bool incognito = stoi(linea.substr(pos + 1)) != 0;

	Pestaña* pestaña = new Pestaña(name);
	if (incognito) {
		pestaña->activarModoIncognito();
	}
	return pestaña;
}


void Pestaña::guardarHistorial(ofstream& file) {
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

void Pestaña::leerHistorial(ifstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return;
	}

	while (true) {
		PaginaWeb* pag = new PaginaWeb();
		PaginaWeb* pagLeida = pag->leerPaginaWeb(file);

		if (pagLeida == nullptr) {
			delete pag;
			break;
		}
		insertarPrimero(*pagLeida);
	}
	file.close();
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