// ----------ENCRYPTION / DECRYPTION PROGRAM WITH RC4 ALGORITHM-----------------

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//  -----------------Inizializzazione variabili---------------------------------

char plaintext_M [128];
char key_K [128];
char text_C[128];

int choice;

int i;

int lenght_M;
int lenght_K;

time_t t;

// ------------------INVOCAZIONE FUNZIONE MAIN
int  main(void){
                puts ("Immettere una frase di lunghezza massima 128 caratteri\n");

                fgets(plaintext_M, 128, stdin);
                fflush(stdin);

                lenght_M = strlen(plaintext_M)-1;     //Viene estratta la lunghezza della stringa escludendo l'ultimo carattere NULL'\0' dell'array

                printf("\nLa lunghezza della frase immessa è: %d\n", lenght_M);
                printf("La fresa immessa è : %s\n", plaintext_M);
                printf("\n>Se vuole inserire la chiave manualmente prema '1',\n>altrimenti se vuole che venga generata automaticamente prema '2' \n");
                scanf("%d", &choice);
                fflush(stdin);
                printf("\nla scelta fatta è: %d\n", choice);


// -------------SCELTA 1 DALL'UTENTE - INSERIMENTO CHIAVE DI CIFRATURA
               if (choice ==1 ){
                                while (getchar() != '\n');
                                do{
                                puts("\nImmettere una chiave K di lunghezza >= della precedente, non superiore a 128 caratteri\n");

                               fgets( key_K, 128 , stdin);
                               fflush(stdin);

                               lenght_K = strlen(key_K)-1;

                               printf ("\nLa chiave immessa è: %s\n", key_K);
                               printf("\nLa lunghezza della chiave K immessa è: %d\n",lenght_K);
                               fflush(stdout);


                             }while ( lenght_K < lenght_M );  /*fintanto che la chiave key_K immessa non è almeno di lunghezza pari alla plaintext_M
                                                          verrà richiesto all'utente di inserire una chiave maggiore o uguale.
                                                          */

// ----------------------ENCRYPTION/DECRYPTION

                             for (i=0; i<lenght_M; i++){
                                                      text_C[i]= plaintext_M[i] ^ key_K[i];                         /* Cella per cella viene effettuto lo XOR tra il plaintext_M e la chiave key_K,
                                                                                                                         il risultato viene salvato in una array cipher_T.*/

                                                      plaintext_M[i]= text_C[i] ^ key_K[i];
                                                      printf("\nIl testo cifrato è: %x\n", text_C[i]);
                                                     }                                                                /*Infine si effettua la decifratura risalendo al testo originale.
                                                                                                                        Qui lo xor è tra testo cifrato cipher_T e chiave key_K. */
                                                      printf("\nIl testo decifrato è: %s\n", plaintext_M );
                            }
// ---------SCELTA 2 DELL'UTENTE - CHIAVE GENERATA AUTOMATICAMENETE

               if (choice ==2){

                               srand((unsigned)time(NULL));                       /*Tramite la funzione rand si generano caratteri pseudo casuali
                               printf("\nLa chiave generata è : \n");             che salveremo in un array chiave key_K*/

                               for(i=0; i<lenght_M; i++){
                               key_K [i]= (32 + rand() %96);                      //Escludiamo i caratteri speciali partendo dal caratteri 32 della tabella ascii (space)

                              }printf("%s", key_K);

// ----------------------ENCRYPTION/DECRYPTION

                               for (i=0; i<lenght_M; i++){
                                                        text_C[i]= plaintext_M[i] ^ key_K[i];

                                                        plaintext_M[i]= text_C[i] ^ key_K[i];
                                                        printf("\nIl testo cifrato è: %x\n", text_C[i]);
                                                       }
                                                        printf("\nIl testo decifrato è: %s\n", plaintext_M );

// ---------SCELTA DIVERSA DA 1 E 2 DELL'UTENTE - SCELTA INESISTENTE
                               }else if (choice !=1 && choice !=2){
                                                                   printf("\nLa scelta fatta non è esistente!");

                                                                  }


  return (0);
}


// Eseguire codice con: gcc -c Esonero.c -std=c11 -Wall 
