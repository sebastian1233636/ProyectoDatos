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
	// Devuelve el n�mero total de pesta�as en la lista.
int AdminPesta�as::contadorPesta�as() { return tam; }

void AdminPesta�as::menuAdminPesta�as(NodoPest* actual) {
	int op = 0;// Opci�n seleccionada por el usuario
	int op2 = 0;
	int op3 = 0;
	int op4 = 0;
	int op6 = 0;
	string nom = "";
	string palabraclave = "";
	bool incognito = false;// Indica si el modo inc�gnito est� activado
	bool control = true;// Control para seguir mostrando el men�
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool control6 = true;// Control para la opci�n 6 (configuraci�n)
=======



// Muestra el men� de administraci�n de pesta�as para la pesta�a actual.
// Permite al usuario realizar varias operaciones como ir al sitio web, crear una nueva pesta�a, colocar un marcador, activar modo inc�gnito, etc.

>>>>>>> documentacion interna
// Bucle principal que muestra el men� hasta que el usuario elija salir
	while (control != false) {
		system("cls");// Limpia la consola
		cout << "----------------" << actual->pesta�a->getNombre() <<  "----------------" << endl; // Muestra el nombre de la pesta�a actual
		cout << "---------------------------------------" << endl;
		cout << "1.Ver historial" << endl;/// Opci�n para ver el historial de navegaci�n
		cout << "2.Ir al sitio web" << endl;// Opci�n para ir a un sitio web espec�fico
		cout << "3.Nueva pesta�a" << endl;// Opci�n para crear una nueva pesta�a
		cout << "4.Modo incognito" << endl;// Opci�n para activar o desactivar el modo inc�gnito
		cout << "5.Busquedas y filtros" << endl; // Opci�n para realizar b�squedas y aplicar filtros
		cout << "6.Configuracion" << endl;// Opci�n para modificar configuraciones
		cout << "7.Importacion y exportacion" << endl;// Opci�n para importar y exportar datos
		cout << "8.Regresar" << endl;// Opci�n para regresar al men� anterior
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion:";// Solicita al usuario que ingrese una opci�n
		cin >> op;
<<<<<<< HEAD
		cout << endl;
=======
		// Switch para procesar la opci�n seleccionada
>>>>>>> documentacion interna
// Switch para procesar la opci�n seleccionada
		switch (op) {

		case 1: {
			// Ver historial de la pesta�a actual
			if (actual->pesta�a->getIcognito() == false) {

				cout << actual->pesta�a->mostrarPesta�a() << endl;// Muestra la pesta�a normal
				actual->pesta�a->explorarHistorial();// Muestra el historial
			}
			else { cout << actual->pesta�a->mostrarPesta�aIncognito() << endl; }// Muestra la pesta�a en modo inc�gnito
			break;
			
		}

		case 2: {
<<<<<<< HEAD
	// Ir a un sitio web espec�fico
			string url;
			cout << "Digite el URL de la pagina:";// Solicita al usuario que ingrese un URL
			cin >> url;
			cout << endl;
			PaginaWeb* PagNueva = buscaPaginaWeb(url);// Busca la p�gina web
			if (PagNueva == nullptr) { cout << "ERROR 404 NOT FOUND" << endl; }// Muestra error si la p�gina no se encuentra
			else { actual->pesta�a->insertarPrimero(*PagNueva); }// Inserta la p�gina en la pesta�a actual
			system("pause");// Pausa la ejecuci�n
			break;
		}
		case 3: {
			string nombrePesta�a = "Pestana " + to_string(tam + 1);
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pesta�a. Siga las instrucciones anteriores para navegar a ella." << endl;
			system("pause");
=======
			
			break;
		}

		
		case 4:{
	
		
<<<<<<< HEAD
			control3 = true;
			while (control3 != false) {
				system("cls");
				cout << "1.Activar modo incognito" << endl;// Opci�n para activar modo inc�gnito
				cout << "2.Desactivar modo incognito" << endl;// Opci�n para desactivar modo inc�gnito
				cout << "3.Regresar" << endl; // Opci�n para regresar al men� anterior
				cout << "Digite la opcion" << endl;
				cin >> op3;
				switch (op3) {
				case 1:
					actual->pesta�a->activarModoIncognito();// Activa el modo inc�gnito
					if (actual->pesta�a->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;// Confirma que el modo ha sido activado
					
					}
					system("pause");// Pausa la ejecuci�n
					break;
				case 2:
					actual->pesta�a->desactivarModoIncognito();// Desactiva el modo inc�gnito
					if (actual->pesta�a->getIcognito() == false) {
						cout << "Modo incognito desactivado" << endl; // Confirma que el modo ha sido desactivado
					}
					system("pause");
					break;
				case 3: {
					control3 = false;// Regresa al men� anterior
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
			// Realizar b�squedas y aplicar filtros
			control4 = true;
			while (control4 != false) {
				cout << "---------------------------------------" << endl;
				cout << "1.Mostrar solo favoritos" << endl;// Opci�n para mostrar solo las p�ginas favoritas
				cout << "2.Busqueda por palabra clave" << endl; // Opci�n para buscar por palabra clave
				cout << "3.Buscar una pagina especifica" << endl; // Opci�n para buscar una p�gina espec�fica
				cout << "4.regresar" << endl;
				cout << "---------------------------------------" << endl;// Opci�n para regresar al men� anterior
				cin >> op4;
				switch (op4) {

				case 1: {
					actual->pesta�a->buscarFavorito();// Busca y muestra los favoritos
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;// Solicita palabra clave para filtro
					cin >> palabraclave;
					actual->pesta�a->buscarPorPalabraClave(palabraclave);// Aplica filtro por palabra clave

					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;// Solicita el URL o t�tulo para buscar
					cin >> nom;
					pag = actual->pesta�a->buscarPaginaWeb(nom); // Busca la p�gina web
					if (pag == nullptr) {
						cout << "La pagina que busca no se encuentra" << endl;// Mensaje si la p�gina no se encuentra
					}
					else {
						pag->MostrarPaginaWeb();// Muestra la p�gina si se encuentra
					}
					break;
				}
				case 4: {
					control4 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;// Maneja opci�n inv�lida
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
				cout << "1.Limitar cantidad de entradas" << endl;// Opci�n para limitar entradas
				cout << "2.Eliminar historial cada cierto tiempo" << endl;// Opci�n para eliminar historial
				cout << "3.Regresar" << endl; // Opci�n para regresar al men� anterior
				cout << "---------------------------------------" << endl;
				cin >> op2;
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Digite el numero de minutos" << endl;// Solicita al usuario que ingrese minutos
					cin >> min;
					actual->pesta�a->timeFilter(min);// Aplica filtro de tiempo
					system("pause");// Pausa la ejecuci�n
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En este opcion se elminar�n las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;// Solicita minutos para la eliminaci�n
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pesta�a->eliminarCadaTiempo(mins);// Elimina p�ginas seg�n el tiempo
					system("pause");
					break;
				}

				case 3: {
					control5 = false; // Regresa al men� anterior
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
			// Importaci�n y exportaci�n
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
	string archivo("Prueba.csv"); // Nombre del archivo CSV donde se almacenan las p�ginas
	ifstream file(archivo);// Abre el archivo para lectura
	PaginaWeb* pagAr = new PaginaWeb();// Inicializa un objeto PaginaWeb
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
	else {

		string linea;
		// Lee cada l�nea del archivo
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;
			// Obtiene la URL y el t�tulo de cada l�nea
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

void AdminPesta�as::guardarPesta�aBinario() {
	ofstream file("Pesta�as.bin", ios::binary); // Abre un archivo binario para escritura
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
	else {
		NodoPest* actual = tail;// Comienza desde la �ltima pesta�a
		// Itera a trav�s de cada nodo de la lista de pesta�as
		while (actual != nullptr) {
			actual->pesta�a->guardarPesta�a(file); // Llama al m�todo de guardar de cada pesta�a
			actual = actual->siguiente;// Avanza al siguiente nodo
		}
	}
	file.close();
}

void AdminPesta�as::leerPesta�aBinario() {
	ifstream file("Pesta�as.bin", ios::binary); // Abre el archivo binario para lectura
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
	else {
		file.seekg(0, ios::end);// Mueve el cursor al final del archivo
		std::streampos fileSize = file.tellg();// Obtiene el tama�o del archivo
		file.seekg(0, ios::beg);// Mueve el cursor al principio del archivo
		// Lee el archivo hasta que se alcance el final
		while (file.tellg() < fileSize) {
			Pesta�a* pesta�a = new Pesta�a(); // Crea un nuevo objeto Pesta�a
			Pesta�a* pes = pesta�a->leerPesta�a(file);// Llama al m�todo de lectura
			if (pes != nullptr) { InsertarPrimero(pes); } // Inserta la pesta�a le�da en la lista
			else {
				cout << "Error al leer una pesta�a del archivo." << endl;// Mensaje de error si la lectura falla
				break;
			}
		}
	}
	file.close();
}
// Guarda el historial de cada pesta�a actual en archivos binarios.
void AdminPesta�as::guardarHistorialPesta�a() {
	NodoPest* actual = tail;// Comienza desde la �ltima pesta�a
	ofstream file;// Declara un archivo de salida
	string nombre;// Variable para almacenar el nombre del archivo
	// Itera a trav�s de cada nodo de la lista de pesta�as
	while (actual != nullptr) {
		nombre = "Historial" + actual->pesta�a->getNombre() + ".bin";// Crea un nombre de archivo para el historial
		file.open(nombre, ios::binary);// Abre el archivo para escritura
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }// Mensaje de error si no se puede abrir el archivo
		actual->pesta�a->guardarHistorialBinario(file);// Llama al m�todo de guardar historial de cada pesta�a
		actual = actual->siguiente;// Avanza al siguiente nodoo
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
