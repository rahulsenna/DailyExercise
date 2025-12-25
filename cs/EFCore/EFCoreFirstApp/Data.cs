

using Microsoft.EntityFrameworkCore;
using System.Runtime.CompilerServices;

public class BloggingContext: DbContext
{
    public DbSet<Blog> Blogs { get; set; }
    public DbSet<Post> Posts { get; set; }

    public string DbPath { get; }

    static string GetDbPath([CallerFilePath] string sourceFilePath = "")
    {
        string? directory = Path.GetDirectoryName(sourceFilePath);
        return Path.Join(directory, "blogging.db");
    }

    public BloggingContext() => DbPath = GetDbPath();

    protected override void OnConfiguring(DbContextOptionsBuilder options) => options.UseSqlite($"Data Source={DbPath}");

}

public class Blog
{
    public int BlogId { get; set; }
    public string Url { get; set; } = string.Empty;

    public ICollection<Post> Posts { get; } = new List<Post>();
}

public class Post
{
	public int PostId { get; set; }
    public string Title { get; set; } = string.Empty;
    public string Content { get; set; } = string.Empty;


    public int BlogId { get; set; }
    public Blog? Blog { get; set; }
}