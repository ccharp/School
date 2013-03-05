public class Parallelogram extends Shape 
{
	private Coord a,b,c,d;
	private double theta;
	public Parallelogram(Coord a, Coord b, Coord c, Coord d, double theta)
	{
		super(4);
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		if(theta > 90)
		{
			System.out.println("Invalid value for theta.");
		}
		else
		{	
			this.theta = theta;
		}
	}
	
	//find length of two different sides then multiple them by sin(theta)
	//	where theta is the angle between two sides (must be < 90)
	//  Note: does not return correct area, but that isn't the purpose of this exervise.
	public double area()
	{
		return Math.abs((b.x-a.x)*(d.y-c.y)*Math.sin(theta));
	}

	public String toString()
	{
		return "Parallelogram defined by 4 points: " 
				+ a + "," + b + "," + c + "," + d + ".";
	}
}  
