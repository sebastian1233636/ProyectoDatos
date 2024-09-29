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
	bool bandera = true; // Variable que controla el bucle de exploración
	string marcador;	// Variable para almacenar el nombre del marcador
	NodoPag* nodoActual = tail; 

	// Verifica si el historial está vacío
	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl; 
		system("pause"); // Pausa el sistema
	}
	else {
		// Bucle que permite la exploración del historial
		while (bandera == true) {
			
			if (modoIcognito) {//Verificacion para el modo incognito
				cout << "No guardar historial ni marcadores" << endl; 
			}
			else {
				// Se presiona la tecla izquierda para avanzar hacia atras
				if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
					if (nodoActual->anterior == nullptr) {//hace la verificacion correspondiente 
						if (nodoActual->paginaWeb->getMostrarFiltro() == true && nodoActual->paginaWeb->getFiltroTiempo()==true) {
							nodoActual->paginaWeb->MostrarPaginaWeb();
						}
						cout << "No se puede retroceder mas" << endl;//mensaje limite
					}
					else {
						if (nodoActual->paginaWeb->getMostrarFiltro() == true && nodoActual->paginaWeb->getFiltroTiempo() == true) {
							nodoActual->paginaWeb->MostrarPaginaWeb();
						}
						nodoActual = nodoActual->anterior; 
					}
					Sleep(300); // Pausa para evitar múltiples lecturas rápidas
				}

				// Se presiona la tecla derecha para ir hacia adelante
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					
					if (nodoActual->siguiente == nullptr) {//verificacion 
						if (nodoActual->paginaWeb->getMostrarFiltro() == true && nodoActual->paginaWeb->getFiltroTiempo() == true) {
							nodoActual->paginaWeb->MostrarPaginaWeb();
						}
						
						cout << "No se puede avanzar mas" << endl; //Mensaje limite
					}
					else {
						if (nodoActual->paginaWeb->getMostrarFiltro() == true && nodoActual->paginaWeb->getFiltroTiempo() == true) {
							nodoActual->paginaWeb->MostrarPaginaWeb();
						}
						nodoActual = nodoActual->siguiente;
					}
					Sleep(300); // Pausa para evitar múltiples lecturas rápidas
				}

				// Si se presiona la tecla F
				if (GetAsyncKeyState('F') & 0x8000) {
					nodoActual->paginaWeb->PonerMarcador(); // Activa el marcador para la página
					cout << "Ingrese el nombre del marcador (dejar en blanco para no asignar nombre): ";
					cin.ignore(); // Ignora el buffer de entrada
					getline(cin, marcador); // Obtiene el nombre del marcador
					
					if (!marcador.empty()) {// Si no se ingresó un nombre de marcador
						nodoActual->paginaWeb->setMarcadorPersonal(marcador); // Asigna el marcador personal como favorito
					}
					cout << "Pagina marcada como favorita" << endl; 
					Sleep(300); 
				}

				// Se presiona la tecla Escape para salir del bucle
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
					bandera = false;
				}
			}
		}
	}
}


void Pestaña::buscarFavorito() {
	NodoPag* nodoActual = tail; 
	bool bandera = false; // Controla si se encontraron páginas favoritas

	// Recorre la lista de páginas
	while (nodoActual != nullptr) {
		// Se verifica si la página está marcada como favorita y no ha sido mostrada
		if (nodoActual->paginaWeb->getMarcador() == true && nodoActual->paginaWeb->yaMostrada() == false) {
			bandera = true;
			nodoActual->paginaWeb->marcarComoMostrada(); // Marca la página como mostrada
			nodoActual->paginaWeb->MostrarPaginaWeb(); // Muestra la página
		}
		nodoActual = nodoActual->siguiente; // Avanza al siguiente nodo
	}

	// Mensaje si no se encontro al menos una pagina marcada como favorita
	if (bandera == false) {
		cout << "No hay paginas marcadas como favoritas" << endl;
	}
}


void Pestaña::activarModoIncognito() { modoIcognito = true; }

void Pestaña::desactivarModoIncognito() { modoIcognito = false; }

string Pestaña::mostrarPestaña() {//El cuerpo de la pestaña que se va a mostrar 
	stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opción 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
	s << "|Para dejar de ver el historial y volver al menu de Pestaña presionar ESC." << endl;
	s << "|-------------------------" << nombre << "---------------------------|" << endl;
	return s.str();
}

string Pestaña::mostrarPestañaIncognito() {//Mensaje si se selecciona el modo incognito
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

PaginaWeb* Pestaña::buscarPaginaWeb(string nomURL)
{
	NodoPag* actual = tail;
	//Recorre toda la lista y pregunta si se cumple alguna de las 2 condiciones
	while (actual != nullptr) {
		if (nomURL == actual->paginaWeb->getURL() || nomURL == actual->paginaWeb->getTitulo()) {
			return actual->paginaWeb;//si se cumplen retorna la pagina, de lo contrario nullptr
		}
		else {
			actual = actual->siguiente;
		}
	}
	return nullptr;
}

void Pestaña::buscarPorPalabraClave(string palabraclave) {
	NodoPag* actual = tail;
	bool bandera = false; // Controla si se encontraron páginas que no cumplen con la palabra clave

	// Recorre la lista de páginas
	while (actual != nullptr) {

		string url = actual->paginaWeb->getURL();
		string titulo = actual->paginaWeb->getTitulo();

		// Verifica si la URL o el título NO contienen la palabra clave
		if (url.find(palabraclave) == string::npos && titulo.find(palabraclave) == string::npos) {
			actual->paginaWeb->desactivarFiltro();//Desactuva el filtro de las que no cumplen el requisito
		}
		else {
			actual->paginaWeb->activarFiltro();//activa el filtro de quienes si cumplen
			bandera = true;
		}
		actual = actual->siguiente;//continua la busqueda
	}

	system("pause");

	if (bandera == false) {
		cout << "No se ha encontrado una pagina que cumpla con el requisito." << endl;
		system("pause");
	}
}



void Pestaña::timeFilter(int minutos) {
	time_t tiempoActual = std::time(nullptr); // Obtiene el tiempo actual
	NodoPag* actual = tail; 

	// Recorre la lista
	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb; // Obtiene la página web del nodo actual
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo()); // Calcula el tiempo transcurrido desde que se guardó la página

		// Muestra la página si no fue guardada dentro del límite de tiempo especificado por el usuario
		if (segundosTranscurridos > minutos * 60) {
			pagina->desactivarFiltroTiempo();//Desactiva el filtro de quines incumplen el requisito
		}
		else {
			pagina->activarFiltroTiempo();// se activan los que si cumplen para poder mostrarse
		}
		actual = actual->siguiente; // Continua la busqueda
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

void Pestaña::desactivarFiltros()
{
	NodoPag* actual = tail;

	while (actual != nullptr) {
		actual->paginaWeb->activarFiltro();
		actual = actual->siguiente;
	}
}

void Pestaña::desactivarFiltroTiempo()
{
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

	//Recorre la lista llamando al metodo para guardar los historiales
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

void Pestaña::leerHistorialBinario(ifstream& file) {
	// Recorre la lista llamando al método para cargar los historiales
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return; 
	}

	file.seekg(0, ios::end); // Mover el cursor al final del archivo
	std::streampos fileSize = file.tellg(); // Obtener el tamaño del archivo
	file.seekg(0, ios::beg); // Volver al inicio del archivo

	// Leer el archivo hasta que se alcance su final
	while (file.tellg() < fileSize) {
		PaginaWeb* pagLeida = new PaginaWeb();
		PaginaWeb* pag = pagLeida->leerPaginaWeb(file); // Lee una página web del archivo

		// Insertar la página en la lista si se leyó correctamente
		if (pag != nullptr) {
			insertarPrimero(*pag);
		}
		else {
			cout << "Error al leer una página web del archivo." << endl; 
			break; // Salir del bucle en caso de error
		}
	}
	file.close(); // Cerrar el archivo
	cout << "Lectura del historial completada." << endl; 
}



void Pestaña::explorarHistorialIncognito() {
	bool bandera = true;
	NodoPag* nodoActual = tail;
	//Metodo que se ejecuta en caso de que la pestaña este en modo incognito

	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl;
		return;
	}

	cout << "Modo incognito activado. No se guardara historial ni marcadores." << endl;

	while (bandera) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) { cout << "No se puede retroceder más." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) { cout << "No se puede avanzar más." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
	}
}