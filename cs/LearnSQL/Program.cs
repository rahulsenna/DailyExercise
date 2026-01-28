// See https://aka.ms/new-console-template for more information
using Microsoft.Data.Sqlite;


await using var connection = new SqliteConnection("Data Source=MyDatabse.db");
{
	try
	{
		await connection.OpenAsync();
		Console.WriteLine("Database connection opened successfuly");

		// await LoadData("Products.sq");
		await ReadAllProducts();

	}
	catch (SqliteException ex)
	{
		Console.Error.WriteLine($"SqliteException Message: {ex.Message}");
	}
}

async Task LoadData(string dbfile)
{
	var mockDataSql = await File.ReadAllTextAsync($"../../../{dbfile}");
	var seedCommand = connection.CreateCommand();
	seedCommand.CommandText = mockDataSql;
	await seedCommand.ExecuteNonQueryAsync();
}

async Task ReadAllProducts()
{
	var allProductsSql = connection.CreateCommand();
	allProductsSql.CommandText = @"SELECT name, category_name, price, price * 1.1
																	FROM Products
																	LIMIT -1
																	";

	var reader = await allProductsSql.ExecuteReaderAsync();


	Console.Error.WriteLine(new string('-', 110));
	Console.Error.WriteLine($"{"Name",-50} | {"Category",-30} | {"Price",-12} | {"New Price",-12}");
	Console.Error.WriteLine(new string('-', 110));

	while (await reader.ReadAsync())
	{
		string productName = reader.GetString(0);
		string categoryName = reader.GetString(1);
		float price = reader.GetFloat(2);
		float newPrice = reader.GetFloat(3);

		Console.Error.WriteLine($"{productName,-50} | {categoryName,-30} | {price,-12:F2} | {newPrice,-12:F2}");
	}

	Console.Error.WriteLine(new string('-', 110));
}