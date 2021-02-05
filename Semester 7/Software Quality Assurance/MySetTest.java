import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import org.junit.Test;

public class MySetTest
{
    @Test
    public void testAddNewElement()
    {
        MySet mySet = new MySet();
        mySet.add("Uwais");
        assertEquals(1, mySet.getSize());
    }

    @Test
    public void testAddMultipleElement()
    {
        MySet mySet = new MySet();
        mySet.add("Uwais");
        mySet.add("Annas");
        mySet.add("Zul");
        assertEquals(3, mySet.getSize());
    }

    @Test
    public void testDuplicateElement()
    {
        MySet mySet = new MySet();
        mySet.add("Uwais");
        mySet.add("Annas");
        mySet.add("Annas");
        assertEquals(2, mySet.getSize());
    }

    @Test
    public void testFindElement()
    {
        MySet mySet = new MySet();
        mySet.add("Uwais");
        mySet.add("Annas");
        mySet.add("Zul");
        assertEquals(2, mySet.find("Zul"));
        assertEquals(-1, mySet.find("Salman"));
    }
}
