
public class Main {
	
	static PolarGen pg;
	public static void main(String[] args) 
	{
		//System.out.println(args.length);
		if(args.length == 1)
		{
			System.out.println(args.length);
			pg = new PolarGen(Integer.parseInt(args[0]));
		}
		else 
		{
			System.out.println(args.length);
			pg = new PolarGen();
		}
		double  dEredmeny = pg.kovetkezo();
	    System.out.println(dEredmeny);
	}

}
