public class Shape {
    private int sides;
    public Shape(int sides) {
	this.sides = sides;
    }

    public int sides() {
	return sides;
    }
    
    public double area() {
	throw new UnsupportedOperationException("area() not supported");
    }
}

