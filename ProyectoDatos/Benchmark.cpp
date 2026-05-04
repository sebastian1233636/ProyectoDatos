#include "Benchmark.h"
#include "AdminPestanas.h"
#include "Pestana.h"

#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

void medirOperacion(string nombre, void (*operacion)()) {
	double inicio = omp_get_wtime();

	operacion();

	double fin = omp_get_wtime();
	double tiempoMs = (fin - inicio) * 1000.0;

	cout << nombre << ": " << tiempoMs << " ms" << endl;
}

void benchmarkBusquedaURLArchivoCSV() {
	AdminPestanas admin;

	PaginaWeb* resultado = admin.buscaPaginaWeb("www.groupglobal999999.com");

	if (resultado != nullptr) {
		delete resultado;
	}
}

void benchmarkCargaHistorialDesdeArchivo() {
	Pestana pestana("Benchmark");

	ifstream file("Historial_Pestana 1.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorial(file);

	file.close();
}

void benchmarkGuardadoHistorial() {
	Pestana pestana("Benchmark");

	ifstream fileEntrada("Historial_Pestana 1.txt");

	if (!fileEntrada.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorial(fileEntrada);
	fileEntrada.close();

	ofstream fileSalida("Historial_Benchmark_Salida.txt");

	if (!fileSalida.is_open()) {
		cout << "No se pudo crear Historial_Benchmark_Salida.txt" << endl;
		return;
	}

	pestana.guardarHistorial(fileSalida);
	fileSalida.close();
}

void benchmarkBusquedaPalabraClave() {
	Pestana pestana("Benchmark");

	ifstream file("Historial_Pestana 1.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorial(file);
	file.close();

	pestana.buscarPorPalabraClave("cloud");
}

void benchmarkFiltradoPorTiempo() {
	Pestana pestana("Benchmark");

	ifstream file("Historial_Pestana 1.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorial(file);
	file.close();

	pestana.timeFilter(10);
}

void benchmarkMostrarFavoritos() {
	Pestana pestana("Benchmark");

	ifstream file("Historial_Pestana 1.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorial(file);
	file.close();

	pestana.mostrarFavoritos();
}

void ejecutarBenchmarks() {
	cout << "==============================================" << endl;
	cout << "       PRUEBAS DE TIEMPO CON OPENMP           " << endl;
	cout << "==============================================" << endl;

	medirOperacion("Busqueda por URL en archivo CSV", benchmarkBusquedaURLArchivoCSV);
	medirOperacion("Carga de historial y paginas desde archivo", benchmarkCargaHistorialDesdeArchivo);
	medirOperacion("Guardado de historial", benchmarkGuardadoHistorial);
	medirOperacion("Busqueda por palabra clave", benchmarkBusquedaPalabraClave);
	medirOperacion("Filtrado por tiempo", benchmarkFiltradoPorTiempo);
	//medirOperacion("Mostrar favoritos", benchmarkMostrarFavoritos);

	cout << "==============================================" << endl;
	cout << "          FIN DE LAS PRUEBAS                  " << endl;
	cout << "==============================================" << endl;
}