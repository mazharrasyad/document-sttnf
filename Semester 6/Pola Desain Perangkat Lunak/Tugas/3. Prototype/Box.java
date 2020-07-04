public class Box implements Cloneable{
    private String color;
    
    public Box(String col){
        setColor(col);
    }
     
    public Box clone(){
        Box b = null;
        try{
            b = (Box)super.clone();
        }catch(Exception e){
             
        }
        return b;
    }
     
    public String getColor() {
        return color;
    }
     
    public void setColor(String color){
        this.color = color;
    }
}