public class Circle extends Shape {
    private Coord a;
    private double r;
    
    public Circle(Coord a,double r) {
	super(1);
	this.a = a;
	this.r = r;
    }    

    public double area() {
	return Math.PI * r * r;
    }

    public String toString() {
	return "Circle with center " + a +
	    " and radius " + r;
    }

}
