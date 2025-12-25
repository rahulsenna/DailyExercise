
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using Microsoft.EntityFrameworkCore;




internal class Program
{
  private static async Task Main(string[] args)
  {
    Console.WriteLine("Hello, World!");
    
    var db = new BloggingContext();
    Console.Error.WriteLine($"db.DbPath: {db.DbPath}");
    
    // Create
    // db.Add(new Blog { Url = "http://blogs.msdn.com/adonet" });
    // await db.SaveChangesAsync();

    var blogs = await db.Blogs.ToListAsync();
    var posts = await db.Posts.ToListAsync();
    var blog = blogs.First();
    // var blog = await db.Blogs.FirstAsync();

    // var blog = await db.Blogs.OrderBy(b => b.BlogId).FirstAsync();


    // Update
    // blog.Url = "https://devblogs.microsoft.com/dotnet";
    // blog.Posts.Add(new Post { Title = "Hello World", Content = "I wrote an app using EF Core!" });
    // blog.Posts.Add(new Post { Title = "2", Content = "2" });
    // await db.SaveChangesAsync();

    // Delete
    // db.RemoveRange(blogs);
    // db.Remove(blog);
    // await db.SaveChangesAsync();
    int d = 3;


  }

}