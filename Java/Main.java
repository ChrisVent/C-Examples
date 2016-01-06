package App;
public class Main {

	public static void main(String[] args) {
		
		
		/////////////////// CLASE PERSONA ///////////////////////////
		/*Persona Me = new Persona("Christopher");
		Me.Saludar();
		System.out.println(Me.GetNombre());
		Me.Despedirse();
		Me.setNombre("Carlitos");
		System.out.println(Me.GetNombre());
		Me.Saludar();
		Me.Despedirse();
		*/
		
		
		
		
		
		//////////// CLASE HILO /////////////////////////////
		/*
		//int MIN_PRIORY = 1;
		int NORM_PRIORY = 5;
		//int MAX_PRIORY = 10;
		Hilo Hilo1 = new Hilo("Hilo 1");
		Hilo Hilo2 = new Hilo("Hilo 2");
		Hilo1.setPriority(NORM_PRIORY); // prioridad de ejecucion en hilos
		Hilo2.setPriority(NORM_PRIORY);
		Hilo1.start();
		Hilo2.start();
		*/
		
		
		
		
		/////////////// CLASE FILES //////////////////////////
		/*
		Files f = new Files();
		f.Escribir("archivo.txt","Hola Mundo");
		f.Leer("archivo.txt");
		*/
		
		
		//////////// CLASES VERIFICARCUENTA Y CUENTABANCO ////////////////// 
		
		/*
		VerificarCuenta vc = new VerificarCuenta();
		Thread Luis = new Thread(vc,"Luis");
		Thread Manuel = new Thread(vc,"Manuel");
		Luis.start();
		Manuel.start();
		*/
		
		
		

		
		/////////// CLASES SALUDO Y PERSONAL //////////////////// 
		
		/*
		// 		objeto en comun, se encarga del wait y notify

		Saludo saludo = new Saludo();
		
		// 		Instancio los hilos y le paso como parametros:
		// 			el nombre del hilo(en este caso es el nombre del personal)
		// 			el objeto en comun (Saludo)
		// 			un booleano para verificar si es jefe o empleado
		 
		 
		Personal Empleado1 = new Personal("Pepe",saludo,false);
		Personal Empleado2 = new Personal("Jose",saludo,false);
		Personal Empleado3 = new Personal("Pedro",saludo,false);
		Personal Jefe1 = new Personal("Jefe",saludo,true);
		
		// 		Lanzo los hilos
		Empleado1.start();
		Empleado2.start();
		Empleado3.start();
		Jefe1.start();
		
		*/
	}

}
