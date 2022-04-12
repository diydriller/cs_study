package adapter_pattern;

public class Dog implements Pet {

    @Override
    public void bark() {
        System.out.println("멍멍");
    }
}
