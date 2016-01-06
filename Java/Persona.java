package App;

// esto no tiene mucha 'ciencia' -> es como el hola mundo de la POO

public class Persona{
	private String Nombre;
	public Persona(){
		System.out.print("Que Nombre le pondras a esta persona?: ");
		String Nacido =  "Eustaqueo";
		this.Nombre = Nacido;
	}
	public Persona(String Nombre){
		this.Nombre = Nombre;
		System.out.println("Ha Nacido " + this.Nombre + "!!! XD");
	}
	public void Saludar(){
		System.out.println("Hola, soy " + this.Nombre);
	}
	public void setNombre(String Nuevo){
		this.Nombre = Nuevo;
	}
	public void Despedirse(){
		System.out.println("Adios, soy" + this.Nombre);
	}
	public String GetNombre(){
		return this.Nombre;
	}
	
	public static void main(String[] args) {
	}

}

