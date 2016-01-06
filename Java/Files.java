package App;
import java.io.*; // libreria para los inputs y outputs en ficheros

// mediante la clase Files puedes escribir y leer archivos de texto 

public class Files {
	// variable para guardar el contenido en caso de que no este en blanco, para volverlo a escribir
	// cuando querramos textear en el archivo.
	// me explico... cuando querramos escribir en el archivo, primero guardamos lo que tenia antes
	// en la variable Content, para antes de escribir, lo guardamos denuevo
	private String Content;
	// metodo para leer en archivo (como parametro, el filename)
	// este metodo consigue el contenido del archivo de text pero no lo muestra
	public void getContent(String Archivo){
		// definimos Content con 0 caracteres
		this.Content = "";
		try{
			// un FileReader sera un objeto que 'llamara' al archivo que pasamos por param 
			FileReader file = new FileReader(Archivo);
			// BufferedReader sera un objeto que guardara el contenido del objeto-archivo de arriba
			// en otras palabras, guardara el contenido del archivo al que llama FileReader
			BufferedReader buffer = new BufferedReader(file);
			// variable temporal para guardar cada linea del archivo
			String Temp = "";
			// mientras Temp no sea null, es decir, mientras no sea el fin de fichero
			while(Temp != null){
				// guardamos en la variable el contenido de una linea del fichero
				// el metodo readLine una vez llamado lee solo una linea del archivo
				Temp = buffer.readLine();
				// si esa linea no es fin de fichero
				if(Temp == null){
					// salimos del ciclo
					break;
				}
				// de lo contrario (si nisiquiera pasa por el if)
				// agragamos esa linea a la variable Content,  asi al final tendra todas las lineas
				this.Content += Temp + "\n";
			}
			// cerramos el proceso del objeto buffer
			buffer.close();
			
		}
		catch(IOException e){
			// en caso de no encontrar el archivo
			System.out.println("[!] Error, Archivo no encontrado!");
		}
	}

	// este metodo consigue el contenido del archivo, y muestra lo guardado en Content
	public void Leer(String Archivo){
		this.getContent(Archivo);
		System.out.println(this.Content);
	}
	
	// funcion que escribe al final del archivo de texto
	public void Escribir(String Archivo, String Content){
		// instanciamos un onjeto tipo File con el que podamos trabajar
		File f = new File(Archivo);
		// guardamos el contenido anterior del archivo  para agregarlo despues y asi no sobrescribirlo
		this.getContent(Archivo);
		try{
			// FileWriter es un objeto que llama a un File para iniciar un proceso para escribir en el
			FileWriter w = new FileWriter(f);
			// creamos un buffer para escritura para almacenar lo que querramos agregarle al File
			BufferedWriter buffer = new BufferedWriter(w);
			// PrintWritter es un objeto que usa el bufferedwriter para lo que halla en el, imprimirlo en nuestro
			// archivo, es decir , como el print de teclado a pantalla , pero este es un print de buffer a archivo 
			PrintWriter wr = new PrintWriter(buffer);
			// escribimos nuevamente lo anterior guardado en el archivo
			wr.append(this.Content);
			//Ahora escribimos al final , lo que el usuario paso por param
			wr.append(Content);
			// cerramos los objetos que tenian un proceso corriendo con el archivo
			wr.close();
			buffer.close();
		}
		catch(IOException e){
			System.out.println("[!] No se que paso!");
		}
		
	}


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
