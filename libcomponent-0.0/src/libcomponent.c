
/**@file libcomponent.c */

/*!
 * \var float data_matrix[7][12]
 * \brief includes the data for E12-series resistor components
 */ 

/*!
 * \var int x 
 * \brief An variable for the row 
 */ 

/*!
 * \var int i
 * \brief An variable for the column
 */
 
 /*!
 * \var int count_answere
 * \brief An variable that incremented for counting the amount of components found
 */
 
 /*!
 * \var float answere
 * \brief An variable to compute the if the value is positive or negative from "answere - data_matrix[x][i];" to see if it should continue searching 
 */
 
 /*!
 * \var float last_answere1
 * \brief An variable to compute the the last answere if it is closer to the resistor value than last_answere2 
 */
 
 /*!
 * \var float last_answere2 
 * \brief An variable to compute the the last answere if it is closer to the resistor value than last_answere1
 */

 /*!
 * \var float temp
 * \brief An variable that temporary store the value from answere just incase it needs to save the value and overite answere later
 */


//libcomponent.c letar efter komponenter i E12-serien för ersättningsresistansen
int e_resistance(float orig_resistance, float *res_array ){
	//använder mig av matris för att få korrekta svar annars ifall jag använder mig av pow så blir det fel på decimaler. 
	
	
	float data_matrix[7][12] = {
		
		{1.00,1.20,1.50,1.80,2.20,2.70,3.30,3.90,4.70,5.60,6.80,8.20},
		{10.00,12.00,15.00,18.00,22.00,27.00,33.00,39.00,47.00,56.00,68.00,82.00},
		{100.00,120.00,150.00,180.00,220.00,270.00,330.00,390.00,470.00,560.00,680.00,820.00},
		{1000.00,1200.00,1500.00,1800.00,2200.00,2700.00,3300.00,3900.00,4700.00,5600.00,6800.00,8200.00},
		{10000.00,12000.00,15000.00,18000.00,22000.00,27000.00,33000.00,39000.00,47000.00,56000.00,68000.00,82000.00},
		{100000.00,120000.00,150000.00,180000.00,220000.00,270000.00,330000.00,390000.00,470000.00,560000.00,680000.00,820000.00},
		{1000000.00,1200000.00,1500000.00,1800000.00,2200000.00,2700000.00,3300000.00,3900000.00,4700000.00,5600000.00,6800000.00,8200000.00}
		}; 
		
	*res_array = 0; //sätter värdet på res_array till noll för ifall det hittas inget så blir det inte en segmentationfault
	int x=6; //börjar med Mega 10^6
	int i=11; //börjar med 8.20
	int count_answere = 0; //börjar räkna från noll
	float answere = orig_resistance; //sätter orig_resitance på answere som ska decrementera
	float last_answere1 = 0; //sista svar för att jämföra med för närmaste värde
	float last_answere2 = 0; //sista svar för att jämföra med för närmaste värde
	float temp = orig_resistance; //temporär variabel för att skriva över med
	
	if(orig_resistance != 0){
	
	if(data_matrix[6][11] < orig_resistance){return 0;} //Om största resistansen är mindre än ersättningsresistansen så returnera 0
	
	while(1){
		/*
		 * Loop until somethings return;
		 * 
		 */ 
		
		 
		if(count_answere < 2){ 
			/*
			 * This computes as long count_answere is less than 2
			 * 
			 * */
			 
			answere = answere - data_matrix[x][i]; //subtrahera	
			}
		else{
			/*
			 * This computes as long count_answere is less than 3
			 * 
			 */ 
			
			last_answere1 = data_matrix[x][i+1] - answere; 
			last_answere2 = answere - data_matrix[x][i];
			answere = answere - data_matrix[x][i]; //subtrahera	
			
			
			}
		
		if(answere > 0){ //hittat ett värde som passar till resistansen
			/*
			 * Found an component in otherwords an answere
		     * 
			 */
			
			if(count_answere < 2){
				/*
				 * The answere is stored
				 * 
				 */ 
			*(res_array+count_answere) = data_matrix[x][i]; 
			count_answere += 1;
			temp = answere; //Har hittat resistansen så skriv över temp så att vi letar vidare med resistansen
			}
			else if(count_answere < 3){
				
				/*
				 * The last answere is stored and by looking at the closest value
				 * 
				 */ 
				
				if(last_answere1 < last_answere2){ //Om det föregående värdet är närmare ersättningsresistansen än det nuvarande så ta det
					/*
					 * The closest answere is the previous value and store the value
					 * 
					 * 
					 */ 
					
					
					*(res_array+count_answere) = data_matrix[x][i+1];
					
					
					}
				else if(last_answere1 > last_answere2){ //Om nuvarande värde är närmare ersättningsresistansen än det föregående så ta det
				/*
				 * The closes answere is current value and store the value
				 * 
				 */ 
				
				*(res_array+count_answere) = data_matrix[x][i];
				}
				count_answere += 1;
				//temp = answere; //Har hittat resistansen så skriv över temp så att vi letar vidare med resistansen
				/*
				 * If last is found the return integer value that is the number of components
				 * 
				 */ 
				return count_answere; 
				}
			}
		else if(answere == 0){ //sista resistansen hittad och returnera count
			/*
			 * If exact value is found then store the value and return the integer value that is the number of components
			 */ 
			*(res_array+count_answere) = data_matrix[x][i];
			count_answere +=1;
			return count_answere; 
			
			}
			
		else{ //Om answere är negativ så bläddra vidare
			/*
			 * If value is not found then go through the next row or column
			 */ 
			
			if((i==0) && (x==0)){ //resistansen inte hittas
				/*
				 * If no answere is found then return integer value that is the number of components
				 */ 
				
				return count_answere; 
				} 
			if((x>0) && (i == 0) ){ //bläddra vidare 
				/*
				 * If row is larger than zero but column is zero then go through next row and set the column to 11
				 * 
				 */ 
				x-=1;
				i = 11;
			}
			else{
				/*
				 * Else go through next column
				 * 
				 */ 
				i -= 1; //bläddra vidare i data
				
				}
			/*
			 * Overwrite the answere so that it doesnt reach zero value directly
			 * 
			 */ 
			answere = temp; //Om answere är negativ så sätt tillbaka orig_resistance temp 
			} 
		
		
		}
	}
	else
	{
		return 0;
		}
	
	
	return count_answere; //returnera oavsett eftersom det kommer annars en varning i kompilatorn för en int function
	
	
	}
