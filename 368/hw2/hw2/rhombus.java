public class rhombus extends Shape 
{
	private Coord center;
	private int bisecting_line1, bisecting_line2;
	public rhombus(int bisecting_line1, int bisecting_line2, Coord center)
	{
		super(4);	
		this.bisecting_line1 = bisecting_line1;
		this.bisecting_line2 = bisecting_line2;
		this.center = center; 
	}
	
	//Add the lengh of the two parallel lines divided by to. Multiply by h
	public double area()
	{
		return bisecting_line1*bisecting_line2;
	}

	public String toString()
	{
		return "Rhombus defied by two bisecting lines and a center point: " 
				+ bisecting_line1 + "," + bisecting_line2 + "," + center;
	}
}
