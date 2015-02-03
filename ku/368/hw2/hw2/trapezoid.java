
public class trapezoid extends Shape 
{
	private Coord a,b,c,d;
	private int height;
	public trapezoid(Coord a, Coord b, Coord c, Coord d, int height)
	{
		super(4);
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.height = height; 
	}
	
	//Add the lengh of the two parallel lines divided by to. Multiply by h
	public double area()
	{
		return Math.abs(((b.x-a.x)+(d.y-c.y))/2*height);
	}

	public String toString()
	{
		return "Parallelogram defined by 4 points: " 
				+ a + "," + b + "," + c + "," + d + ".";
	}
}
