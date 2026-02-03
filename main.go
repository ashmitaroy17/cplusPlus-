package main

import (
    "database/sql"
    "fmt"
    "log"

     // <--- ADD THIS LINE EXACTLY
)

func main() {
	// Connection string - using your credentials from the image
	connStr := "host=localhost port=5432 user=postgres password=SATCOM33 dbname=GO sslmode=disable"

	// 1. Open the connection
	db, err := sql.Open("postgres", connStr)
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	// 2. Test the connection
	err = db.Ping()
	if err != nil {
		fmt.Println("Ping failed! Check if PostgreSQL service is running.")
		log.Fatal(err)
	}

	fmt.Println("Successfully connected to PostgreSQL database 'GO'!")

	// 3. Fetch data from your 'bottle' table
	rows, err := db.Query("SELECT id, name, email FROM bottle")
	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()

	fmt.Println("--- Table Data ---")

	// 4. Iterate through rows
	for rows.Next() {
		var id int
		var name, email string

		// This scans the database columns into your Go variables
		err := rows.Scan(&id, &name, &email)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Printf("ID: %d | Name: %s | Email: %s\n", id, name, email)
	}

	// 5. Final check for errors during iteration
	if err = rows.Err(); err != nil {
		log.Fatal(err)
	}
}
