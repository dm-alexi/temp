CREATE TABLE bands (
	id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO bands (name) VALUES ('Iron Maiden'), ('Judas Priest'), ('Helloween'), ('Kamelot'), ('Def Leppard');