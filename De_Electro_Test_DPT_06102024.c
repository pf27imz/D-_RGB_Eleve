// Titre				: 
// Source				: 
// Auteur				: 
// Lieu					: 
// Cr�ation			: 
// Description	: 
//===============================================================================

#include <c8051f300.h>	// inclure fichier d�finition SFR
#include <intrins.h>		// librairie intrins

// *** NOUVEAUX TYPES ***
typedef unsigned char uint8;		// 8 bits non sign�
typedef signed char int8;			// 8 bits sign�
typedef unsigned int uint16;		// 16 bits non sign�
typedef signed int int16;			// 16 bits sign�
typedef unsigned long uint32;		// 32 bits non sign�
typedef signed long int32;			// 32 bits sign�

// Equivalences
#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80	

#define CFG_IO	0x84	

// Entr�es:
#define BYES_IO P0	//entr�es d�
	
// Prototypes de fonctions (d�clarations)
void Ports_init(void);		//Initialisation des ports

// Programme principal
void Main(void)
{
	char byV_Counter = 1;
	
	//Disable watchdog timer
	PCA0MD &= ~BIT6;	//WDTE = 0;
	
	Ports_init();						// initialisation des ports 8 - 0

	while(1)
	{
		BYES_IO = CFG_IO | 0x00;/*Data*/
	}
}

void Ports_init(void)
// Fonction
// Description	: Initialise les ports 8 - 0
//										Digital Outputs
//										Digital inputs
//										Analog Inputs (P1)
//								Default state P 7 - 0 : 
//										Weak Pull up enable
//										Open Drain
//										Data 0xFF
//										
// Entr�es			: Aucun
// Sorties			: Aucun
{
	// Equivalences pour initialisation Port

	// initialisation du port 0:
	P0MDOUT = ~CFG_IO;	// Port P0 en entr�e open drain --> a corriger
	P0 = CFG_IO;
	
	//initialisation du crossbar "ne pas toucher"
	XBR2 &= (~BIT7); 					//active weak pull-up pour les Ports 0 - 3 (default state)
	//XBR2 |= (BIT7); 				//desactive weak pull-up 	
	XBR2 |= (BIT6); 					// XBARE: enable crossbar (active toutes les I/O)
}
