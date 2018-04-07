1. For creating tables:
	i)  users:
	    >>> CREATE TABLE users (
               uid INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
			   firstname VARCHAR(100) NOT NULL,
               lastname VARCHAR(100) NOT NULL,
               email VARCHAR(120) NOT NULL UNIQUE,
               pwdhash VARCHAR(100) NOT NULL
               );

	ii) posts:
		>>> CREATE TABLE posts (
                    pid INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
                    uid INT NOT NULL,
                    subject VARCHAR(50) NOT NULL,
                    post_content text NOT NULL,
                    date int not null
               );
               
               
UPDATE table_name SET column1=value, column2=value2 WHERE some_column=some_value 