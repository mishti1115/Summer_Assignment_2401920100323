import java.util.Random;

public class TestCompartment {

    public static void main(String[] args) {

        Compartment[] c = new Compartment[10];
        Random r = new Random();

        for (int i = 0; i < 10; i++) {

            int n = r.nextInt(4) + 1;

            switch (n) {

                case 1:
                    c[i] = new FirstClass();
                    break;

                case 2:
                    c[i] = new Ladies();
                    break;

                case 3:
                    c[i] = new General();
                    break;

                case 4:
                    c[i] = new Luggage();
                    break;
            }

            System.out.println("Compartment " + (i + 1) + ": " + c[i].notice());
        }
    }
}
