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
	allProductsSql.CommandText = @"
		SELECT name, category_name, price, price * 1.1 AS new_price
		FROM Products
		LIMIT 20";
	await PrintQueryResults(allProductsSql);
}

async Task PrintQueryResults(SqliteCommand command)
{
	using var reader = await command.ExecuteReaderAsync();

	if (!reader.HasRows)
	{
		Console.Error.WriteLine("No rows returned.");
		return;
	}

	int columnCount = reader.FieldCount;
	var columnNames = new string[columnCount];
	var widths = new int[columnCount];

	for (int i = 0; i < columnCount; i++)
	{
		columnNames[i] = reader.GetName(i);
		widths[i] = columnNames[i].Length;
	}

	var allRows = new List<string[]>();

	while (await reader.ReadAsync())
	{
		var values = new string[columnCount];
		for (int i = 0; i < columnCount; i++)
		{
			if (reader.IsDBNull(i))
			{
				values[i] = "NULL";
			}
			else
			{
				Type fieldType = reader.GetFieldType(i);

				if (fieldType == typeof(float) || fieldType == typeof(double) || fieldType == typeof(decimal))
				{
					values[i] = $"{reader.GetValue(i):F2}";
				}
				else
				{
					values[i] = reader.GetValue(i)?.ToString() ?? "NULL";
				}
			}

			widths[i] = Math.Max(widths[i], values[i].Length);
		}

		allRows.Add(values);
	}

	int totalWidth = widths.Sum() + (columnCount - 1) * 3;

	Console.Error.WriteLine(new string('-', totalWidth));
	Console.Error.WriteLine(string.Join(" | ",
			columnNames.Select((name, i) => name.PadRight(widths[i]))));
	Console.Error.WriteLine(new string('-', totalWidth));

	foreach (var row in allRows)
	{
		Console.Error.WriteLine(string.Join(" | ",
				row.Select((val, i) => val.PadRight(widths[i]))));
	}

	Console.Error.WriteLine(new string('-', totalWidth));
}



/*
https://datalemur.com/sql-tutorial/sql-between
https://datalemur.com/questions/sql-between-practice-exercise
SELECT manufacturer, drug, units_sold
FROM pharmacy_sales
WHERE (manufacturer = 'Biogen' OR manufacturer = 'AbbVie' OR manufacturer = 'Eli Lilly')
AND units_sold BETWEEN 100000 AND 105000;



*/