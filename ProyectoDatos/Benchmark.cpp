
#include "Benchmark.h"
#include "AdminPestanas.h"
#include "Pestana.h"
#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

//Crea una pestaña global para pruebas
Pestana benchmark("Benchmark");
void InicializarPestanaBenchmark() {
	ifstream file("Historial_Pestana 1.txt");
	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}
	benchmark.leerHistorial(file);
	file.close();
}

// Función para medir el tiempo de ejecución de una operación
void medirOperacion(string nombre, void (*operacion)()) {
	double inicio = omp_get_wtime();

	operacion();

	double fin = omp_get_wtime();
	double tiempoMs = (fin - inicio) * 1000.0;

	cout << nombre << ": " << tiempoMs << " ms" << endl;
}

// Busca una URL específica en el archivo CSV y mide el tiempo que tarda en encontrarla
void benchmarkBusquedaURLArchivoCSV() {
	AdminPestanas admin;

	PaginaWeb* resultado = admin.buscaPaginaWeb("www.groupglobal999999.com");

	if (resultado != nullptr) {
		delete resultado;
	}
}

// Se cargan los datos del historial desde el archivo
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

void benchmarkFiltradoPorTiempoParalelo() {
	benchmark.timeFilterParalelo(10);
}

//Guarda el historial ya existente de la pestaña benchmark en un nuevo archivo de texto
void benchmarkGuardadoHistorial() {
	ofstream fileSalida("Historial_Benchmark_Salida.txt");

	if (!fileSalida.is_open()) {
		cout << "No se pudo crear Historial_Benchmark_Salida.txt" << endl;
		return;
	}

	benchmark.guardarHistorial(fileSalida);
	fileSalida.close();
}

void benchmarkBusquedaPalabraClave() {
	benchmark.buscarPorPalabraClave("cloud");
}

void benchmarkFiltradoPorTiempo() {
	benchmark.timeFilter(10);
}

void benchmarkMostrarFavoritos() {
	benchmark.mostrarFavoritos();
}

void ejecutarBenchmarks() {
	cout << "==============================================" << endl;
	cout << "       PRUEBAS DE TIEMPO CON OPENMP           " << endl;
	cout << "==============================================" << endl;
	cout << "Cargando datos para las pruebas..." << endl;
	InicializarPestanaBenchmark();
	medirOperacion("Busqueda por URL en archivo CSV", benchmarkBusquedaURLArchivoCSV);
	medirOperacion("Carga de historial", benchmarkCargaHistorialDesdeArchivo);
	medirOperacion("Guardado de historial", benchmarkGuardadoHistorial);
	medirOperacion("Busqueda por palabra clave", benchmarkBusquedaPalabraClave);
	medirOperacion("Filtrado por tiempo (secuencial)", benchmarkFiltradoPorTiempo);
	medirOperacion("Filtrado por tiempo (paralelo)", benchmarkFiltradoPorTiempoParalelo);
	cout << "==============================================" << endl;
	cout << "==============================================" << endl;
	cout << "          FIN DE LAS PRUEBAS                  " << endl;
	cout << "==============================================" << endl;
}