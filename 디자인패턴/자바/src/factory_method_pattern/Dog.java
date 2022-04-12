package factory_method_pattern;

public class Dog implements Pet{
    @Override
    public void info() {
        System.out.println("강아지");
    }
}
