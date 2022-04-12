package adapter_pattern;

public class Adapter implements Animal {

    private Pet pet;
    public Adapter(Pet pet){
        this.pet = pet;
    }

    @Override
    public void sound() {
        pet.bark();
    }
}
