import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BigInteger N = sc.nextBigInteger();
		BigInteger buf = BigInteger.ONE;
		BigInteger i = BigInteger.ZERO;
		
		while (buf.compareTo(N) <= 0) {
			buf = buf.multiply(BigInteger.valueOf(2));		
			i = i.add(BigInteger.ONE);
		}
		System.out.println(i);
		System.exit(0);
	}

}
