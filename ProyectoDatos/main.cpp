#include "AdminPestanas.h"
#include "Benchmark.h"

int main() {
	bool ejecutarBenchmark = true;

	if (ejecutarBenchmark) {
		ejecutarBenchmarks();
	}
	else {
		AdminPestanas* Admin = new AdminPestanas();
		Admin->iniciarNavegador();
		delete Admin;
	}

	return 0;
}