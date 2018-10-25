public class ComboLock
{
  private int secret1 = 0;
  private int secret2 = 0;
  private int secret3 = 0;
  private int first = 0;
  private int second = 0;
  private int third = 0;
  private boolean open;

  public ComboLock(int secret1, int secret2, int secret3)
  {   
    if(secret1 < 0 || secret2 < 0 || secret3 < 0)
    {
      System.out.println("Kunci Kombinasi Tidak Boleh Kurang Dari Angka 0");
      System.exit(0);
    }    
    else if(39 < secret1 || 39 < secret2 || 39 < secret3)
    {
      System.out.println("Kunci Kombinasi Tidak Boleh Lebih Dari Angka 39");
      System.exit(0);
    }
    else
    {
      this.secret1 = secret1;
      this.secret2 = secret2;
      this.secret3 = secret3;
    }        
  }

  public void reset()
  {
    this.first = 0;
    this.second = 0;
    this.third = 0;
  }

  public void turnLeft(int ticks)
  {    
    if(ticks < 0)
    {
      System.out.println("Kombinasi Kiri Tidak Boleh Kurang Dari Angka 0");
      System.exit(0);
    }
    else if(39 < ticks)
    {
      System.out.println("Kombinasi Kiri Tidak Boleh Lebih Dari Angka 39");
      System.exit(0);
    }
    else
    {
      if(this.second == 0)
      {
        this.second = ticks;
      }
    }    
  }

  public void turnRight(int ticks)
  {
    if(ticks < 0)
    {
      System.out.println("Kombinasi Kanan Tidak Boleh Kurang Dari Angka 0");
      System.exit(0);
    }
    else if(39 < ticks)
    {
      System.out.println("Kombinasi Kanan Tidak Boleh Lebih Dari Angka 39");
      System.exit(0);
    }
    else
    {
      if(this.first == 0)
      {
        this.first = ticks;
      }
      else if(this.third == 0 && this.second != 0)
      {
        this.third = ticks;
      }    
    }  
  }

  public boolean open()
  {    
    if(this.secret1 == this.first && this.secret2 == this.second && this.secret3 == this.third)
    {
      this.open = true;            
    }    
    else
    {
      this.open = false;      
    }     

    System.out.println("Combination : " + this.open);
    return this.open;    
  }
}
