#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, const char* argv[] )
{
    if( argc==4 && argv[0]=="set" ){
    	
        /**
            Si hay 4 argumentos y el primero es la palabra set:
            aplicacion.c set nom user pass
            añadir una fila a un archivo users.txt del estilo CSV
                nom,user,pass;
        */
        char nom[20] = argv[1];
        char user[20] = argv[2];
        char pass[20] = argv[3];
        
        File f*;
		f = fopen("contrasenyes.csv", "a"); //modo para situarte al final y afegir contenido
		fprintf(f, "%s,%s,%s\n", nom,user,pass); //no se si esto es correcto
        fclose(f);
        
        
    }else if ( argc==2 && argv[0] == "get" ){
        /**
            Si hay 2 argumentos y el primero es la palabra get:
            aplicacion.c get manolo 
            buscar en el users.txt el primer manolo y devolver su pass 
        */
        
		char qui_busco[20] = argv[1];
		
        File f*;
		f = fopen("contrasenyes.csv", "r");
		char linia*;
		
		while(!EOF && !trobada){
			linia = Fgets("(variable)");
			char aux[3][20] = separarLiniasPorComas(linia); //devuelve un array de cadenas ["facebook","pepe@gmail.com","1234"];
			//supongo que tendras que reccorer letra a letra buscando las ','
			char usuari* = aux[1];
			if(usuari == qui_busco){ //strcmp
				
				print("Tu password es: %s",aux[2]);
				bool trobada = TRUE; //salir	!EOF && !trobada => !EOF && FALSE => FALSE
			}
		}
		
		fclose(f);
		
    }else if ( argc==1 argv[0] == "list" ){
        /**
            Si hay 1 argumento y es la palabra list:
            aplicacion.c list 
            leer i mostrar todas las filas.
        */
        File f*;
		f = fopen("contrasenyes.csv", "r");
		char linia*;
		
		while(!EOF){
			linia = Fgets("(variable)");	//lee linia
			print("%s\n",linia);			//escupe linia
		}
		
		
    }else{ return -1; } //final malo
    return 0;//final ok
}
