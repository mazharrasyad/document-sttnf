public class BankAccount
{
  /*
  Dalam Suatu   Kelas :
  1. Punya apa = property = variabel(tempat menyimpan nilai)
  2. Bisa apa = method = function = prosedur, return_value(type data) variabel (argument) | return_value = informasi yang didapat
  3. Sedang apa =
  */

  // property --> punya apa ?
  private double balance;
  private String account_name;

  // method --> bisa apa ?
  public double getBalance()
  {
    return balance;
  }

  public void printDetail()
  {
    System.out.println("Saldo : " + getBalance());
    System.out.println("Nama : " + account_name);
  }

  // overload constructor

  public BankAccount(String name)
  {
    balance = 0;
    account_name = name;
  }

  public BankAccount()
  {
    balance = 0;
    account_name = "Fulan";
  }

  public void deposit(double amount)
  {
    balance = balance + amount;
  }

  public void deposit(int amount)
  {
    balance = balance + amount;
  }

  public void deposit(int amount,double tax)
  {
    balance = balance + amount - tax;
  }

  public void transfer(double amount, BankAccount dest)
  {
    // kurangi saldo tujuan
    balance = balance - amount;

    // tambah saldo tujuan
    // dest.balance = dest.getBalance() + amount;
    // dest.deposit(dest.getBalance() + amount);
    dest.deposit(amount);
  }
}
