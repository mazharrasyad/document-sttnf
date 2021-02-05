public class MySet
{
    private String[] items = new String[5];
    private int index = 1;
    private int size = 1;

    public int getSize()
    {
        return size;
    }

    public void add(String item)
    {
        if(this.isExist(item)) return;
        if(this.isFull()) this.expand();

        items[index++] = item;
        size++;
    }

    public void remove(String item)
    {
        int index = this.find(item);
        if(index > -1) {
            items[index] = null;
            size--;
        }

    }

    public int find(String item)
    {
        for(int i=0; i<size; i++) {
            if(items[i] == item) {
                return i;
            }
        }

        return -1;
    }

    private void expand()
    {
        String[] newItems = new String[items.length * 2];
        for(int i=0; i<items.length; i++) {
            newItems[i] = items[i];
        }

        this.items = newItems;
    }

    private boolean isFull()
    {
        return index == items.length;
    }

    public String getItem(int index) {
        return items[index];
    }

    private boolean isExist(String item)
    {
        return this.find(item) > -1;
    }
}
