public class Triangle extends Shape {
    private Coord a,b,c;
    public Triangle(Coord a,Coord b,Coord c) {
	super(3);
	this.a = a;
	this.b = b;
	this.c = c;
    }    

    public double area() {
	return Math.abs(
	   (a.x * (b.y - c.y) +
	    b.x * (c.y - a.y) +
	    c.x * (a.y - b.y)) 
          / 2);
    }

    public String toString() {
	return "Triangle with corners " + 
	    a + "," +
	    b + "," +
	    c + ".";
    }
}
