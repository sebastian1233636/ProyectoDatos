#include "Pestana.h"
#include <iostream>
#include <omp.h>
#include <vector>

Pestana::Pestana(string nom) {
	tail = nullptr;
	head = nullptr;
	nombre = nom;
	modoIcognito = false;
}

Pestana::Pestana() {
	nombre = "Sin registro";
	modoIcognito = false;
	tail = nullptr;
	head = nullptr;
}

Pestana::~Pestana() {
	NodoPag* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

bool Pestana::getIcognito() { return modoIcognito; }
string Pestana::getNombre() { return nombre; }
NodoPag* Pestana::getTail() { return tail; }
NodoPag* Pestana::getHead() { return head; }
void Pestana::setNombre(string nom) { nombre = nom; }
void Pestana::activarModoIncognito() { modoIcognito = true; }
void Pestana::desactivarModoIncognito() { modoIcognito = false; }

void Pestana::insertarPrimero(PaginaWeb& pag) {
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

void Pestana::explorarHistorial() {
	bool bandera = true;
	string marcador;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "\x1B[2J\x1B[H";
		cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
		cout << "\x1B[36m  ||              HISTORIAL DE PESTAnA             ||\x1B[0m" << endl;
		cout << "\x1B[36m  ===================================================\x1B[0m\n" << endl;
		cout << "  \x1B[31m[!] El historial de paginas web esta vacio.\x1B[0m\n" << endl;
		system("pause");
		return;
	}

	cout << "\x1B[2J\x1B[H";
	cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
	cout << "\x1B[36m  ||              HISTORIAL DE PESTAnA             ||\x1B[0m" << endl;
	cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
	cout << "  \x1B[33mCONTROLES:\x1B[0m" << endl;
	cout << "  [ <- ] Flecha Izquierda | Volver (Atras)" << endl;
	cout << "  [ -> ] Flecha Derecha   | Avanzar (Adelante)" << endl;
	cout << "  [ F ]  Tecla F          | Marcar p�g. como Favorito" << endl;
	cout << "  [ESC]  Escape           | Salir del historial" << endl;
	cout << "\x1B[36m  ---------------------------------------------------\x1B[0m\n" << endl;

	if (modoIcognito) {
		cout << "  \x1B[35m> No guardar historial ni marcadores\x1B[0m" << endl;
	}
	else if (nodoActual->paginaWeb->getMostrarFiltro() && nodoActual->paginaWeb->getFiltroTiempo()) {
		nodoActual->paginaWeb->MostrarPaginaWeb();
	}
	else {
		cout << "  \x1B[31m[PAGINA OCULTA POR FILTRO]\x1B[0m" << endl;
	}

	while (bandera) {
		if (!modoIcognito) {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "\n  \x1B[31m[!] No se puede retroceder mas.\x1B[0m" << endl;
				}
				else {
					nodoActual = nodoActual->anterior;
					cout << "\x1B[2J\x1B[H";
					cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
					cout << "\x1B[36m  ||              HISTORIAL DE PESTAnA             ||\x1B[0m" << endl;
					cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
					cout << "  \x1B[33mCONTROLES:\x1B[0m" << endl;
					cout << "  [ <- ] Flecha Izquierda | Volver (Atras)" << endl;
					cout << "  [ -> ] Flecha Derecha   | Avanzar (Adelante)" << endl;
					cout << "  [ F ]  Tecla F          | Marcar p�g. como Favorito" << endl;
					cout << "  [ESC]  Escape           | Salir del historial" << endl;
					cout << "\x1B[36m  ---------------------------------------------------\x1B[0m\n" << endl;

					if (nodoActual->paginaWeb->getMostrarFiltro() && nodoActual->paginaWeb->getFiltroTiempo()) {
						nodoActual->paginaWeb->MostrarPaginaWeb();
					}
					else {
						cout << "  \x1B[31m[PAGINA OCULTA POR FILTRO]\x1B[0m" << endl;
					}
				}
				Sleep(300);
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "\n  \x1B[31m[!] No se puede avanzar mas.\x1B[0m" << endl;
				}
				else {
					nodoActual = nodoActual->siguiente;
					cout << "\x1B[2J\x1B[H";
					cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
					cout << "\x1B[36m  ||              HISTORIAL DE PESTAnA             ||\x1B[0m" << endl;
					cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
					cout << "  \x1B[33mCONTROLES:\x1B[0m" << endl;
					cout << "  [ <- ] Flecha Izquierda | Volver (Atras)" << endl;
					cout << "  [ -> ] Flecha Derecha   | Avanzar (Adelante)" << endl;
					cout << "  [ F ]  Tecla F          | Marcar p�g. como Favorito" << endl;
					cout << "  [ESC]  Escape           | Salir del historial" << endl;
					cout << "\x1B[36m  ---------------------------------------------------\x1B[0m\n" << endl;

					if (nodoActual->paginaWeb->getMostrarFiltro() && nodoActual->paginaWeb->getFiltroTiempo()) {
						nodoActual->paginaWeb->MostrarPaginaWeb();
					}
					else {
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

void Pestana::buscarFavorito() {
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

string Pestana::mostrarPestana() {
	stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opci�n 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
	s << "|Para dejar de ver el historial y volver al menu de Pestana presionar ESC." << endl;
	s << "|-------------------------" << nombre << "---------------------------|" << endl;
	return s.str();
}

string Pestana::mostrarPestanaIncognito() {
	return "PESTAnA: [Modo Incognito Activo]";
}

PaginaWeb* Pestana::buscarPaginaWeb(string nomURL) {
	NodoPag* actual = tail;
	while (actual != nullptr) {
		if (nomURL == actual->paginaWeb->getURL() || nomURL == actual->paginaWeb->getTitulo()) {
			return actual->paginaWeb;
		}
		actual = actual->siguiente;
	}
	return nullptr;
}

void Pestana::mostrarFavoritos() {
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
	}
	else {
		cout << "  \x1B[31m[!] No hay paginas marcadas como favoritas\x1B[0m" << endl;
	}
	cout << endl;
	system("pause");
}

// Filtra las paginas de la pestana segun una palabra clave.
// Activa el filtro en las paginas que contienen la palabra (en URL o titulo) y lo desactiva en las que no. 
void Pestana::buscarPorPalabraClave(string palabraclave) {

    // Copia los punteros de la lista enlazada a un vector para poder usar indices con OpenMP
    vector<PaginaWeb*> paginas;
    NodoPag* actual = tail;

    // Recorre la lista enlazada.
    while (actual != nullptr) {
        paginas.push_back(actual->paginaWeb);
        actual = actual->siguiente;
    }

    bool bandera = false; // Bandera que sera true si al menos una pagina coincide con la palabra clave
    int numHilos = 2;
    int n = paginas.size();

    // Divide el vector en X bloques estaticos iguales entre los hilos.
    // 'reduction(|:bandera)' evita condicion de carrera: cada hilo tiene su copia
    // de bandera y al final se combinan con OR para obtener el resultado
    #pragma omp parallel for num_threads(numHilos) schedule(static) reduction(|:bandera)
    for (int i = 0; i < n; ++i) {
        string url    = paginas[i]->getURL();
        string titulo = paginas[i]->getTitulo();

        // Si la palabra clave NO aparece ni en la URL ni en el titulo -> desactivar filtro
        if (url.find(palabraclave) == string::npos && titulo.find(palabraclave) == string::npos) {
            paginas[i]->desactivarFiltro();
        }
        else {
            // La palabra clave aparece en la URL o en el titulo -> activar filtro
            paginas[i]->activarFiltro();
            bandera = true; // Al menos una pagina coincidio
        }
    }
}

void Pestana::timeFilter(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	NodoPag* actual = tail;

	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());

		if (segundosTranscurridos > minutos * 60) {
			pagina->desactivarFiltroTiempo();
		}
		else {
			pagina->activarFiltroTiempo();
		}
		actual = actual->siguiente;
	}
}

void Pestana::timeFilterParalelo(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	vector<PaginaWeb*> paginas;
	NodoPag* actual = tail;

	while (actual != nullptr) {
		paginas.push_back(actual->paginaWeb);
		actual = actual->siguiente;
	}

	int n = paginas.size();
	int numHilos = 5;

	if (numHilos <= 0) {
		numHilos = omp_get_max_threads();
	}

#pragma omp parallel for schedule(static) num_threads(numHilos) default(none) shared(paginas, n, tiempoActual, minutos)
	for (int i = 0; i < n; ++i) {
		PaginaWeb* pagina = paginas[i];
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());

		if (segundosTranscurridos > minutos * 60) {
			pagina->desactivarFiltroTiempo();
		}
		else {
			pagina->activarFiltroTiempo();
		}
	}
}

void Pestana::eliminarCadaTiempo(int minutos) {
	time_t tiempoActual = std::time(nullptr);//Obtiene  el tiempo actual
	NodoPag* aux = tail;

	while (aux != nullptr) {
		double segundosTranscurridos = difftime(tiempoActual, aux->paginaWeb->getTiempo());//cacula el timepo transcurrido desde que se ingres� la p�gina
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

void Pestana::desactivarFiltros() {
	NodoPag* actual = tail;
	while (actual != nullptr) {
		actual->paginaWeb->activarFiltro();
		actual = actual->siguiente;
	}
}

void Pestana::desactivarFiltroTiempo() {
	NodoPag* actual = tail;
	while (actual != nullptr) {
		actual->paginaWeb->activarFiltroTiempo();
		actual = actual->siguiente;
	}
}

void Pestana::guardarPestana(ofstream& file) {
	file << getNombre() << "|" << getIcognito() << "\n";
}

Pestana* Pestana::leerPestana(ifstream& file) {
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

	Pestana* pestana = new Pestana(name);
	if (incognito) {
		pestana->activarModoIncognito();
	}
	return pestana;
}

void Pestana::guardarHistorial(ofstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
		return;
	}

	int numHilos = 5;

	vector<PaginaWeb*> paginas;
	paginas.reserve(100000);

	NodoPag* actual = tail;
	while (actual != nullptr) {
		paginas.push_back(actual->paginaWeb);
		actual = actual->siguiente;
	}

	int n = paginas.size();

	if (numHilos <= 0) {
		numHilos = omp_get_max_threads();
	}

#pragma omp parallel for ordered schedule(dynamic,1000) num_threads(numHilos)
	for (int i = 0; i < n; ++i) {
#pragma omp ordered
		{
			file << paginas[i]->getURL() << '|'
				<< paginas[i]->getTitulo() << '|'
				<< paginas[i]->getMarcador() << '|'
				<< paginas[i]->getMarcadorPersonal() << '\n';
		}
	}

	file.close();
}

void Pestana::leerHistorial(ifstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return;
	}

	int numHilos = 5;

	vector<string> lineas;
	lineas.reserve(100000);

	string linea;
	while (getline(file, linea)) {
		if (!linea.empty()) {
			lineas.push_back(linea);
		}
	}
	file.close();

	int n = lineas.size();

	if (numHilos <= 0) {
		numHilos = omp_get_max_threads();
	}

	vector<PaginaWeb*> paginasLeidas(n, nullptr);

#pragma omp parallel for schedule(static) num_threads(numHilos) default(none) shared(lineas, paginasLeidas, n)
	for (int i = 0; i < n; ++i) {
		const string& linea = lineas[i];

		size_t pos1 = linea.find('|');
		if (pos1 == string::npos) {
			continue;
		}

		size_t pos2 = linea.find('|', pos1 + 1);
		if (pos2 == string::npos) {
			continue;
		}

		size_t pos3 = linea.find('|', pos2 + 1);
		if (pos3 == string::npos) {
			continue;
		}

		string url = linea.substr(0, pos1);
		string titulo = linea.substr(pos1 + 1, pos2 - pos1 - 1);

		bool marcadores = false;
		if (pos2 + 1 < linea.size()) {
			marcadores = linea[pos2 + 1] == '1';
		}

		string marcadorPersonal = linea.substr(pos3 + 1);

		PaginaWeb* paginaWeb = new PaginaWeb(url, titulo);
		paginaWeb->setMarcadorPersonal(marcadorPersonal);

		if (marcadores) {
			paginaWeb->PonerMarcador();
		}

		paginasLeidas[i] = paginaWeb;
	}

	for (int i = n - 1; i >= 0; --i) {
		if (paginasLeidas[i] != nullptr) {
			insertarPrimero(*paginasLeidas[i]);
		}
	}
}

void Pestana::explorarHistorialIncognito() {
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
				cout << "No se puede retroceder m�s." << endl;
			}
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) {
				cout << "No se puede avanzar m�s." << endl;
			}
			else {
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

