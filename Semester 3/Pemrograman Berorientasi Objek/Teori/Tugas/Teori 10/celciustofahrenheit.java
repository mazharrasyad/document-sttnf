public class celciustofahrenheit implements iconverter{
    @Override
    public double convert (double input){
        return input = (((double)9/5) * input) + 32;
    }
}