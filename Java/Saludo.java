package App;
import java.util.logging.*; // libreria para el mostrar el log de error

	// la clase se trata de que si es un empleado, saluda al jefe
	// si es un jefe, entonces saluda todos los empleados
	// si el jefe no ha llegado, dormimos los "hilos" empleados para que cuando venga el jefe
	// este notifique a los hilos que despiertes que el ha llegado [ con wait para los empleados y notifyAll para el jefe]


public class Saludo {
	
	public Saludo(){
		/* Si no es jefe, el empleado va a quedar esperando a que llegue el jefe
		 * se hace el wait de el hilo que esta corriendo y se bloquea, hasta que le avise que
		 * ya puede saludar
		 */
	}

	public synchronized void saludoEmpleado(String Nombre){
		try{
			wait();
			System.out.println("\n" + Nombre.toUpperCase() + " : Buenos dias Jefe.");
		}
		catch(InterruptedException e){
			Logger.getLogger(Saludo.class.getName()).log(Level.SEVERE, null, e); // mostrara el log del error
		//  objeto - llamar al log (clasename - clasetype - clasemethod - escribimos en el log -> Nivel:Severo, null, y
			// la excepcion
		}
	}
	
	//Si es jefe, saluda y luego avisa a los empledos para que saluden
	// El notifyAll() despierta todos los hilos que estan bloqueados (por wait() )
	
	public synchronized void saludoJefe(String Nombre){
		System.out.println("\n***** " + Nombre + ": Buenos dias, Empleados. *****");
		notifyAll();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
