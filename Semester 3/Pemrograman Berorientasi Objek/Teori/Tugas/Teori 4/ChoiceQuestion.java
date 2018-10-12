import java.util.ArrayList;

public class ChoiceQuestion extends Question
{
  // pilihan
  ArrayList<String> choices = new ArrayList<String>();

  public void addChoice(String choice, boolean isTrue)
  {
    choices.add(choice);

    if(isTrue)
    {
      setAnswer(choices.size() + "");
    }
  }

  public void display()
  {
    super.display();
    // 9. System.out.println(text);
    // 10. this.display();
    for(int i = 0; i < choices.size(); i++)
    {
      System.out.println(i + 1 + " " + choices.get(i));
    }
  }
}
