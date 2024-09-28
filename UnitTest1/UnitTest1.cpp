#include "pch.h"
#include "CppUnitTest.h"
#include"../ProyectoDatos/PaginaWeb.cpp"
#include"../ProyectoDatos/Pestaña.cpp"
#include"../ProyectoDatos/AdminPestañas.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		

		TEST_METHOD(TestTiempo)
		{
			PaginaWeb pagina;
			time_t tiempoActual = time(0);

			pagina.setTiempo(tiempoActual);

			Assert::AreEqual(tiempoActual, pagina.getTiempo());
		}

		TEST_METHOD(TestArchivos)
		{
			
			PaginaWeb pagina("www:algo.com", "algo");
			pagina.setMarcadorPersonal("Marcador");
			pagina.PonerMarcador();
			time_t tiempoActual = time(0);
			pagina.setTiempo(tiempoActual);

			
			ofstream fileOut("testPaginaWeb.bin", ios::binary);
			pagina.guardarPaginaWeb(fileOut);
			fileOut.close();

			
			ifstream fileIn("testPaginaWeb.bin", ios::binary);
			PaginaWeb* paginaLeida = pagina.leerPaginaWeb(fileIn);
			fileIn.close();

			
			Assert::AreEqual(pagina.getURL(), paginaLeida->getURL());
			Assert::AreEqual(pagina.getTitulo(), paginaLeida->getTitulo());
			Assert::AreEqual(pagina.getMarcadorPersonal(), paginaLeida->getMarcadorPersonal());
			Assert::AreEqual(pagina.getMarcador(), paginaLeida->getMarcador());
			Assert::AreEqual(pagina.getTiempo(), paginaLeida->getTiempo());

			
			delete paginaLeida;
		}


	};



	TEST_CLASS(UnitTestPestaña)
	{
	public:

		TEST_METHOD(TestInsertar)
		{
			Pestaña pestaña;
			PaginaWeb pagina("www:algo.com", "Example");

			pestaña.insertarPrimero(pagina);

			Assert::IsNotNull(pestaña.getTail());
			Assert::IsNotNull(pestaña.getHead());
			Assert::AreEqual(pestaña.getTail()->paginaWeb->getURL(), std::string("www:algo.com"));
		}

		// Test activar/desactivar modo incógnito
		TEST_METHOD(TestIncognito)
		{
			Pestaña pestaña;
			pestaña.activarModoIncognito();
			Assert::IsTrue(pestaña.getIcognito());

			pestaña.desactivarModoIncognito();
			Assert::IsFalse(pestaña.getIcognito());
		}

		// Test guardar y leer pestaña
		TEST_METHOD(TestArchivosPestaña)
		{
			
			ofstream archivoGuardar("pestaña.bin", ios::binary);
			Pestaña pestaña("TestPestaña");
			pestaña.guardarPestaña(archivoGuardar);
			archivoGuardar.close();

			ifstream archivoLeer("pestaña.bin", ios::binary);
			Pestaña* pestañaLeida = Pestaña::leerPestaña(archivoLeer);
			archivoLeer.close();

			Assert::AreEqual(pestañaLeida->getNombre(), std::string("TestPestaña"));
			delete pestañaLeida;
		}

		TEST_METHOD(TestBuscarFavorito)
		{
		
			Pestaña pestaña;
			PaginaWeb pagina1("www.pagina1.com", "Página 1");
			PaginaWeb pagina2("www.pagina2.com", "Página 2");
			PaginaWeb pagina3("www.pagina3.com", "Página 3");

			
			pagina1.PonerMarcador();
			pagina3.PonerMarcador();

			
			pestaña.insertarPrimero(pagina1);
			pestaña.insertarPrimero(pagina2);
			pestaña.insertarPrimero(pagina3);

			
			pestaña.buscarFavorito();

			
			Assert::IsTrue(pagina1.yaMostrada());
			Assert::IsFalse(pagina2.yaMostrada());
			Assert::IsTrue(pagina3.yaMostrada());

		}

		TEST_METHOD(TestBuscarPagina)
		{
			Pestaña pestaña;
			PaginaWeb pagina1("www.pagina1.com", "Pagina 1");
			PaginaWeb pagina2("www.pagina2.com", "Pagina 2");
			PaginaWeb pagina3("www.pagina3.com", "Pagina 3");

			pestaña.insertarPrimero(pagina1);
			pestaña.insertarPrimero(pagina2);
			pestaña.insertarPrimero(pagina3);

			PaginaWeb* resultado = pestaña.buscarPaginaWeb("www.pagina1.com");
			Assert::IsNotNull(resultado);
			Assert::AreEqual(string("Pagina 1"), resultado->getTitulo());

			resultado = pestaña.buscarPaginaWeb("Pagina 2");
			Assert::IsNotNull(resultado);
			Assert::AreEqual(string("www.pagina2.com"), resultado->getURL());

			resultado = pestaña.buscarPaginaWeb("No existe");
			Assert::IsNull(resultado);

		}

		TEST_METHOD(TestArchivosPestaña2)
		{
			
			
			Pestaña pestaña("TestPestaña");
			PaginaWeb* pag1 = new PaginaWeb("www.ejemplo1.com", "ejemplo1");
			PaginaWeb* pag2 = new PaginaWeb("www.ejemplo2.com", "ejemplo2");
			pestaña.insertarPrimero(*pag1);
			pestaña.insertarPrimero(*pag2);

			
			ofstream file("test_historial.bin", ios::binary);
			pestaña.guardarHistorialBinario(file);
			file.close();

			
			Pestaña pestañaLeida("TestPestañaLeida");
			ifstream FileLectura("test_historial.bin", ios::binary);
			pestañaLeida.leerHistorialBinario(FileLectura);
			FileLectura.close();

			
			PaginaWeb* resultado1 = pestañaLeida.buscarPaginaWeb("www.ejemplo1.com");
			PaginaWeb* resultado2 = pestañaLeida.buscarPaginaWeb("www.ejemplo2.com");

			Assert::IsNotNull(resultado1, L"La página 1 no se encontró después de leer el historial.");
			Assert::IsNotNull(resultado2, L"La página 2 no se encontró después de leer el historial.");

			
			remove("test_historial.bin");
			delete pag1;
			delete pag2;
		}





	};

	TEST_CLASS(UnitTestAdmin)
	{
	public:
		TEST_METHOD(TestInsertarPrimeroAdmin)
		{
		
			AdminPestañas admin;
			Pestaña* nuevaPestaña = new Pestaña("Pestaña1");
			admin.InsertarPrimero(nuevaPestaña);

			
			Assert::AreEqual(1, admin.contadorPestañas());
			Assert::IsNotNull(admin.getTail());
			Assert::AreEqual("Pestaña1", admin.getTail()->pestaña->getNombre().c_str());

		
			Pestaña* segundaPestaña = new Pestaña("Pestaña2");
			admin.InsertarPrimero(segundaPestaña);

			
			Assert::AreEqual(2, admin.contadorPestañas());
			Assert::AreEqual("Pestaña2", admin.getTail()->pestaña->getNombre().c_str());
			Assert::AreEqual("Pestaña1", admin.getTail()->siguiente->pestaña->getNombre().c_str());
		}


		TEST_METHOD(TestBuscaPaginaWeb)
		{
		
			string testArchivo = "Prueba.csv";
			ofstream archivoPrueba(testArchivo);
			archivoPrueba << "www.ejemplo.com,ejemplo\n"; 
			archivoPrueba.close();

			
			AdminPestañas admin;
			PaginaWeb* paginaBuscada = admin.buscaPaginaWeb("www.ejemplo.com");

			Assert::IsNotNull(paginaBuscada);
			Assert::AreEqual("www.ejemplo.com", paginaBuscada->getURL().c_str());
			Assert::AreEqual("ejemplo", paginaBuscada->getTitulo().c_str());

			PaginaWeb* paginaNoExistente = admin.buscaPaginaWeb("No Existe");
			Assert::IsNull(paginaNoExistente);

		
			remove(testArchivo.c_str());
		}



	};


}
