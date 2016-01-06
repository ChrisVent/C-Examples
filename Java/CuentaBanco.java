package App;

// simple clase que define un balance de 50 , retorna ese balance y tambien puede retirar y depositar
public class CuentaBanco {
	protected int balance = 50;
	public CuentaBanco(){
		
	}
	public int getBalance(){
		return balance;
	}
	public void retiroBancario(int retiro){
		this.balance -= retiro; 
	}
	public void depositoBancario(int deposito){
		this.balance += deposito;
	}
	static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
