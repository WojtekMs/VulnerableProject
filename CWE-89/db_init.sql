CREATE DATABASE sklep_rtv; 
USE sklep_rtv;

-- Tworzenie Tabel
CREATE TABLE Produkty (
	produkt_id INT PRIMARY KEY AUTO_INCREMENT,
    producent_id INT,
    model_id INT,
    kategorie_id INT,
    wymiar_id INT,
    opis VARCHAR(200),
    ilosc INT DEFAULT 0,
    cena DECIMAL(10,2) NOT NULL
);


CREATE TABLE Producenci (
	producent_id INT PRIMARY KEY AUTO_INCREMENT,
    producent VARCHAR(30),
    dane_kontaktowe_id INT
);

ALTER TABLE Produkty
ADD FOREIGN KEY(producent_id)
REFERENCES Producenci(producent_id)
ON DELETE SET NULL;


CREATE TABLE Dane_kontaktowe(
	dane_kontaktowe_id INT PRIMARY KEY AUTO_INCREMENT,
    adres_email VARCHAR(50) UNIQUE,
    numer_telefonu VARCHAR(15) UNIQUE,
    adres VARCHAR(100)
);

ALTER TABLE Producenci
ADD FOREIGN KEY(dane_kontaktowe_id)
REFERENCES Dane_kontaktowe(dane_kontaktowe_id)
ON DELETE SET NULL;


CREATE TABLE Zamowienie(
	zamowienie_id INT PRIMARY KEY AUTO_INCREMENT,
    produkt_id INT,
    kasa_id INT,
    FOREIGN KEY(produkt_id) REFERENCES Produkty(produkt_id) ON DELETE SET NULL
);


CREATE TABLE Modele(
	model_id INT PRIMARY KEY AUTO_INCREMENT,
    producent_id INT,
    model VARCHAR(50),
    rok_produkcji INT,
    FOREIGN KEY(producent_id) REFERENCES Producenci(producent_id) ON DELETE SET NULL
);

ALTER TABLE Produkty
ADD FOREIGN KEY(model_id)
REFERENCES Modele(model_id)
ON DELETE SET NULL;


CREATE TABLE Kategorie(
	kategorie_id INT PRIMARY KEY AUTO_INCREMENT,
    kategoria VARCHAR(30)
);

ALTER TABLE Produkty
ADD FOREIGN KEY(kategorie_id)
REFERENCES Kategorie(kategorie_id)
ON DELETE SET NULL;

-- skala w mm
CREATE TABLE Wymiary(
	wymiar_id INT PRIMARY KEY AUTO_INCREMENT,
    wysokosc INT NOT NULL,
    szerokosc INT NOT NULL,
    glebokosc INT NOT NULL
);

ALTER TABLE Produkty
ADD FOREIGN KEY(wymiar_id)
REFERENCES Wymiary(wymiar_id)
ON DELETE SET NULL;

CREATE TABLE Uprawnienia(
	uprawnienie_id INT PRIMARY KEY,
    uprawnienie VARCHAR(30)
);

-- haslo przechowywane w formie hashy (planowane 256 bitow)
CREATE TABLE Dane_logowania(
	dane_logowania_id INT PRIMARY KEY AUTO_INCREMENT,
    login VARCHAR(20) UNIQUE,
    haslo VARCHAR(100)
);

CREATE TABLE Pracownik(
	pracownik_id INT PRIMARY KEY AUTO_INCREMENT,
    dane_logowania_id INT,
    dane_kontaktowe_id INT,
    uprawnienie_id INT,
    imie VARCHAR(20),
    nazwisko VARCHAR(20),
    FOREIGN KEY(dane_logowania_id) REFERENCES Dane_logowania(dane_logowania_id) ON DELETE SET NULL,
    FOREIGN KEY(dane_kontaktowe_id) REFERENCES Dane_kontaktowe(dane_kontaktowe_id) ON DELETE SET NULL,
    FOREIGN KEY(uprawnienie_id) REFERENCES Uprawnienia(uprawnienie_id) ON DELETE SET NULL
);


LOAD DATA INFILE '/db_data/dane_kontaktowe.csv' 
INTO TABLE Dane_kontaktowe 
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/dane_logowania.csv' 
INTO TABLE Dane_logowania 
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/kategorie.csv' 
INTO TABLE Kategorie 
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/producenci.csv' 
INTO TABLE Producenci
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/modele.csv' 
INTO TABLE Modele
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/uprawnienia.csv' 
INTO TABLE Uprawnienia
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/wymiary.csv' 
INTO TABLE Wymiary
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/pracownik.csv' 
INTO TABLE Pracownik
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

LOAD DATA INFILE '/db_data/produkty.csv' 
INTO TABLE Produkty
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\n'
IGNORE 1 ROWS; 

-- tworzenie rol w systemie
CREATE ROLE IF NOT EXISTS 'admin', 'pracownik', 'klient';

-- przyznanie wszystkich przywilejow adminowi
GRANT ALL ON *.* TO 'admin';

-- przyznanie odpowiednich przywilejow pracownikowi:
GRANT SELECT, UPDATE, DELETE, INSERT ON Kategorie TO 'pracownik';
GRANT SELECT, UPDATE, DELETE, INSERT ON Modele TO 'pracownik';
GRANT SELECT, UPDATE, DELETE, INSERT ON Producenci TO 'pracownik';
GRANT SELECT, UPDATE, DELETE, INSERT ON Produkty TO 'pracownik';
GRANT SELECT, UPDATE, DELETE, INSERT ON Wymiary TO 'pracownik';
GRANT SELECT, UPDATE, DELETE, INSERT ON Zamowienie TO 'pracownik';

-- przyznanie odpowiednich przywilejow klientowi:
GRANT SELECT ON Kategorie TO 'klient';
GRANT SELECT ON Modele TO 'klient';
GRANT SELECT ON Producenci TO 'klient';
GRANT SELECT ON Produkty TO 'klient';
GRANT SELECT ON Wymiary TO 'klient';
GRANT INSERT ON Zamowienie TO 'klient';

-- tworzenie konta admina
CREATE USER IF NOT EXISTS 'admin'@'localhost' IDENTIFIED BY 'admin' DEFAULT ROLE 'admin';

-- tworzenie domyslnego konta klienta
CREATE USER IF NOT EXISTS 'klient'@'localhost' DEFAULT ROLE 'klient';
