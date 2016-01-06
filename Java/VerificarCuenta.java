package App;
import java.util.logging.*; // libreria para los errores y logs

public class VerificarCuenta implements Runnable {
	private CuentaBanco cb = new CuentaBanco();
	// con synchronized creamos una funcion restringida para el uso de Threads, quiere decir que si un hilo esta
	// utilizando una funcion symchronized, solo este tendra acceso a la instancia del olbjeto, y los demas hilos
	// dormiran hasta que se desocupe el metodo
	private synchronized void HacerRetiro(int cantidad) throws InterruptedException{
		// si la cantidad a retirar es menor que lo que tenemos en fondo
		if(cb.getBalance() >= cantidad){
			System.out.println(Thread.currentThread().getName() + " Estas Realizando Un Retiro de RD$" + cantidad + ".");
			
		// ponemos el hilo a dormir durante 1 seg
		Thread.sleep(1000);
		// entonces retiramos la cantidad
		cb.retiroBancario(cantidad);
		// Thread.currentThread() --> de todos los hilos apunta el objeto hacia el hilo en cuestion
		// getName() --> es un metodo del objeto del comment de arriba que nos returnara el nombre del Objeto
		// en este caso del hilo
		System.out.println(Thread.currentThread().getName() + ": Retiro realizado.");
		System.out.println(Thread.currentThread().getName() + ", Los fondos son de: RD$" + cb.getBalance());
		}
		// si la cantidad excede nuestro fondo en la cuenta
		else{
			System.out.println("Sr. " + Thread.currentThread().getName() +" No hay suficiente dinero en la cuenta para realizar el retiro.");
			System.out.println("Sr. " + Thread.currentThread().getName() + " Su saldo actual es de RD$" + cb.getBalance());
			// aqui tambien dormimos en hilo 1 seg
			Thread.sleep(1000);
		}
		
	}
	// Override sobrescribe el run de la clase padre
	@ Override
	public void run(){
		//
		// iteramos 3 veces
		for(int i = 0 ; i <= 3 ; i++){
			try{
				// retiramos 10 al objeto (cuenta)
				this.HacerRetiro(10);
				// si ya no queda balance
				if(cb.getBalance() < 0){
					System.out.println("Sr. " + Thread.currentThread().getName() + ", La cuenta esta sobregirada.");
				}
			}
			catch(InterruptedException e){
				Logger.getLogger(VerificarCuenta.class.getName()).log(Level.SEVERE, null, e);
				System.out.println("Sr. " + Thread.currentThread().getName() + " HA OCURRIDO UN ERROR EN EL SERVIDOR.");
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
