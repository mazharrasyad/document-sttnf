import java.util.Scanner;

public class Quiz
{
  public static void main(String a[])
  {
    // buat obj question
    Question q1 = new Question();

    q1.setText("Siapa penemu java ?");
    q1.setAnswer("James Gosling");
    q1.display();

    // terima jawaban user
    Scanner s = new Scanner(System.in);
    String jawaban = s.nextLine();
    System.out.println("Jawaban anda : " + q1.cekAnswer(jawaban));

    ChoiceQuestion cq1 = new ChoiceQuestion();
    cq1.setText("Siapa presiden RI ke 4 ? ");
    cq1.addChoice("Megawati",false);
    cq1.addChoice("Gusdur",true);
    cq1.addChoice("Habibie",false);
    cq1.addChoice("SBY",false);

    cq1.display();
    s = new Scanner(System.in);
    String pil = s.nextLine();
    System.out.println(cq1.cekAnswer(pil));
  }
}
