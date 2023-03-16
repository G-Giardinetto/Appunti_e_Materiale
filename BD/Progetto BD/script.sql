DROP DATABASE IF EXISTS AziendaCeramica;
CREATE DATABASE AziendaCeramica;
USE AziendaCeramica;
DROP USER IF EXISTS 'utenteazienda'@'%';
CREATE USER 'utenteazienda'@'%' identified by 'utenteazienda';
GRANT ALL ON AziendaCeramica.* TO 'utenteazienda'@'%';

CREATE TABLE dipartimento(
  codiceDipartimento INT NOT NULL,
  CF_Direttore_Dip VARCHAR(16),
  PRIMARY KEY (codiceDipartimento)
);
CREATE TABLE sezione(
  lettera CHAR NOT NULL,
  numero INT NOT NULL,
  codiceDipartimento INT NOT NULL,
  PRIMARY KEY (lettera, numero),
  FOREIGN KEY (codiceDipartimento) REFERENCES dipartimento(codiceDipartimento)
);
CREATE TABLE settore(
  codiceSettore INT NOT NULL,
  CF_Direttore_Sett VARCHAR(16),
  indirizzo VARCHAR(70),
  PRIMARY KEY (codiceSettore)
);
CREATE TABLE dipendente(
  codiceDipendente INT NOT NULL,
  nome VARCHAR(25) NOT NULL,
  cognome VARCHAR(25) NOT NULL,
  dataNascita DATE,
  cittaNascita VARCHAR(25),
  stipendio DOUBLE,
  codiceDipartimento INT NOT NULL,
  codiceSettore INT NOT NULL,
  PRIMARY KEY (codiceDipendente),
  FOREIGN KEY (codiceDipartimento) REFERENCES dipartimento(codiceDipartimento),
  FOREIGN KEY (codiceSettore) REFERENCES settore(codiceSettore)
);
CREATE TABLE ceramica_in_creazione(
  sigla VARCHAR(25) NOT NULL,
  tecnicaCreazione VARCHAR(75),
  PRIMARY KEY (sigla)
);
CREATE TABLE controlla(
  codiceDipendente INT NOT NULL,
  sigla VARCHAR(25) NOT NULL,
  dataControllo DATE NOT NULL,
  FOREIGN KEY (codiceDipendente) REFERENCES dipendente(codiceDipendente),
  FOREIGN KEY (sigla) REFERENCES ceramica_in_creazione(sigla),
  PRIMARY KEY (codiceDipendente, sigla)
);
CREATE TABLE numero_telefono(
  numero VARCHAR(16) NOT NULL,
  codiceSettore INT NOT NULL,
  FOREIGN KEY (codiceSettore) REFERENCES settore(codiceSettore),
  PRIMARY KEY (numero, codiceSettore)
);




CREATE TABLE postazione(
  codicePostazione INT NOT NULL,
  numMacchine INT NOT NULL,
  tipoMacchinari VARCHAR(25) NOT NULL,
  codiceSettore INT NOT NULL,
  PRIMARY KEY (codicePostazione),
  FOREIGN KEY (codiceSettore) REFERENCES settore(codiceSettore)
);

CREATE TABLE ceramica(
  codiceCeramica INT NOT NULL,
  dataProduzione DATE NOT NULL,
  costo DOUBLE NOT NULL,
  tipo VARCHAR(15) NOT NULL,
  firma VARCHAR(25),
  codiceSettore INT NOT NULL,
  PRIMARY KEY (codiceCeramica),
  FOREIGN KEY (codiceSettore) REFERENCES settore(codiceSettore)
);

INSERT INTO settore
VALUES (1, "NDRFBY43S41M167T", "Via Acrone, 4"),
       (2, "KBRYGW56C01E031A", "Via Giberti, 42"),
       (3, "RSTNSM30A41I711L", "Corso Porta Borsari, 16"),
       (4, "CRSMRA10S41F606B", "Piazza Giuseppe Garibaldi, 58");
INSERT INTO dipartimento
VALUES (1, "GRNLYN19T41H720Y"),
       (2, "PGLMRM14L41L463M"),
       (3, "BNMMLS26T41L859U"),
       (4, "LMBJND92A41D960D");
INSERT INTO sezione
VALUES ("A", 1, 1),
       ("A", 2, 1),
       ("B", 1, 2),
       ("B", 2, 2),
       ("B", 3, 2),
       ("C", 1, 3);
INSERT INTO dipendente
VALUES (1, "Diego", "Sarnese", "1983-06-04", "Salerno", 1250, 1, 1),
       (2, "Agatino", "Baresi", "1990-07-19", "Napoli", 1400, 1, 1),
       (3, "Umberto", "Fonti", "1971-02-14", "Cava De Tirreni", 1350, 2, 1),
       (4, "Andrea", "Baresi", "1985-10-01", "Napoli", 1290, 2, 2),
       (5, "Ambra", "Rizzo", "1995-09-24", "Salerno", 1250, 2, 2),
       (6, "Silvestro", "Calabresi", "1979-03-18", "Salerno", 1500,  2, 3),
       (7, "Rosalia", "Fanucci", "1978-06-11", "Cava De Tirreni", 1450, 3, 4),
       (8, "Franco", "Manna", "1962-08-17", "Vietri", 1300, 3, 4),
       (9, "Giorgia", "Palerma", "1972-03-13", "Cava De Tirreni", 1380, 3, 4),
       (10, "Francesco", "Chirico", "1981-04-10", "Napoli", 1280, 3, 4),
       (11, "Umberto", "Nespoli", "1999-04-08", "Napoli", 1250, 2, 3),
       (12, "Chiara", "Giusti", "1969-10-25", "Vallo Di Diano", 1300, 3, 4),
       (13, "Carlo", "Russo", "2000-11-13", "Benevento", 1280, 1, 1),
       (14, "Marianna", "Colombo", "1988-03-26", "Cava De Tirreni", 1250, 1, 2),
       (15, "Giorgia", "Genovesi", "1973-07-15", "Salerno", 1300, 2, 2),
       (16, "Cinzia", "Mancini", "1981-05-30", "Bologna", 1280, 3, 1),
       (17, "Fabrizio", "Manna", "1977-12-13", "Vietri", 1180, 4, 2),
       (18, "Lorenzo", "Buonomo", "1992-10-23", "Palermo", 1200, 3, 3),
       (19, "Michele", "De Rosa", "2001-11-28", "Bari", 1180, 2, 1),
       (20, "Giancarlo", "Borriello", "1996-08-13", "Torre Del Greco", 1250, 4, 4),
       (21, "Fortunata", "Siciliani", "2001-09-24", "Torre Annunziata", 1280, 1, 2),
       (22, "Agostino", "Bruno", "1988-01-26", "Roma", 1360, 3, 3),
       (23, "Jolanda", "Lombardo", "1992-01-01", "Gela", 1300, 1, 4),
       (24, "Fabio", "Barese", "2000-10-17", "Torino", 1200, 2, 1),
       (25, "Guglielmo", "Pisano", "1997-05-03", "Salerno", 1240, 3, 3),
       (26, "Pasquale", "Esposito", "1969-04-02", "Ercolano", 1190, 3, 4),
       (27, "Lucia", "Olivieri", "1972-01-13", "Cava De Tirreni", 1380, 1, 2),
       (28, "Carla", "Palerma", "1979-08-11", "Bracigliano", 1280, 3, 1),
       (29, "Giuseppe", "Longo", "2000-11-21", "Baronissi", 1380, 3, 4),
       (30, "Filippo", "Bassani", "2001-03-13", "Pompei", 1200, 4, 4);
INSERT INTO numero_telefono
VALUES ("03756939696", 1),
       ("03818447846", 2),
       ("03936998878", 3),
       ("03402436293", 3),
       ("03814716551", 4),
       ("03593516929", 4),
       ("03259924874", 1),
       ("0384 4928711", 1),
       ("0317 0718685", 2);
INSERT INTO ceramica_in_creazione
VALUES ("Vaso 1", "Tecnica a Colombino"),
       ("Vaso 2", "Tecnica a Lastre"),
       ("Vaso 3", "Tecnica a Colatura"),
       ("Piatto 1", "Tecnica a Colombino"),
       ("Piatto 2", "Tecnica a Colombino"),
       ("Ornamento 1", "Tecnica per Ornamenti Standard"),
       ("Ornamento 2", "Tecnica per Ornamenti in Terracotta"),
       ("Ornamento 3", "Tecnica per Ornamenti Greificati"),
       ("Da Appendere 1", "Tecnica per Maiolica");
INSERT INTO controlla
VALUES (2, "Vaso 1", "2020-03-10"),
       (2, "Ornamento 1", "2020-03-10"),
       (9, "Vaso 2", "2020-03-05"),
       (29, "Ornamento 1", "2021-10-07"),
       (17, "Da Appendere 1", "2022-03-05"),
       (22, "Vaso 3", "2020-03-05"),
       (22, "Piatto 2", "2023-01-05"),
       (8, "Ornamento 3", "2022-10-07"),
       (16, "Ornamento 2", "2021-12-19"),
       (5, "Piatto 1", "2020-03-12");
INSERT INTO postazione
VALUES (1, 15, "Fornaci", 1),
       (2, 10, "Torni", 1),
       (3, 30, "Tavoli per raffreddare", 1),
       (4, 25, "Scaffali", 1),
       (5, 15, "Torni", 2),
       (6, 10, "Fornaci", 2),
       (7, 25, "Tavoli per raffreddare", 2),
       (8, 20, "Scaffali", 2),
       (9, 10, "Torni", 4),
       (10, 15, "Scaffali", 4),
       (11, 13, "Fornaci", 4),
       (12, 15, "Tavoli per raffreddare", 4),
       (13, 15, "Essiccatori", 1),
       (14, 15, "Essiccatori", 2),
       (15, 20, "Essiccatori", 4);
INSERT INTO ceramica
VALUES (1, "2020-03-09", 29.99, "Ornamento", "Agatino", 3),
       (2, "2020-02-20", 44.99, "Vaso", "Vista Vietri", 3),
       (3, "2020-02-25", 19.99, "Da Appendere", "Antonio", 3),
       (4, "2020-03-05", 34.99, "Vaso", "Cava", 3),
       (5, "2020-02-20", 54.45, "Ornamento", "Salvatore", 3),
       (6, "2022-10-25", 68.45, "Vaso", "Marianna", 3),
       (7, "2021-08-01", 21.90, "Da Appendere", "Cinzia", 3),
       (8, "2022-02-20", 80.30, "Ornamento", "Filippo", 3),
       (9, "2021-12-20", 107.45, "Vaso", "Umberto", 3),
       (10, "2022-12-10", 74.50, "Ornamento", "Salvatore", 3),
       (11, "2021-12-20", 27.45, "Da Appendere", "Agatino", 3),
       (12, "2022-11-30", 48.30, "Vaso", "Fortunata", 3),
       (13, "2023-01-20", 70.00, "Da Appendere", "Lucia", 3),
       (14, "2023-01-30", 25.50, "Da Appendere", "Umberto", 3),
       (15, "2022-11-15", 82.00, "Ornamento", "Jolanda", 3),
       (16, "2021-12-01", 47.50, "Ornamento", "Salvatore", 3),
       (17, "2023-01-15", 169.90, "Vaso", "Fabrizio", 3),
       (18, "2021-02-26", 44.70, "Da Appendere", "Antonio", 3),
       (19, "2022-10-27", 29.70, "Vaso", "Agatino", 3),
       (20, "2020-12-20", 88.50, "Ornamento", "Cinzia", 3),
       (21, "2020-07-15", 20.50, "Ornamento", "Lucia", 3),
       (22, "2021-05-13", 33.40, "Vaso", "Fortunata", 3),
       (23, "2021-05-13", 50.50, "Vaso", "Fabio", 3),
       (24, "2022-10-17", 81.50, "Da Appendere", "Lucia", 3),
       (25, "2022-11-13", 59.90, "Ornamento", "Salvatore", 3),
       (26, "2022-12-10", 13.90, "Vaso", "Carla", 3),
       (27, "2023-01-08", 24.90, "Piatto", "Giancarlo", 3),
       (28, "2023-01-15", 42.70, "Da Appendere", "Fabrizio", 3),
       (29, "2020-12-20", 11.98, "Da Appendere", "Lorenzo", 3),
       (30, "2022-12-24", 199.90, "Vaso", "Salvatore", 3);
