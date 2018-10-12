public class DemoBankAccount
{
  public static void main(String [] args)
  {
    /*
    // instantiation (bikin obj)
    BankAccount b1 = new BankAccount();
    BankAccount b2 = new BankAccount();

    double saldob1 = b1.getBalance();
    System.out.println("Saldo b1 : " + saldob1);

    b1.deposit(1000);
    b1.deposit(500);
    b2.deposit(4000);

    saldob1 = b1.getBalance();

    System.out.println("Saldo b1 : " + saldob1);
    System.out.println("Saldo b2 : " + b2.getBalance());


    BankAccount b1 = new BankAccount("Azhar");
    BankAccount b2 = new BankAccount("Rasyad");
    BankAccount b3 = b1; // Type data reference selain 7 data primitive
    /*
                |          |
      b1,b3 --> |  Memory  |
                |          |
                Tempatnya barengan


    b1.deposit(99.99);
    b2.deposit(100.50);
    b3.deposit(45.765);

    System.out.println("saldo b1:"+b1.getBalance()); // ?
    System.out.println("saldo b2:"+b2.getBalance()); // ?
    System.out.println("saldo b3:"+b3.getBalance()); // ?
    */

    BankAccount b1 = new BankAccount("Fulan 2");
    BankAccount b2 = new BankAccount();

    b1.deposit(10000);
    b2.deposit(200);

    b1.printDetail();
    System.out.println();
    b2.printDetail();
    System.out.println();
    b1.transfer(200, b2);
    System.out.println();
    b1.printDetail();
    System.out.println();
    b2.printDetail();
  }
}
