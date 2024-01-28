Cognome e Nome: Giardinetto Giuseppe
Data: 21/12/2023

Breve descrizione riassuntiva delle modifiche: 
Modifiche su errori sintattici, 
aggiunta metodi getter, setter e toString,
gestite eccezioni e aggiunto throws Exception,
aggiunti alcuni cast a classi,
aggiunto qualche @Override,
aggiunta una constrain su una colonna dell'entità
------------------------------
MODIFICHE
PROGETTO: GIARDINETTOGIUSEPPE_SERVER
FILE: EventoMusicale.java
Linea 27: aggiunta constraint @Column(unique=true) sulla colonna titolo
Linea 49-117: aggiunta getter,setter e toString

FILE: EventoMusicaleBean.java
Linea 24: cambiato il tipo di ritorno del metodo aggiungiEventoMusicale con void
Linea 25: rimossa la return
Linea 102: fix maiuscola del nome delle variabili (da Data a data)

FILE: RemoteBean.java
Linea 11: cambiato il tipo di ritorno del metodo aggiuntiEventoMusicale con void

FILE: DBPopulator.java
Linea 28: fix 30.0 -> 30.0f
Linea 29: rimossa l'assegnazione
Linea 35: aggiunto metodo e l'assegnazione dell'oggetto managed restituito dalla merge 

FILE: InterceptEventiMusicali.java
Linea 14: aggiunta throws Exception
Linea 18: fix sintassi aggiunta parentesi di chiusura per il metodo equals
Linea 24: fix sintassi aggiunta parentesi di chiusura dell'if clause
Linea 34: fix sintassi operatore == (da = a ==)
Linea 36: fix sintassi operatore == (da = a ==)

FILE: eventoAggiunto.java
Linea 11: fix sintassi ElementType.PARAMETERS -> ElementType.PARAMETER

FILE: EventHandler.java
Linea 15: fix sintassi nome classe (da Lista a List)
Linea 23-25: fix nome variabile (da e a ev) 

FILE: MDB.java
Linea 24: aggiunto @Override
Linea 27-37: aggiunto try-catch
Linea 28: aggiunto MessageWrapper.class nel metodo getBody
Linea 31: aggiunta stampa messaggio arrivato

FILE: MessageWrapper.java
Linea 31-92: aggiunta setter,getter e toString

PROGETTO: GIARDINETTOGIUSEPPE_EventoMusicaleClient
FILE: EventoMusicaleClient.java
Linea 10: aggiunta throws NamingException
Linea 12: aggiunto cast a RemoteBean
Linea 12: aggiunta stringa di lookup

PROGETTO: GIARDINETTOGIUSEPPE_MessageClient
FILE: MessageClient.java
Linea 24: 30.0 -> 30.0f

PROGETTO: GIARDINETTOGIUSEPPE_WebServiceClient
FILE: WebServiceClient.java
Linea 20: fix nome metodo da modificaEvento() a modificaEventoMusicale()
