/* 
public class MyHashSet
{
    readonly Dictionary<int,bool> map;

    public MyHashSet()
    {
        map = [];
    }

    public void Add(int key)
    {
        map[key] = true;

    }

    public void Remove(int key)
    {
        map.Remove(key);
    }

    public bool Contains(int key)
    {
        return map.ContainsKey(key);
    }
}
 */

public class MyHashSet
{
    bool[] data;

    public MyHashSet()
    {
        data = new data[int.MaxValue];
    }

    public void Add(int key)
    {
        data[key] = true;

    }

    public void Remove(int key)
    {
        data[key] = false;
    }

    public bool Contains(int key)
    {
        return data[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.Add(key);
 * obj.Remove(key);
 * bool param_3 = obj.Contains(key);
 */