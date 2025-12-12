
public class Main
{
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
		String b, c, d;
		b = in.next();
		c = in.next();
		d = in.next();
		BigInteger x = new BigInteger(b);
		BigInteger y = new BigInteger(c);
		BigInteger z = new BigInteger(d);
		BigInteger ans = x.add(z);
		BigInteger ans2 = y.multiply(2);
		ans = ans2.subtract(ans);
		System.out.print(ans);
	}
}
