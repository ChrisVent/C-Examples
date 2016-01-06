package App;
// el otro metodo para hacerlo es public class Hilo implements Runnable
// y se instancia ==> Thread myHilo = new Thread( [objeto tipo clasename] , [nombre del hilo]);
// ej: una clase hilo llamada: MyClase 
//		MyClase [objeto] = new MyClase();
//		Thread myHilo = new Thread([objeto] , [nombre del hilo]);
public class Hilo extends Thread{

	/**
	 * @param args
	 */
	private String desc;
	public Hilo(String Nombre){
		this.desc = Nombre;
	}
	//metodo run , esto es como el main  del hilo - lo que hara el hilo cuando se encuentre en ejecucion
	public void run(){
		for(int i = 0 ; i < 5 ; i++){
			System.out.println("[*] " + this.desc +" Esto es un hilo que hereda de la clase Thread!");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
