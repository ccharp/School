public class Rectangle extends Shape {
    private Coord a;
    private double x,y;
    
    public Rectangle(Coord a,double x,double y) {
	super(4);
	this.a = a;
	this.x = x;
	this.y = y;
    }    

    public Rectangle(Coord a,Coord b) {
	this(a,Math.abs(a.x - b.x),Math.abs(a.y - b.y));
    }    

    public double area() {
	return x * y;
    }

    public String toString() {
	Coord c1,c2,c3,c4;
	c1 = a;
	c2 = new Coord(c1.x,c1.y + y);
	c3 = new Coord(c1.x + x,c1.y + y);
	c4 = new Coord(c1.x + x,c1.y);
	return "Rectangle with corners " + 
	    c1 + "," +
	    c2 + "," +
	    c3 + "," +
	    c4 + ".";
    }

}
