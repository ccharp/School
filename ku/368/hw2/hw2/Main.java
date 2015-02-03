import java.lang.Math;

public class Main {
    public static void main(String[] args) {
	Rectangle rec1 = new Rectangle(new Coord(10,20),new Coord(30,50));
	
	System.out.println("rec1 = " + rec1);
	System.out.println("rec1.area() = " + rec1.area());
	System.out.println("rec1.sides() = " + rec1.sides());

	Rectangle rec2 = new Rectangle(new Coord(10,20),10,20);

	System.out.println("rec2 = " + rec2);
	System.out.println("rec2.area() = " + rec2.area());
	System.out.println("rec2.sides() = " + rec2.sides());


	Triangle tri1 = new Triangle(new Coord(10,20),
				     new Coord(0,0),
				     new Coord(20,10));

	System.out.println("tri1 = " + tri1);
	System.out.println("tri1.area() = " + tri1.area());
	System.out.println("tri1.sides() = " + tri1.sides());


	Circle cir1 = new Circle(new Coord(10,20),25);

	System.out.println("cir1 = " + cir1);
	System.out.println("cir1.area() = " + cir1.area());
	System.out.println("cir1.sides() = " + cir1.sides());


	Square sq1 =  new Square(new Coord(0,0),25);
	System.out.println("sq1 = " + sq1);
	System.out.println("sq1.area() = " + sq1.area());
	System.out.println("sq1.sides() = " + sq1.sides());

	//instantiate Parallelogram object
	Parallelogram para = new Parallelogram(new Coord(0,0),
				     	 new Coord(1,2),
				    	 new Coord(2,2),
						 new Coord(1,0), 60); 
	System.out.println("para = " + para);
	System.out.println("para.area() = " + para.area());
	System.out.println("para.sides() = " + para.sides());

	trapezoid trap = new trapezoid(new Coord(0,0),
				     	 new Coord(1,2),
				    	 new Coord(2,2),
						 new Coord(3,0), 2); 
	System.out.println("trap = " + trap);
	System.out.println("trap.area() = " + trap.area());
	System.out.println("trap.sides() = " + trap.sides());
	
	rhombus rhom = new rhombus(2, 2, new Coord(0,0)); 
	System.out.println("rhom = " + rhom);
	System.out.println("rhom.area() = " + rhom.area());
	System.out.println("rhom.sides() = " + rhom.sides());

	  describe(rec1);
	  describe(rec2);
	  describe(tri1);
	  describe(cir1);
	  describe(sq1);
	  describe(para);
	  describe(trap);
	  describe(rhom);
    }


    public static void describe(Shape s) {
	System.out.println("s = " + s);
	System.out.println("s.area() = " + s.area());
	System.out.println("s.sides() = " + s.sides());
    }	
}






















