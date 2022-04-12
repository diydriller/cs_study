package factory_method_pattern;

public class Client {

    public static void main(String[] args){
        Factory factory=new PetFactory();
        Pet dog = factory.createPet("dog");
        dog.info();
    }
}
