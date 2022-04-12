package adapter_pattern;

public class Client {
    public static void main(String[] args){
        Pet dog =new Dog();
        Animal animal=new Adapter(dog);
        animal.sound();
    }
}
