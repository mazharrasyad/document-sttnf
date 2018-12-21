public class fahrenheittocelcius implements iconverter{
    @Override
    public double convert (double input){
        return input =  ((double)5/9) * (input - 32);
    }
}