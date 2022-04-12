package factory_method_pattern;

public class PetFactory implements Factory{
    private Pet pet=null;

    @Override
    public Pet createPet(String type) {
        switch (type){
            case "dog":
                pet=new Dog();
                break;
            case "cat":
                pet=new Cat();
                break;
        }
        return pet;
    }
}
