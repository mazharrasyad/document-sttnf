import java.util.LinkedList;
import java.util.ListIterator;
/**
This program demonstrates the LinkedList class.
*/
public class ListDemo
{
public static void main(String[] args)
{

// No 1
// LinkedList<String> staff = new LinkedList<String>();
// staff.addFirst("Harry");
// staff.addFirst("Diana");
// staff.addFirst("Tom");
// System.out.println(staff.removeFirst());
// System.out.println(staff.removeFirst());
// System.out.println(staff.removeFirst());
// 1. H
// 2. D H 
// 3. T D H
// 4. T
// 5. T D
// 6. T D H
// T D H

// No 2
// LinkedList<String> staff = new LinkedList<String>();
// staff.addFirst("Harry");
// staff.addFirst("Diana");
// staff.addFirst("Tom");
// System.out.println(staff.removeLast());
// System.out.println(staff.removeFirst());
// System.out.println(staff.removeLast());
// 1. H
// 2. D H
// 3. T D H
// 4. H
// 5. H T
// 6. H T D
// H T D

// No 3
// LinkedList<String> staff = new LinkedList<String>();
// staff.addFirst("Harry");
// staff.addLast("Diana");
// staff.addFirst("Tom");
// System.out.println(staff.removeLast());
// System.out.println(staff.removeFirst());
// System.out.println(staff.removeLast());
// 1. H
// 2. H D
// 3. T H D
// 4. D
// 5. D T
// 6. D T H
// D T H

// No 4
// LinkedList<String> staff = new LinkedList<String>();
// ListIterator<String> iterator = staff.listIterator();
// iterator.add("Tom");
// iterator.add("Diana");
// iterator.add("Harry");
// iterator = staff.listIterator();
// if (iterator.next().equals("Tom")) { iterator.remove(); }
// while (iterator.hasNext()) { System.out.println(iterator.next()); }
// 1. T |
// 2. T D |
// 3. T D H |
// D H

// No 5
// LinkedList<String> staff = new LinkedList<String>();
// ListIterator<String> iterator = staff.listIterator();
// iterator.add("Tom");
// iterator.add("Diana");
// iterator.add("Harry");
// iterator = staff.listIterator();
// iterator.next();
// iterator.next();
// iterator.add("Romeo");
// iterator.next();
// iterator.add("Juliet");
// iterator = staff.listIterator();
// iterator.next();
// iterator.remove();
// while (iterator.hasNext()) { System.out.println(iterator.next()); }
// 1. | T
// 2. | T D
// 3. | T D H
// 4. T | D H
// 5. T D | H
// 6. T D R | H
// 7. T D R H |
// 8. T D R H J | 
// 9. T D R H J
// 10. T | D R H J
// 11. D R H J
// D R H J

}
}