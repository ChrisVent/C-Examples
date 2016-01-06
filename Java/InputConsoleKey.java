package App;
import java.util.*; // libreria para el objeto Scanner
public class InputConsoleKey {

	public static Scanner Teclado; // instanciamos un Scanner llamado teclado para leerlo
	public static void main(String[] args) {
		Teclado = new Scanner(System.in); // definimos teclado como un Scanner para System.in (lectura por teclado)
		System.out.print("Escribe Tu Edad: ");
		int variable = Teclado.nextInt(); // guardamos el valor que aceptamos por pantalla desde el objeto teclado
		//		mediante el metodo next ----- [Int] , [Float] ,[Boolean], [Double] o ninguno para Strings
		System.out.println("Tienes " + variable);
		

	}

}
