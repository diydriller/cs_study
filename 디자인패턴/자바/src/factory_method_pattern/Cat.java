package factory_method_pattern;

public class Cat implements Pet{
    @Override
    public void info() {
        System.out.println("고양이");
    }
}
