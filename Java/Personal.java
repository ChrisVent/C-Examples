package App;
import java.util.logging.*; // libreria para el mostrar el log de error


// el hilo verifica mediante sus variables, si es un jefe o no para saber a quien saluda
// al ser un hilo, los empleados pueden llegar al mismo tiempo, al igual que el jefe
public class Personal extends Thread{
	private String Nombre; // nombre del empleado
	private Saludo saludo; // instanciamos un objeto saludo para el empleado
	boolean esJefe; // booleano que utilizaremos para saber si es jefe o no, el empleado
	
	// 	incializamos el objetos para definir los valores
	public Personal(String nombre,Saludo salu, boolean esjefe){
		this.Nombre = nombre;
		this.saludo = salu;
		this.esJefe = esjefe;
	}
	public void run(){
		System.out.println(this.Nombre + " Ha Llegado.");
		try{
			// dormimos el hilo 1 seg
			Thread.sleep(1000);
			// verifico si es jefe o no
			if(esJefe){
				saludo.saludoJefe(this.Nombre); // si es jefe, saludo a los empleados
			}
			else{
				saludo.saludoEmpleado(this.Nombre); // si es empleado, saludan al jefe
			}
		}
		catch(InterruptedException e){
			Logger.getLogger(Personal.class.getName()).log(Level.SEVERE,null,e);
			//  objeto - llamar al log (clasename - clasetype - clasemethod - escribimos en el log -> Nivel:Severo, null, y
			// la excepcion
			System.out.println("[!] No se que paso!");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
