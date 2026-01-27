// See https://aka.ms/new-console-template for more information
using Microsoft.Data.Sqlite;


await using var connection = new SqliteConnection("Data Source=MyDatabse.db");
{
	try
	{
		await connection.OpenAsync();
		Console.WriteLine("Database connection opened successfuly");

		// var mockDataSql = await File.ReadAllTextAsync("../../../MOCK_DATA.sql");
		// var command = connection.CreateCommand();
		// command.CommandText = mockDataSql;
		// await command.ExecuteNonQueryAsync();

		var command = connection.CreateCommand();
		command.CommandText = @"SELECT Id, first_name AS Name FROM Users";

		var reader = command.ExecuteReader();

		while(reader.Read())
		{
			int id = reader.GetInt32(0);
			string name = reader.GetString(1);
			Console.Error.WriteLine($"Id: {id}, Name: {name}"); 
		}


	} catch (SqliteException ex)
	{
		Console.Error.WriteLine($"SqliteException Message: {ex.Message}"); 
	}
}
