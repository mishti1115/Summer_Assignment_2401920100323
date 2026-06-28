public class Outer {

    public void display() {
        System.out.println("Display method of Outer class");
    }

    class Inner {

        public void display() {
            System.out.println("Display method of Inner class");
        }
    }

    public static void main(String[] args) {

        Outer o = new Outer();
        o.display();

        Outer.Inner i = o.new Inner();
        i.display();
    }
}
