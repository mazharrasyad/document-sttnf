/*
  1. Class (True)
  - Superclass = Employee
  - Subclass = Manager

  2. Class (True)
  - BankAccount = Superclass
  - CheckingAccount = Subclass
  - SavingsAccount = Subclass

  3. Kuis warisan Pertanyaan ? (False)
  - Ya, Karena quiz merupakan pertanyaan yang khusus (False)
  - Tidak, Karena quiz merupakan bagian pertanyaan (True)

  4. Which of the following calls are legal? (False)
  - a. q.setAnswer(response)
  - b. cq.setAnswer(response)
  - c. q.addChoice(choice, true)
  - d. cq.addChoice(choice, true)
  Legal kecuali yang c

  5. Superclass       | Subclass
  a. Employee         | Manager Y
  b. Student          | GraduateStudent Y
  c. Person           | Student Y
  d. Employee         | Professor Y
  e. BankAccount      | CheckingAccount Y
  f. Vehicle          | Car Y
  g. Vehicle          | Minivan Y
  h. Car              | Minivan Y
  i. Vehicle          | Truck Y

  6. Karena setiap barang berbeda" dan juga bukan bagian dari barang tersebut

  7. Diagram
    Object
      |----> Person
      |        |----> Employee ----> Instructor
      |        |----> Student      
      |
      |----> Classroom

  8. Relationship University
    - DepartmentChair, Person, Student, Professor, Employee, Janitor, TeachingAssistant, Secretary
    - Course, Lecture, Seminar, SeminarSpeaker, ComputerLab

  9. System.out.println(text);
  - Run jika variabel text public
  - Error jika variabel text private

  10. this.display();
  - Error karena yang dipanggil display ChoiceQuestion dan akan terjadi infinity loop
*/

public class Question
{
  // punya apa ?
  // text,answer
  public String text,answer;

  // konstruktor
  public Question()
  {
    text = "";
    answer = "";
  }

  // bisa apa ?
  // set text
  public void setText(String newtext)
  {
    text = newtext;
  }

  // set answer
  public void setAnswer(String correctAnswer)
  {
    answer = correctAnswer;
  }

  // cek answer
  public boolean cekAnswer(String response)
  {
    return answer.equals(response);
  }

  public void display()
  {
    System.out.println(text);
  }
}
