public class Square extends Rectangle {
    
    public Square(Coord a,double sz) {
	super(a,sz,sz);
    }    

    public String toString() {    
	return "Square, which is a " + super.toString();
    }

}
