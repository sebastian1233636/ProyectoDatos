#include "AdminPestañas.h"
<<<<<<< HEAD

AdminPestañas::AdminPestañas() {
=======
// Constructor de la clase AdminPestañas.
// Inicializa los apuntadores 'tail' y 'head' en nullptr y el tamaño 'tam' en 0, indicando que la lista está vacía.
AdminPestañas::AdminPestañas(){
>>>>>>> documentacion interna
	tail = nullptr;
	head = nullptr;
	tam = 0;
}
<<<<<<< HEAD

AdminPestañas::~AdminPestañas() {
=======
// Destructor de la clase AdminPestañas.
// Libera la memoria de todos los nodos en la lista, eliminando todas las pestañas.
// Recorre desde 'tail' hacia adelante, eliminando los nodos uno por uno.
AdminPestañas::~AdminPestañas(){
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

NodoPest* AdminPestañas::getTail() { return tail; }

NodoPest* AdminPestañas::getHead() { return head; }

void AdminPestañas::InsertarPrimero(Pestaña* pes) {
=======
// Retorna el apuntador al nodo 'tail', que representa la pestaña más reciente.
NodoPest* AdminPestañas::getTail() {return tail;}
// Retorna el apuntador al nodo 'head', que representa la pestaña más antigua.
NodoPest* AdminPestañas::getHead() {return head;}
// Inserta una nueva pestaña al principio de la lista.
// Si la lista está vacía, 'tail' y 'head' apuntan al mismo nodo nuevo.
// Si no está vacía, el nuevo nodo se coloca antes del nodo actual de 'tail' y se actualiza el puntero.
void AdminPestañas::InsertarPrimero(Pestaña* pes){
>>>>>>> documentacion interna
	NodoPest* nuevo = new NodoPest();
	nuevo->pestaña = pes;
	if (tail == nullptr) {
		// Si la lista está vacía
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
// Recorre la lista de pestañas desde 'tail' y busca aquellas que están marcadas como favoritas.
// Llama a la función buscarFavorito() de cada pestaña.

void AdminPestañas::BuscarFavorito() {
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}
// Explora el historial de pestañas permitiendo al usuario navegar por las pestañas con las teclas de dirección.
// Se detiene cuando se llega a los extremos de la lista o cuando el usuario presiona 'ESC' para salir.

void AdminPestañas::ExplorarHistorialPestañas() {
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
		menuAdminPestañas(nodoActual);
=======
		system("cls");// Limpia la pantalla
		menuAdminPestañas(nodoActual);// Muestra el menú de administración de pestañas

		// Esperar a que el usuario presione una tecla para navegar o salir
>>>>>>> documentacion interna
		while (true) {
			// Navegar hacia la pestaña anterior con tecla abajo
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200); // Pausa para evitar múltiples lecturas
				break;
			}
			// Navegar hacia la pestaña siguiente con tecla arriba

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
	// Devuelve el número total de pestañas en la lista.
int AdminPestañas::contadorPestañas() { return tam; }

void AdminPestañas::menuAdminPestañas(NodoPest* actual) {
	int op = 0;// Opción seleccionada por el usuario
	int op2 = 0;
	int op3 = 0;
	int op4 = 0;
	int op6 = 0;
	string nom = "";
	string palabraclave = "";
	bool incognito = false;// Indica si el modo incógnito está activado
	bool control = true;// Control para seguir mostrando el menú
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool control6 = true;// Control para la opción 6 (configuración)
=======



// Muestra el menú de administración de pestañas para la pestaña actual.
// Permite al usuario realizar varias operaciones como ir al sitio web, crear una nueva pestaña, colocar un marcador, activar modo incógnito, etc.

>>>>>>> documentacion interna
// Bucle principal que muestra el menú hasta que el usuario elija salir
	while (control != false) {
		system("cls");// Limpia la consola
		cout << "----------------" << actual->pestaña->getNombre() <<  "----------------" << endl; // Muestra el nombre de la pestaña actual
		cout << "---------------------------------------" << endl;
		cout << "1.Ver historial" << endl;/// Opción para ver el historial de navegación
		cout << "2.Ir al sitio web" << endl;// Opción para ir a un sitio web específico
		cout << "3.Nueva pestaña" << endl;// Opción para crear una nueva pestaña
		cout << "4.Modo incognito" << endl;// Opción para activar o desactivar el modo incógnito
		cout << "5.Busquedas y filtros" << endl; // Opción para realizar búsquedas y aplicar filtros
		cout << "6.Configuracion" << endl;// Opción para modificar configuraciones
		cout << "7.Importacion y exportacion" << endl;// Opción para importar y exportar datos
		cout << "8.Regresar" << endl;// Opción para regresar al menú anterior
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion:";// Solicita al usuario que ingrese una opción
		cin >> op;
<<<<<<< HEAD
		cout << endl;
=======
		// Switch para procesar la opción seleccionada
>>>>>>> documentacion interna
// Switch para procesar la opción seleccionada
		switch (op) {

		case 1: {
			// Ver historial de la pestaña actual
			if (actual->pestaña->getIcognito() == false) {

				cout << actual->pestaña->mostrarPestaña() << endl;// Muestra la pestaña normal
				actual->pestaña->explorarHistorial();// Muestra el historial
			}
			else { cout << actual->pestaña->mostrarPestañaIncognito() << endl; }// Muestra la pestaña en modo incógnito
			break;
			
		}

		case 2: {
<<<<<<< HEAD
	// Ir a un sitio web específico
			string url;
			cout << "Digite el URL de la pagina:";// Solicita al usuario que ingrese un URL
			cin >> url;
			cout << endl;
			PaginaWeb* PagNueva = buscaPaginaWeb(url);// Busca la página web
			if (PagNueva == nullptr) { cout << "ERROR 404 NOT FOUND" << endl; }// Muestra error si la página no se encuentra
			else { actual->pestaña->insertarPrimero(*PagNueva); }// Inserta la página en la pestaña actual
			system("pause");// Pausa la ejecución
			break;
		}
		case 3: {
			string nombrePestaña = "Pestana " + to_string(tam + 1);
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pestaña. Siga las instrucciones anteriores para navegar a ella." << endl;
			system("pause");
=======
			
			break;
		}

		
		case 4:{
	
		
<<<<<<< HEAD
			control3 = true;
			while (control3 != false) {
				system("cls");
				cout << "1.Activar modo incognito" << endl;// Opción para activar modo incógnito
				cout << "2.Desactivar modo incognito" << endl;// Opción para desactivar modo incógnito
				cout << "3.Regresar" << endl; // Opción para regresar al menú anterior
				cout << "Digite la opcion" << endl;
				cin >> op3;
				switch (op3) {
				case 1:
					actual->pestaña->activarModoIncognito();// Activa el modo incógnito
					if (actual->pestaña->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;// Confirma que el modo ha sido activado
					
					}
					system("pause");// Pausa la ejecución
					break;
				case 2:
					actual->pestaña->desactivarModoIncognito();// Desactiva el modo incógnito
					if (actual->pestaña->getIcognito() == false) {
						cout << "Modo incognito desactivado" << endl; // Confirma que el modo ha sido desactivado
					}
					system("pause");
					break;
				case 3: {
					control3 = false;// Regresa al menú anterior
					break;
				}
=======
			// Activar/desactivar modo incógnito
>>>>>>> documentacion interna

				default:
					cout << "Opcion no valida" << endl;
					break;
				}

			}
			break;
		}
		case 5: {
			// Realizar búsquedas y aplicar filtros
			control4 = true;
			while (control4 != false) {
				cout << "---------------------------------------" << endl;
				cout << "1.Mostrar solo favoritos" << endl;// Opción para mostrar solo las páginas favoritas
				cout << "2.Busqueda por palabra clave" << endl; // Opción para buscar por palabra clave
				cout << "3.Buscar una pagina especifica" << endl; // Opción para buscar una página específica
				cout << "4.regresar" << endl;
				cout << "---------------------------------------" << endl;// Opción para regresar al menú anterior
				cin >> op4;
				switch (op4) {

				case 1: {
					actual->pestaña->buscarFavorito();// Busca y muestra los favoritos
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;// Solicita palabra clave para filtro
					cin >> palabraclave;
					actual->pestaña->buscarPorPalabraClave(palabraclave);// Aplica filtro por palabra clave

					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;// Solicita el URL o título para buscar
					cin >> nom;
					pag = actual->pestaña->buscarPaginaWeb(nom); // Busca la página web
					if (pag == nullptr) {
						cout << "La pagina que busca no se encuentra" << endl;// Mensaje si la página no se encuentra
					}
					else {
						pag->MostrarPaginaWeb();// Muestra la página si se encuentra
					}
					break;
				}
				case 4: {
					control4 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;// Maneja opción inválida
					break;


				}
			}
			break;
		}
		case 6: {
			// Configuraciones
			//--------------------------------------------------------------------------------------
			control5 = true;
			while (control5 != false) {
				system("cls");
				cout << "---------------------------------------" << endl;
				cout << "1.Limitar cantidad de entradas" << endl;// Opción para limitar entradas
				cout << "2.Eliminar historial cada cierto tiempo" << endl;// Opción para eliminar historial
				cout << "3.Regresar" << endl; // Opción para regresar al menú anterior
				cout << "---------------------------------------" << endl;
				cin >> op2;
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Digite el numero de minutos" << endl;// Solicita al usuario que ingrese minutos
					cin >> min;
					actual->pestaña->timeFilter(min);// Aplica filtro de tiempo
					system("pause");// Pausa la ejecución
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En este opcion se elminarán las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;// Solicita minutos para la eliminación
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pestaña->eliminarCadaTiempo(mins);// Elimina páginas según el tiempo
					system("pause");
					break;
				}

				case 3: {
					control5 = false; // Regresa al menú anterior
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
			// Importación y exportación
			guardarPestañaBinario();
			guardarHistorialPestaña();
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

PaginaWeb* AdminPestañas::buscaPaginaWeb(string urlBuscado) {
	string archivo("Prueba.csv"); // Nombre del archivo CSV donde se almacenan las páginas
	ifstream file(archivo);// Abre el archivo para lectura
	PaginaWeb* pagAr = new PaginaWeb();// Inicializa un objeto PaginaWeb
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
	else {

		string linea;
		// Lee cada línea del archivo
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;
			// Obtiene la URL y el título de cada línea
			if (getline(ss, url, ',') && getline(ss, titulo)) {// Crea un nuevo objeto PaginaWeb si se encuentra la URL

				if (url == urlBuscado) {
					pagAr = new PaginaWeb(url, titulo);
					return pagAr;// Devuelve el objeto encontrado
				}
				
				
				else { pagAr = nullptr; }
			}
		}
		file.close(); // Cierra el archivo
	}
	return nullptr;
}

void AdminPestañas::guardarPestañaBinario() {
	ofstream file("Pestañas.bin", ios::binary); // Abre un archivo binario para escritura
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
	else {
		NodoPest* actual = tail;// Comienza desde la última pestaña
		// Itera a través de cada nodo de la lista de pestañas
		while (actual != nullptr) {
			actual->pestaña->guardarPestaña(file); // Llama al método de guardar de cada pestaña
			actual = actual->siguiente;// Avanza al siguiente nodo
		}
	}
	file.close();
}

void AdminPestañas::leerPestañaBinario() {
	ifstream file("Pestañas.bin", ios::binary); // Abre el archivo binario para lectura
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
	else {
		file.seekg(0, ios::end);// Mueve el cursor al final del archivo
		std::streampos fileSize = file.tellg();// Obtiene el tamaño del archivo
		file.seekg(0, ios::beg);// Mueve el cursor al principio del archivo
		// Lee el archivo hasta que se alcance el final
		while (file.tellg() < fileSize) {
			Pestaña* pestaña = new Pestaña(); // Crea un nuevo objeto Pestaña
			Pestaña* pes = pestaña->leerPestaña(file);// Llama al método de lectura
			if (pes != nullptr) { InsertarPrimero(pes); } // Inserta la pestaña leída en la lista
			else {
				cout << "Error al leer una pestaña del archivo." << endl;// Mensaje de error si la lectura falla
				break;
			}
		}
	}
	file.close();
}
// Guarda el historial de cada pestaña actual en archivos binarios.
void AdminPestañas::guardarHistorialPestaña() {
	NodoPest* actual = tail;// Comienza desde la última pestaña
	ofstream file;// Declara un archivo de salida
	string nombre;// Variable para almacenar el nombre del archivo
	// Itera a través de cada nodo de la lista de pestañas
	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";// Crea un nombre de archivo para el historial
		file.open(nombre, ios::binary);// Abre el archivo para escritura
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
		actual->pestaña->guardarHistorialBinario(file);// Llama al método de guardar historial de cada pestaña
		actual = actual->siguiente;// Avanza al siguiente nodoo
		file.close();
	}
}

void AdminPestañas::leerHistorialPestaña(){
	NodoPest* actual = tail;
	ifstream file;
	string nombre;
	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pestaña->leerHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}
