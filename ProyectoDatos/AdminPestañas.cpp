#include "AdminPesta�as.h"
<<<<<<< HEAD

AdminPesta�as::AdminPesta�as() {
=======
// Constructor de la clase AdminPesta�as.
// Inicializa los apuntadores 'tail' y 'head' en nullptr y el tama�o 'tam' en 0, indicando que la lista est� vac�a.
AdminPesta�as::AdminPesta�as(){
>>>>>>> documentacion interna
	tail = nullptr;
	head = nullptr;
	tam = 0;
}
<<<<<<< HEAD

AdminPesta�as::~AdminPesta�as() {
=======
// Destructor de la clase AdminPesta�as.
// Libera la memoria de todos los nodos en la lista, eliminando todas las pesta�as.
// Recorre desde 'tail' hacia adelante, eliminando los nodos uno por uno.
AdminPesta�as::~AdminPesta�as(){
>>>>>>> documentacion interna
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}
<<<<<<< HEAD

NodoPest* AdminPesta�as::getTail() { return tail; }

NodoPest* AdminPesta�as::getHead() { return head; }

void AdminPesta�as::InsertarPrimero(Pesta�a* pes) {
=======
// Retorna el apuntador al nodo 'tail', que representa la pesta�a m�s reciente.
NodoPest* AdminPesta�as::getTail() {return tail;}
// Retorna el apuntador al nodo 'head', que representa la pesta�a m�s antigua.
NodoPest* AdminPesta�as::getHead() {return head;}
// Inserta una nueva pesta�a al principio de la lista.
// Si la lista est� vac�a, 'tail' y 'head' apuntan al mismo nodo nuevo.
// Si no est� vac�a, el nuevo nodo se coloca antes del nodo actual de 'tail' y se actualiza el puntero.
void AdminPesta�as::InsertarPrimero(Pesta�a* pes){
>>>>>>> documentacion interna
	NodoPest* nuevo = new NodoPest();
	nuevo->pesta�a = pes;
	if (tail == nullptr) {
		// Si la lista est� vac�a
		tail = head = nuevo;
		nuevo->siguiente;
		nuevo->anterior;
	}
	else {
		// Inserta el nodo antes de 'tail'
		nuevo->siguiente = tail;
		tail->anterior = nuevo;
		tail = nuevo;
	}
	tam++;
}
// Recorre la lista de pesta�as desde 'tail' y busca aquellas que est�n marcadas como favoritas.
// Llama a la funci�n buscarFavorito() de cada pesta�a.

void AdminPesta�as::BuscarFavorito() {
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pesta�a->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}
// Explora el historial de pesta�as permitiendo al usuario navegar por las pesta�as con las teclas de direcci�n.
// Se detiene cuando se llega a los extremos de la lista o cuando el usuario presiona 'ESC' para salir.

void AdminPesta�as::ExplorarHistorialPesta�as() {
	bool bandera = true;
	NodoPest* nodoActual = tail;
	// Si no hay historial, mostrar mensaje y terminar

	if (nodoActual == nullptr) {
		cout << "No hay historial todavia" << endl;
		return;
	}
	// Mientras el usuario no presione 'ESC', seguir explorando
	while (bandera) {
<<<<<<< HEAD
		system("cls");
		menuAdminPesta�as(nodoActual);
=======
		system("cls");// Limpia la pantalla
		menuAdminPesta�as(nodoActual);// Muestra el men� de administraci�n de pesta�as

		// Esperar a que el usuario presione una tecla para navegar o salir
>>>>>>> documentacion interna
		while (true) {
			// Navegar hacia la pesta�a anterior con tecla abajo
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200); // Pausa para evitar m�ltiples lecturas
				break;
			}
			// Navegar hacia la pesta�a siguiente con tecla arriba

			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);
				break;
			}
			// Salir del historial con tecla ESC

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				bandera = false;
				system("cls");
				break;
			}
			Sleep(100);
		}
	}
}

<<<<<<< HEAD
int AdminPesta�as::contadorPesta�as() { return tam; }

void AdminPesta�as::menuAdminPesta�as(NodoPest* actual) {
	int op = 0;
	int op2 = 0;
	int op3 = 0;
	int op4 = 0;
	int op6 = 0;
	string nom = "";
	string palabraclave = "";
	bool incognito = false;
	bool control = true;
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool control6 = true;
=======
// Devuelve el n�mero total de pesta�as en la lista.

int AdminPesta�as::contadorPesta�as()
{

	return tam;
}
// Muestra el men� de administraci�n de pesta�as para la pesta�a actual.
// Permite al usuario realizar varias operaciones como ir al sitio web, crear una nueva pesta�a, colocar un marcador, activar modo inc�gnito, etc.

void AdminPesta�as::menuAdminPesta�as(NodoPest* actual)
{
	int op = 0; // Opci�n seleccionada por el usuario
	bool incognito;// Indica si el modo inc�gnito est� activado
	bool control = true; // Control para seguir mostrando el men�
	bool control6 = true;// Control para la opci�n 6 (configuraci�n)
	// Control para la opci�n 6 (configuraci�n)
>>>>>>> documentacion interna
	while (control != false) {
		system("cls");
		cout << "----------------" << actual->pesta�a->getNombre() <<  "----------------" << endl;
		cout << "---------------------------------------" << endl;
		cout << "1.Ver historial" << endl;
		cout << "2.Ir al sitio web" << endl;
		cout << "3.Nueva pesta�a" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Importacion y exportacion" << endl;
		cout << "8.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion:";
		cin >> op;
<<<<<<< HEAD
		cout << endl;
=======
		// Switch para procesar la opci�n seleccionada
>>>>>>> documentacion interna
		switch (op) {

		case 1: {
			if (actual->pesta�a->getIcognito() == false) {

				cout << actual->pesta�a->mostrarPesta�a() << endl;
				actual->pesta�a->explorarHistorial();
			}
			else { cout << actual->pesta�a->mostrarPesta�aIncognito() << endl; }
			break;
			
		}

		case 2: {
<<<<<<< HEAD
			string url;
			cout << "Digite el URL de la pagina:";
			cin >> url;
			cout << endl;
			PaginaWeb* PagNueva = buscaPaginaWeb(url);
			if (PagNueva == nullptr) { cout << "ERROR 404 NOT FOUND" << endl; }
			else { actual->pesta�a->insertarPrimero(*PagNueva); }
			system("pause");
			break;
		}
		case 3: {
			string nombrePesta�a = "Pestana " + to_string(tam + 1);
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pesta�a. Siga las instrucciones anteriores para navegar a ella." << endl;
			system("pause");
=======
			// Crear una nueva pesta�a
			string nombrePesta�a = "Pesta�a " + to_string(tam + 1);
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
			InsertarPrimero(pes);
			break;
		}

		
		case 3:{
			// Colocar un marcador, si no est� en modo inc�gnito
			if (!incognito) {
				string marcador;
				cout << "Ingrese el nombre del marcador: ";
				cin >> marcador;
				NodoPag().paginaWeb->getMarcador();
				cout << "Marcador agregado: " << marcador << endl;
			}
			else {
				cout << "La opci�n de marcadores no est� disponible en modo inc�gnito." << endl;
			}


>>>>>>> documentacion interna
			break;
		}
		case 4: {
<<<<<<< HEAD
			control3 = true;
			while (control3 != false) {
				system("cls");
				cout << "1.Activar modo incognito" << endl;
				cout << "2.Desactivar modo incognito" << endl;
				cout << "3.Regresar" << endl;
				cout << "Digite la opcion" << endl;
				cin >> op3;
				switch (op3) {
				case 1:
					actual->pesta�a->activarModoIncognito();
					if (actual->pesta�a->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					actual->pesta�a->desactivarModoIncognito();
					if (actual->pesta�a->getIcognito() == false) {
						cout << "Modo incognito desactivado" << endl;
					}
					system("pause");
					break;
				case 3: {
					control3 = false;
					break;
				}
=======
			// Activar/desactivar modo inc�gnito
>>>>>>> documentacion interna

				default:
					cout << "Opcion no valida" << endl;
					break;
				}

			}
			break;
		}
		case 5: {
			control4 = true;
			while (control4 != false) {
				cout << "---------------------------------------" << endl;
				cout << "1.Mostrar solo favoritos" << endl;
				cout << "2.Busqueda por palabra clave" << endl;
				cout << "3.Buscar una pagina especifica" << endl;
				cout << "4.regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op4;
				switch (op4) {

				case 1: {
					actual->pesta�a->buscarFavorito();
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;
					cin >> palabraclave;
					actual->pesta�a->buscarPorPalabraClave(palabraclave);

					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;
					cin >> nom;
					pag = actual->pesta�a->buscarPaginaWeb(nom);
					if (pag == nullptr) {
						cout << "La pagina que busca no se encuentra" << endl;
					}
					else {
						pag->MostrarPaginaWeb();
					}
					break;
				}
				case 4: {
					control4 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;
					break;


				}
			}
			break;
		}
		case 6: {
			//--------------------------------------------------------------------------------------
			control5 = true;
			while (control5 != false) {
				system("cls");
				cout << "---------------------------------------" << endl;
				cout << "1.Limitar cantidad de entradas" << endl;
				cout << "2.Eliminar historial cada cierto tiempo" << endl;
				cout << "3.Regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op2;
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Digite el numero de minutos" << endl;
					cin >> min;
					actual->pesta�a->timeFilter(min);
					system("pause");
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En este opcion se elminar�n las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pesta�a->eliminarCadaTiempo(mins);
					system("pause");
					break;
				}

				case 3: {
					control5 = false;
					break;
				}
				default:
					cout << "Opcion no valida" << endl;
					break;
				}
			}
			break;
		}
		case 7: {
			guardarPesta�aBinario();
			guardarHistorialPesta�a();
			cout << "Historial guardado" << endl;
			system("pause");
			break;
		}
		case 8:
			control = false;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}

PaginaWeb* AdminPesta�as::buscaPaginaWeb(string urlBuscado) {
	string archivo("Prueba.csv");
	ifstream file(archivo);
	PaginaWeb* pagAr = new PaginaWeb();
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		string linea;
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;
			if (getline(ss, url, ',') && getline(ss, titulo)) {
				if (url == urlBuscado) {
					pagAr = new PaginaWeb(url, titulo);
					return pagAr;
				}
				else { pagAr = nullptr; }
			}
		}
		file.close();
	}
	return nullptr;
}

void AdminPesta�as::guardarPesta�aBinario() {
	ofstream file("Pesta�as.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		NodoPest* actual = tail;
		while (actual != nullptr) {
			actual->pesta�a->guardarPesta�a(file);
			actual = actual->siguiente;
		}
	}
	file.close();
}

void AdminPesta�as::leerPesta�aBinario() {
	ifstream file("Pesta�as.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		file.seekg(0, ios::end);
		std::streampos fileSize = file.tellg();
		file.seekg(0, ios::beg);
		while (file.tellg() < fileSize) {
			Pesta�a* pesta�a = new Pesta�a();
			Pesta�a* pes = pesta�a->leerPesta�a(file);
			if (pes != nullptr) { InsertarPrimero(pes); }
			else {
				cout << "Error al leer una pesta�a del archivo." << endl;
				break;
			}
		}
	}
	file.close();
}

void AdminPesta�as::guardarHistorialPesta�a() {
	NodoPest* actual = tail;
	ofstream file;
	string nombre;
	while (actual != nullptr) {
		nombre = "Historial" + actual->pesta�a->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pesta�a->guardarHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}

void AdminPesta�as::leerHistorialPesta�a(){
	NodoPest* actual = tail;
	ifstream file;
	string nombre;
	while (actual != nullptr) {
		nombre = "Historial" + actual->pesta�a->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pesta�a->leerHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}
