public class rupiahtodollar implements iconverter{
    @Override
    public double convert (double input){
        return input /= 14000;
    }
}