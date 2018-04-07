1. For creating tables:
	i)  users:
	    >>> CREATE TABLE users (uid INT NOT NULL PRIMARY KEY AUTO_INCREMENT,firstname VARCHAR(100) NOT NULL,lastname VARCHAR(100) NOT NULL,email VARCHAR(120) NOT NULL UNIQUE,pwdhash VARCHAR(100) NOT NULL);

	ii) posts:
		>>> CREATE TABLE posts (pid INT NOT NULL PRIMARY KEY AUTO_INCREMENT,uid INT NOT NULL,subject VARCHAR(50) NOT NULL,post_content text NOT NULL,date int not null);



2. For inserting dummy data:
     i) users:
        >>> INSERT INTO users (firstname, lastname, email, pwdhash) VALUES("Mohan","Kapoor","mohan@xyz.com","abc1"),("Sunil","Chopra","sunil@xyz.com","abc2"),("Ajay","Shetty","ajay@xyz.com","abc3");
                  